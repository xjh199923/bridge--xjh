#include "exam.h"
#include "ui_exam.h"
#include"strainsensor.h"
#include"deflectsensor.h"
#include "displacesensor.h"
#include"strainpoint.h"
#include"deflectpoint.h"
#include"displacepoint.h"
#include "bradge.h"
#include"login.h"

Exam::Exam(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Exam)
{
    ui->setupUi(this);

    init();
}

Exam::~Exam()
{
    delete ui;
}

void Exam::init()
{
    setWindowTitle(tr("桥梁监测系统"));
}

void Exam::on_strainSensorpushButton_clicked()
{
    this->hide();
    StrainSensor *a=new StrainSensor;
    a->show();
    emit close();
}


void Exam::on_displacepushButton_clicked()
{
    this->close();
    displacesensor *a=new displacesensor;
    a->show();
    emit close();
}

void Exam::on_strainpointpushButton_clicked()
{
    this->close();
    strainpoint *a =new strainpoint;
    a->show();
    emit close();
}

void Exam::on_displacepointpushButton_clicked()
{
    this->close();
    displacepoint *a=new displacepoint;
    a->show();
    emit close();
}

void Exam::on_deflectpointpushButton_clicked()
{
    this->close();
    deflectpoint *a=new deflectpoint;
    a->show();
    emit close();
}

void Exam::on_deflectsensorpushButton_clicked()
{
    this->close();
    DeflectSensor *a=new DeflectSensor;
    a->show();
    emit close();
}

void Exam::on_bradgepushButton_clicked()
{
    this->close();
    bradge *a=new bradge;
    a->show();
    emit close();

}

void Exam::on_returnpushButton_clicked()
{
    this->close();
    Login *w=new Login;
    w->show();
    emit close();
}
