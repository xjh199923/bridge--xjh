#ifndef DISPLACEPOINTLINE_H
#define DISPLACEPOINTLINE_H

#include <QWidget>
#include "qcustomplot.h"

namespace Ui {
class displacepointline;
}

class displacepointline : public QWidget
{
    Q_OBJECT

public:
    explicit displacepointline(QWidget *parent = nullptr);
    ~displacepointline();

    void initCustomPlot1();
    void dealDrawLine1();


private slots:
     void receive_data2(const QString &data);


     void on_linepushButton_clicked();

     void on_returnpushButton_clicked();

private:
    Ui::displacepointline *ui;
};

#endif // DISPLACEPOINTLINE_H
