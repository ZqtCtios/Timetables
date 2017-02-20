#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

About::~About()
{
    delete ui;
}

void About::on_close_clicked()
{
    this->close();
}
void About::openAbout()
{
    this->show();
}
void About::mousePressEvent (QMouseEvent *e)
{
    last = e->globalPos();
}
void About:: mouseMoveEvent (QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    last = e->globalPos();
    move(x()+dx,y()+dy);
}
void About:: mouseReleaseEvent (QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    move(x()+dx, y()+dy);
}
