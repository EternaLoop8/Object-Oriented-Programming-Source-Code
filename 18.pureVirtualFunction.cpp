#include <bits/stdc++.h>
using namespace std;

// base class
class Base
{
public:
    virtual void show() = 0; // pure virtual function
};

// derived class 1
class Derv1 : public Base
{
public:
    void show()
    {
        cout << "Derv1\n";
    }
};

// derived class 2
class Derv2 : public Base
{
public:
    void show()
    {
        cout << "Derv2\n";
    }
};

int main()
{
    // Base bad; //can't make object from abstract class
    Base *arr[2]; // array of pointers to base class
    Derv1 dv1;    // object of derived class 1
    Derv2 dv2;    // object of derived class 2

    arr[0] = &dv1; // put address of dv1 in array
    arr[1] = &dv2; // put address of dv2 in array

    arr[0]->show();
    arr[1]->show();

    return 0;
}