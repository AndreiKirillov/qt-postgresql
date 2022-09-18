#include <iostream>

#include <QString>
#include <string>
#include <QCoreApplication>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlRecord>

#include "DbReader.h"
#include "DbDataParser.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if(DbReader::connectToDb())
    {
        cout << "Подключение к базе удалось!" << endl;

        // читаем базу
        auto data_from_db = DbReader::readFromTable("tech_object_data");

        // создаем обработчик данных
        DbDataParser parser(data_from_db);
        // обрабатываем данные
        parser.processData();
        // печатаем в консоль
        parser.printParsedData();

        // выводим в xml формат
        parser.convertToXml();
    }
    else
    {
        cout << "Не удалось подключиться!";
    }
    return a.exec();
}
