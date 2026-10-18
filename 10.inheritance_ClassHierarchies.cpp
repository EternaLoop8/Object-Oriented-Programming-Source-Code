/*Our example models a database of employees of a widget company. We’ve simplified the situation
so that only three kinds of employees are represented. Managers manage, scientists perform
research to develop better widgets, and laborers operate the dangerous widget-stamping presses.
The database stores a name and an employee identification number for all employees, no matter
what their category. However, for managers, it also stores their titles and golf club dues. For
scientists, it stores the number of scholarly articles they have published. Laborers need no
additional data beyond their names and numbers.*/

#include <bits/stdc++.h>
using namespace std;

const int LEN = 80; // maximum length of names

class employee
{
private:
    char name[LEN];       // employee name
    unsigned long number; // employee number

public:
    void getdata()
    {
        cout << "Enter last name: " << endl;
        cin >> name;
        cout << "Enter number: " << endl;
        cin >> number;
    }

    void putdata() const
    {
        cout << "Name: " << name << endl;
        cout << "Number: " << number << endl;
    }
};

class manager : public employee // management class
{
private:
    char title[LEN]; //"vice-president" etc.
    double dues;     // golf club dues

public:
    void getdata()
    {
        employee::getdata();
        cout << "Enter title: " << endl;
        cin >> title;
        cout << "Enter golf club dues: " << endl;
        cin >> dues;
    }

    void putdata() const
    {
        employee::putdata();
        cout << "Title: " << title << endl;
        cout << "Golf club dues: " << dues << endl;
    }
};

class scientist : public employee // scientist class
{
private:
    int pubs; // number of publications
public:
    void getdata()
    {
        employee::getdata();
        cout << "Enter number of pubs: " << endl;
        cin >> pubs;
    }

    void putdata() const
    {
        employee::putdata();
        cout << "Number of publications: " << pubs << endl;
    }
};

class laborer : public employee // laborer class
{
};

int main()
{
    manager m1, m2;
    scientist s1;
    laborer l1;
    cout << "Enter data for manager 1" << endl;
    m1.getdata();

    cout << "Enter data for manager 2" << endl;
    m2.getdata();

    cout << "Enter data for scientist 1" << endl;
    s1.getdata();

    cout << "Enter data for laborer 1" << endl;
    l1.getdata();

    // display data for several employees
    cout << "Data on manager 1" << endl;
    m1.putdata();

    cout << "Data on manager 2" << endl;
    m2.putdata();

    cout << "Data on scientist 1" << endl;
    s1.putdata();

    cout << "Data on laborer 1" << endl;
    l1.putdata();

    return 0;
}