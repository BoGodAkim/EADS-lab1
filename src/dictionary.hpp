#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

#include <bits/stdc++.h>
#include "sequence.hpp"
using namespace std;

template <typename Key, typename Info>
class Dictionary
{
private:
    Sequence<Key, Info> *sequence;

public:
    Dictionary();
    Dictionary(const Dictionary<Key, Info> &other);
    ~Dictionary();
    void insert(const Key &key, const Info &value);
    void operator=(const Dictionary<Key, Info> &other);
    Info &operator[](const Key &key) const;
    void remove(const Key &key);
    void clear();
    bool has(const Key &key) const;
    int size() const;
    typename Sequence<Key, Info>::Iterator begin() const;
    typename Sequence<Key, Info>::Iterator end() const;

};

#endif // DICTIONARY_HPP