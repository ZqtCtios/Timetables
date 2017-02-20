#ifndef DATABASE_H
#define DATABASE_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <classmsg.h>
#include <QTime>
#include <QDebug>
class DataBase
{
public:
    bool connect(const QString &dbName);
    bool updateById(QClassMsg msg,int id);
    bool select();
    QString create_sql = "create table class "
                         "(id int primary key,classname varchar,teacher varchar,"
                         "classRoom varchar,weekNum int,time int,fromWeek int,"
                         "toWeek int,choice int)";
    QString update_sql = "update class set classname=?,teacher=?,"
                         "classRoom=?, weekNum=?,"
                         "time=?, fromWeek=?,"
                         "toWeek=?, choice=?"
                         "where id=?";
};

#endif // DATABASE_H
