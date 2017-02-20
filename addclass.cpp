#include "addclass.h"
#include "ui_addclass.h"
#include <classmsg.h>
AddClass::AddClass(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddClass)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->msg->hide();
    for (int i=1;i<=5;i++)
    {
        QString s=QString::number(i);
        ui->weekNum->addItem(s);
    }
    for (int i=1;i<=9;i=i+2)
    {
        QString s=QString::number(i)+'-'+QString::number(i+1);
        ui->time->addItem(s);
    }
    for (int i=1;i<=25;i++)
    {
        QString s=QString::number(i);
        ui->fromWeek->addItem(s);
        ui->toWeek->addItem(s);
    }
    this->parent=parent;

}

AddClass::~AddClass()
{
    delete ui;
}
void AddClass::mousePressEvent (QMouseEvent *e)
{
    last = e->globalPos();
}
void AddClass:: mouseMoveEvent (QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    last = e->globalPos();
    move(x()+dx,y()+dy);
}
void AddClass:: mouseReleaseEvent (QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    move(x()+dx, y()+dy);
}

void AddClass::on_quit_clicked()
{
    this->close();
}


void AddClass::on_confirm_clicked()
{
    msg.className=ui->className->text();
    msg.teacher=ui->teacherName->text();
    msg.classRoom=ui->classRoom->text();
    msg.weekNum=ui->weekNum->currentIndex()+1;
    msg.time=ui->time->currentIndex()+1;
    msg.fromWeek=ui->fromWeek->currentIndex()+1;
    msg.toWeek=ui->toWeek->currentIndex()+1;
    if (ui->singleWeek->isChecked())
    {
        msg.choice=1;
    }else
        if (ui->doubleWeek->isChecked())
        {
            msg.choice=2;
        }else {
            msg.choice=3;
        }
    if (msg.className.length()==0||msg.teacher.length()==0||msg.classRoom.length()==0)
    {
        ui->msg->show();
        return;
    }
    this->close();
    emit back(msg);
}

void AddClass::open()
{
    ui->className->setText("");
    ui->teacherName->setText("");
    ui->classRoom->setText("");
    ui->weekNum->setCurrentIndex(0);
    ui->time->setCurrentIndex(0);
    ui->fromWeek->setCurrentIndex(0);
    ui->toWeek->setCurrentIndex(0);
    this->show();
}
