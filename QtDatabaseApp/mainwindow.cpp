#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), db(), is_connected(false)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Кнопка подключения к базе данных
void MainWindow::on_connect_btn_clicked()
{
    if(!is_connected)
    {
        db = QSqlDatabase::addDatabase("QPSQL");
        db.setHostName("127.0.0.1");
        db.setDatabaseName("testdb");
        db.setUserName("myuser");
        db.setPassword("123");
        if(db.open())
        {
            is_connected = true;
            QMessageBox::about(this, "Внимание", "Подключение к базе удалось!");
        }
        else
            QMessageBox::about(this, "Внимание", "Не удалось подключиться!");
    }
}
