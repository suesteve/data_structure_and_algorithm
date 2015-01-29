#ifndef LIST_H_
#define LIST_H_

template <typename Object>
class List {
private:
    struct Node {
        Object data;
        Node* prev;
        Node* next;

        Node(const Object& d = Object(), Node* p = nullptr, Node* n = nullptr) :
                data(d), prev(p), next(n)
        {}
    };

public:
    class const_iterator {
    public:
        const_iterator() :
                current_(nullptr)
        {}

    protected:
        Node* current_;

        // retrieve the data of the curernt node
        Object& retrieve() const
        {
            return current_->data;
        }

        const_iterator(Node* p) :
                current_(p)
        {
        }
    };
    class iterator {};

public:
    List();
    List(const List& rhs);
    ~List();

    const List& operator= (const List& rhs);

    iterator begin();
    const_iterator begin() const;

    iterator end();
    const_iterator end() const;

    int size() const;
    bool empty() const;

    void clear();

    Object& front();
    const Object& front() const;

    Object& back();
    Object& back() const;

    void push_front(const Object& x);
    void push_back(const Object& x);

    void pop_front();
    void pop_back();

    iterator insert(iterator itr, const Object& x);
    iterator erase(iterator itr);

private:
    int size_;
    // use head_ and tail_ to simplify implementation
    Node* head_;
    Node* tail_;

    // helper function
    void init();
};

#endif LIST_H_
