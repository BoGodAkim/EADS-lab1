#include "dictionary.hpp"

using namespace std;

template <typename Key, typename Info>
Dictionary<Key, Info>::Dictionary()
{
    sequence = Sequence<Key, Info>();
}

template <typename Key, typename Info>
Dictionary<Key, Info>::Dictionary(const Dictionary<Key, Info> &other)
{
    sequence = Sequence<Key, Info>(other.sequence);
}

template <typename Key, typename Info>
Dictionary<Key, Info>::~Dictionary()
{
}

template <typename Key, typename Info>
void Dictionary<Key, Info>::insert(const Key &key, const Info &value)
{
    if (sequence.has(key))
    {
        throw logic_error("Key already exists");
    }
    sequence.push_back(key, value);
}

template <typename Key, typename Info>
void Dictionary<Key, Info>::operator=(const Dictionary<Key, Info> &other)
{
    sequence = Sequence<Key, Info>(other.sequence);
}

template <typename Key, typename Info>
const Info &Dictionary<Key, Info>::operator[](const Key &key) const
{
    if (!sequence.has(key))
    {
        sequence.push_back(key, Info());
    }
    return sequence[key];
}

template <typename Key, typename Info>
Info &Dictionary<Key, Info>::operator[](const Key &key)
{
    if (!sequence.has(key))
    {
        sequence.push_back(key, Info());
    }
    return sequence[key];
}

template <typename Key, typename Info>
void Dictionary<Key, Info>::remove(const Key &key)
{
    sequence.remove(key);
}

template <typename Key, typename Info>
void Dictionary<Key, Info>::clear()
{
    sequence = Sequence<Key, Info>();
}

template <typename Key, typename Info>
bool Dictionary<Key, Info>::has(const Key &key) const
{
    return sequence.has(key);
}

template <typename Key, typename Info>
unsigned int Dictionary<Key, Info>::size() const
{
    return sequence.size();
}

template <typename Key, typename Info>
Dictionary<Key, Info>::Iterator::Iterator(typename Sequence<Key, Info>::Iterator current)
{
    this->current = current;
}

template <typename Key, typename Info>
Dictionary<Key, Info>::Iterator::Iterator()
{
    current = typename Sequence<Key, Info>::Iterator();
}

template <typename Key, typename Info>
typename Dictionary<Key, Info>::Iterator &Dictionary<Key, Info>::Iterator::operator++()
{
    ++current;
    return *this;
}

template <typename Key, typename Info>
typename Dictionary<Key, Info>::Iterator Dictionary<Key, Info>::Iterator::operator++(int)
{
    Iterator temp = *this;
    ++current;
    return temp;
}

template <typename Key, typename Info>
bool Dictionary<Key, Info>::Iterator::operator==(const Iterator &other) const
{
    return current == other.current;
}

template <typename Key, typename Info>
bool Dictionary<Key, Info>::Iterator::operator!=(const Iterator &other) const
{
    return current != other.current;
}

template <typename Key, typename Info>
pair<const Key &, const Info &> Dictionary<Key, Info>::Iterator::operator*() const
{
    return *current;
}

template <typename Key, typename Info>
pair<const Key &, Info &> Dictionary<Key, Info>::Iterator::operator*()
{
    return *current;
}

template <typename Key, typename Info>
typename Dictionary<Key, Info>::Iterator Dictionary<Key, Info>::begin() const
{
    return Iterator(sequence.begin());
}

template <typename Key, typename Info>
typename Dictionary<Key, Info>::Iterator Dictionary<Key, Info>::end() const
{
    return Iterator(sequence.end());
}
