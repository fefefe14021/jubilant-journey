#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <random>
#include <cstring>
#include <limits>

using namespace std;

// Класс Toy
class Toy {
public:
    char name[50];  // Ограничение длины имени игрушки
    double price;   // Цена игрушки
    int minAge;     // Минимальный возраст для использования
    int maxAge;     // Максимальный возраст для использования

    Toy() : price(0), minAge(0), maxAge(0) {
        name[0] = '\0';
    }

    Toy(const string& name, double price, int minAge, int maxAge) {
        strncpy(this->name, name.c_str(), sizeof(this->name) - 1);
        this->name[sizeof(this->name) - 1] = '\0';
        this->price = price;
        this->minAge = minAge;
        this->maxAge = maxAge;
    }
};

// Класс FileManager для работы с файлами
class FileManager {
public:
    static void fillBinaryFile(const string& filename, int count);
    static void fillTextFile(const string& filename, int count);
    static void fillBinaryFileWithStructs(const string& filename, int count);
    static void fillTextFileWithText(const string& filename, int count);
};

// Реализация методов FileManager
void FileManager::fillBinaryFile(const string& filename, int count) {
    ofstream file(filename, ios::binary);
    if (!file) {
        cerr << "Ошибка открытия файла: " << filename << '\n';
        return;
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);

    for (int i = 0; i < count; ++i) {
        int num = dis(gen);
        file.write(reinterpret_cast<const char*>(&num), sizeof(int));
    }

    cout << "Бинарный файл " << filename << " заполнен случайными числами.\n";
}

void FileManager::fillTextFile(const string& filename, int count) {
    ofstream file(filename);
    if (!file) {
        cerr << "Ошибка открытия файла: " << filename << '\n';
        return;
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);

    for (int i = 0; i < count; ++i) {
        file << dis(gen) << '\n';
    }

    cout << "Текстовый файл " << filename << " заполнен случайными числами.\n";
}

void FileManager::fillBinaryFileWithStructs(const string& filename, int count) {
    ofstream file(filename, ios::binary);
    if (!file) {
        cerr << "Ошибка открытия файла: " << filename << '\n';
        return;
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);
    uniform_real_distribution<> disPrice(10.0, 100.0);
    vector<string> names = {"Toy1", "Toy2", "Toy3"};

    for (int i = 0; i < count; ++i) {
        Toy toy(names[i % 3], disPrice(gen), dis(gen), dis(gen));
        file.write(reinterpret_cast<const char*>(&toy), sizeof(Toy));
    }

    cout << "Бинарный файл с игрушками " << filename << " заполнен.\n";
}

void FileManager::fillTextFileWithText(const string& filename, int count) {
    ofstream file(filename);
    if (!file) {
        cerr << "Ошибка открытия файла: " << filename << '\n';
        return;
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);

    for (int i = 0; i < count; ++i) {
        file << "Line " << dis(gen) << '\n';
    }

    cout << "Текстовый файл с текстом " << filename << " заполнен.\n";
}

// Класс TaskManager для выполнения задач
class TaskManager {
public:
    static void task1(const string& filename);
    static void task2(const string& filename, int m, int n);
    static void task3(const string& filename);
    static void task4(const string& filename);
    static void task5(const string& filename);
    static void task6(const string& inputFile, const string& outputFile);
};

// Реализация методов TaskManager
void TaskManager::task1(const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Ошибка открытия файла: " << filename << '\n';
        return;
    }

    int number, count = 0;
    while (file.read(reinterpret_cast<char*>(&number), sizeof(int))) {
        if (number % 2 == 0) {
            count++;  // Число нечётное
        }
    }

    cout << "Количество удвоенных нечётных чисел: " << count << '\n';
}

void TaskManager::task2(const string& filename, int m, int n) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Ошибка открытия файла: " << filename << '\n';
        return;
    }

    vector<vector<int>> matrix(m, vector<int>(n, 0));
    int number, i = 0, j = 0;

    while (file.read(reinterpret_cast<char*>(&number), sizeof(int)) && i < m) {
        matrix[i][j] = number;
        if (++j == n) {
            j = 0;
            ++i;
        }
    }

    int maxDim = max(m, n);
    matrix.resize(maxDim, vector<int>(maxDim, 1));
    for (auto& row : matrix) {
        row.resize(maxDim, 1);
    }

    cout << "Квадратная матрица:\n";
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << ' ';
        }
        cout << '\n';
    }
}

void TaskManager::task3(const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Ошибка открытия файла: " << filename << '\n';
        return;
    }

    Toy toy, cheapestToy;
    cheapestToy.price = numeric_limits<double>::max();

    while (file.read(reinterpret_cast<char*>(&toy), sizeof(Toy))) {
        if (toy.price < cheapestToy.price) {
            cheapestToy = toy;
        }
    }

    cout << "Самая дешёвая игрушка: " << cheapestToy.name << " (Цена: " << cheapestToy.price << " руб.)\n";
}

void TaskManager::task4(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Ошибка открытия файла: " << filename << '\n';
        return;
    }

    int number, maxVal = numeric_limits<int>::min(), minVal = numeric_limits<int>::max();
    while (file >> number) {
        maxVal = max(maxVal, number);
        minVal = min(minVal, number);
    }

    int result = (maxVal - minVal) * (maxVal - minVal);
    cout << "Квадрат разности max и min: " << result << '\n';
}

void TaskManager::task5(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Ошибка открытия файла: " << filename << '\n';
        return;
    }

    int k;
    cout << "Введите число К: ";
    cin >> k;

    int number, sum = 0;
    while (file >> number) {
        if (number % k != 0) {
            sum += number;
        }
    }

    cout << "Сумма нечётных элементов: " << sum << '\n';
}

void TaskManager::task6(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);
    if (!inFile || !outFile) {
        cerr << "Ошибка открытия файлов.\n";
        return;
    }

    string line;
    while (getline(inFile, line)) {
        if (!line.empty()) {
            outFile << line.back() << '\n';
        }
    }

    cout << "Файл " << outputFile << " создан с последними символами строк.\n";
}
