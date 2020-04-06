#ifndef ROLESSQLMODEL_H
#define ROLESSQLMODEL_H
#include <QSqlQueryModel>
#include "ndbserver.h"


class RolesSqlModel : public QSqlQueryModel
{
    Q_OBJECT
QHash<int, QByteArray> _roleNames;
NdbServer srv;
QSqlDatabase db;
public:
    explicit RolesSqlModel(QObject *parent = nullptr);
QHash<int, QByteArray> roleNames()const{
    return this->_roleNames;
};

   QSqlDatabase getDB(){
       auto value=srv.connectDB();
       if(value.open()){
           qDebug()<<"connected to db";
       }
       return value; };
   void setQuery(const QString &query, const QSqlDatabase &db = QSqlDatabase());
    void refresh();
     QVariant data(const QModelIndex &index, int role) const;
void generateRoleNames();
 signals:

 public slots:

 private:
     const static char* COLUMN_NAMES[];
     const static char* SQL_SELECT;
};

#endif // ROLESSQLMODEL_H
