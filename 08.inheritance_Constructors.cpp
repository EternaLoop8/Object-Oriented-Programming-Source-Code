// Derived Class Constructors
#include <bits/stdc++.h>
using namespace std;

class Counter
{
protected:
    unsigned int count;

public:
    Counter() : count() {} // constructor, no args

    Counter(int c) : count(c) {} // constructor, one arg

    unsigned int get_count() const
    {
        return count;
    }

    Counter operator++()
    { // increase count (prefix)
        return Counter(++count);
    }
};

class CountDn : public Counter
{
public:
    CountDn() : Counter() {} // constructor, no args

    CountDn(int c) : Counter(c) {} // constructor, 1 arg

    CountDn operator--()
    { // decrease count (prefix)
        return CountDn(--count);
    }
};

int main()
{
    CountDn c1;
    CountDn c2(100);

    cout << "c1 = " << c1.get_count() << endl;
    cout << "c2 = " << c2.get_count() << endl;

    ++c1;
    ++c1;
    ++c1;
    cout << "c1 = " << c1.get_count() << endl;

    --c2;
    --c2;
    cout << "c2 = " << c2.get_count() << endl;

    CountDn c3 = --c2;
    cout << "c3 = " << c3.get_count() << endl;

    return 0;
}