#ifndef POINTLINE_H
#define POINTLINE_H

#include <QWidget>
#include "qcustomplot.h"

namespace Ui {
class Pointline;
}

class Pointline : public QWidget
{
    Q_OBJECT

public:
    explicit Pointline(QWidget *parent = nullptr);
    ~Pointline();

    void initCustomPlot();
    void dealDrawLine();
    void dealDrawBarChart();

private slots:

    void on_linepushButton_clicked();

    void on_barpushButton_clicked();

    void on_pushButton_clicked();

    void receive_data(const QString &data);


private:
    Ui::Pointline *ui;
};

#endif // POINTLINE_H
