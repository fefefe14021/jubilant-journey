#include <QApplication>
#include "mainwindow.h"
#include "databaseconnection.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // Подключение к базе данных
    DatabaseConnection dbConnection;
    if (!dbConnection.openConnection("localhost", "CreditManagement", "postgres", "1234")) {
        qDebug() << "Не удалось подключиться к базе данных.";
        return -1; // Завершаем программу, если подключение не удалось
    }

    // Передача подключения к MainWindow
    MainWindow w(dbConnection.getDatabase());
    w.show();

    return a.exec();
}
