#include "rolessqlmodel.h"


const char* RolesSqlModel::SQL_SELECT =
    "SELECT * FROM roles";


RolesSqlModel::RolesSqlModel(QObject *parent):QSqlQueryModel(parent)
{
    refresh();
}

QVariant RolesSqlModel::data(const QModelIndex &index, int role) const
{ QVariant value;
    if(role < Qt::UserRole) {
            value = QSqlQueryModel::data(index, role);
        }
        else {
            int columnIdx = role - Qt::UserRole - 1;
            QModelIndex modelIndex = this->index(index.row(), columnIdx);
            value = QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
        }
    return value;
}

void RolesSqlModel::refresh()
{
    this->setQuery(SQL_SELECT,this->getDB());
}
void RolesSqlModel::setQuery(const QString &query, const QSqlDatabase &db)
{
    if(db.isOpen()){



    QSqlQueryModel::setQuery(query, db);
    generateRoleNames();
   }
}


void RolesSqlModel::generateRoleNames()
{

    _roleNames.clear();
    for( int i = 0; i < record().count(); i ++) {
        _roleNames.insert(Qt::UserRole + i + 1, record().fieldName(i).toUtf8());
    }

}
