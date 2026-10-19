#include <bits/stdc++.h>
using namespace std;

class student
{
private:
    string school;
    string degree;

public:
    void getedu()
    {
        cout << "Enter name of school or university: ";
        cin >> school;
        cout << endl;
        cout << "Enter highest degree earned: ";
        cin >> degree;
        cout << endl;
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
    string name;
    unsigned long number;

public:
    void getdata()
    {
        cout << "Enter last name: ";
        cin >> name;
        cout << endl;
        cout << "Enter number: ";
        cin >> number;
        cout << endl;
    }
    void putdata() const
    {
        cout << "Name: " << name;
        cout << "Number: " << number;
    }
};

class manager
{
private:
    string title;
    double dues;
    employee emp; // object of class employee
    student stu;  // object of class student
public:
    void getdata()
    {
        emp.getdata();
        cout << "Enter title: ";
        cin >> title;
        cout << endl;
        cout << "Enter golf club dues: ";
        cin >> dues;
        cout << endl;
        stu.getedu();
    }
    void putdata() const
    {
        emp.putdata();
        cout << "Title: " << title;
        cout << "Golf club dues: " << dues;
        stu.putedu();
    }
};

class scientist
{
private:
    int pubs;
    employee emp;
    student stu;

public:
    void getdata()
    {
        emp.getdata();
        cout << "Enter number of pubs: ";
        cin >> pubs;
        cout << endl;
        stu.getedu();
    }
    void putdata() const
    {
        emp.putdata();
        cout << "Number of publications: " << pubs << endl;
        stu.putedu();
    }
};

class laborer
{
private:
    employee emp;

public:
    void getdata()
    {
        emp.getdata();
    }
    void putdata() const
    {
        emp.putdata();
    }
};

int main()
{

    manager m1;
    scientist s1, s2;
    laborer l1;

    cout << endl;
    cout << "Enter data for manager 1" << endl;
    m1.getdata();

    cout << "Enter data for scientist 1" << endl;
    s1.getdata();

    cout << "Enter data for scientist 2" << endl;
    s2.getdata();

    cout << "Enter data for laborer 1" << endl;
    l1.getdata();

    cout << "Data on manager 1" << endl;
    m1.putdata();

    cout << "Data on scientist 1" << endl;
    s1.putdata();

    cout << "Data on scientist 2" << endl;
    s2.putdata();

    cout << "Data on laborer 1" << endl;
    l1.putdata();

    return 0;
}