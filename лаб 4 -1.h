#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>

class Triangle {
private:
    double a, b, c;  // Длины сторон треугольника

public:
    // Конструкторы
    Triangle();
    Triangle(double a, double b, double c);
    Triangle(const Triangle& other);

    // Метод для проверки существования треугольника
    bool isValid() const;

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const Triangle& t);

    // Методы доступа (геттеры)
    double getA() const;
    double getB() const;
    double getC() const;

    // Метод для вычисления периметра
    double perimeter() const;

    // Метод для вычисления площади с использованием формулы Герона
    double area() const;

    // Унарная операция ~ для вычисления площади
    double operator~() const;

    // Операции приведения типа
    operator double() const;  // Приведение к double (периметр)
    operator bool() const;    // Приведение к bool (существование треугольника)

    // Бинарная операция < (сравнение площадей)
    bool operator<(const Triangle& other) const;

    // Бинарная операция > (сравнение площадей)
    bool operator>(const Triangle& other) const;
};

#endif  // TRIANGLE_H
