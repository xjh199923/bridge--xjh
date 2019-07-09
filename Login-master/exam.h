#ifndef EXAM_H
#define EXAM_H

#include <QMainWindow>

namespace Ui {
class Exam;
}

class Exam : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Exam(QWidget *parent = 0);
    ~Exam();

    void init();
    
private slots:
    void on_strainSensorpushButton_clicked();



    void on_displacepushButton_clicked();

    void on_strainpointpushButton_clicked();


    void on_displacepointpushButton_clicked();


    void on_deflectpointpushButton_clicked();



    void on_deflectsensorpushButton_clicked();

    void on_bradgepushButton_clicked();

    void on_returnpushButton_clicked();

private:
    Ui::Exam *ui;
};

#endif // EXAM_H
