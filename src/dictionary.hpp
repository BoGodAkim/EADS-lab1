#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

#include "sequence.hpp"

template <typename Key, typename Info>
class Dictionary
{
private:
    Sequence<Key, Info> sequence;

public:
    Dictionary();
    Dictionary(const Dictionary<Key, Info> &other);
    ~Dictionary();
    void insert(const Key &key, const Info &value);
    void operator=(const Dictionary<Key, Info> &other);
    Info &operator[](const Key &key);
    const Info &operator[](const Key &key) const;
    void remove(const Key &key);
    void clear();
    bool has(const Key &key) const;
    unsigned int size() const;

    class Iterator
    {
    private:
        typename Sequence<Key, Info>::Iterator current;

        Iterator(typename Sequence<Key, Info>::Iterator current);

    public:
        Iterator();
        Iterator &operator++();
        Iterator operator++(int);
        bool operator==(const Iterator &other) const;
        bool operator!=(const Iterator &other) const;
        std::pair<const Key &, const Info &> operator*() const;
        std::pair<const Key &, Info &> operator*();

        friend class Dictionary;
    };
    Iterator begin() const;
    Iterator end() const;
};

#endif // DICTIONARY_HPP