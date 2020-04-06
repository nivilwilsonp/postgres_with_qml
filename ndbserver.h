#ifndef NDBSERVER_H
#define NDBSERVER_H

#include<QtSql>
#include<QSqlDatabase>
#include<QDebug>

class NdbServer{
private:
    QSqlDatabase db;
public:
    NdbServer(){
        QSqlDatabase db=QSqlDatabase::addDatabase("QPSQL");
        this->db=db;
    }

    QSqlDatabase connectDB();

};


#endif // NDBSERVER_H
