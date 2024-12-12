#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <cctype>

// Шаблонный класс для однонаправленного списка
template <typename T>
class SinglyLinkedList {
private:
    // Вложенная структура для узла списка
    struct Node {
        T data;     // Данные, хранящиеся в узле
        Node* next; // Указатель на следующий узел
        Node(T value) : data(value), next(nullptr) {} // Конструктор узла
    };
    Node* head; // Указатель на голову списка

public:
    SinglyLinkedList() : head(nullptr) {} // Инициализация списка с пустой головой

    // Метод для добавления элемента в конец списка
    void Add(T value) {
        if (!head) {  // Если список пуст, создаем новый узел
            head = new Node(value);
        } else {
            Node* temp = head;
            while (temp->next) {  // Ищем последний элемент списка
                temp = temp->next;
            }
            temp->next = new Node(value);  // Добавляем новый элемент в конец
        }
    }

    // Метод для вывода списка на экран
    void Print() const {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " ";  // Выводим данные текущего узла
            temp = temp->next;  // Переходим к следующему узлу
        }
        std::cout << std::endl;
    }

    // Метод для удаления дубликатов из списка
    void RemoveDuplicates() {
        if (!head) return; // Если список пуст, выходим
        Node* current = head;
        while (current && current->next) {
            // Если текущий элемент равен следующему
            if (current->data == current->next->data) {
                Node* duplicate = current->next;  // Дублирующий узел
                current->next = duplicate->next;  // Пропускаем дублирующий узел
                delete duplicate;  // Удаляем дублирующий узел
            } else {
                current = current->next;  // Переходим к следующему элементу
            }
        }
    }
};

// Шаблонный класс для двунаправленного списка
template <typename T>
class DoublyLinkedList {
private:
    // Вложенная структура для узла двунаправленного списка
    struct Node {
        T data;     // Данные
        Node* next; // Указатель на следующий узел
        Node* prev; // Указатель на предыдущий узел
        Node(T value) : data(value), next(nullptr), prev(nullptr) {} // Конструктор
    };
    Node* head; // Указатель на голову списка

public:
    DoublyLinkedList() : head(nullptr) {} // Инициализация списка с пустой головой

    // Метод для добавления элемента в конец двунаправленного списка
    void Add(T value) {
        if (!head) {
            head = new Node(value);
        } else {
            Node* temp = head;
            while (temp->next) {  // Ищем последний элемент
                temp = temp->next;
            }
            temp->next = new Node(value);  // Добавляем новый узел
            temp->next->prev = temp;  // Устанавливаем указатель на предыдущий узел
        }
    }

    // Метод для вывода двунаправленного списка на экран
    void Print() const {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " ";  // Выводим данные текущего узла
            temp = temp->next;  // Переходим к следующему узлу
        }
        std::cout << std::endl;
    }
};

// Шаблонный класс для набора уникальных элементов
template <typename T>
class UnorderedList {
private:
    std::set<T> data;  // Множество для хранения уникальных элементов

public:
    // Метод для добавления элемента в набор
    void Add(T value) {
        data.insert(value);  // Вставляем элемент в множество
    }

    // Метод для проверки наличия элемента в наборе
    bool Contains(T value) const {
        return data.find(value) != data.end();  // Проверяем наличие элемента
    }

    // Метод для объединения двух наборов
    void Union(const UnorderedList<T>& other) {
        data.insert(other.data.begin(), other.data.end());  // Добавляем элементы другого набора
    }

    // Метод для пересечения двух наборов
    UnorderedList<T> Intersect(const UnorderedList<T>& other) const {
        UnorderedList<T> result;  // Новый набор для хранения пересечения
        for (const auto& elem : data) {
            if (other.Contains(elem)) {  // Если элемент есть в обоих наборах
                result.Add(elem);  // Добавляем его в результат
            }
        }
        return result;
    }

    // Метод для вывода элементов набора на экран
    void Print() const {
        for (const auto& elem : data) {
            std::cout << elem << " ";  // Выводим каждый элемент набора
        }
        std::cout << std::endl;
    }
};

// Задание 1: Однонаправленный список (удаление дубликатов)
void Task1() {
    SinglyLinkedList<int> list;
    list.Add(1);
    list.Add(1);
    list.Add(2);
    list.Add(3);
    list.Add(3);

    std::cout << "Исходный список: ";
    list.Print();

    list.RemoveDuplicates();  // Удаление дубликатов

    std::cout << "Список после удаления дубликатов: ";
    list.Print();
}

// Задание 2: Перенос данных из однонаправленного списка в двунаправленный
void Task2() {
    SinglyLinkedList<int> singleList;
    singleList.Add(1);
    singleList.Add(2);
    singleList.Add(3);

    DoublyLinkedList<int> doubleList;
    std::cout << "Исходный однонаправленный список: ";
    singleList.Print();

    // Перенос данных из однонаправленного списка в двунаправленный
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

    // Пересечение: факультативы, на которые записались все студенты
    UnorderedList<std::string> common;
    common = student1.Intersect(student2).Intersect(student3);
    std::cout << "Факультативы, на которые записались все студенты: ";
    common.Print();

    // Объединение: факультативы, на которые записан хотя бы один студент
    UnorderedList<std::string> any;
    any = student1;
    any.Union(student2);
    any.Union(student3);
    std::cout << "Факультативы, на которые записан хотя бы один студент: ";
    any.Print();

    // Разность: факультативы, на которые не записан ни один студент
    std::set<std::string> allCourses = {"Math", "Physics", "Biology", "Chemistry", "History"};
    UnorderedList<std::string> none;

    for (const auto& course : allCourses) {
        if (!student1.Contains(course) && !student2.Contains(course) && !student3.Contains(course)) {
            none.Add(course);  // Добавляем в результат факультативы, на которые не записан ни один студент
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
        return;  // Выход, если файл не открылся
    }

    std::string word;  // Переменная для чтения слов
    std::set<char> oddIndexChars;  // Множество для хранения символов с нечётных позиций

    size_t wordIndex = 1;  // Номер текущего слова (начинаем с 1)
    while (file >> word) {  // Чтение файла по словам
        if (wordIndex % 2 != 0) {  // Если номер слова нечётный
            for (char ch : word) {  // Проходим по каждому символу в слове
                if (std::isalpha(ch)) {  // Если символ — буква
                    oddIndexChars.insert(std::tolower(ch));  // Добавляем символ в множество, преобразовав его в нижний регистр
                }
            }
        }
        wordIndex++;  // Переходим к следующему слову
    }

    std::cout << "Символы, встречающиеся в словах с нечётными номерами: ";
    for (char ch : oddIndexChars) {  // Выводим все найденные символы
        std::cout << ch << " ";
    }
    std::cout << std::endl;

    file.close();  // Закрытие файла
}

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
            case 1:
                Task1();
                break;
            case 2:
                Task2();
                break;
            case 3:
                Task3();
                break;
            case 4:
                Task4();
                break;
            case 0:
                std::cout << "Выход из программы." << std::endl;
                break;
            default:
                std::cout << "Неверный выбор. Пожалуйста, выберите от 0 до 4." << std::endl;
        }
    } while (choice != 0);

    return 0;
}
