
#ifndef LINEAR_LIST_H_
#define LINEAR_LIST_H_ 1
template <typename T>
class linearList
{
public:
    virtual ~linearList(){};
    virtual bool is_empty() const = 0;
    virtual int size() const = 0;
    virtual T &get(int theIndex) const = 0;
    virtual void append(T &theElement) = 0;
    virtual void output(std::ostream &cout) const = 0;
    //  virtual void insert(int theIndex, const T &theElement) = 0;
    //  virtual int indexOf(const T &theElement) const = 0;
    //  virtual void erase(int theIndex) = 0;
};

#endif