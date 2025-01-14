#include "databaseconnection.h"
#include <QSqlError>
#include <QDebug>

DatabaseConnection::DatabaseConnection() {
    db = QSqlDatabase::addDatabase("QPSQL");
}

DatabaseConnection::~DatabaseConnection() {
    closeConnection();
}

bool DatabaseConnection::openConnection(const QString &hostName, const QString &databaseName,
                                        const QString &userName, const QString &password) {
    db.setHostName(hostName);
    db.setDatabaseName(databaseName);
    db.setUserName(userName);
    db.setPassword(password);

    if (!db.open()) {
        qDebug() << "Database connection failed: " << db.lastError().text();
        return false;
    }
    qDebug() << "Database connected successfully!";
    return true;
}

void DatabaseConnection::closeConnection() {
    if (db.isOpen()) {
        db.close();
        qDebug() << "Database connection closed.";
    }
}

QSqlDatabase DatabaseConnection::getDatabase() const {
    return db;
}
