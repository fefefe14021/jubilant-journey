#include "Classes.h"

// Реализация методов класса Point
Point::Point(double xCoord, double yCoord) : x(xCoord), y(yCoord) {}

string Point::toString() const {
    stringstream ss;
    ss << "{" << x << ";" << y << "}";
    return ss.str();
}

double Point::distanceTo(const Point& other) const {
    return sqrt(pow(other.x - x, 2) + pow(other.y - y, 2));
}

void Point::shift(double deltaX, double deltaY) {
    x += deltaX;
    y += deltaY;
}

// Реализация методов класса Name
Name::Name(optional<string> s, optional<string> f, optional<string> m)
    : surname(s), firstName(f), middleName(m) {}

string Name::toString() const {
    string result;
    if (surname.has_value()) result += *surname + " ";
    if (firstName.has_value()) result += *firstName + " ";
    if (middleName.has_value()) result += *middleName;

    if (!result.empty() && result.back() == ' ') {
        result.pop_back();
    }
    return result;
}

bool Name::isValidName(const string& name) {
    regex namePattern("^[А-Яа-яA-Za-z ]+$");
    return !name.empty() && regex_match(name, namePattern);
}

optional<string> Name::getSurname() const { return surname; }
optional<string> Name::getFirstName() const { return firstName; }
optional<string> Name::getMiddleName() const { return middleName; }

// Реализация методов класса Human
Human::Human(const Name& n, int h, optional<Human*> f)
    : name(n), height(h), father(f) {
    updateName();
}

void Human::updateName() {
    if (!name.getSurname().has_value() && father.has_value() && (*father)->name.getSurname().has_value()) {
        name = Name((*father)->name.getSurname(), name.getFirstName(), name.getMiddleName());
    }
    if (!name.getMiddleName().has_value() && father.has_value() && (*father)->name.getFirstName().has_value()) {
        string fatherFirstName = *(*father)->name.getFirstName();
        name = Name(name.getSurname(), name.getFirstName(), fatherFirstName + "ович");
    }
}

string Human::toString() const {
    return name.toString() + " и ростом " + to_string(height);
}

// Реализация методов класса BrokenLine
BrokenLine::BrokenLine() = default;

BrokenLine::BrokenLine(const vector<Point>& pts) : points(pts) {}

void BrokenLine::addPoints(const vector<Point>& newPoints) {
    points.insert(points.end(), newPoints.begin(), newPoints.end());
}

double BrokenLine::length() const {
    double totalLength = 0;
    for (size_t i = 0; i < points.size() - 1; ++i) {
        totalLength += points[i].distanceTo(points[i + 1]);
    }
    return totalLength;
}

string BrokenLine::toString() const {
    stringstream ss;
    ss << "Линия [";
    for (size_t i = 0; i < points.size(); ++i) {
        ss << points[i].toString();
        if (i < points.size() - 1) ss << ", ";
    }
    ss << "]";
    return ss.str();
}

void BrokenLine::shift(double deltaX, double deltaY) {
    for (auto& point : points) {
        point.shift(deltaX, deltaY);
    }
}

const Point& BrokenLine::firstPoint() const {
    return points.front();
}

const Point& BrokenLine::lastPoint() const {
    return points.back();
}

// Функция для ввода высоты
int inputHeight() {
    int height;
    while (true) {
        cout << "Введите рост (целое число): ";
        cin >> height;
        if (cin.fail() || height <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Некорректный ввод. Пожалуйста, введите положительное целое число." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }
    return height;
}
