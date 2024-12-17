 #include <iostream> 
#include <vector>
#include <cmath>
#include <sstream>
#include <limits>
#include <optional>
#include <regex>

using namespace std;

// Класс, представляющий точку
class Point {
private:
    double x, y;

public:
    Point(double xCoord, double yCoord) : x(xCoord), y(yCoord) {}

    string toString() const {
        stringstream ss;
        ss << "{" << x << ";" << y << "}";
        return ss.str();
    }

    double distanceTo(const Point& other) const {
        return sqrt(pow(other.x - x, 2) + pow(other.y - y, 2));
    }

    void shift(double deltaX, double deltaY) {
        x += deltaX;
        y += deltaY;
    }
};

// Класс, представляющий имя
class Name {
private:
    optional<string> surname;
    optional<string> firstName;
    optional<string> middleName;

public:
    Name(optional<string> s, optional<string> f, optional<string> m)
        : surname(s), firstName(f), middleName(m) {}

    string toString() const {
        string result;
        if (surname.has_value()) result += *surname + " ";
        if (firstName.has_value()) result += *firstName + " ";
        if (middleName.has_value()) result += *middleName;

        if (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }

        return result;
    }

    static bool isValidName(const string& name) {
        regex namePattern("^[А-Яа-яA-Za-z ]+$");
        return !name.empty() && regex_match(name, namePattern);
    }

    optional<string> getSurname() const { return surname; }
    optional<string> getFirstName() const { return firstName; }
    optional<string> getMiddleName() const { return middleName; }
};

// Класс, представляющий человека
class Human {
private:
    Name name;
    int height;
    optional<Human*> father;

public:
    Human(const Name& n, int h, optional<Human*> f = nullopt)
        : name(n), height(h), father(f) {
        updateName();
    }

    void updateName() {
        if (!name.getSurname().has_value() && father.has_value() && (*father)->name.getSurname().has_value()) {
            name = Name((*father)->name.getSurname(), name.getFirstName(), name.getMiddleName());
        }
        if (!name.getMiddleName().has_value() && father.has_value() && (*father)->name.getFirstName().has_value()) {
            string fatherFirstName = *(*father)->name.getFirstName();
            name = Name(name.getSurname(), name.getFirstName(), fatherFirstName + "ович");
        }
    }

    string toString() const {
        return name.toString() + " и ростом " + to_string(height);
    }
};

// Класс, представляющий ломаную
class BrokenLine {
private:
    vector<Point> points;

public:
    BrokenLine() = default;

    BrokenLine(const vector<Point>& pts) : points(pts) {}

    void addPoints(const vector<Point>& newPoints) {
        points.insert(points.end(), newPoints.begin(), newPoints.end());
    }

    double length() const {
        double totalLength = 0;
        for (size_t i = 0; i < points.size() - 1; ++i) {
            totalLength += points[i].distanceTo(points[i + 1]);
        }
        return totalLength;
    }

    string toString() const {
        stringstream ss;
        ss << "Линия [";
        for (size_t i = 0; i < points.size(); ++i) {
            ss << points[i].toString();
            if (i < points.size() - 1) {
                ss << ", ";
            }
        }
        ss << "]";
        return ss.str();
    }

    void shift(double deltaX, double deltaY) {
        for (auto& point : points) {
            point.shift(deltaX, deltaY);
        }
    }

    const Point& firstPoint() const {
        return points.front();
    }

    const Point& lastPoint() const {
        return points.back();
    }
};

// Задача 1: Имена
void task1() {
    cout << "Создание имен:\n";
    Name cleopatraName(nullopt, "Клеопатра", nullopt);
    Name pushkinName("Пушкин", "Александр", "Сергеевич");
    Name mayakovskyName("Маяковский", "Владимир", nullopt);

    cout << cleopatraName.toString() << endl;
    cout << pushkinName.toString() << endl;
    cout << mayakovskyName.toString() << endl;
}

// Задача 2: Человек с именем
void task2() {
    cout << "Создание людей с именами:\n";
    Human cleopatra(Name(nullopt, "Клеопатра", nullopt), 152);
    Human pushkin(Name("Пушкин", "Александр", "Сергеевич"), 167);
    Human mayakovsky(Name("Маяковский", "Владимир", nullopt), 189);

    cout << cleopatra.toString() << endl;
    cout << pushkin.toString() << endl;
    cout << mayakovsky.toString() << endl;
}

// Задача 3: Человек с родителем
void task3() {
    cout << "Создание людей с родителями:\n";
    Human ivan(Name("Чудов", "Иван", nullopt), 180);
    Human petya(Name("Чудов", "Петр", nullopt), 175, &ivan);
    Human boris(Name(nullopt, "Борис", nullopt), 170, &petya);

    cout << ivan.toString() << endl;
    cout << petya.toString() << endl;
    cout << boris.toString() << endl;
}

// Задача 4: Ломаная
void task4() {
    cout << "Создание ломаных...\n";
    
    BrokenLine line1({Point(1, 5), Point(2, 8), Point(5, 3)});
    cout << "Первая ломаная: " << line1.toString() << endl;

    BrokenLine line2({line1.firstPoint(), Point(2, -5), Point(4, -8), line1.lastPoint()});
    cout << "Вторая ломаная: " << line2.toString() << endl;

    double shiftX = 1, shiftY = 1; // Пример сдвига
    line1.shift(shiftX, shiftY);
    line2.shift(shiftX, shiftY);

    cout << "Первая ломаная после сдвига: " << line1.toString() << endl;
    cout << "Вторая ломаная после сдвига: " << line2.toString() << endl;
}

// Задача 5: Создание ломаной
void task5() {
    cout << "Создание ломаной без параметров...\n";
    BrokenLine emptyLine; // Пустая ломаная
    cout << "Пустая ломаная: " << emptyLine.toString() << endl;

    cout << "Создание ломаной с параметрами...\n";
    BrokenLine lineWithPoints({Point(1, 1), Point(2, 2)});
    cout << "Ломаная с точками: " << lineWithPoints.toString() << endl;
}

// Задача 6: Длина ломаной
void task6() {
    cout << "Создание ломаной и вывод длины...\n";
    BrokenLine line({Point(1, 5), Point(2, 8), Point(5, 3)});
    cout << "Длина ломаной: " << line.length() << endl;

    // Добавление новых точек
    line.addPoints({Point(5, 15), Point(8, 10)});
    cout << "Ломаная после добавления точек: " << line.toString() << endl;
    cout << "Новая длина ломаной: " << line.length() << endl;
}

// Функция для ввода высоты с проверкой
int inputHeight() {
    int height;
    while (true) {
        cout << "Введите рост (целое число): ";
        cin >> height;
        if (cin.fail() || height <= 0) {
            cin.clear(); // Очистка флага ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорируем неверный ввод
            cout << "Некорректный ввод. Пожалуйста, введите положительное целое число." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорируем остаток ввода
            break; // Ввод корректен, выходим из цикла
        }
    }
    return height;
}

// Главная функция
int main() {
    int choice;
    do {
        cout << "\nВыберите задачу (1-6, 0 для выхода): ";
        cin >> choice;

        if (cin.fail() || choice < 0 || choice > 6) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Некорректный ввод. Попробуйте снова." << endl;
            continue; // Повторяем ввод
        }

        switch (choice) {
            case 1: task1(); break;
            case 2: {
                cout << "Создание человека:\n";
                Name name("Пушкин", "Александр", "Сергеевич"); // Имя человека
                int height = inputHeight(); // Ввод высоты с проверкой
                Human pushkin(name, height);
                cout << pushkin.toString() << endl;
                break;
            }
            case 3: task3(); break;
            case 4: task4(); break;
            case 5: task5(); break;
            case 6: task6(); break;
            case 0: cout << "Выход..." << endl; break;
        }
    } while (choice != 0);

    return 0;
}
