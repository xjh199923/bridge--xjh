#ifndef STRAINPOINTLINE_H
#define STRAINPOINTLINE_H

#include <QMainWindow>
#include"qcustomplot.h"

namespace Ui {
class strainpointline;
}

class strainpointline : public QMainWindow
{
    Q_OBJECT

public:
    explicit strainpointline(QWidget *parent = nullptr);
    ~strainpointline();

    void initCustomPlot();
    void dealDrawLine();
    void dealDrawBarChart();



private slots:
    void on_returnpushButton_clicked();

    void on_pushButton_clicked();






private:
    Ui::strainpointline *ui;
};

#endif // STRAINPOINTLINE_H
