#ifndef DEFLECTPOINT_H
#define DEFLECTPOINT_H

#include <QMainWindow>

namespace Ui {
class deflectpoint;
}

class deflectpoint : public QMainWindow
{
    Q_OBJECT

public:
    explicit deflectpoint(QWidget *parent = nullptr);
    ~deflectpoint();

private slots:
    void on_returnpushButton_clicked();

    void on_delepushButton_clicked();

    void on_addpushButton_clicked();

    void on_savepushButton_clicked();

    void on_setsensorpushButton_clicked();

    void on_pushButton_clicked();

    void on_deflectlinepushButton_clicked();

private:
    Ui::deflectpoint *ui;
};

#endif // DEFLECTPOINT_H
