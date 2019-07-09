#include "systemtrayicon.h"

#include <QApplication>
#include <QDebug>

SystemTrayIcon::SystemTrayIcon(QStringList strList, QIcon icon, QWidget *parent)
    : QWidget(parent)
{
    pWidget = parent;
    m_strList = strList;
    m_icon = icon;
    createAct();
    createTrayMenu();
    createTrayIcon();
}

SystemTrayIcon::~SystemTrayIcon()
{

}

void SystemTrayIcon::createAct()
{
    actMin = new QAction("最小化(&N)",this);
    connect(actMin,SIGNAL(triggered()),pWidget,SLOT(hide()));
    actNormal = new QAction("还 原(&R)",this);
    connect(actNormal,SIGNAL(triggered()),pWidget,SLOT(showNormal()));
    actExit = new QAction("退出(&Q)",this);
    connect(actExit,SIGNAL(triggered()),qApp,SLOT(quit()));
}

void SystemTrayIcon::createTrayMenu()
{
    menu = new QMenu((QWidget*)QApplication::desktop());
    menu->addAction(actMin);
    menu->addAction(actNormal);
    menu->addSeparator();     //加入一个分离符
    menu->addAction(actExit);
}

void SystemTrayIcon::createTrayIcon()
{
    if (!QSystemTrayIcon::isSystemTrayAvailable())      //判断系统是否支持系统托盘图标
    {
        return;
    }

    m_trayIcon = new QSystemTrayIcon(pWidget);
    m_trayIcon->setIcon(m_icon);   //设置图标图片
    m_trayIcon->setToolTip(m_strList.at(1));    //托盘时，鼠标放上去的提示信息
    m_trayIcon->showMessage(m_strList.at(0), m_strList.at(1), QSystemTrayIcon::Information, 10000);
    m_trayIcon->setContextMenu(menu);     //设置托盘上下文菜单
    m_trayIcon->show();
    connect(m_trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this,
            SLOT(slot_iconActivated(QSystemTrayIcon::ActivationReason)));
}

void SystemTrayIcon::slot_iconActivated(QSystemTrayIcon::ActivationReason reason)
{    
    switch (reason) {
    case QSystemTrayIcon::Unknown:
        break;
    case QSystemTrayIcon::Context:
        break;
    case QSystemTrayIcon::DoubleClick:
        pWidget->setWindowState(Qt::WindowActive);
        emit signal_showWin();
        pWidget->show();
        break;
    case QSystemTrayIcon::Trigger:
        break;
    case QSystemTrayIcon::MiddleClick:
        break;
    default:
        break;
    }
}
