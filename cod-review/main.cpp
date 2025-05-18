#include <iostream>
#include <limits>
#include "name.h"
#include "human.h"
#include "broken_line.h"

int InputHeight() {
  int height;
  while (true) {
    std::cout << "Введите рост (целое число): ";
    std::cin >> height;
    if (std::cin.fail() || height <= 0) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Некорректный ввод. Пожалуйста, введите положительное целое число." << std::endl;
    } else {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      break;
    }
  }
  return height;
}

void Task1() {
  Name cleopatra_name(std::nullopt, "Клеопатра", std::nullopt);
  Name pushkin_name("Пушкин", "Александр", "Сергеевич");
  Name mayakovsky_name("Маяковский", "Владимир", std::nullopt);

  std::cout << cleopatra_name.ToString() << std::endl;
  std::cout << pushkin_name.ToString() << std::endl;
  std::cout << mayakovsky_name.ToString() << std::endl;
}

void Task2() {
  Name name("Пушкин", "Александр", "Сергеевич");
  int height = InputHeight();
  Human pushkin(name, height);
  std::cout << pushkin.ToString() << std::endl;
}

void Task3() {
  Human ivan(Name("Чудов", "Иван", std::nullopt), 180);
  Human petya(Name("Чудов", "Петр", std::nullopt), 175, &ivan);
  Human boris(std::nullopt, "Борис", std::nullopt), 170, &petya;

  std::cout << ivan.ToString() << std::endl;
  std::cout << petya.ToString() << std::endl;
  std::cout << boris.ToString() << std::endl;
}

void Task4() {
  BrokenLine line1({Point(1, 5), Point(2, 8), Point(5, 3)});
  std::cout << "Первая ломаная: " << line1.ToString() << std::endl;

  BrokenLine line2({line1.FirstPoint(), Point(2, -5), Point(4, -8), line1.LastPoint()});
  std::cout << "Вторая ломаная: " << line2.ToString() << std::endl;

  line1.Shift(1, 1);
  line2.Shift(1, 1);

  std::cout << "Первая после сдвига: " << line1.ToString() << std::endl;
  std::cout << "Вторая после сдвига: " << line2.ToString() << std::endl;
}

void Task5() {
  BrokenLine empty_line;
  std::cout << "Пустая ломаная: " << empty_line.ToString() << std::endl;

  BrokenLine line({Point(1, 1), Point(2, 2)});
  std::cout << "Ломаная с точками: " << line.ToString() << std::endl;
}

void Task6() {
  BrokenLine line({Point(1, 5), Point(2, 8), Point(5, 3)});
  std::cout << "Длина: " << line.Length() << std::endl;

  line.AddPoints({Point(5, 15), Point(8, 10)});
  std::cout << "После добавления: " << line.ToString() << std::endl;
  std::cout << "Новая длина: " << line.Length() << std::endl;
}

int main() {
  int choice;
  do {
    std::cout << "\nВыберите задачу (1-6, 0 для выхода): ";
    std::cin >> choice;

    if (std::cin.fail() || choice < 0 || choice > 6) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Некорректный ввод. Попробуйте снова." << std::endl;
      continue;
    }

    switch (choice) {
      case 1: Task1(); break;
      case 2: Task2(); break;
      case 3: Task3(); break;
      case 4: Task4(); break;
      case 5: Task5(); break;
      case 6: Task6(); break;
      case 0: std::cout << "Выход..." << std::endl; break;
    }
  } while (choice != 0);

  return 0;
}
