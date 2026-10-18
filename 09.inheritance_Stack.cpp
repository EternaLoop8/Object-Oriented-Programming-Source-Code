// Overriding Member Functions
#include <bits/stdc++.h>
using namespace std;

class Stack
{
protected:
    enum
    {
        MAX = 3
    };
    int st[MAX];
    int top;

public:
    Stack()
    { // constructor
        top = -1;
    }
    void push(int var)
    {
        st[++top] = var; // put number on stack
    }
    int pop()
    {
        return st[top--]; // take number off stack
    }
};

class Stack2 : public Stack
{
public:
    void push(int var)
    {
        if (top >= MAX - 1) // error if stack full
        {
            cout << "Error: stack is full" << endl;
            exit(1);
        }

        Stack::push(var); // Moved OUTSIDE the if block so it runs when NOT full
    }
    int pop()
    {
        if (top < 0)
        {
            cout << "Error: stack is empty" << endl;
            exit(1);
        }
        return Stack::pop(); // call pop() in Stack class
    }
};

int main()
{
    Stack2 s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    return 0;
}