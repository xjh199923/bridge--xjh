#include "pointline.h"
#include "ui_pointline.h"

#include"strainpoint.h"
#include <QVector>

extern QString globaldata; //声明外部变量
Pointline::Pointline(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Pointline)
{
    ui->setupUi(this);

    ui->lineEdit->setText(globaldata);
    initCustomPlot();
    dealDrawLine();
}

Pointline::~Pointline()
{
    delete ui;
}


void Pointline::initCustomPlot()
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

void Pointline::dealDrawLine()
{

   int plottableCount = ui->widget->plottableCount();
    if (plottableCount != 0)
         ui->widget->clearPlottables();

    ui->widget->xAxis->setRange(0, 40);
    ui->widget->yAxis->setRange(1514.00, 1550);
    ui->widget->setBackground(QBrush(QColor(Qt::gray)));
    ui->widget->legend->setVisible(true);
    ui->widget->xAxis->setTickLabelRotation(30);
    QPen drawPen;
    drawPen.setColor(Qt::blue);
    drawPen.setWidth(1);

    QFile file("/Users/xjh/Desktop/Qt/Bradge_xjh/txt/cc.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    return;
    QTextStream in(&file);
    QString line[38]; //读取第0行文档
    for(int i=0;i<38;i++)
    {
        line[i]=in.readLine();
    }
     QString line1[38];
     QString line3[38];
     double a[38];
     switch (ui->lineEdit->text().toInt())
     {
         case 1:for(int i=0;i<38;i++)
         {
             line3[i]=line[i].mid(0,19).append("#");
             line1[i]=line[i].mid(20,10);
         }break;
     case 2:for(int i=0;i<38;i++)
         {
             line3[i]=line[i].mid(0,19).append("#");
             line1[i]=line[i].mid(31,10);
         }break;
     case 3:for(int i=0;i<38;i++)
         {
             line3[i]=line[i].mid(0,19).append("#");
             line1[i]=line[i].mid(42,10);
         }break;
     case 4:for(int i=0;i<38;i++)
         {
             line3[i]=line[i].mid(0,19).append("#");
             line1[i]=line[i].mid(53,10);
         }break;
         case 5:for(int i=0;i<38;i++)
             {
                 line3[i]=line[i].mid(0,19).append("#");
                 line1[i]=line[i].mid(64,10);
             }break;
         case 6:for(int i=0;i<38;i++)
             {
                 line3[i]=line[i].mid(0,19).append("#");
                 line1[i]=line[i].mid(75,10);
             }break;
         case 7:for(int i=0;i<38;i++)
             {
                 line3[i]=line[i].mid(0,19).append("#");
                 line1[i]=line[i].mid(86,10);
             }break;
         case 8:for(int i=0;i<38;i++)
             {
                 line3[i]=line[i].mid(0,19).append("#");
                 line1[i]=line[i].mid(97,10);
             }break;
         case 9:for(int i=0;i<38;i++)
             {
                 line3[i]=line[i].mid(0,19).append("#");
                 line1[i]=line[i].mid(108,10);
             }break;
         case 10:for(int i=0;i<38;i++)
             {
                 line3[i]=line[i].mid(0,19).append("#");
                 line1[i]=line[i].mid(119,10);
             }break;


     }

     for(int i=0;i<38;i++)
     {
     a[i] =line1[i].toDouble();
      qDebug()<<fixed<<qSetRealNumberPrecision(5)<<a[i]<<endl;
     }
      QString list1;
      for(int i=0;i<38;i++)
      {
          list1=list1.append(line3[i]);
      }
      qDebug()<<list1<<endl;
    QStringList list = list1.split("#");//假设数据
    QVector<double> time(38), value(38);
        for(int i = 0; i < time.count(); i++)
        {
            time[i] = QDateTime::fromString(list[i],"yyyy/MM/dd hh:mm:ss").toTime_t();
            //time[i] = QDateTime::currentSecsSinceEpoch() + i;//以此刻的时间做X轴（总秒数），一秒一个值
            value[i] = a[i] ;
        }//生成模拟数据

    QCPGraph * curGraph = ui->widget->addGraph();
    curGraph->setPen(drawPen);
    curGraph->setLineStyle(QCPGraph::lsLine);
    curGraph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
    curGraph->setData(time, value);
    ui->widget->rescaleAxes();
    QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);//日期做X轴
    dateTicker->setDateTimeFormat("yyyy-MM-dd\nhh:mm:ss");//日期格式(可参考QDateTime::fromString()函数)
    ui->widget->xAxis->setTicker(dateTicker);//设置X轴为时间轴
}

void Pointline::dealDrawBarChart()
{
    int plottableCount = ui->widget->plottableCount();
    if (plottableCount != 0)
         ui->widget->clearPlottables();

   ui->widget->xAxis->setRange(0,40 );

   QLinearGradient gradient(0, 0, 0, 400);
   gradient.setColorAt(0, QColor(90, 90, 90));
   gradient.setColorAt(0.38, QColor(100, 100, 100));
   gradient.setColorAt(1, QColor(70, 70, 70));
   ui->widget->setBackground(QBrush(gradient));


   ui->widget->replot();
    QFile file("/Users/xjh/Desktop/Qt/Bradge_xjh/txt/cc.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    return;
    QTextStream in(&file);
    QString line[38]; //读取第0行文档
    for(int i=0;i<38;i++)
    {
        line[i]=in.readLine();
    }
     QString line1[38];
     QString line3[38];
     double a[38];
     switch (ui->lineEdit->text().toInt())
     {
         case 1:for(int i=0;i<38;i++)
         {
             line3[i]=line[i].mid(0,19).append("#");
             line1[i]=line[i].mid(20,10);
         }break;
     case 2:for(int i=0;i<38;i++)
         {
             line3[i]=line[i].mid(0,19).append("#");
             line1[i]=line[i].mid(31,10);
         }break;
     case 3:for(int i=0;i<38;i++)
         {
             line3[i]=line[i].mid(0,19).append("#");
             line1[i]=line[i].mid(42,10);
         }break;
     case 4:for(int i=0;i<38;i++)
         {
             line3[i]=line[i].mid(0,19).append("#");
             line1[i]=line[i].mid(53,10);
         }break;
         case 5:for(int i=0;i<38;i++)
             {
                 line3[i]=line[i].mid(0,19).append("#");
                 line1[i]=line[i].mid(64,10);
             }break;
         case 6:for(int i=0;i<38;i++)
             {
                 line3[i]=line[i].mid(0,19).append("#");
                 line1[i]=line[i].mid(75,10);
             }break;
         case 7:for(int i=0;i<38;i++)
             {
                 line3[i]=line[i].mid(0,19).append("#");
                 line1[i]=line[i].mid(86,10);
             }break;
         case 8:for(int i=0;i<38;i++)
             {
                 line3[i]=line[i].mid(0,19).append("#");
                 line1[i]=line[i].mid(97,10);
             }break;
         case 9:for(int i=0;i<38;i++)
             {
                 line3[i]=line[i].mid(0,19).append("#");
                 line1[i]=line[i].mid(108,10);
             }break;
         case 10:for(int i=0;i<38;i++)
             {
                 line3[i]=line[i].mid(0,19).append("#");
                 line1[i]=line[i].mid(119,10);
             }break;
}

     for(int i=0;i<38;i++)
     {
     a[i] =line1[i].toDouble();
      qDebug()<<fixed<<qSetRealNumberPrecision(5)<<a[i]<<endl;
     }
      QString list1;
      for(int i=0;i<38;i++)
      {
          list1=list1.append(line3[i]);
      }
      qDebug()<<list1<<endl;
    QStringList list = list1.split("#");//假设数据
    QVector<double> time(38), value(38);
        for(int i = 0; i < time.count(); i++)
        {
            time[i] = QDateTime::fromString(list[i],"yyyy/MM/dd hh:mm:ss").toTime_t();
            value[i] = a[i] ;
        }//生成模拟数据
        QVector<double> ab,ss;
        ab<<time[0]<<time[1]<<time[2]<<time[3]<<time[5]<<time[4];
        ss<<1519.22<<1519.69<<1519.64<<1519.98<<1520.22<<1519.77;
        QCPBars *rectBar = new QCPBars(ui->widget->xAxis, ui->widget->yAxis);
        rectBar->setAntialiased(false);
        rectBar->setStackingGap(1);
        rectBar->setPen(QPen(QColor(0, 168, 140).lighter(130)));
        rectBar->setBrush(QColor(0, 168, 140));
        rectBar->setData(time, value);
       ui->widget->rescaleAxes();
         ui->widget->yAxis->setRange(1519.00, 1550);
        ui->widget->replot();

    ui->widget->legend->setVisible(true);
    QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);//日期做X轴
    dateTicker->setDateTimeFormat("yyyy-MM-dd\nhh:mm:ss");//日期格式(可参考QDateTime::fromString()函数)
    ui->widget->xAxis->setTicker(dateTicker);//设置X轴为时间轴
}

void Pointline::on_linepushButton_clicked()
{
    dealDrawLine();
}

void Pointline::on_barpushButton_clicked()
{
    dealDrawBarChart();
}

void Pointline::on_pushButton_clicked()
{
    this->close();
    strainpoint *a =new strainpoint;
    a->show();
    emit close();
}
void Pointline::receive_data(const QString &data)
{
    ui->lineEdit->setText(data);
}
