#ifndef ADDCLASS_H
#define ADDCLASS_H

#include <QWidget>
#include <QMouseEvent>
#include <QPoint>
#include <classmsg.h>
#include <QDebug>
namespace Ui {
class AddClass;
}

class AddClass : public QWidget
{
    Q_OBJECT

public:
    QWidget *parent;
    explicit AddClass(QWidget *parent=0);
    ~AddClass();
    QClassMsg msg;
    QPoint last;                                /*主界面鼠标拖动*/
    void mousePressEvent (QMouseEvent *e);
    void mouseMoveEvent (QMouseEvent *e);
    void mouseReleaseEvent (QMouseEvent *e);

private slots:
    void on_quit_clicked();
\

    void on_confirm_clicked();

    void open();

private:
    Ui::AddClass *ui;
signals:
    void back(QClassMsg msg);
};

#endif // ADDCLASS_H
