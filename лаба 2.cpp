#include <iostream> // Ввод/вывод данных
#include <Windows.h> // Для использования русской речи в консоли
#include <string> // Для использования строк
#include <vector> // Вектор для работы с динамическими массивами
#include <deque> // Дек для двусторонней очереди
#include <list> // Список для двусвязного списка
#include <algorithm> // Алгоритмы для контейнеров
#include <iterator> // Итераторы для контейнеров
#include <fstream> // Работа с файлами
#include <numeric> // Для использования adjacent_difference
using namespace std;
// Основная функция для обмена средних элементов и вывода результата
void swapMiddleElements() {
    // Задание вектора
    vector<int> V = { 1, 2, 3, 4, 5, 6 };
    cout << "Результат для вектора (до): ";
    for (int v : V) {
        cout << v << " ";
    }
    cout << endl;
    swap(V[V.size() / 2 - 1], V[V.size() / 2]);

    cout << "Результат для вектора (после): ";
    for (int v : V) {
        cout << v << " ";
    }
    cout << endl;

    // Задание дека
    deque<int> D = { 10, 20, 30, 40, 50, 60 };
    cout << "Результат для дека (до): ";
    for (int d : D) {
        cout << d << " ";
    }
    cout << endl;
    swap(D[D.size() / 2 - 1], D[D.size() / 2]);

    cout << "Результат для дека (после): ";
    for (int d : D) {
        cout << d << " ";
    }
    cout << endl;

    // Задание списка
    list<int> L = { 100, 200, 300, 400, 500, 600 };
    cout<< "Результат для списка до: ";
    for (int l : L) {
        cout << l << " ";
    }
    cout << endl;

    auto it1 = next(L.begin(), L.size() / 2 - 1);
    auto it2 = next(L.begin(), L.size() / 2);
    swap(*it1, *it2);

    cout << "Результат для списка после: ";
    for (int l : L) {
        cout << l << " ";
    }
    cout << endl;
}
// Функция добавления пяти средних элементов в начало дека
void add_middle_elements_to_front(deque<int>& D) {
    int N = D.size();
    // Найдем индекс среднего элемента
    int mid_index = N / 2;
    // Вставляем 5 средних элементов в начало
    D.insert(D.begin(), D.begin() + mid_index - 2, D.begin() + mid_index + 3);
}
// Функция для ввода элементов от пользователя
deque<int> input_deque() {
    deque<int> D;
    int N;
    cout << "Введите количество элементов дека (N >= 5 и должно быть нечетным): ";
    cin >> N;
    if (N < 5 || N % 2 == 0) {
        cerr << "Ошибка: количество элементов должно быть нечетным и не менее 5." << endl;
        exit(1);
    }
    cout << "Введите " << N << " элементов дека:" << endl;
    for (int i = 0; i < N; ++i) {
        int element;
        cin >> element;
        D.push_back(element);
    }
    return D;
}
// Функция для вывода дека
void print_deque(const deque<int>& D, const string& message) {
    cout << message;
    for (int elem : D) {
        cout << elem << " ";
    }
    cout << endl;
}
//3 задача
void reorder_list(list<int>& L) {
    auto i = L.begin();
    auto r = prev(L.end());  // Устанавливаем r на последний элемент

    int N = L.size();  // Размер списка должен быть четным

    // Цикл выполняется N / 2 раз
    for (int count = 0; count < N / 2; ++count) {
        // Сдвигаем элемент r на позицию перед i
        L.splice(i, L, r);

        // После вставки сдвигаем итератор r на новую позицию (r сдвигается на предыдущий элемент)
        r = prev(L.end());

        // Продвигаем i на следующую позицию после вставки
        advance(i, 1);

        // Если итераторы пересекаются, цикл завершается
        if (distance(i, r) <= 0) {
            break;
        }
    }
}
// Функция для вывода списка
void print_list(const list<int>& L, const string& message) {
    cout << message;
    for (int elem : L) {
        cout << elem << " ";
    }
    cout << endl;
}
// Функция для ввода списка
list<int> input_list() {
    list<int> L;
    int N;
    cout << "Введите количество элементов списка (четное число): ";
    cin >> N;

    if (N % 2 != 0) {
        cerr << "Ошибка: количество элементов должно быть четным." << endl;
        exit(1);
    }

    cout << "Введите " << N << " элементов списка:" << endl;
    for (int i = 0; i < N; ++i) {
        int element;
        cin >> element;
        L.push_back(element);
    }
    return L;
}
void printOddIndexedNumbers(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Ошибка открытия файла!" << endl;
        return;
    }

    vector<int> numbers;
    int number;

    // Считываем числа из файла
    while (inputFile >> number) {
        numbers.push_back(number);
    }
    inputFile.close();

    // Выводим числа с нечетными порядковыми номерами
    for (size_t i = 0; i < numbers.size(); i++) {
        if (i % 2 == 0) { // Нечетные порядковые номера (1-е, 3-е, ...)
            cout << numbers[i] << " ";
        }
    }
    cout << endl;
}

// Функция для вывода вектора
void printVector(const vector<int>& V) {
    for (int num : V) {
        cout << num << " ";
    }
    cout << endl;
}

void removeSecondZero(vector<int>& V) {
    // Ищем первый ноль
    auto firstZero = find(V.begin(), V.end(), 0);

    // Проверяем, найден ли первый ноль
    if (firstZero != V.end()) {
        // Ищем второй ноль, начиная с позиции после первого
        auto secondZero = find(firstZero + 1, V.end(), 0);

        // Если второй ноль найден
        if (secondZero != V.end()) {
            // Удаляем второй ноль
            V.erase(secondZero);
        }
    }
}
// 6 задача 
// Функциональный объект для замены отрицательных чисел на -1
struct ReplaceNegative {
    bool operator()(int value) const {
        return value < 0;
    }
};

// Функциональный объект для замены положительных чисел на 1
struct ReplacePositive {
    bool operator()(int value) const {
        return value > 0;
    }
};

// Функция для обработки вектора
void processVector(vector<int>& V) {
    size_t halfSize = V.size() / 2;

    // Замена отрицательных чисел на -1 в первой половине вектора
    replace_if(V.begin(), V.begin() + halfSize, ReplaceNegative(), -1);

    // Замена положительных чисел на 1 во второй половине вектора
    replace_if(V.begin() + halfSize, V.end(), ReplacePositive(), 1);
}
// Функциональный объект для определения отрицательных чисел
struct IsNegative {
    bool operator()(int value) const {
        return value < 0;
    }
};

// Функциональный объект для определения нулевых чисел
struct IsZero {
    bool operator()(int value) const {
        return value == 0;
    }
};

// Функция для перегруппировки элементов списка
void rearrangeList(list<int>& L) {
    // Сначала перемещаем отрицательные элементы в начало
    auto it = stable_partition(L.begin(), L.end(), IsNegative());

    // Затем перемещаем нулевые элементы за отрицательные
    stable_partition(it, L.end(), IsZero());
}

vector<double> calculate_averages(const list<int>& L) {
    vector<double> V;

    // Используем adjacent_difference для вычисления разности соседних элементов,
    // а затем выводим среднее арифметическое
    adjacent_difference(L.begin(), L.end(), back_inserter(V),
        [](int a, int b) { return (a + b) / 2.0; });

    // Удаляем первый элемент вектора, так как adjacent_difference сохраняет первый элемент исходным
    V.erase(V.begin());

    return V;
}

// Функция, которая вызывает решение
void solve() {
    // Пример списка L
    list<int> L = { 1, 3, 4, 6 };
    print_list(L, "Список: ");
    // Вызываем функцию для вычисления среднего арифметического соседних элементов
    vector<double> result = calculate_averages(L);

    // Выводим результат
    cout << "Вектор средних арифметических: ";
    for (double x : result) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    int num_zad;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Введите число от 1 до 10 чтобы выбрать задачу:\n";
    cin >> num_zad;

    switch (num_zad) {
    case 1:
        cout << "Задача 1: Обмен средних элементов вектора, дека и списка.\n";
        swapMiddleElements();
        break;
    case 2: {
        cout << "Задача 2: Вставка средних элементов дека в начало.\n";
        // Ввод дека
        deque<int> D = input_deque();

        // Вывод дека до изменения
        print_deque(D, "Дек до изменения: ");

        // Вставка средних элементов
        add_middle_elements_to_front(D);

        // Вывод дека после изменения
        print_deque(D, "Дек после добавления 5 средних элементов в начало: ");
    }
        break;
    case 3: {
        cout << "Задача 3: Перемещение элементов списка.\n";
        // Ввод списка
        list<int> L = input_list();

        // Вывод списка до изменения
        print_list(L, "Список до изменения: ");

        // Изменение порядка элементов
        reorder_list(L);

        // Вывод списка после изменения
        print_list(L, "Список после изменения: ");
    }
        break;

    case 4:
        { 
        cout << "Задача 4: Вывод чисел с нечетными индексами из файла.\n";
            printOddIndexedNumbers("name.txt"); }
        break;
    case 5:
        {
        cout << "Задача 5: Удаление второго нуля из вектора.\n";
        vector<int> V = { 1, 0, 2, 0, 3, 0, 4 }; // Пример вектора
        cout << "Исходный вектор: ";
        printVector(V);
        removeSecondZero(V);
        cout << "Вектор после удаления второго нуля: ";
        printVector(V);
    }
        break;
    case 6:
    {
        cout << "Задача 6: Обработка положительных и отрицательных чисел вектора.\n";
        vector<int> V = { 3, -2, 5, -1, -3, 6, 0, 2 };
        cout << "Вектор до изменений ";
        printVector(V);
        // Обработка вектора
        processVector(V);
        // Вывод измененного вектора
        cout << "Вектор после изменений ";
        printVector(V);
        }

        break;
    case 7:
    {
        cout << "Задача 7: Перегруппировка списка.\n";
        list<int> L = { 3, -1, 0, 2, -3, 0, 4, -2 };
        print_list(L, "Список до изменения: ");
        // Перегруппировка элементов списка
        rearrangeList(L);

        // Вывод измененного списка
        print_list(L, "Список до изменения: ");
    }

        break;
    case 8:
    {
        cout << "Задача 8: Вычисление средних арифметических соседних элементов списка.\n";
            solve(); }

        break;
    case 9:
    {}

        break;
    case 10:
    {}
        break;
    default:
        cout << "Неверный номер задачи.\n";
    }
    return 0;
}
