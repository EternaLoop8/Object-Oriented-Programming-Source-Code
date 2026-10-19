#include <bits/stdc++.h>
using namespace std;

const int LEN = 80; // maximum length of names

class student // educational background
{
private:
    char school[LEN];
    char degree[LEN];

public:
    void getedu()
    {
        cout << "Enter name of school or university: " << endl;
        cin >> school;
        cout << "Enter highest degree earned: " << endl;
        cin >> degree;
    }
    void putedu() const
    {
        cout << "School or university: " << school << endl;
        cout << "Highest degree earned: " << degree << endl;
    }
};

class employee
{
private:
    char name[LEN];
    unsigned long number;

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

class manager : private employee, private student
{
private:
    char title[LEN];
    double dues;

public:
    void getdata()
    {
        employee::getdata();
        cout << "Enter title: " << endl;
        cin >> title;
        cout << "Enter golf club dues: " << endl;
        cin >> dues;
        student::getedu();
    }
    void putdata() const
    {
        employee::putdata();
        cout << "Title: " << title << endl;
        cout << "Golf club dues: " << dues << endl;
        student::putedu();
    }
};

class scientist : private employee, private student
{
private:
    int pubs;

public:
    void getdata()
    {
        employee::getdata();
        cout << "Enter number of pubs: " << endl;
        cin >> pubs;
        student::getedu();
    }
    void putdata() const
    {
        employee::putdata();
        cout << "Number of publications: " << pubs << endl;
        student::putedu();
    }
};

class laborer : public employee
{
};

int main()
{
    manager m1;
    scientist s1, s2;
    laborer l1;

    cout << endl;
    cout << "Enter data for manager 1" << endl;
    m1.getdata();

    cout << "\nEnter data for scientist 1" << endl;
    s1.getdata();

    cout << "\nEnter data for scientist 2" << endl;
    s2.getdata();

    cout << "\nEnter data for laborer 1" << endl;
    l1.getdata();

    cout << "\n--- Data on manager 1 ---" << endl;
    m1.putdata();

    cout << "\n--- Data on scientist 1 ---" << endl;
    s1.putdata();

    cout << "\n--- Data on scientist 2 ---" << endl;
    s2.putdata();

    cout << "\n--- Data on laborer 1 ---" << endl;
    l1.putdata();

    return 0;
}
