#include <bits/stdc++.h>
using namespace std;

class Counter
{
private:
    unsigned int count; // count

public:
    Counter() : count(0) // constructor
    {
        cout << "I'm the constructor" << endl;
    }

    void inc_count()
    {
        count++; // Increment count
    }

    int get_count()
    {
        return count; // return count
    }
};

int main()
{
    Counter c1, c2; // define and initialize

    cout << "c1=" << c1.get_count() << endl; // display
    cout << "c2=" << c2.get_count() << endl;

    c1.inc_count(); // increment c1
    c2.inc_count(); // increment c2
    c2.inc_count(); // increment c2

    cout << "c1=" << c1.get_count() << endl; // display again
    cout << "c2=" << c2.get_count() << endl;

    return 0;
}