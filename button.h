#ifndef BUTTON_H
#define BUTTON_H
#include<QWidget>
#include<QPushButton>
#include<classmsg.h>
#include<QDebug>
class Button :public QPushButton
{
public:
    explicit Button(QWidget *parent=0);
    QClassMsg msg;
    void reflash();

};

#endif // BUTTON_H

