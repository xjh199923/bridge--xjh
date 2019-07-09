#ifndef SYSTEMTRAYICON_H
#define SYSTEMTRAYICON_H

#include <QWidget>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QCloseEvent>

class SystemTrayIcon : public QWidget
{
    Q_OBJECT
public:
    explicit SystemTrayIcon(QStringList strList, QIcon icon, QWidget *parent = 0);
    ~SystemTrayIcon();

    void createAct();
    void createTrayMenu();
    void createTrayIcon();

signals:
    void signal_showWin();          //显示窗口

public slots:
    void slot_iconActivated(QSystemTrayIcon::ActivationReason reason);

private:
    QSystemTrayIcon *m_trayIcon;        //系统托盘
    QMenu *menu;                        //菜单
    QAction *actMin;                    //最小化
    QAction *actNormal;                 //正常
    QAction *actExit;                   //退出

    QStringList m_strList;                //托盘信息
    QIcon m_icon;                         //托盘图标

    QWidget *pWidget;
};

#endif // SYSTEMTRAYICON_H
