#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

template <typename Key, typename Info>
class Sequence{
private:
    struct Node{
        Key key;
        Info value;
        Node *next;
        Node(Key key, Info value, Node *next);
    };
    Node *head;
    int length;
    Node* find(const Key& key, int occurrence = 0) const;
    
public:
    Sequence();
    Sequence(Key key, Info value);
    Sequence(const Sequence<Key,Info> &other);
    ~Sequence();
    void insert(const Key& key, const Info& value, const Key& after = nullptr, int occurrence = 0);
    Info& operator[](const Key& key, int occurrence = 0) const;
    void remove(const Key& key, int occurrence = 0);
    int occurrences(const Key& key) const;
    bool has(const Key& key) const;
    int size() const;

    class Iterator
    {
    private:
        Node *current;
    public:
        Iterator(Sequence<Key, Info> *list);
        Iterator(Iterator &other);
        Iterator &operator++();
        Iterator &operator++(int);
        bool operator==(const Iterator &other) const;
        bool operator!=(const Iterator &other) const;
        void operator=(const Iterator &other);
        pair<Key, Info> &operator*() const;
    };
    Iterator& begin();
};

template <typename Key, typename Info>
class Map
{
private:
    

public:
    Map();
    Map(const Map<Key, Info> &other);
    ~Map();
    void operator=(const Map<Key, Info> &other);
    Info &operator[](const Key &key) const;
    bool has(const Key &key) const;
};

template <typename Key, typename Info>
Sequence<Key, Info>::Sequence()
{
    head = nullptr;
    length = 0;
}

template <typename Key, typename Info>
Sequence<Key, Info>::Sequence(Key key, Info value)
{
    head = new Node(key, value, nullptr);
    length = 1;
}

template <typename Key, typename Info>
Sequence<Key, Info>::Sequence(const Sequence<Key,Info> &other)
{
    head = new Node(other.head->key, other.head->value, nullptr);
    Node *current = head;
    Node *otherCurrent = other.head;
    while (otherCurrent->next != nullptr)
    {
        current->next = new Node(otherCurrent->next->key, otherCurrent->next->value, nullptr);
        current = current->next;
        otherCurrent = otherCurrent->next;
    }
    length = other.length;
}

template <typename Key, typename Info>
Sequence<Key, Info>::~Sequence()
{
    Node *current = head;
    while (current != nullptr)
    {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
}

template <typename Key, typename Info>
Sequence<Key,Info>::Node* Sequence<Key, Info>::find(const Key& key, int occurrence = 0) const
{
    Node *current = head;
    int counter = 0;
    while (current != nullptr)
    {
        if (current->key == key)
        {
            if (counter == occurrence)
            {
                return current;
            }
            counter++;
        }
        current = current->next;
    }
    return nullptr;
}

template <typename Key, typename Info>
void Sequence<Key, Info>::insert(const Key& key, const Info& value, const Key& after = nullptr, int occurrence = 0)
{
    if (after == nullptr)
    {
        head = new Node(key, value, head);
        length++;
        return;
    }
    Node *current = find(after, occurrence);
    if (current == nullptr)
    {
        throw "Key not found";
    }
    current->next = new Node(key, value, current->next);
    length++;
}