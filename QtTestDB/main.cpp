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

void testSqlTableModel()
{
    QSqlTableModel model;
    model.setTable("student");
    model.select();

    cout << "1-change"<< endl << "2-new" << endl;
    int what_to_do;
    cin >> what_to_do;
    if(what_to_do == 1)
    {

    }
    else  // Вставка новой записи
    {
        int new_raw_index = model.rowCount();
        model.insertRows(new_raw_index,1);
        model.setData(model.index(new_raw_index,0),new_raw_index+1);

        cout << "firstname:";
        string firstname;
        cin >> firstname;
        QString qfirstname(firstname.c_str());
        model.setData(model.index(new_raw_index,1),qfirstname);

        cout << "lastname:";
        string lastname;
        cin >> lastname;
        QString qlastname(lastname.c_str());
        model.setData(model.index(new_raw_index,2),qlastname);

        cout << "gpa:";
        float gpa;
        cin >> gpa;
        model.setData(model.index(new_raw_index,3),gpa);

        cout << "group_id:";
        float group_id;
        cin >> group_id;
        model.setData(model.index(new_raw_index,4),group_id);

        if(model.submitAll())
            cout << "New row was added!" << endl;
        else
            cout << "Error inserting to database!" << endl << model.lastError().text().toStdString();

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
            testSqlTableModel();
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
