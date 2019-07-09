#ifndef STRAINPOINT_H
#define STRAINPOINT_H

#include <QMainWindow>

namespace Ui {
class strainpoint;
}

class strainpoint : public QMainWindow
{
    Q_OBJECT

public:
    explicit strainpoint(QWidget *parent = nullptr);
    ~strainpoint();

private slots:
    void on_returnpushButton_clicked();

    void on_delepushButton_clicked();

    void on_savepushButton_clicked();

    void on_addpushButton_clicked();

    void on_setsensorpushButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::strainpoint *ui;
};

#endif // STRAINPOINT_H
