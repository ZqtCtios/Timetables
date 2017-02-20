#ifndef ABOUT_H
#define ABOUT_H

#include <QWidget>
#include <QMouseEvent>
#include <QPoint>
namespace Ui {
class About;
}

class About : public QWidget
{
    Q_OBJECT

public:
    explicit About(QWidget *parent = 0);
    ~About();

    QPoint last;                                /*主界面鼠标拖动*/
    void mousePressEvent (QMouseEvent *e);
    void mouseMoveEvent (QMouseEvent *e);
    void mouseReleaseEvent (QMouseEvent *e);

private slots:
    void on_close_clicked();
    void openAbout();

private:
    Ui::About *ui;


};

#endif // ABOUT_H
