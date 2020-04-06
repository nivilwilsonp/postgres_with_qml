#include "ndbserver.h"

QSqlDatabase NdbServer::connectDB(){
    this->db.setPort(5432);
    this->db.setHostName("127.0.0.1");
    this->db.setUserName("postgres");
    this->db.setPassword("123456");
    this->db.setDatabaseName("cute");
    if(this->db.open()){
qDebug()<<"connection was successful!";
return this->db;
    }
    else{
       qDebug() << this->db.lastError();
    }
    return db={};
}
