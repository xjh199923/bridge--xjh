#include "deflectpointline.h"
#include "ui_deflectpointline.h"
#include"deflectpoint.h"
#include <QVector>


extern QString globaldata1; //声明外部变量

deflectpointline::deflectpointline(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::deflectpointline)
{
    ui->setupUi(this);

    ui->lineEdit->setText(globaldata1);
    initCustomPlot();
    dealDrawLine();
}

deflectpointline::~deflectpointline()
{
    delete ui;
}


void deflectpointline::initCustomPlot()
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

void deflectpointline::dealDrawLine()
{

   int plottableCount = ui->widget->plottableCount();
    if (plottableCount != 0)
         ui->widget->clearPlottables();

    ui->widget->xAxis->setRange(0, 40);
    ui->widget->yAxis->setRange(100, 150);
    ui->widget->setBackground(QBrush(QColor(Qt::gray)));
    ui->widget->legend->setVisible(true);
    ui->widget->xAxis->setTickLabelRotation(30);
    QPen drawPen;
    drawPen.setColor(Qt::blue);
    drawPen.setWidth(1);

    QFile file("/Users/xjh/Desktop/Qt/Bradge_xjh/txt/挠度监测数据.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    return;
    QTextStream in(&file);
    QString line[84]; //读取第0行文档
    for(int i=0;i<84;i++)
    {
        line[i]=in.readLine();
    }
     QString line1[84];
     QString line3[6];
     double a[6];
     switch (ui->lineEdit->text().toInt())
     {
     case 700737:
         for(int i=0;i<6;i++)
         {
             line3[i]=line[i*14].mid(0,16).append("#");
             line1[i]=line[i*14].mid(24,6);
             line1[0]="100.71";
         }break;
     case 700738:
         for(int i=0;i<6;i++)
         {
             line3[i]=line[i*14+1].mid(0,16).append("#");
             line1[i]=line[i*14+1].mid(24,6);
         }break;
     case 700742:
         for(int i=0;i<6;i++)
         {
             line3[i]=line[i*14+2].mid(0,16).append("#");
             line1[i]=line[i*14+2].mid(24,6);
         }break;
     case 700744:
         for(int i=0;i<6;i++)
         {
             line3[i]=line[i*14+3].mid(0,16).append("#");
             line1[i]=line[i*14+3].mid(24,6);
         }break;
     case 700753:
         for(int i=0;i<6;i++)
         {
             line3[i]=line[i*14+4].mid(0,16).append("#");
             line1[i]=line[i*14+4].mid(24,6);
         }break;
     case 700758:
         for(int i=0;i<6;i++)
         {
             line3[i]=line[i*14+5].mid(0,16).append("#");
             line1[i]=line[i*14+5].mid(24,6);
         }break;
     case 700763:
         for(int i=0;i<6;i++)
         {
             line3[i]=line[i*14+6].mid(0,16).append("#");
             line1[i]=line[i*14+6].mid(24,6);
         }break;
     case 700764:
         for(int i=0;i<6;i++)
         {
             line3[i]=line[i*14+7].mid(0,16).append("#");
             line1[i]=line[i*14+7].mid(24,6);
         }break;
     case 700765:
         for(int i=0;i<6;i++)
         {
             line3[i]=line[i*14+8].mid(0,16).append("#");
             line1[i]=line[i*14+8].mid(24,6);
         }break;
     case 700767:
         for(int i=0;i<6;i++)
         {
             line3[i]=line[i*14+9].mid(0,16).append("#");
             line1[i]=line[i*14+9].mid(24,6);
         }break;
     case 700771:
         for(int i=0;i<6;i++)
         {
             line3[i]=line[i*14+10].mid(0,16).append("#");
             line1[i]=line[i*14+10].mid(24,6);
         }break;
     case 700773:
         for(int i=0;i<6;i++)
         {
             line3[i]=line[i*14+11].mid(0,16).append("#");
             line1[i]=line[i*14+11].mid(24,6);
         }break;
     case 700774:
         for(int i=0;i<6;i++)
         {
             line3[i]=line[i*14+12].mid(0,16).append("#");
             line1[i]=line[i*14+12].mid(24,6);
         }break;
     case 700775:
         for(int i=0;i<6;i++)
         {
             line3[i]=line[i*14+13].mid(0,16).append("#");
             line1[i]=line[i*14+13].mid(24,6);
         }break;

     }
     for(int i=0;i<6;i++)
     {
     a[i] =line1[i].toDouble();
      qDebug()<<fixed<<qSetRealNumberPrecision(5)<<a[i]<<endl;
     }
      QString list1;
      for(int i=0;i<6;i++)
      {
          list1=list1.append(line3[i]);
      }
      qDebug()<<list1<<endl;
    QStringList list = list1.split("#");//假设数据
    QVector<double> time(6), value(6);
        for(int i = 0; i < 6; i++)
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

void deflectpointline::dealDrawBarChart()
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
   QFile file("/Users/xjh/Desktop/Qt/Bradge_xjh/txt/挠度监测数据.txt");
   if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
   return;
   QTextStream in(&file);
   QString line[84]; //读取第0行文档
   for(int i=0;i<84;i++)
   {
       line[i]=in.readLine();
   }
    QString line1[84];
    QString line3[6];
    double a[6];
    switch (ui->lineEdit->text().toInt())
    {
    case 700737:
        for(int i=0;i<6;i++)
        {
            line3[i]=line[i*14].mid(0,16).append("#");
            line1[i]=line[i*14].mid(24,6);
            line1[0]="100.71";
        }break;
    case 700738:
        for(int i=0;i<6;i++)
        {
            line3[i]=line[i*14+1].mid(0,16).append("#");
            line1[i]=line[i*14+1].mid(24,6);
        }break;
    case 700742:
        for(int i=0;i<6;i++)
        {
            line3[i]=line[i*14+2].mid(0,16).append("#");
            line1[i]=line[i*14+2].mid(24,6);
        }break;
    case 700744:
        for(int i=0;i<6;i++)
        {
            line3[i]=line[i*14+3].mid(0,16).append("#");
            line1[i]=line[i*14+3].mid(24,6);
        }break;
    case 700753:
        for(int i=0;i<6;i++)
        {
            line3[i]=line[i*14+4].mid(0,16).append("#");
            line1[i]=line[i*14+4].mid(24,6);
        }break;
    case 700758:
        for(int i=0;i<6;i++)
        {
            line3[i]=line[i*14+5].mid(0,16).append("#");
            line1[i]=line[i*14+5].mid(24,6);
        }break;
    case 700763:
        for(int i=0;i<6;i++)
        {
            line3[i]=line[i*14+6].mid(0,16).append("#");
            line1[i]=line[i*14+6].mid(24,6);
        }break;
    case 700764:
        for(int i=0;i<6;i++)
        {
            line3[i]=line[i*14+7].mid(0,16).append("#");
            line1[i]=line[i*14+7].mid(24,6);
        }break;
    case 700765:
        for(int i=0;i<6;i++)
        {
            line3[i]=line[i*14+8].mid(0,16).append("#");
            line1[i]=line[i*14+8].mid(24,6);
        }break;
    case 700767:
        for(int i=0;i<6;i++)
        {
            line3[i]=line[i*14+9].mid(0,16).append("#");
            line1[i]=line[i*14+9].mid(24,6);
        }break;
    case 700771:
        for(int i=0;i<6;i++)
        {
            line3[i]=line[i*14+10].mid(0,16).append("#");
            line1[i]=line[i*14+10].mid(24,6);
        }break;
    case 700773:
        for(int i=0;i<6;i++)
        {
            line3[i]=line[i*14+11].mid(0,16).append("#");
            line1[i]=line[i*14+11].mid(24,6);
        }break;
    case 700774:
        for(int i=0;i<6;i++)
        {
            line3[i]=line[i*14+12].mid(0,16).append("#");
            line1[i]=line[i*14+12].mid(24,6);
        }break;
    case 700775:
        for(int i=0;i<6;i++)
        {
            line3[i]=line[i*14+13].mid(0,16).append("#");
            line1[i]=line[i*14+13].mid(24,6);
        }break;

    }
    for(int i=0;i<6;i++)
    {
    a[i] =line1[i].toDouble();
     qDebug()<<fixed<<qSetRealNumberPrecision(5)<<a[i]<<endl;
    }
     QString list1;
     for(int i=0;i<6;i++)
     {
         list1=list1.append(line3[i]);
     }
     qDebug()<<list1<<endl;
   QStringList list = list1.split("#");//假设数据
   QVector<double> time(6), value(6);
       for(int i = 0; i < 6; i++)
       {
           time[i] = QDateTime::fromString(list[i],"yyyy/MM/dd hh:mm").toTime_t();
           value[i] = a[i] ;
       }//生成模拟数据


        QCPBars *rectBar = new QCPBars(ui->widget->xAxis, ui->widget->yAxis);
        rectBar->setAntialiased(false);
        rectBar->setStackingGap(1);
        rectBar->setPen(QPen(QColor(0, 168, 140).lighter(130)));
        rectBar->setBrush(QColor(0, 168, 140));
        rectBar->setData(time, value);
       ui->widget->rescaleAxes();
        ui->widget->replot();

    ui->widget->legend->setVisible(true);
    QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);//日期做X轴
    dateTicker->setDateTimeFormat("yyyy-MM-dd\nhh:mm:ss");//日期格式(可参考QDateTime::fromString()函数)
    ui->widget->xAxis->setTicker(dateTicker);//设置X轴为时间轴
}

void deflectpointline::on_linepushButton_clicked()
{
    dealDrawLine();
}

void deflectpointline::on_barpushButton_clicked()
{
    dealDrawBarChart();
}
void deflectpointline::receive_data(const QString &data)
{
    ui->lineEdit->setText(data);
}

void deflectpointline::on_returnpushButton_clicked()
{
    this->close();
    deflectpoint* a =new deflectpoint;
    a->show();
    emit close();
}
