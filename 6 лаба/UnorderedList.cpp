#include "UnorderedList.h"

template <typename T>
void UnorderedList<T>::Add(T value) {
    data.insert(value);
}

template <typename T>
bool UnorderedList<T>::Contains(T value) const {
    return data.find(value) != data.end();
}

template <typename T>
void UnorderedList<T>::Union(const UnorderedList<T>& other) {
    data.insert(other.data.begin(), other.data.end());
}

template <typename T>
UnorderedList<T> UnorderedList<T>::Intersect(const UnorderedList<T>& other) const {
    UnorderedList<T> result;
    for (const auto& elem : data) {
        if (other.Contains(elem)) {
            result.Add(elem);
        }
    }
    return result;
}

template <typename T>
void UnorderedList<T>::Print() const {
    for (const auto& elem : data) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

// Не забываем инстанцировать шаблон для нужных типов
template class UnorderedList<std::string>;
