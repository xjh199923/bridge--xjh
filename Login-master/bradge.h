#ifndef BRADGE_H
#define BRADGE_H

#include <QWidget>
#include<QButtonGroup>

namespace Ui {
class bradge;
}

class bradge : public QWidget
{
    Q_OBJECT

public:
    explicit bradge(QWidget *parent = nullptr);
    ~bradge();

private slots:


    void on_resultpushButton_clicked();

    void on_strainradioButton_clicked(bool checked);

    void on_deflectradioButton_clicked(bool checked);

    void on_displaceradioButton_clicked(bool checked);

private:
    Ui::bradge *ui;
    QButtonGroup *sortButtonGroup;
};

#endif // BRADGE_H
