#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDate>
#include <QMessageBox>
#include <QSqlRecord>
#include <QRegularExpression>

MainWindow::MainWindow(QSqlDatabase database, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), model(new QSqlTableModel(this)), db(database) {
    ui->setupUi(this);

    if (db.isOpen()) {
        model->setTable("clients");
        model->select();
        ui->tableView->setModel(model);
    }

    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::addData);
    connect(ui->deleteButton, &QPushButton::clicked, this, &MainWindow::deleteData);
    connect(ui->switchToTable1, &QPushButton::clicked, this, &MainWindow::switchToTable1);
    connect(ui->switchToTable2, &QPushButton::clicked, this, &MainWindow::switchToTable2);
    connect(ui->switchToTable3, &QPushButton::clicked, this, &MainWindow::switchToTable3);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &MainWindow::refreshTable);
    connect(ui->tableView, &QTableView::doubleClicked, this, &MainWindow::editData);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::addData() {
    // Поле для clientid
    QString clientIdField = "clientid";
    QString emailField = "Email"; // Поле для email
    QString phoneField = "КонтактныйТелефон"; // Поле для телефона

    // Находим минимально допустимое значение для clientid
    QSqlQuery query(db);
    query.prepare(QString("SELECT MIN(%1 + 1) AS nextId FROM %2 WHERE (%1 + 1) NOT IN (SELECT %1 FROM %2)")
                      .arg(clientIdField)
                      .arg(model->tableName()));
    int newClientId = 1; // Начальное значение, если таблица пуста
    if (query.exec() && query.next()) {
        newClientId = query.value("nextId").toInt();
    }

    // Создаем новую строку в модели
    int newRow = model->rowCount();
    model->insertRow(newRow);

    // Устанавливаем clientid
    model->setData(model->index(newRow, model->fieldIndex(clientIdField)), newClientId);

    // Проверка данных перед сохранением
    connect(model, &QSqlTableModel::beforeUpdate, this, [this, emailField, phoneField](int row) {
        QString email = model->data(model->index(row, model->fieldIndex(emailField))).toString();
        QString phone = model->data(model->index(row, model->fieldIndex(phoneField))).toString();

        // Регулярные выражения
        QRegularExpression emailRegex(R"(^[\w.-]+@[\w.-]+\.[a-zA-Z]{2,}$)");
        QRegularExpression phoneRegex(R"(^\d{10,15}$)");

        // Проверка корректности email
        if (!emailRegex.match(email).hasMatch()) {
            QMessageBox::warning(this, "Ошибка", "Некорректный формат email!");
            model->revertAll();
            return;
        }

        // Проверка корректности номера телефона
        if (!phoneRegex.match(phone).hasMatch()) {
            QMessageBox::warning(this, "Ошибка", "Некорректный номер телефона!");
            model->revertAll();
            return;
        }

        // Проверка уникальности email и телефона
        QSqlQuery query(db);
        query.prepare(QString("SELECT COUNT(*) FROM %1 WHERE %2 = :email OR %3 = :phone")
                          .arg(model->tableName())
                          .arg(emailField)
                          .arg(phoneField));
        query.bindValue(":email", email);
        query.bindValue(":phone", phone);
        query.exec();
        if (query.next() && query.value(0).toInt() > 0) {
            QMessageBox::warning(this, "Ошибка", "Email или номер телефона уже существуют!");
            model->revertAll();
        }
    });

    qDebug() << "Добавлена новая строка с clientid =" << newClientId << ". Заполните данные и сохраните изменения.";
    ui->tableView->scrollToBottom(); // Прокручиваем к новой строке
}


void MainWindow::deleteData() {
    QModelIndex index = ui->tableView->currentIndex();
    if (index.isValid()) {
        model->removeRow(index.row());
        if (!model->submitAll()) {
            QMessageBox::critical(this, "Ошибка", model->lastError().text());
        } else {
            model->select();
            QMessageBox::information(this, "Успех", "Запись успешно удалена!");
        }
    }
}

void MainWindow::editData() {
    QModelIndex index = ui->tableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Ошибка", "Нет выделенной строки для редактирования.");
        return;
    }

    QString oldValue = model->data(index).toString();
    QString newValue = QInputDialog::getText(this, "Редактирование данных",
                                             "Введите новое значение:", QLineEdit::Normal, oldValue);

    if (!newValue.isEmpty() && newValue != oldValue) {
        model->setData(index, newValue);
        if (!model->submitAll()) {
            QMessageBox::critical(this, "Ошибка", model->lastError().text());
        } else {
            model->select();
            QMessageBox::information(this, "Успех", "Данные успешно обновлены!");
        }
    }
}

void MainWindow::switchToTable1() {
    model->setTable("clients");
    model->select();
    ui->tableView->resizeColumnsToContents();
}

void MainWindow::switchToTable2() {
    model->setTable("credits");
    model->select();
    ui->tableView->resizeColumnsToContents();
}

void MainWindow::switchToTable3() {
    model->setTable("transactions");
    model->select();
    ui->tableView->resizeColumnsToContents();
}

void MainWindow::refreshTable() {
    model->select();
}


