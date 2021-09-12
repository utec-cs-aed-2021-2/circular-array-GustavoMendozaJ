#include "circulararray.h"

template <typename T>
class QueueArray : public CircularArray<T>
{
private:
    T *array;
    int capacity;
    int back, front;

public:
    QueueArray();
    void Enqueue(int number);
    int Dequeue();
    QueueArray(int capacity);
    ~QueueArray();
};

template <class T>
QueueArray<T>::QueueArray()
{
    QueueArray(0);
}

template <class T>
QueueArray<T>::QueueArray(int capacity)
{
    this->array = new T[capacity];
    this->capacity = capacity;
    this->front = this->back = -1;
}

template <class T>
QueueArray<T>::~QueueArray()
{
    delete[] array;
}

template <class T>
void QueueArray<T>::Enqueue(int number)
{
    if (array.is_full())
        return;
    if (array.is_empty())
        front = back = 0;
    else if (back == capacity - 1)
        back = 0;
    else
        back++;
    array[back] = number;
}

template <class T>
int QueueArray<T>::Dequeue()
{
    if (array.is_empty())
        return 0;
    int number = array[front];
    if (front == back)
        front = back = -1;
    else if (front == capacity - 1)
        front = 0;
    else
        front++;
    return number;
}