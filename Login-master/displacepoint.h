#ifndef DISPLACEPOINT_H
#define DISPLACEPOINT_H

#include <QMainWindow>

namespace Ui {
class displacepoint;
}

class displacepoint : public QMainWindow
{
    Q_OBJECT

public:
    explicit displacepoint(QWidget *parent = nullptr);
    ~displacepoint();

private slots:
    void on_returnpushButton_clicked();

    void on_delepushButton_clicked();

    void on_savepushButton_clicked();

    void on_addpointpushButton_clicked();

    void on_setsensorpushButton_clicked();

    void on_pointlinepushButton_clicked();

private:
    Ui::displacepoint *ui;
};

#endif // DISPLACEPOINT_H
