#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QLayout>
#include <QSystemTrayIcon>
#include <QDebug>
#include <QMenu>
#include <QAction>
#include <QMouseEvent>
#include <button.h>
#include <QGridLayout>
#include <classmsg.h>
#include <addclass.h>
#include <database.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QSystemTrayIcon *systemTray;                /*系统托盘*/
    QAction *restoreAction;
    QAction *quitAction;
    QMenu   *trayIconMenu;
    QGridLayout *gridLayout;
    Button* buttons[5][5];
    QClassMsg msg;
    QPoint last;
    QString select_all_sql = "select * from class";
    /*主界面鼠标拖动*/
    void mousePressEvent (QMouseEvent *e);
    void mouseMoveEvent (QMouseEvent *e);
    void mouseReleaseEvent (QMouseEvent *e);

    bool loadDataBase();

private slots:
    void on_closeButton_clicked();

    void on_aboutButton_clicked();

    void showNormal();                          /*系统托盘打开主界面*/

    void quit();                                /*系统托盘关闭主界面*/

    void trayiconActivated(QSystemTrayIcon::ActivationReason reason);

    void on_addButton_clicked();

    void getMsg(QClassMsg msg);

private:
    Ui::MainWindow *ui;

signals:
    void openAbout();
    void openAddClassWighet();

};

#endif // MAINWINDOW_H
