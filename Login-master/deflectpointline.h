#ifndef DEFLECTPOINTLINE_H
#define DEFLECTPOINTLINE_H

#include <QWidget>
#include "qcustomplot.h"

namespace Ui {
class deflectpointline;
}

class deflectpointline : public QWidget
{
    Q_OBJECT

public:
    explicit deflectpointline(QWidget *parent = nullptr);
    ~deflectpointline();

    void initCustomPlot();
    void dealDrawLine();
    void dealDrawBarChart();

private slots:
    void on_linepushButton_clicked();

    void on_barpushButton_clicked();

     void receive_data(const QString &data);

     void on_returnpushButton_clicked();

private:
    Ui::deflectpointline *ui;
};

#endif // DEFLECTPOINTLINE_H
