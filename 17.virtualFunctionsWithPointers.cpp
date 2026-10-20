#include <bits/stdc++.h>
using namespace std;

class Base
{
public:
    // virtual function
    virtual void show()
    {
        cout << "Base \n";
    }
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

    Derv1 dv1; // object of derived class 1
    Derv2 dv2; // object of derived class 2
    Base *ptr; // pointor to base class

    ptr = &dv1; // put address of dv1 in pointer
    ptr->show();

    ptr = &dv2;
    ptr->show();

    return 0;
}