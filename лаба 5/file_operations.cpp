#include "file_operations.h"
#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <string>
#include <cstring>
#include "Toy.h"

using namespace std;

void fillBinaryFile(const string& filename, int count) {
    ofstream file(filename, ios::binary);  // Открываем бинарный файл
    if (!file) {
        cerr << "Ошибка открытия файла: " << filename << '\n';
        return;
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);

    // Заполняем файл случайными числами
    for (int i = 0; i < count; ++i) {
        int num = dis(gen);
        file.write(reinterpret_cast<const char*>(&num), sizeof(int));
    }

    cout << "Бинарный файл " << filename << " заполнен случайными числами.\n";
}

void fillTextFile(const string& filename, int count) {
    ofstream file(filename);  // Открываем текстовый файл
    if (!file) {
        cerr << "Ошибка открытия файла: " << filename << '\n';
        return;
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);

    // Заполняем файл случайными числами
    for (int i = 0; i < count; ++i) {
        file << dis(gen) << '\n';
    }

    cout << "Текстовый файл " << filename << " заполнен случайными числами.\n";
}

void fillBinaryFileWithStructs(const string& filename, int count) {
    ofstream file(filename, ios::binary);  // Открываем бинарный файл
    if (!file) {
        cerr << "Ошибка открытия файла: " << filename << '\n';
        return;
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);
    uniform_real_distribution<> disPrice(10.0, 100.0);
    vector<string> names = {"Toy1", "Toy2", "Toy3"};

    // Заполняем файл случайными игрушками
    for (int i = 0; i < count; ++i) {
        Toy toy;
        strncpy(toy.name, names[i % 3].c_str(), sizeof(toy.name) - 1);
        toy.name[sizeof(toy.name) - 1] = '\0';
        toy.price = disPrice(gen);
        toy.minAge = dis(gen);
        toy.maxAge = toy.minAge + dis(gen);
        file.write(reinterpret_cast<const char*>(&toy), sizeof(Toy));
    }

    cout << "Бинарный файл с игрушками " << filename << " заполнен.\n";
}

void fillTextFileWithText(const string& filename, int count) {
    ofstream file(filename);  // Открываем текстовый файл
    if (!file) {
        cerr << "Ошибка открытия файла: " << filename << '\n';
        return;
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);

    // Заполняем файл строками с числами
    for (int i = 0; i < count; ++i) {
        file << "Line " << dis(gen) << '\n';
    }

    cout << "Текстовый файл с текстом " << filename << " заполнен.\n";
}
