#include <stdio.h>
#include <iostream>
#include <ostream>

template <typename T>
class linearList
{
public:
    virtual ~linearList(){};
    virtual bool empty() const = 0;
    // virtual int size() const = 0;
    // virtual T &get(int theIndex) const = 0;
    // virtual int indexOf(const T &theElement) const = 0;
    // virtual void erase(int theIndex) = 0;
    // virtual void insert(int theIndex, const T &theElement) = 0;
    // virtual void output(ostream &cout) const = 0;
};

template <typename T>
class arrayList : public linearList<T>
{
public:
    arrayList(int initialCapacity = 10);
    arrayList(const arrayList<T> &);
    ~arrayList() { delete[] element; }
    void checkIndex(int theIndex) const;
    bool empty() const;

private:
    T *element;
    int arrayLength;
    int arraySize;
};

template <typename T>
arrayList<T>::arrayList(int initialCapacity)
{
    this->element = new T[initialCapacity];
    this->arrayLength = initialCapacity;
    this->arraySize = 0;
}

template <typename T>
arrayList<T>::arrayList(const arrayList<T> &source)
{
    this->arrayLength = source.arrayLength;
    this->arraySize = source.arraySize;
    this->element = new T[source.arrayLength];
    /**
     * arraySize 是用来标记已经用了几个位置的
     */
    for (int i = 0; i < source.arraySize; i++)
    {
        this->element[i] = source.element[i];
    }
}

template <typename T>
void arrayList<T>::checkIndex(int theIndex) const
{
    if (theIndex < 0 && theIndex >= arraySize)
    {
        throw "index error ";
    }
}

template <typename T>
bool arrayList<T>::empty() const
{
    return arraySize == 0;
}

int main()
{
    using namespace std;
    arrayList<int> arr(3);
    cout << arr.empty() << endl;
}