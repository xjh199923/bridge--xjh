#include "displacepointline.h"
#include "ui_displacepointline.h"
#include"displacepoint.h"
#include <QVector>

extern QString globaldata2; //声明外部变量

displacepointline::displacepointline(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::displacepointline)
{
    ui->setupUi(this);

    //ui->lineEdit->setText(globaldata2);

    initCustomPlot1();
    dealDrawLine1();
}

displacepointline::~displacepointline()
{
    delete ui;
}
void displacepointline::initCustomPlot1()
{
    ui->widget->resize(this->width(),this->height());
    ui->widget->xAxis->setVisible(true);
    ui->widget->yAxis->setVisible(true);
    /// 设置顶边线和右边线显示但不显示刻度值
    ui->widget->xAxis2->setVisible(true);
    ui->widget->xAxis2->setTickLabels(true);
    ui->widget->yAxis2->setVisible(true);
    ui->widget->yAxis2->setTickLabels(true);
    ui->widget->xAxis2->setTicks(false);
    ui->widget->yAxis2->setTicks(false);
    /// 设置顶边线和右边线随x、y变化而变化
   connect(ui->widget->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->widget->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget->yAxis2, SLOT(setRange(QCPRange)));

    /// 设置拖拽、放大缩小功能
   ui->widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
}
void displacepointline::receive_data2(const QString &data)
{
    ui->pointnumlineEdit->setText(data);
}
void displacepointline::dealDrawLine1()
{

       int plottableCount = ui->widget->plottableCount();
        if (plottableCount != 0)
             ui->widget->clearPlottables();

        ui->widget->xAxis->setRange(0, 9);
        ui->widget->yAxis->setRange(0, 9);
        ui->widget->setBackground(QBrush(QColor(Qt::gray)));

        QPen drawPen;
        drawPen.setColor(Qt::blue);
        drawPen.setWidth(1);

        QFile file("/Users/xjh/Desktop/Qt/Bradge_xjh/txt/位移监测数据.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
        QTextStream in(&file);
        QString line[84]; //读取第0行文档
        for(int i=0;i<84;i++)
        {
            line[i]=in.readLine();
        }
        qDebug()<<line[1]<<endl;
         QString line1[84];
         QString line3[10];
         double a[6];
         /*switch(ui->lineEdit->text().toInt())
         {
         case 800827:*/
             for(int i=0;i<10;i++)
             {
                 line3[i]=line[i*2].mid(0,16).append("#");
                 line1[i]=line[i*2].mid(24,5);
             }
        /*case 800825:
             for(int i=0;i<10;i++)
             {
                 line3[i]=line[i*2+1].mid(0,16).append("#");
                 line1[i]=line[i*2+1].mid(24,5);
             }

         }*/
         for(int i=0;i<5;i++)
         {
         a[i] =line1[i].toDouble();
          qDebug()<<fixed<<qSetRealNumberPrecision(5)<<a[i]<<endl;
         }
          QString list1;
          for(int i=0;i<5;i++)
          {
              list1=list1.append(line3[i]);
          }
          qDebug()<<list1<<endl;
        QStringList list = list1.split("#");//假设数据
        QVector<double> time(5), value(5);
            for(int i = 0; i < 5; i++)
            {
                time[i] = QDateTime::fromString(list[i],"yyyy/MM/dd hh:mm").toTime_t();
                value[i] = a[i] ;
            }//生成模拟数据

        QCPGraph * curGraph = ui->widget->addGraph();
        curGraph->setPen(drawPen);
        curGraph->setLineStyle(QCPGraph::lsLine);
        curGraph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
        curGraph->setData(time, value);
        ui->widget->rescaleAxes();
        QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);//日期做X轴
        dateTicker->setDateTimeFormat("yyyy-MM-dd\nhh:mm");
        ui->widget->xAxis->setTicker(dateTicker);//设置X轴为时间轴
}

void displacepointline::on_linepushButton_clicked()
{
    dealDrawLine1();
}

void displacepointline::on_returnpushButton_clicked()
{
    this->close();
    displacepoint *a=new displacepoint;
    a->show();
    emit close();

}
