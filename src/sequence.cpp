#include "sequence.hpp"

using namespace std;

namespace CHECK
{
    struct No
    {
    };
    template <typename T, typename Arg>
    No operator==(const T &, const Arg &);

    template <typename T, typename Arg = T>
    struct EqualExists
    {
        enum
        {
            value = !std::is_same<decltype(*(T *)(0) == *(Arg *)(0)), No>::value
        };
    };
}

template <typename Key, typename Info>
Sequence<Key, Info>::Node::Node(Key key, Info value, Node *next)
{
    this->key = key;
    this->value = value;
    this->next = next;
}

template <typename Key, typename Info>
void Sequence<Key, Info>::checkTemplateOnOperators() const
{
    if (!CHECK::EqualExists<Key, Key>::value)
    {
        throw "Key does not have operator==";
    }
    if (!CHECK::EqualExists<Info, Info>::value)
    {
        throw "Info does not have operator==";
    }
}

template <typename Key, typename Info>
Sequence<Key, Info>::Sequence()
{
    checkTemplateOnOperators();
    head = nullptr;
    tail = nullptr;
    length = 0;
}

template <typename Key, typename Info>
Sequence<Key, Info>::Sequence(const Sequence<Key, Info> &other)
{
    checkTemplateOnOperators();
    head = nullptr;
    tail = nullptr;
    length = 0;
    Node *current = other.head;
    while (current != nullptr)
    {
        push_back(current->key, current->value);
        current = current->next;
    }
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
typename std::pair<typename Sequence<Key, Info>::Node *, typename Sequence<Key, Info>::Node *>
Sequence<Key, Info>::find(const Key &key, unsigned int occurrence) const
{
    if (occurrence < 0)
    {
        throw "Occurrence must be non-negative";
    }
    Node *current = head;
    Node *previous = nullptr;
    unsigned int count = 0;
    while (current != nullptr)
    {
        if (current->key == key)
        {
            if (count == occurrence)
            {
                return make_pair(previous, current);
            }
            count++;
        }
        previous = current;
        current = current->next;
    }
    return make_pair(nullptr, nullptr);
}

template <typename Key, typename Info>
void Sequence<Key, Info>::push_back(const Key &key, const Info &value)
{
    Node *newNode = new Node(key, value, nullptr);
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    length++;
}

template <typename Key, typename Info>
void Sequence<Key, Info>::push_front(const Key &key, const Info &value)
{
    Node *newNode = new Node(key, value, head);
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        head = newNode;
    }
    length++;
}

template <typename Key, typename Info>
void Sequence<Key, Info>::insert(const Key &key, const Info &value, const Key &after, unsigned int occurrence)
{
    Node *current = find(after, occurrence).second;
    if (current == nullptr)
    {
        throw "Key not found";
    }
    else
    {
        Node *temp = current->next;
        current->next = new Node(key, value, temp);
        length++;
        if (temp == nullptr)
        {
            tail = current->next;
        }
    }
}

template <typename Key, typename Info>
const Info &Sequence<Key, Info>::operator[](const Key &key) const
{
    Node *current = find(key).second;
    if (current == nullptr)
    {
        throw "Key not found";
    }
    else
    {
        return current->value;
    }
}

template <typename Key, typename Info>
Info &Sequence<Key, Info>::operator[](const Key &key)
{
    Node *current = find(key).second;
    if (current == nullptr)
    {
        throw "Key not found";
    }
    else
    {
        return current->value;
    }
}

template <typename Key, typename Info>
const Info &Sequence<Key, Info>::operator()(const Key &key, unsigned int occurrence) const
{
    Node *current = find(key, occurrence).second;
    if (current == nullptr)
    {
        throw "Key not found";
    }
    else
    {
        return current->value;
    }
}

template <typename Key, typename Info>
Info &Sequence<Key, Info>::operator()(const Key &key, unsigned int occurrence)
{
    Node *current = find(key, occurrence).second;
    if (current == nullptr)
    {
        throw "Key not found";
    }
    else
    {
        return current->value;
    }
}

template <typename Key, typename Info>
Sequence<Key, Info> &Sequence<Key, Info>::operator=(const Sequence<Key, Info> &other)
{
    Node *current = head;
    while (current != nullptr)
    {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
    length = 0;
    current = other.head;
    while (current != nullptr)
    {
        push_back(current->key, current->value);
        current = current->next;
    }
    return *this;
}

template <typename Key, typename Info>
bool Sequence<Key, Info>::operator==(const Sequence<Key, Info> &other) const
{
    if (length != other.length)
    {
        return false;
    }
    Node *current = head;
    Node *otherCurrent = other.head;
    while (current != nullptr)
    {
        if (!(current->key == otherCurrent->key) || !(current->value == otherCurrent->value))
        {
            return false;
        }
        current = current->next;
        otherCurrent = otherCurrent->next;
    }
    return true;
}

template <typename Key, typename Info>
void Sequence<Key, Info>::remove(const Key &key, unsigned int occurrence)
{
    pair<Node *, Node *> result = find(key, occurrence);
    Node *previous = result.first;
    Node *current = result.second;

    if (current == nullptr)
    {
        throw "Key not found";
    }
    else
    {
        if (previous == nullptr)
        {
            head = current->next;
        }
        else
        {
            previous->next = current->next;
        }

        if (current == tail)
        {
            tail = previous;
        }
        delete current;
        length--;
    }
}

template <typename Key, typename Info>
unsigned int Sequence<Key, Info>::occurrences(const Key &key) const
{
    Node *current = head;
    unsigned int count = 0;
    while (current != nullptr)
    {
        if (current->key == key)
        {
            count++;
        }
        current = current->next;
    }
    return count;
}

template <typename Key, typename Info>
bool Sequence<Key, Info>::has(const Key &key) const
{
    return find(key).second != nullptr;
}

template <typename Key, typename Info>
unsigned int Sequence<Key, Info>::size() const
{
    return length;
}

template <typename Key, typename Info>
typename Sequence<Key, Info>::Iterator Sequence<Key, Info>::begin() const
{
    return Iterator(head);
}

template <typename Key, typename Info>
typename Sequence<Key, Info>::Iterator Sequence<Key, Info>::end() const
{
    return Iterator(nullptr);
}

template <typename Key, typename Info>
Sequence<Key, Info>::Iterator::Iterator(Node *node)
{
    current = node;
}

template <typename Key, typename Info>
Sequence<Key, Info>::Iterator::Iterator()
{
    current = nullptr;
}

template <typename Key, typename Info>
typename Sequence<Key, Info>::Iterator &Sequence<Key, Info>::Iterator::operator++()
{
    if (current != nullptr)
    {
        current = current->next;
    }
    return *this;
}

template <typename Key, typename Info>
typename Sequence<Key, Info>::Iterator Sequence<Key, Info>::Iterator::operator++(int)
{
    Iterator temp = *this;
    if (current != nullptr)
    {
        current = current->next;
    }
    return temp;
}

template <typename Key, typename Info>
bool Sequence<Key, Info>::Iterator::operator==(const Iterator &other) const
{
    return current == other.current;
}

template <typename Key, typename Info>
bool Sequence<Key, Info>::Iterator::operator!=(const Iterator &other) const
{
    return current != other.current;
}

template <typename Key, typename Info>
void Sequence<Key, Info>::Iterator::operator=(const Iterator &other)
{
    current = other.current;
}

template <typename Key, typename Info>
pair<const Key &, const Info &> Sequence<Key, Info>::Iterator::operator*() const
{
    if (current == nullptr)
    {
        return pair<const Key &, const Info &>();
    }
    else
    {
        return pair<const Key &, Info &>(current->key, current->value);
    }
}

template <typename Key, typename Info>
pair<const Key &, Info &> Sequence<Key, Info>::Iterator::operator*()
{
    if (current == nullptr)
    {
        Key key;
        Info info;
        return pair<const Key &, Info &>(key, info);
    }
    else
    {
        return pair<const Key &, Info &>(current->key, current->value);
    }
}