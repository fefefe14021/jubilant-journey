#include "tasks.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
#include <cstring>
#include "Toy.h"  // Структура для игрушки

using namespace std;

void task1(const string& filename) {
    ifstream file(filename, ios::binary);  // Открываем бинарный файл
    if (!file) {
        cerr << "Ошибка открытия файла: " << filename << '\n';
        return;
    }

    int number, count = 0;
    // Читаем данные из файла, пока не достигнем конца
    while (file.read(reinterpret_cast<char*>(&number), sizeof(int))) {
        if (number % 2 != 0) {
            count++;  // Увеличиваем счетчик для нечётных чисел
        }
    }

    cout << "Количество удвоенных нечётных чисел: " << count << '\n';  // Выводим результат
}

void task2(const string& filename, int m, int n) {
    ifstream file(filename, ios::binary);  // Открываем бинарный файл
    if (!file) {
        cerr << "Ошибка открытия файла: " << filename << '\n';
        return;
    }

    vector<vector<int>> matrix(m, vector<int>(n, 0));  // Инициализируем матрицу
    int number, i = 0, j = 0;

    // Читаем данные в матрицу
    while (file.read(reinterpret_cast<char*>(&number), sizeof(int)) && i < m) {
        matrix[i][j] = number;
        if (++j == n) {
            j = 0;
            ++i;
        }
    }

    // Преобразуем матрицу в квадратную
    int maxDim = max(m, n);
    matrix.resize(maxDim, vector<int>(maxDim, 1));
    for (auto& row : matrix) {
        row.resize(maxDim, 1);
    }

    // Выводим квадратную матрицу
    cout << "Квадратная матрица:\n";
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << ' ';
        }
        cout << '\n';
    }
}

void task3(const string& filename) {
    ifstream file(filename, ios::binary);  // Открываем бинарный файл
    if (!file) {
        cerr << "Ошибка открытия файла: " << filename << '\n';
        return;
    }

    Toy toy, cheapestToy;
    cheapestToy.price = numeric_limits<double>::max();  // Инициализируем максимальную цену

    // Читаем данные о игрушках и находим самую дешёвую
    while (file.read(reinterpret_cast<char*>(&toy), sizeof(Toy))) {
        if (toy.price < cheapestToy.price) {
            cheapestToy = toy;
        }
    }

    cout << "Самая дешёвая игрушка: " << cheapestToy.name << " (Цена: " << cheapestToy.price << " руб.)\n";
}

void task4(const string& filename) {
    ifstream file(filename);  // Открываем текстовый файл
    if (!file) {
        cerr << "Ошибка открытия файла: " << filename << '\n';
        return;
    }

    int number, maxVal = numeric_limits<int>::min(), minVal = numeric_limits<int>::max();
    // Читаем числа из файла и находим максимальное и минимальное
    while (file >> number) {
        maxVal = max(maxVal, number);
        minVal = min(minVal, number);
    }

    int result = (maxVal - minVal) * (maxVal - minVal);  // Вычисляем квадрат разности
    cout << "Квадрат разности max и min: " << result << '\n';
}

void task5(const string& filename) {
    ifstream file(filename);  // Открываем текстовый файл
    if (!file) {
        cerr << "Ошибка открытия файла: " << filename << '\n';
        return;
    }

    int number, sum = 0;
    // Суммируем все нечётные числа из файла
    while (file >> number) {
        if (number % 2 != 0) {
            sum += number;
        }
    }

    cout << "Сумма нечётных элементов: " << sum << '\n';
}

void task6(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile);  // Открываем исходный файл
    ofstream outFile(outputFile);  // Открываем файл для записи
    if (!inFile || !outFile) {
        cerr << "Ошибка открытия файлов.\n";
        return;
    }

    string line;
    // Читаем строки из исходного файла и записываем в новый файл последние символы
    while (getline(inFile, line)) {
        if (!line.empty()) {
            outFile << line.back() << '\n';
        }
    }

    cout << "Файл " << outputFile << " создан с последними символами строк.\n";
}
