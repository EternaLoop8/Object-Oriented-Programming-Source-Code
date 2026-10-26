#include <bits/stdc++.h>
using namespace std;

class alpha
{
private:
    int data;

public:
    alpha()
    {
    }
    alpha(int d)
    {
        data = d;
    }
    void display()
    {
        cout << data;
    }
    alpha operator=(alpha &a) // overloaded = operator
    {
        data = a.data; // not done automatically
        cout << "\nAssignment operator invoked";
        return alpha(data);
    }
};

int main()
{
    alpha a1(37);
    alpha a2;

    a2 = a1; // invoke overloaded =
    cout << "\na2=";
    a2.display();

    alpha a3 = a2; // does NOT invoke =
    cout << "\na3=";
    a3.display();
    cout << endl;

    return 0;
}