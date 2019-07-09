#ifndef ADDSTRAINSENSOR_H
#define ADDSTRAINSENSOR_H

#include <QMainWindow>

namespace Ui {
class addstrainsensor;
}

class addstrainsensor : public QMainWindow
{
    Q_OBJECT

public:
    explicit addstrainsensor(QWidget *parent = nullptr);
    ~addstrainsensor();

private slots:
    void on_pushButton_clicked();

private:
    Ui::addstrainsensor *ui;
};

#endif // ADDSTRAINSENSOR_H
