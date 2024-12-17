#ifndef UNORDEREDLIST_H
#define UNORDEREDLIST_H

#include <iostream>
#include <set>

// Шаблонный класс для набора уникальных элементов
template <typename T>
class UnorderedList {
private:
    std::set<T> data;

public:
    void Add(T value);
    bool Contains(T value) const;
    void Union(const UnorderedList<T>& other);
    UnorderedList<T> Intersect(const UnorderedList<T>& other) const;
    void Print() const;
};

#include "UnorderedList.inl"
#endif
