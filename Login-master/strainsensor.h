#ifndef STRAINSENSOR_H
#define STRAINSENSOR_H

#include <QWidget>

#include <QTableWidgetItem> //头文件槽函数使用到了

namespace Ui {
class StrainSensor;
}

class StrainSensor : public QWidget
{
    Q_OBJECT

public:
    explicit StrainSensor(QWidget *parent = nullptr);
    ~StrainSensor();

private slots:

    void on_tableWidget_currentItemChanged(QTableWidgetItem *current, QTableWidgetItem *previous);

    void on_pushButtonSave_clicked();

    void on_pushButtonDel_clicked();

    void on_pushButtonAdd_clicked();

    void on_returnpushButton_clicked();

private:
    Ui::StrainSensor *ui;
};

#endif // STRAINSENSOR_H
