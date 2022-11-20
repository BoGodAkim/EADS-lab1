#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP

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
    unsigned int length;
    std::pair<Node *, Node *> find(const Key &key, unsigned int occurrence = 0) const;
    void checkTemplateOnOperators() const;

public:
    Sequence();
    Sequence(const Sequence<Key, Info> &other);
    ~Sequence();
    void push_back(const Key &key, const Info &value);
    void push_front(const Key &key, const Info &value);
    void insert(const Key &key, const Info &value, const Key &after, unsigned int occurrence = 0);
    const Info &operator[](const Key &key) const;
    Info &operator[](const Key &key);
    const Info &operator()(const Key &key, unsigned int occurrence = 0) const;
    Info &operator()(const Key &key, unsigned int occurrence = 0);
    Sequence<Key, Info> &operator=(const Sequence<Key, Info> &other);
    bool operator==(const Sequence<Key, Info> &other) const;
    void remove(const Key &key, unsigned int occurrence = 0);
    unsigned int occurrences(const Key &key) const;
    bool has(const Key &key) const;
    unsigned int size() const;

    class Iterator
    {
    private:
        Node *current;

        Iterator(Node *current);

    public:
        Iterator();
        Iterator &operator++();
        Iterator operator++(int);
        bool operator==(const Iterator &other) const;
        bool operator!=(const Iterator &other) const;
        std::pair<const Key &, const Info &> operator*() const;
        std::pair<const Key &, Info &> operator*();

        friend class Sequence;
    };

    Iterator begin() const;
    Iterator end() const;
};

#endif // SEQUENCE_HPP