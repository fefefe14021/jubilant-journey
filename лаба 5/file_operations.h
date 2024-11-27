#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include <string>

// Объявление функций для работы с файлами
void fillBinaryFile(const std::string& filename, int count);  // Заполнение бинарного файла
void fillTextFile(const std::string& filename, int count);  // Заполнение текстового файла
void fillBinaryFileWithStructs(const std::string& filename, int count);  // Заполнение бинарного файла с игрушками
void fillTextFileWithText(const std::string& filename, int count);  // Заполнение текстового файла текстом

#endif // FILE_OPERATIONS_H

