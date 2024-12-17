#ifndef CLASSES_H
#define CLASSES_H

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
    Point(double xCoord, double yCoord);
    string toString() const;
    double distanceTo(const Point& other) const;
    void shift(double deltaX, double deltaY);
};

// Класс, представляющий имя
class Name {
private:
    optional<string> surname;
    optional<string> firstName;
    optional<string> middleName;

public:
    Name(optional<string> s, optional<string> f, optional<string> m);
    string toString() const;
    static bool isValidName(const string& name);
    optional<string> getSurname() const;
    optional<string> getFirstName() const;
    optional<string> getMiddleName() const;
};

// Класс, представляющий человека
class Human {
private:
    Name name;
    int height;
    optional<Human*> father;

public:
    Human(const Name& n, int h, optional<Human*> f = nullopt);
    void updateName();
    string toString() const;
};

// Класс, представляющий ломаную
class BrokenLine {
private:
    vector<Point> points;

public:
    BrokenLine();
    BrokenLine(const vector<Point>& pts);
    void addPoints(const vector<Point>& newPoints);
    double length() const;
    string toString() const;
    void shift(double deltaX, double deltaY);
    const Point& firstPoint() const;
    const Point& lastPoint() const;
};

// Функция для ввода высоты
int inputHeight();

#endif // CLASSES_H
