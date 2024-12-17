#include "LinkedLists.h"
#include <iostream>
#include <set>
#include <string>
#include <fstream>

void Task1() {
    SinglyLinkedList<int> list;
    list.Add(1);
    list.Add(1);
    list.Add(2);
    list.Add(3);
    list.Add(3);

    std::cout << "Исходный список: ";
    list.Print();

    list.RemoveDuplicates();

    std::cout << "Список после удаления дубликатов: ";
    list.Print();
}

void Task2() {
    SinglyLinkedList<int> singleList;
    singleList.Add(1);
    singleList.Add(2);
    singleList.Add(3);

    DoublyLinkedList<int> doubleList;

    std::cout << "Исходный однонаправленный список: ";
    singleList.Print();

    doubleList.Add(1);
    doubleList.Add(2);
    doubleList.Add(3);

    std::cout << "Построенный двунаправленный список: ";
    doubleList.Print();
}

void Task3() {
    std::set<std::string> student1 = {"Math", "Physics", "Biology"};
    std::set<std::string> student2 = {"Math", "Chemistry", "Biology"};
    std::set<std::string> student3 = {"Math", "History"};

    std::set<std::string> common;
    for (const auto& subj : student1) {
        if (student2.find(subj) != student2.end() && student3.find(subj) != student3.end()) {
            common.insert(subj);
        }
    }

    std::cout << "Факультативы, на которые записались все студенты: ";
    for (const auto& subj : common) {
        std::cout << subj << " ";
    }
    std::cout << std::endl;
}

void Task4() {
    std::ifstream file("text.txt");
    if (!file.is_open()) {
        std::cout << "Не удалось открыть файл.\n";
        return;
    }

    std::set<char> oddChars;
    std::string word;
    size_t wordIndex = 1;

    while (file >> word) {
        if (wordIndex % 2 != 0) {
            for (char ch : word) {
                if (isalpha(ch)) {
                    oddChars.insert(tolower(ch));
                }
            }
        }
        ++wordIndex;
    }

    std::cout << "Символы из нечётных слов: ";
    for (char c : oddChars) std::cout << c << " ";
    std::cout << std::endl;
}

int main() {
    int choice;
    do {
        std::cout << "Выберите задачу (1-4), или 0 для выхода:\n";
        std::cout << "1. Однонаправленный список\n";
        std::cout << "2. Двунаправленный список\n";
        std::cout << "3. Факультативы студентов\n";
        std::cout << "4. Символы из файла\n";
        std::cout << "0. Выход\n";

        std::cout << "Ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
            case 1: Task1(); break;
            case 2: Task2(); break;
            case 3: Task3(); break;
            case 4: Task4(); break;
            case 0: std::cout << "Выход из программы.\n"; break;
            default: std::cout << "Неверный выбор.\n";
        }
    } while (choice != 0);

    return 0;
}
