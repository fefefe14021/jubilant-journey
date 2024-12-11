#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include "UnorderedList.h"
#include <iostream>
#include <fstream>
#include <set>
#include <cctype>

// Задание 1: Однонаправленный список (удаление дубликатов)
void Task1() {
    SinglyLinkedList list;
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

// Задание 2: Перенос данных из однонаправленного списка в двунаправленный
void Task2() {
    SinglyLinkedList singleList;
    singleList.Add(1);
    singleList.Add(2);
    singleList.Add(3);

    DoublyLinkedList doubleList;
    std::cout << "Исходный однонаправленный список: ";
    singleList.Print();

    doubleList.Add(1);
    doubleList.Add(2);
    doubleList.Add(3);

    std::cout << "Построенный двунаправленный список: ";
    doubleList.Print();
}

// Задание 3: Факультативы студентов (операции с неупорядоченными наборами)
void Task3() {
    UnorderedList<std::string> student1, student2, student3;

    student1.Add("Math");
    student1.Add("Physics");
    student1.Add("Biology");

    student2.Add("Math");
    student2.Add("Chemistry");
    student2.Add("Biology");

    student3.Add("Math");
    student3.Add("History");

    UnorderedList<std::string> common;
    common = student1.Intersect(student2).Intersect(student3);
    std::cout << "Факультативы, на которые записались все студенты: ";
    common.Print();

    UnorderedList<std::string> any;
    any = student1;
    any.Union(student2);
    any.Union(student3);
    std::cout << "Факультативы, на которые записан хотя бы один студент: ";
    any.Print();

    std::set<std::string> allCourses = {"Math", "Physics", "Biology", "Chemistry", "History"};
    UnorderedList<std::string> none;

    for (const auto& course : allCourses) {
        if (!student1.Contains(course) && !student2.Contains(course) && !student3.Contains(course)) {
            none.Add(course);
        }
    }
    std::cout << "Факультативы, на которые не записан ни один студент: ";
    none.Print();
}

// Задание 4: Обработка русского текста (символы из слов с нечётными номерами)
void Task4() {
    std::ifstream file("text.txt");
    if (!file.is_open()) {
        std::cout << "Не удалось открыть файл." << std::endl;
        return;
    }

    std::string word;
    std::set<char> oddIndexChars;
    size_t wordIndex = 1;
    while (file >> word) {
        if (wordIndex % 2 != 0) {
            for (char ch : word) {
                if (std::isalpha(ch)) {
                    oddIndexChars.insert(std::tolower(ch));
                }
            }
        }
        wordIndex++;
    }

    std::cout << "Символы, встречающиеся в словах с нечётными номерами: ";
    for (char ch : oddIndexChars) {
        std::cout << ch << " ";
    }
    std::cout << std::endl;

    file.close();
}
