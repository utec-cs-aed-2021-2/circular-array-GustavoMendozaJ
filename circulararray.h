#include <iostream>
using namespace std;

template <class T>
class CircularArray
{
private:
    T *array;
    int capacity;
    int back, front;

public:
    CircularArray();                    //done
    CircularArray(int _capacity);       //done
    virtual ~CircularArray();           //done
    void push_front(T data);            //done
    void push_back(T data);             //done
    void insert(T data, int pos);       //done
    T pop_front();                      //done
    T pop_back();                       //done
    bool is_full();                     //done
    bool is_empty();                    //done
    int size();                         //done
    void clear();                       //done
    T &operator[](int);                 //done
    void sort();                        //done
    bool is_sorted();                   //done
    void reverse();                     //done
    string to_string(string sep = " "); //done

private:
    int next(int);
    int prev(int);
};

template <class T>
CircularArray<T>::CircularArray()
{
    CircularArray(0);
}

template <class T>
CircularArray<T>::CircularArray(int _capacity)
{
    this->array = new T[_capacity];
    this->capacity = _capacity;
    this->front = this->back = -1;
}

template <class T>
CircularArray<T>::~CircularArray()
{
    delete[] array;
}

template <class T>
int CircularArray<T>::prev(int index)
{
    return (index == 0) ? capacity - 1 : index - 1;
}

template <class T>
int CircularArray<T>::next(int index)
{
    return (index + 1) % capacity;
}

template <class T>
bool CircularArray<T>::is_empty()
{
    return front == -1;
}

template <class T>
bool CircularArray<T>::is_full()
{
    return front == next(back) && !is_empty();
}

template <class T>
void CircularArray<T>::push_back(T data)
{
    if (is_full())
        throw "Array is full";
    if (is_empty())
        front = back = 0;
    else
        back = next(back);
    array[back] = data;
}

template <class T>
void CircularArray<T>::push_front(T data)
{
    if (is_full())
        throw "Array is full";
    if (is_empty())
        front = back = 0;
    else
        front = prev(front);
    array[front] = data;
}

template <class T>
T CircularArray<T>::pop_back()
{
    if (is_empty())
        throw "Array is empty";
    T temp = array[back];
    if (front == back)
        front = back = -1;
    else
        back = prev(back);
    return temp;
}

template <class T>
T CircularArray<T>::pop_front()
{
    if (is_empty())
        throw "Array is empty";
    T temp = array[front];
    if (front == back)
        front = back = -1;
    else
        front = next(front);
    return temp;
}

template <class T>
int CircularArray<T>::size()
{
    if (is_empty())
        return 0;
    return (back >= front) ? back - front + 1 : capacity - front + back + 1;
}

template <class T>
void CircularArray<T>::insert(T data, int pos)
{
    int n = size();
    if (pos < 0 || pos > n)
        throw "Out of range";
    if (n == capacity)
        throw "Array is full";
    if (pos == 0)
        push_front(data);
    else
    {
        for (int i = n - 1; i >= pos; i--)
            (*this)[i + 1] = (*this)[i];
        (*this)[pos] = data;
        back = next(back);
    }
}

template <class T>
T &CircularArray<T>::operator[](int pos)
{
    if (pos >= capacity)
        throw "Out of range";
    return array[(front + pos) % capacity];
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

template <class T>
bool CircularArray<T>::is_sorted()
{
    if (is_empty())
        return false;
    else
    {
        int first_el = front;
        int last_el = back;
        if (first_el == last_el)
            return true;
        else
        {
            int i = first_el;
            while (++i != last_el)
            {
                if (*(this->array + i) < *(this->array + first_el))
                {
                    return false;
                }
                ++first_el;
            }
            return true;
        }
    }
}

template <class T>
void CircularArray<T>::sort()
{
    if (is_empty())
        throw "Array is empty";
    else
    {
        int var = front;
        do
        {
            int pvt = next(var);
            while (pvt != next(back))
            {
                if (*(this->array + var) > *(this->array + pvt))
                {
                    int tmp = *(this->array + var);
                    *(this->array + var) = *(this->array + pvt);
                    *(this->array + pvt) = tmp;
                }
                pvt = next(pvt);
            }
            var = next(var);
        } while (next(var) != next(back));
        if ((*this)[0] > (*this)[1])
        {
            int a = (*this)[0];
            for (int i = 0; i < size() - 1; i++)
            {
                (*this)[i] = (*this)[i + 1];
            }
            (*this)[size() - 1] = a;
        }
    }
}

template <class T>
void CircularArray<T>::reverse()
{
    int n = int(size() / 2);
    for (int i = 0; i < n; i++)
    {
        swap((*this)[i], (*this)[size() - 1 - i]);
    }
}

template <class T>
void CircularArray<T>::clear()
{
    front = back = -1;
}

template <class T>
string CircularArray<T>::to_string(string sep)
{
    string result = "";
    for (int i = 0; i < size(); i++)
        result += std::to_string((*this)[i]) + sep;
    return result;
}
