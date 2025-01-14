#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QSqlDatabase database, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addData();
    void deleteData();
    void editData();
    void switchToTable1();
    void switchToTable2();
    void switchToTable3();
    void refreshTable();

private:
    Ui::MainWindow *ui;
    QSqlTableModel *model;   // Модель для работы с таблицей
    QSqlDatabase db;         // Подключение к базе данных
};

#endif // MAINWINDOW_H
