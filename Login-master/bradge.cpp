#include "bradge.h"
#include "ui_bradge.h"
#include"exam.h"

#include <QDebug>
#include <QMessageBox>
#include <QHeaderView>  //表头视图类

#include <QFileDialog>      //打开或保存文件对话框
#include <QFile>            //文件类
#include <QTextStream>      //文本流输入输出


bradge::bradge(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::bradge)
{
    ui->setupUi(this);
        sortButtonGroup = new QButtonGroup();
        //实例化sortButtonGroup
        sortButtonGroup->addButton(ui->strainradioButton, 0);
        //将代表数学的单选框加入sortButtonGroup并将其id设为0
        //不建议使用默认id，默认id是由-2开始依次递减的
        sortButtonGroup->addButton(ui->deflectradioButton, 1);
        //将代表英语的单选框加入sortButtonGroup并将其id设为1
        sortButtonGroup->addButton(ui->displaceradioButton, 2);
        //自动设置列宽
        ui->strain_tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->strain_tableWidget->hide();

        QFile fyingbian("/Users/xjh/Desktop/Qt/Bradge_xjh/txt/应变传感器数据.txt");
        if(!fyingbian.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            return ;
        }

        QTextStream txtIn(&fyingbian);
        QString lineStr[201];
        int ks=1;
        while(!txtIn.atEnd())
        {

            lineStr[ks] = txtIn.readLine();
                    ks++;
        }
        int num;
        num=ks/8;
        fyingbian.close();
        QFile fweiyi("/Users/xjh/Desktop/Qt/Bradge_xjh/txt/straindate.txt");
            if(!fweiyi.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                return ;
            }
            QTextStream txtInput(&fweiyi);
            QString str;
            int k=1;
            while(!txtInput.atEnd())
            {

                str=txtInput.readLine();
                QStringList qstrList;
                qstrList = str.split("\t");
                QString Date  = qstrList.at(0);
                QString w1  = qstrList.at(1);
                QString w2   = qstrList.at(2);
                QString w3 = qstrList.at(3);
                QString w4  = qstrList.at(4);
                QString w5  = qstrList.at(5);
                QString w6  = qstrList.at(6);
                QString w7  = qstrList.at(7);
                QString w8  = qstrList.at(8);
                QString w9  = qstrList.at(9);
                QString w10  = qstrList.at(10);
                QString w11  = qstrList.at(11);
                double xjh[12];
              for(int i=2;i<=11;i++)
                {
                  xjh[i]=1000*(w2.toDouble()-lineStr[(i-1)*8].toDouble())+4;
                }
                ui->strain_tableWidget->setRowCount(k);
                ui->strain_tableWidget->setItem(k-1,0,new QTableWidgetItem(Date));
                ui->strain_tableWidget->setItem(k-1,1,new QTableWidgetItem(w1));
                for(int j=2;j<=11;j++)
                {
                     ui->strain_tableWidget->setItem(k-1,j,new QTableWidgetItem(QString::number(xjh[j],10,3)));
                }
                k++;
            }
            ui->deflect_tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
            ui->deflect_tableWidget->hide();
            QFile fweiyi1("/Users/xjh/Desktop/Qt/Bradge_xjh/txt/deflectdate.txt");
                if(!fweiyi1.open(QIODevice::ReadOnly | QIODevice::Text))
                {
                    return ;
                }

                QTextStream txtInput1(&fweiyi1);
                QString str1;
                int k1=1;
                while(!txtInput1.atEnd())
                {

                    str1=txtInput1.readLine();
                    QStringList qstrList1;
                    qstrList1 = str1.split("\t");
                    QString Date1  = qstrList1.at(0);
                    QString Time  = qstrList1.at(1);
                    QString Num   = qstrList1.at(2);
                    QString Value = qstrList1.at(3);
                    double count =Value.toDouble()-100.71;
                    QString Unit  = qstrList1.at(4);
                    ui->deflect_tableWidget->setRowCount(k1);
                    ui->deflect_tableWidget->setItem(k1-1,0,new QTableWidgetItem(Date1));
                    ui->deflect_tableWidget->setItem(k1-1,1,new QTableWidgetItem(Time));
                    ui->deflect_tableWidget->setItem(k1-1,2,new QTableWidgetItem(Num));
                    ui->deflect_tableWidget->setItem(k1-1,3,new QTableWidgetItem(Value));
                      ui->deflect_tableWidget->setItem(k1-1,4,new QTableWidgetItem(QString::number(count,10,4)));
                    ui->deflect_tableWidget->setItem(k1-1,5,new QTableWidgetItem(Unit));
                    k1++;
                }
                ui->displace_tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
                ui->displace_tableWidget->hide();
                QFile fweiyi2("/Users/xjh/Desktop/Qt/Bradge_xjh/txt/displacedate.txt");
                    if(!fweiyi2.open(QIODevice::ReadOnly | QIODevice::Text))
                    {
                        return ;
                    }

                    QTextStream txtInput2(&fweiyi2);
                    QString str2;
                    int k2=1;
                    while(!txtInput2.atEnd())
                    {

                        str2=txtInput2.readLine();
                        QStringList qstrList2;
                        qstrList2 = str2.split("\t");
                        QString Date2  = qstrList2.at(0);
                        QString Time1  = qstrList2.at(1);
                        QString Num1   = qstrList2.at(2);
                        QString Value1 = qstrList2.at(3);
                        double count1;
                        if(Num1=="800227")
                        {
                            count1=Value1.toDouble()-0.98;
                        }
                        else if(Num1=="800225")
                        {
                            count1=Value1.toDouble()-0.23;
                        }
                        QString Unit1  = qstrList2.at(4);
                        ui->displace_tableWidget->setRowCount(k2);
                        ui->displace_tableWidget->setItem(k2-1,0,new QTableWidgetItem(Date2));
                        ui->displace_tableWidget->setItem(k2-1,1,new QTableWidgetItem(Time1));
                        ui->displace_tableWidget->setItem(k2-1,2,new QTableWidgetItem(Num1));
                        ui->displace_tableWidget->setItem(k2-1,3,new QTableWidgetItem(Value1));
                        ui->displace_tableWidget->setItem(k2-1,4,new QTableWidgetItem(QString::number(count1,10,4)));
                        ui->displace_tableWidget->setItem(k2-1,5,new QTableWidgetItem(Unit1));
                        k2++;
                    }
}

bradge::~bradge()
{
    delete ui;
}

void bradge::on_resultpushButton_clicked()
{
    this->close();
    Exam *a=new Exam;
    a->show();
    emit close();
}


void bradge::on_strainradioButton_clicked(bool checked)
{
    ui->strain_tableWidget->show();
    ui->deflect_tableWidget->hide();
    ui->displace_tableWidget->hide();
}

void bradge::on_deflectradioButton_clicked(bool checked)
{
    ui->strain_tableWidget->hide();
    ui->deflect_tableWidget->show();
    ui->displace_tableWidget->hide();
}

void bradge::on_displaceradioButton_clicked(bool checked)
{
    ui->strain_tableWidget->hide();
    ui->deflect_tableWidget->hide();
    ui->displace_tableWidget->show();
}
