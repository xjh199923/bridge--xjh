#ifndef DEFLECTSENSOR_H
#define DEFLECTSENSOR_H

#include <QWidget>

namespace Ui {
class DeflectSensor;
}

class DeflectSensor : public QWidget
{
    Q_OBJECT

public:
    explicit DeflectSensor(QWidget *parent = nullptr);
    ~DeflectSensor();
private slots:
    //void mainface();

    void on_quitpushButton_clicked();

    void on_addinfopushButton_clicked();

    void on_deleinfopushButton_clicked();

    void on_savepushButton_clicked();

private:
    Ui::DeflectSensor *ui;
};

#endif // DEFLECTSENSOR_H
