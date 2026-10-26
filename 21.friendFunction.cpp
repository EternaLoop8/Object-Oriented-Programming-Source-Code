#include <bits/stdc++.h>

class beta; // needed for frifunc declaration

class alpha
{
private:
    int data;

public:
    alpha() : data(3) {}             // no-arg constructor
    friend int frifunc(alpha, beta); // friend function
};

class beta
{
private:
    int data;

public:
    beta() : data(7) {}              // no arg constructor
    friend int frifunc(alpha, beta); // friend function
};

int frifunc(alpha a, beta b)
{
    return (a.data + b.data);
}

int main()
{
    alpha aa;
    beta bb;

    std::cout << frifunc(aa, bb) << std::endl;

    return 0;
}