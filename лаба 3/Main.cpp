#include "Classes.h"

void task1() {
    cout << "Создание имен:\n";
    Name cleopatraName(nullopt, "Клеопатра", nullopt);
    Name pushkinName("Пушкин", "Александр", "Сергеевич");
    Name mayakovskyName("Маяковский", "Владимир", nullopt);

    cout << cleopatraName.toString() << endl;
    cout << pushkinName.toString() << endl;
    cout << mayakovskyName.toString() << endl;
}

void task2() {
    cout << "Создание людей с именами:\n";
    Human cleopatra(Name(nullopt, "Клеопатра", nullopt), 152);
    Human pushkin(Name("Пушкин", "Александр", "Сергеевич"), 167);
    Human mayakovsky(Name("Маяковский", "Владимир", nullopt), 189);

    cout << cleopatra.toString() << endl;
    cout << pushkin.toString() << endl;
    cout << mayakovsky.toString() << endl;
}

void task3() {
    cout << "Создание людей с родителями:\n";
    Human ivan(Name("Чудов", "Иван", nullopt), 180);
    Human petya(Name("Чудов", "Петр", nullopt), 175, &ivan);
    Human boris(Name(nullopt, "Борис", nullopt), 170, &petya);

    cout << ivan.toString() << endl;
    cout << petya.toString() << endl;
    cout << boris.toString() << endl;
}

void task4() {
    BrokenLine line({Point(1, 5), Point(2, 8), Point(5, 3)});
    cout << "Ломаная: " << line.toString() << endl;
}

int main() {
    int choice;
    do {
        cout << "\nВыберите задачу (1-4, 0 для выхода): ";
        cin >> choice;

        switch (choice) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 4: task4(); break;
            case 0: cout << "Выход..." << endl; break;
            default: cout << "Некорректный ввод!" << endl;
        }
    } while (choice != 0);

    return 0;
}
