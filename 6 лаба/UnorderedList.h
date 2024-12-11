#ifndef UNORDERED_LIST_H
#define UNORDERED_LIST_H

#include <set>
#include <iostream>

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

#endif
