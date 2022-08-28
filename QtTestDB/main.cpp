#include <iostream>

#include <QString>
#include <string>
#include <QCoreApplication>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QSqlRecord>

using namespace std;

void printMenu()
{
    cout << "1 - read only SqlQueryModel" << endl
         << "2 - read-write SqlTableModel" << endl
         << "3 - tables with relations" << endl
         << "input action" << endl;
}

void testSqlQueryModel()
{
    QSqlQueryModel model;
    model.setQuery("SELECT * FROM student");

    for (int i = 0; i < model.rowCount(); ++i)
    {
        cout << "id: "<< model.record(i).value("id").toInt()
        << " firstname:" << model.record(i).value("firstname").toString().toStdString()
        << " lastname:" << model.record(i).value("lastname").toString().toStdString()
        << " gpa:" << model.record(i).value("gpa").toFloat()
        << " group:" << model.record(i).value("group_id").toInt() << endl;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Подключаемся к базе
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("testdb");
    db.setUserName("myuser");
    db.setPassword("123");
    if(db.open())
    {
        cout << "Подключение к базе удалось!" << endl;

        printMenu();
        int selected_action;
        cin >> selected_action;

        switch(selected_action)
        {
        case 1:
        {
            testSqlQueryModel();
        }
        break;

        case 2:
        {

        }
        break;

        case 3:
        {

        }
        break;
        }

    }
    else
    {
        cout << "Не удалось подключиться!";
    }
    return a.exec();
}
