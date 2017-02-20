#include "database.h"
bool DataBase::connect(const QString &dbName)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbName);
    if (!db.open())
    {
        qDebug() << "Database Error!";
        return false;
    }

    QSqlQuery query;
    if (!query.exec(create_sql))
    {
        qDebug() << "Create Table Failed!";
    }
    query.prepare("insert into class values(?, ?, ?, ?, ?, ?, ?, ?, ?)");
        for(int i=1; i<26; i++)
        {
            query.bindValue(0, i);
            query.bindValue(1, "空");
            query.bindValue(2, "空");
            query.bindValue(3, "空");
            query.bindValue(4, 0);
            query.bindValue(5, 0);
            query.bindValue(6, 0);
            query.bindValue(7, 0);
            query.bindValue(8, 0);;

            bool success=query.exec();
            if(!success)
            {
                QSqlError lastError = query.lastError();
                qDebug() << lastError.driverText() << QString(QObject::tr("插入失败"));
                return false;
            }
        }
    return true;
}
bool DataBase::updateById(QClassMsg msg,int id)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("CLASSDATA.db");
    if (!db.open())
    {
        qDebug() << "Database Error!";
        return false;
    }
    QSqlQuery query;
    query.prepare(update_sql);
    query.bindValue(0,msg.className);
    query.bindValue(1,msg.teacher);
    query.bindValue(2,msg.classRoom);
    query.bindValue(3,msg.weekNum);
    query.bindValue(4,msg.time);
    query.bindValue(5,msg.fromWeek);
    query.bindValue(6,msg.toWeek);
    query.bindValue(7,msg.choice);
    query.bindValue(8,id);
    bool success=query.exec();
    if(!success)
    {
         QSqlError lastError = query.lastError();
         qDebug() << lastError.driverText() << QString(QObject::tr("更新失败"));
    }
    return true;
}
