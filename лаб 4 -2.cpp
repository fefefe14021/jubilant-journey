#include "Triangle.h"
#include <cmath>
#include <iostream>

// Конструкторы
Triangle::Triangle() : a(0), b(0), c(0) {}

Triangle::Triangle(double a, double b, double c) : a(a), b(b), c(c) {
    if (!isValid()) {
        std::cerr << "Некорректные значения сторон. Треугольник не существует." << std::endl;
    }
}

Triangle::Triangle(const Triangle& other) : a(other.a), b(other.b), c(other.c) {}

// Метод для проверки существования треугольника
bool Triangle::isValid() const {
    return (a + b > c) && (a + c > b) && (b + c > a);  // Условие существования треугольника
}

// Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& os, const Triangle& t) {
    os << "Стороны треугольника: a = " << t.a << ", b = " << t.b << ", c = " << t.c;
    return os;
}

// Методы доступа (геттеры)
double Triangle::getA() const { return a; }
double Triangle::getB() const { return b; }
double Triangle::getC() const { return c; }

// Метод для вычисления периметра
double Triangle::perimeter() const {
    if (isValid()) {
        return a + b + c;
    } else {
        return 0.0;  // Если треугольник не существует, возвращаем 0
    }
}

// Метод для вычисления площади с использованием формулы Герона
double Triangle::area() const {
    if (isValid()) {
        double s = perimeter() / 2;  // Полупериметр
        return std::sqrt(s * (s - a) * (s - b) * (s - c));  // Формула Герона
    } else {
        return 0.0;  // Если треугольник не существует, возвращаем 0
    }
}

// Унарная операция ~ для вычисления площади
double Triangle::operator~() const {
    return area();
}

// Операции приведения типа
Triangle::operator double() const {  // Приведение к double (периметр)
    return perimeter();
}

Triangle::operator bool() const {  // Приведение к bool (существование треугольника)
    return isValid();
}

// Бинарная операция < (сравнение площадей)
bool Triangle::operator<(const Triangle& other) const {
    return area() < other.area();
}

// Бинарная операция > (сравнение площадей)
bool Triangle::operator>(const Triangle& other) const {
    return area() > other.area();
}
