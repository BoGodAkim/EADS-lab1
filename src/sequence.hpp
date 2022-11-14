#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP

#include <bits/stdc++.h>
using namespace std;

template <typename Key, typename Info>
class Sequence
{
private:

    struct Node
    {
        Key key;
        Info value;
        Node *next;
        Node(Key key, Info value, Node *next);
    };

    Node *head;
    Node *tail;
    int length;
    pair<Node *, Node *> find(const Key &key, int occurrence = 0) const;
    void checkTemplateOnOperators() const;

public:

    Sequence();
    Sequence(const Sequence<Key, Info> &other);
    ~Sequence();
    void insert(const Key &key, const Info &value);
    void insert(const Key &key, const Info &value, const Key &after, int occurrence = 0);
    Info &operator[](const Key &key) const;
    Info &operator()(const Key &key, int occurrence = 0) const;
    bool operator==(const Sequence<Key, Info> &other) const;
    void remove(const Key &key, int occurrence = 0);
    int occurrences(const Key &key) const;
    bool has(const Key &key) const;
    int size() const;

    class Iterator
    {
    private:
        Node *current;

        Iterator(Node *current);

    public:
        Iterator(Iterator &other);
        Iterator &operator++();
        Iterator &operator++(int);
        bool operator==(const Iterator &other) const;
        bool operator!=(const Iterator &other) const;
        void operator=(const Iterator &other);
        pair<Key, Info> &operator*() const;
        
    };

    Iterator begin() const;
    Iterator end() const;
};

#endif // SEQUENCE_HPP