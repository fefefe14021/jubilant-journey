#include <iostream>
#include "Tasks.cpp"

int main() {
    int choice;

    do {
        std::cout << "Выберите задачу (1-4), или 0 для выхода:\n";
        std::cout << "1. Задание 1: Однонаправленный список\n";
        std::cout << "2. Задание 2: Двунаправленный список\n";
        std::cout << "3. Задание 3: Факультативы студентов\n";
        std::cout << "4. Задание 4: Символы из файла\n";
        std::cout << "0. Выход\n";

        std::cout << "Ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
            case 1: Task1(); break;
            case 2: Task2(); break;
            case 3: Task3(); break;
            case 4: Task4(); break;
            case 0: std::cout << "Выход из программы." << std::endl; break;
            default: std::cout << "Неверный выбор. Пожалуйста, выберите от 0 до 4." << std::endl;
        }
    } while (choice != 0);

    return 0;
}
