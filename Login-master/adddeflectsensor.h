#ifndef ADDDEFLECTSENSOR_H
#define ADDDEFLECTSENSOR_H

#include <QMainWindow>

namespace Ui {
class adddeflectsensor;
}

class adddeflectsensor : public QMainWindow
{
    Q_OBJECT

public:
    explicit adddeflectsensor(QWidget *parent = nullptr);
    ~adddeflectsensor();

private slots:
    void on_setsavepushButton_clicked();

private:
    Ui::adddeflectsensor *ui;
};

#endif // ADDDEFLECTSENSOR_H
