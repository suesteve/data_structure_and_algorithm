#ifndef VECTOR_H_
#define VECTOR_H_

template <typename Object>
class Vector {
public:
    explicit Vector(int size=0) :
        size_(size),
        capacity_(size + kSpareCapacity)
    {
        objects_ = new Object[capacity_];
    }

    Vector(const Vector& rhs)
    {
        operator=(rhs);
    }
    ~Vector()
    {
        delete [] objects_;
    }

    // TODO(suesteve) will cause error when used in expression like Vector<int> vec_i2 = vec_i
    const Vector& operator= (const Vector& rhs)
    {
        if(&rhs != this) {
            delete [] objects_;
            size_ = rhs.size_;
            capacity_ = rhs.capacity_;

            objects_ = new Object[capacity_];
            for(int i = 0; i < size_; ++i) {
                //TODO(suesteve)
                objects_[i] = rhs[i];
            }
        }

        return *this;
    }

    void resize(int new_size)
    {
        if(new_size > capacity_) {
            reserve(new_size * 2 + 1);
        }

        // manipulate capacity_ inside reserve() !
//        capacity_ = new_size * 2 + 1;
        size_ = new_size;
    }
    void reserve(int new_capacity)
    {
        if(new_capacity < size_) {
            return;
        }

        Object* old_array = objects_;
        capacity_ = new_capacity;

        objects_ = new Object[new_capacity];

        for(int i = 0; i < size_; ++i) {
            objects_[i] = old_array[i];
        }

        // don't forget to delete old_array;
        delete [] old_array;
    }

    Object& operator[](int index)
    {
        return objects_[index];
    }
    const Object& operator[](int index) const
    {
        return objects_[index];
    }

    bool empty() const
    {
        return size_ == 0;
    }
    int size() const
    {
        return size_;
    }
    int capacity() const
    {
        return capacity_;
    }

    void push_back(const Object& x)
    {
        if(size_ == capacity_) {
            reserve(capacity_ * 2 + 1);
        }

        objects_[size_++] = x;
    }
    void pop_back()
    {
        --size_;
    }

    // return the last item of the Objects
    const Object& back() const
    {
        return objects_[size_ - 1];
    }

    typedef Object* iterator;
    typedef const Object* const_iterator;

    iterator begin()
    {
        return &objects_[0];
    }
    const_iterator begin() const
    {
        return &objects_[0];
    }

    iterator end()
    {
        return &objects_[size_];
    }
    const_iterator end() const
    {
        return &objects_[size_];
    }

    enum {
        kSpareCapacity = 16
    };

private:
    int size_;
    int capacity_;
    Object* objects_;
};

#endif // VECTOR_H_
