#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

#include <QSqlDatabase>
#include <QString>

class DatabaseConnection {
public:
    DatabaseConnection();
    ~DatabaseConnection();

    bool openConnection(const QString &hostName, const QString &databaseName,
                        const QString &userName, const QString &password);
    void closeConnection();
    QSqlDatabase getDatabase() const;

private:
    QSqlDatabase db;
};

#endif // DATABASECONNECTION_H
