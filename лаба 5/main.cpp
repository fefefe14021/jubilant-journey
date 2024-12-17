#include <iostream>
#include "program.cpp"

using namespace std;

int main() {
    int choice;
    do {
        cout << "\nВыберите задачу (1-6, 0 для выхода): ";
        cout << "\n1. Задание 1: Подсчёт удвоенных нечётных чисел";
        cout << "\n2. Задание 2: Преобразование матрицы";
        cout << "\n3. Задание 3: Поиск самой дешёвой игрушки";
        cout << "\n4. Задание 4: Квадрат разности максимального и минимального чисел";
        cout << "\n5. Задание 5: Сумма нечётных элементов";
        cout << "\n6. Задание 6: Последний символ каждой строки";
        cout << "\n0. Выход\n";
        cin >> choice;

        switch (choice) {
            case 1: 
                FileManager::fillBinaryFile("binary1.dat", 10); 
                TaskManager::task1("binary1.dat"); 
                break;
            case 2: 
                FileManager::fillBinaryFile("binary2.dat", 12); 
                TaskManager::task2("binary2.dat", 3, 4); 
                break;
            case 3: 
                FileManager::fillBinaryFileWithStructs("toys.dat", 5); 
                TaskManager::task3("toys.dat"); 
                break;
            case 4: 
                FileManager::fillTextFile("numbers1.txt", 20); 
                TaskManager::task4("numbers1.txt"); 
                break;
            case 5: 
                FileManager::fillTextFile("numbers2.txt", 20); 
                TaskManager::task5("numbers2.txt"); 
                break;
            case 6: 
                FileManager::fillTextFile("text.txt", 10); 
                TaskManager::task6("text.txt", "output.txt"); 
                break;
            case 0: 
                cout << "Выход из программы.\n"; 
                break;
            default: 
                cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}
