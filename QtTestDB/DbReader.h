#ifndef DBREADER_H
#define DBREADER_H

#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <memory>

class DbReader
{
private:
    static QSqlDatabase _db;
public:
    DbReader();

    static bool connectToDb();
    static std::shared_ptr<QSqlQueryModel> readFromTable(QString table_name);
};

#endif // DBREADER_H
