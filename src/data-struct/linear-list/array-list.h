#include "liner-list.h"

#ifndef ARRAY_LIST_H_
#define ARRAY_LIST_H_ 1
template <typename T>
class arrayList : public linearList<T>
{
public:
    arrayList(int initialCapacity = 10);
    arrayList(const arrayList<T> &);
    ~arrayList() { delete[] element; }
    void checkIndex(int theIndex) const;
    bool is_empty() const;
    int size() const;
    T &get(int theIndex) const;
    void changeCapacity();
    void append(T &theElement);
    void output(std::ostream &cout) const;

private:
    T *element;
    // 初始容量
    int cap;
    // 当前容器中的元素个数
    int current_item_cnts;
};
#endif