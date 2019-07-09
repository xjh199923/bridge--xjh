#include "displacepoint.h"
#include "ui_displacepoint.h"
#include"displacepoint.h"
#include"exam.h"
#include"adddisplacesensor.h"
#include"displacepointline.h"

#include <QDebug>
#include <QMessageBox>
#include <QHeaderView>  //表头视图类

#include <QFileDialog>      //打开或保存文件对话框
#include <QFile>            //文件类
#include <QTextStream>      //文本流输入输出

QString globaldata2; //声明一个全局变量用于窗体间传值

displacepoint::displacepoint(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::displacepoint)
{
    ui->setupUi(this);

    ui->pointnumlineEdit->setPlaceholderText("输入要显示曲线的测点编号");


    QFile fweiyi("/Users/xjh/Desktop/Qt/Bradge_xjh/txt/displacepoint.txt");
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
    num=k/3;

    fweiyi.close();
      int i,j;
      k=1;
    ui->tableWidget->setRowCount(num);
    int r=ui->tableWidget->rowCount();
    for(i=0;i<r;i++)
    {
        for(j=0;j<3;j++)
        {
        ui->tableWidget->setItem(i,j,new QTableWidgetItem(lineStr[k]));
        k++;
        }
    }
    for(int i = 0; i<r;i++)
    {

        // 设置单元格不可编辑
        ui->tableWidget->item(i, 2)->setFlags(ui->tableWidget->item(i,2)->flags() & (~Qt::ItemIsEditable));
        // 设置单元格不可选择
         ui->tableWidget->item(i, 2)->setFlags(ui->tableWidget->item(i,2)->flags() & (~Qt::ItemIsSelectable));
    }
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

displacepoint::~displacepoint()
{
    delete ui;
}

void displacepoint::on_returnpushButton_clicked()
{
    Exam *a=new Exam;
    a->show();
    emit close();
}

void displacepoint::on_delepushButton_clicked()
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

void displacepoint::on_savepushButton_clicked()
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
                    tr("/Users/xjh/Desktop/Qt/Bradge_xjh/txt/displacepoint.txt"),
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
            for(int j=0;j<3;j++)
            {
                QString strCurAll = ui->tableWidget->item(i,j)->text();
                tsOut<<strCurAll<<endl;
            }
            }
        ui->tableWidget->setRowCount(r);
            //提示保存完毕
            QMessageBox::information(this, tr("保存文件"), tr("保存信息文件成功。"));
}

void displacepoint::on_addpointpushButton_clicked()
{
    QString str[3];
    str[0] = ui->pointnamelineEdit->text().trimmed();
      str[1] = ui->pointnumlineEdit->text().trimmed();
      str[2]="否";
        //判断是否为空
        if( str[0].isEmpty() || str[1].isEmpty())
        {
            QMessageBox::warning(this, tr("添加行"), tr("请先填好几项数据再添加！"));
            return ;
        }
        int r=ui->tableWidget->rowCount();
        qDebug()<<"r1"<<r;
        ui->tableWidget->insertRow(r);
       int r2=ui->tableWidget->rowCount();
        ui->tableWidget->setRowCount(r2);
           qDebug()<<"r2"<<r2;
        int i;
       for(i=0;i<3;i++)
       {
        ui->tableWidget->setItem(r,i,new QTableWidgetItem(str[i]));
       }
}

void displacepoint::on_setsensorpushButton_clicked()
{
    this->close();
    adddisplacesensor *a=new adddisplacesensor;
    a->show();
    emit close();

}

void displacepoint::on_pointlinepushButton_clicked()
{
    globaldata2= ui->pointnumlineEdit->text();
    this->close();
    displacepointline *a=new displacepointline;
    a->show();
    emit close();
}
