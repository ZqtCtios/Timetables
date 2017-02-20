#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    /*系统托盘*/
    systemTray=new QSystemTrayIcon(this);
    systemTray->setIcon(QIcon(":/image/image/windowIcon.png"));
    systemTray->setToolTip("开始美好的一天");
    systemTray->show();
    connect(systemTray,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
                this,SLOT(trayiconActivated(QSystemTrayIcon::ActivationReason)));
    restoreAction = new QAction(tr("还原 (&R)"), this);
    connect(restoreAction, SIGNAL(triggered()), this, SLOT(showNormal()));
    quitAction = new QAction(tr("退出 (&Q)"), this);
    connect(quitAction, SIGNAL(triggered()),qApp, SLOT(quit()));
    trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(restoreAction);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(quitAction);
    systemTray->setContextMenu(trayIconMenu);

    /*初始化课程界面*/
    for (int i=0;i<5;i++)
        for (int j=0;j<5;j++)
        {
            buttons[i][j]=new Button(this);
            ui->gridLayout->addWidget(buttons[i][j],i,j,1,1);
        }

    /*初始化数据库*/
    DataBase().connect("CLASSDATA.db");
    /*导入数据库*/
    loadDataBase();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::mousePressEvent (QMouseEvent *e)
{
    last = e->globalPos();
}
void MainWindow:: mouseMoveEvent (QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    last = e->globalPos();
    move(x()+dx,y()+dy);
}
void MainWindow:: mouseReleaseEvent (QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    move(x()+dx, y()+dy);
}
bool MainWindow::loadDataBase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("CLASSDATA.db");
    if (!db.open())
    {
        qDebug() << "Database Error!";
        return false;
    }
    QSqlQuery query;
    QClassMsg msg;
    int i=0;
    int x;
    int y;
    query.prepare(select_all_sql);
    if(!query.exec())
    {
    qDebug()<<query.lastError();
    }
    else
    {
    while(query.next())
    {
        msg.id=query.value(0).toInt();
        msg.className = query.value(1).toString();
        msg.teacher = query.value(2).toString();
        msg.classRoom = query.value(3).toString();
        msg.weekNum = query.value(4).toInt();
        msg.time = query.value(5).toInt();
        msg.fromWeek = query.value(7).toInt();
        msg.toWeek = query.value(7).toInt();
        msg.choice = query.value(8).toInt();
        x=i/5;
        y=i%5;
        buttons[x][y]->msg=msg;
        if (msg.weekNum>0)
            buttons[x][y]->reflash();
        i++;
    }
    }
    return true;
}

void MainWindow::on_closeButton_clicked()
{
    this->hide();
}

void MainWindow::on_aboutButton_clicked()
{
    emit openAbout();
}
 void MainWindow::showNormal()
 {
     this->show();
 }
void MainWindow::quit()
{
    this->close();
}
void MainWindow::trayiconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
    {
    //点击托盘显示窗口
    case QSystemTrayIcon::Trigger:
     {
       showNormal();
       break;
     }
    //双击托盘显示窗口
    case QSystemTrayIcon::DoubleClick:
    {
      showNormal();
      break;
    }
    default:
     break;
    }
}

void MainWindow::on_addButton_clicked()
{
    emit openAddClassWighet();
}

void MainWindow::getMsg(QClassMsg msg)
{
    this->msg=msg;
    int y=msg.weekNum-1;
    int x=msg.time-1;
    int id=x*5+y+1;
    msg.id=id;
    DataBase().updateById(msg,id);

    buttons[x][y]->msg=msg;
    buttons[x][y]->reflash();
}
