#ifndef DISPLACESENSOR_H
#define DISPLACESENSOR_H

#include <QWidget>

namespace Ui {
class displacesensor;
}

class displacesensor : public QWidget
{
    Q_OBJECT

public:
    explicit displacesensor(QWidget *parent = nullptr);
    ~displacesensor();

private slots:
    void on_addpushButton_clicked();

    void on_delepushButton_clicked();

    void on_savepushButton_clicked();

    void on_returnpushButton_clicked();

private:
    Ui::displacesensor *ui;
};

#endif // DISPLACESENSOR_H
