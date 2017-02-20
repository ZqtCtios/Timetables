#include<button.h>
Button::Button(QWidget *parent):
    QPushButton(parent)
{
    this->setStyleSheet("QPushButton{"
                        "border-image:url(:/image/image/white.png);"
                        "	font: 10pt \"幼圆\";"
                        "color:white;}"
                        "QPushButton:hover{"
                        "border-image:url(:/image/image/black.png);}");
    this->setMinimumSize(100,80);
}
void Button::reflash()
{
    this->setText(msg.className+"\n@"+msg.classRoom);
    QString color;
    int x=msg.id%4;
    switch (x) {
    case 0:
        color="green";
        break;
    case 1:
        color="blue";
        break;
    case 2:
        color="red";
        break;
    case 3:
        color="bgreen";
        break;
    }
    this->setStyleSheet("QPushButton{"
                        "border-image:url(:/image/image/"+color+".png);"
                        "	font: 10pt \"幼圆\";"
                        "color:white;}"
                        "QPushButton:hover{"
                        "border-image:url(:/image/image/black.png);}");
    this->setToolTip("课程名字："+msg.className
                     +"\n授课老师："+msg.teacher
                     +"\n教室："+msg.classRoom
                     +"\n授课周期："
                     +"\n从"+QString::number(msg.fromWeek)
                     +"周到"+QString::number(msg.toWeek)+"周");
}
