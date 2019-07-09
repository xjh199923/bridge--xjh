#ifndef ADDDISPLACESENSOR_H
#define ADDDISPLACESENSOR_H

#include <QMainWindow>

namespace Ui {
class adddisplacesensor;
}

class adddisplacesensor : public QMainWindow
{
    Q_OBJECT

public:
    explicit adddisplacesensor(QWidget *parent = nullptr);
    ~adddisplacesensor();

private slots:
    void on_setsavepushButton_clicked();

private:
    Ui::adddisplacesensor *ui;
};

#endif // ADDDISPLACESENSOR_H
