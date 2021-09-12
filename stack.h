#include "circulararray.h"

template <typename T>
class StackArray : public CircularArray<T>
{
private:
    T *array;
    int capacity;
    int back, front;

public:
    StackArray();
    StackArray(int capacity);
    ~StackArray();
    void Push(int number);
    int Pop();
    void resize(int new_size);
};

template <class T>
StackArray<T>::StackArray()
{
    StackArray(0);
}

template <class T>
StackArray<T>::StackArray(int capacity)
{
    this->array = new T[capacity];
    this->capacity = capacity;
    this->front = this->back = -1;
}

template <class T>
void StackArray<T>::Push(int number)
{
    this->array[this->size++] = number;
    if (this->size == this->capacity)
        resize(this->capacity + 1);
}

template <class T>
void StackArray<T>::resize(int new_size)
{
    this->capacity = new_size;
    int *tmp = new int[this->capacity];
    for (int i = 0; i < capacity; i++)
        tmp[i] = array[i];
    delete[] array;
    array = tmp;
}

template <class T>
int StackArray<T>::Pop()
{
    if (this->capacity > 0)
    {
        return array[--this->capacity];
        if (this->capacity <= 0.25 * this->capacity)
            resize(this->capacity - 1);
    }
    return 0;
}

template <class T>
StackArray<T>::~StackArray()
{
    delete[] array;
}