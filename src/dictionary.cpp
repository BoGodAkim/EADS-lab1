#include "dictionary.hpp"

template <typename Key, typename Info>
Dictionary<Key, Info>::Dictionary()
{
    sequence = new Sequence<Key, Info>();
}

template <typename Key, typename Info>
Dictionary<Key, Info>::Dictionary(const Dictionary<Key, Info> &other)
{
    sequence = new Sequence<Key, Info>(*other.sequence);
}

template <typename Key, typename Info>
Dictionary<Key, Info>::~Dictionary()
{
    delete sequence;
}

template <typename Key, typename Info>
void Dictionary<Key, Info>::insert(const Key &key, const Info &value)
{
    if(sequence->has(key))
    {
        throw "Key already exists";
    }
    sequence->insert(key, value);
}

template <typename Key, typename Info>
void Dictionary<Key, Info>::operator=(const Dictionary<Key, Info> &other)
{
    delete sequence;
    sequence = new Sequence<Key, Info>(*other.sequence);
}

template <typename Key, typename Info>
Info &Dictionary<Key, Info>::operator[](const Key &key) const
{
    if(!sequence->has(key))
    {
        sequence->insert(key, Info());
    }
    return sequence[key];
}

template <typename Key, typename Info>
void Dictionary<Key, Info>::remove(const Key &key)
{
    sequence->remove(key);
}

template <typename Key, typename Info>
void Dictionary<Key, Info>::clear()
{
    delete sequence;
    sequence = new Sequence<Key, Info>();
}

template <typename Key, typename Info>
bool Dictionary<Key, Info>::has(const Key &key) const
{
    return sequence->has(key);
}

template <typename Key, typename Info>
int Dictionary<Key, Info>::size() const
{
    return sequence->size();
}

template <typename Key, typename Info>
typename Sequence<Key, Info>::Iterator Dictionary<Key, Info>::begin() const
{
    return sequence->begin();
}

template <typename Key, typename Info>
typename Sequence<Key, Info>::Iterator Dictionary<Key, Info>::end() const
{
    return sequence->end();
}