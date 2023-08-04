#include <stdio.h>
#include <iostream>
#include <ostream>
#include "array-list.h"

template <typename T>
arrayList<T>::arrayList(int initialCapacity)
{
    this->element = new T[initialCapacity];
    this->cap = initialCapacity;
    this->current_item_cnts = 0;
}

template <typename T>
arrayList<T>::arrayList(const arrayList<T> &source)
{
    this->cap = source.cap;
    this->current_item_cnts = source.current_item_cnts;
    this->element = new T[source.cap];
    /**
     * arraySize 是用来标记已经用了几个位置的
     */
    for (int i = 0; i < source.current_item_cnts; i++)
    {
        this->element[i] = source.element[i];
    }
}

template <typename T>
void arrayList<T>::checkIndex(int theIndex) const
{
    if (theIndex < 0 || theIndex >= current_item_cnts)
    {
        std::cout << "raise ... " << std::endl;
        throw "index error";
    }
}

template <typename T>
bool arrayList<T>::is_empty() const
{
    return current_item_cnts == 0;
}

template <typename T>
int arrayList<T>::size() const
{
    return current_item_cnts;
}

template <typename T>
T &arrayList<T>::get(int theIndex) const
{
    checkIndex(theIndex);

    return element[theIndex];
}

template <typename T>
void arrayList<T>::changeCapacity()
{
    if (current_item_cnts == cap)
    {
        std::cout << "arrayLength > arraySize not need malloc mem" << std::endl;
        return;
    }
    T *tp = new T[cap * 2];
    for (int i = 0; i < cap; i++)
    {
        tp[i] = element[i];
    }
    delete[] element;
    element = tp;
}

template <typename T>
void arrayList<T>::append(T &theElement)
{
    element[current_item_cnts] = theElement;
    current_item_cnts++;
}

template <typename T>
void arrayList<T>::output(std::ostream &cout) const
{
    cout << "[";
    for (int i = 0; i < current_item_cnts; i++)
    {
        cout << element[i] << ", ";
    }
    cout << "]" << std::endl;
}

int main()
{
    using namespace std;
    int size = 3;
    arrayList<int> arr(size);

    for (int i = 0; i < size; i++)
    {
        int value = i * 100 + 100;
        arr.append(value);
    }
    cout << arr.is_empty() << endl;
    cout << arr.size() << endl;
    arr.checkIndex(1);
    arr.output(std::cout);

    cout << "this is the end" << endl;
    return 0;
}