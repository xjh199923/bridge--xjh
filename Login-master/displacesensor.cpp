#include "displacesensor.h"
#include "ui_displacesensor.h"
#include"exam.h"


#include <QDebug>
#include <QMessageBox>
#include <QHeaderView>  //表头视图类

#include <QFileDialog>      //打开或保存文件对话框
#include <QFile>            //文件类
#include <QTextStream>      //文本流输入输出

displacesensor::displacesensor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::displacesensor)
{
    ui->setupUi(this);


    QFile fweiyi("/Users/xjh/Desktop/Qt/Bradge_xjh/txt/位移传感器数据.txt");
    if(!fweiyi.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return ;
    }

    QTextStream txtInput(&fweiyi);
    QString lineStr[201];
    int k=1;
    while(!txtInput.atEnd())
    {

        lineStr[k] = txtInput.readLine();
                k++;
    }
    int num;
    num=k/10;

    fweiyi.close();
      int i,j;
      k=1;
    ui->tableWidget->setRowCount(num);
    int r=ui->tableWidget->rowCount();
    for(i=0;i<r;i++)
    {
        for(j=0;j<10;j++)
        {
        ui->tableWidget->setItem(i,j,new QTableWidgetItem(lineStr[k]));
        k++;
        }
    }
    //设置日期编辑控件可以弹出日历
      ui->prodateEdit->setCalendarPopup(true);
      //设置表格控件特性
          //每次选中整行
          ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
          //为方便删除按钮操作，把选中模式设为单选，即每次只选中一行，而不能选中多行
          ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
          //开启自动排序
          ui->tableWidget->setSortingEnabled(true);
          ui->tableWidget->sortByColumn(0, Qt::AscendingOrder);
          //设置末尾一列自动拉伸
          ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
          //表头序号不可见
          ui->tableWidget->verticalHeader()->setVisible(false);
          //设置默认行高，把图标设置更大一些
              ui->tableWidget->verticalHeader()->setDefaultSectionSize(36);
              ui->tableWidget->setIconSize( QSize(32,32) );

}

displacesensor::~displacesensor()
{
    delete ui;
}

void displacesensor::on_addpushButton_clicked()
{
    QString str[10];
    str[0] = ui->sennamelineEdit->text().trimmed();
     str[1] = ui->modellineEdit->text().trimmed();
      str[2] = ui->manufalineEdit->text().trimmed();
     str[3] = ui->spftionlineEdit->text().trimmed();
      str[4]= ui->numlineEdit->text().trimmed();
      str[5]= ui->prodateEdit->text().trimmed();
      str[6] = ui->statuelineEdit->text().trimmed();
      str[7] = ui->upmeasurelineEdit->text().trimmed();
      str[8] = ui->lowmeasurelineEdit->text().trimmed();
      str[9] = ui->lineEditshensuo->text().trimmed();
        //判断是否为空
        if( str[0].isEmpty() || str[1].isEmpty() || str[2].isEmpty()|| str[3].isEmpty()|| str[4].isEmpty()
                || str[5].isEmpty() || str[6].isEmpty()|| str[7].isEmpty()|| str[8].isEmpty()|| str[9].isEmpty())
        {
            QMessageBox::warning(this, tr("添加行"), tr("请先填好几项数据再添加！"));
            return ;
        }
        int r=ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(r);
       int r2=ui->tableWidget->rowCount();
        ui->tableWidget->setRowCount(r2);
        int i;
       for(i=0;i<10;i++)
       {
        ui->tableWidget->setItem(r,i,new QTableWidgetItem(str[i]));
       }
}

void displacesensor::on_delepushButton_clicked()
{
    //目前仅支持删除选中的当前行
        //获取当前条目
        QTableWidgetItem *curItem = ui->tableWidget->currentItem();
        if(curItem != NULL) //当前条目非空
        {
            if(curItem->isSelected())
            {
                //当前条目被选中，那么确定是删除该行
                ui->tableWidget->removeRow( curItem->row()  );
                int r=ui->tableWidget->rowCount();
                ui->tableWidget->setRowCount(r);
            }
        }
}

void displacesensor::on_savepushButton_clicked()
{
    QString item1 = ui->tableWidget->item(0,0)->text();
    if(item1.isEmpty())
    {
        //没有数据
                return;
    }
    //获取保存的文件名
        QString strFileSave = QFileDialog::getSaveFileName(
                    this,
                    tr("保存文件"),
                    tr("/Users/xjh/Desktop/Qt/Bradge_xjh/txt/位移传感器数据.txt"),
                    tr("Text Files(*.txt)")
                    );
        if(strFileSave.isEmpty())
        {
            return;
        }
        //打开输出文件
        QFile fileOut(strFileSave);
        if( ! fileOut.open(QIODevice::WriteOnly))
        {
            QMessageBox::warning(this, tr("保存文件"), tr("打开保存文件失败：") + fileOut.errorString());
            return;
        }
        //定义输出文本流
        QTextStream tsOut( & fileOut);
        int r=ui->tableWidget->rowCount();
        for(int i=0; i<r; i++)
            {
            for(int j=0;j<10;j++)
            {
                QString strCurAll = ui->tableWidget->item(i,j)->text();
                tsOut<<strCurAll<<endl;
            }
            }
        ui->tableWidget->setRowCount(r);
            //提示保存完毕
            QMessageBox::information(this, tr("保存文件"), tr("保存表格文件成功。"));
}

void displacesensor::on_returnpushButton_clicked()
{
    this->close();
    Exam *a=new Exam;
    a->show();
    emit close();

}
