#include <bits/stdc++.h>
using namespace std;

// person class
class person
{
protected:
    char name[40];

public:
    void getName()
    {
        cout << "Enter name: ";
        cin >> name;
    }

    void putName()
    {
        cout << "Name is: " << name << endl;
    }
    virtual void getData() = 0;       // pure virtual func
    virtual bool isOutstanding() = 0; // pure virtual func
};

// student class
class student : public person
{
private:
    float gpa; // grade point average
public:
    void getData() // get student dataa from user
    {
        person::getName();
        cout << "  Enter student's GPA: ";
        cin >> gpa;
    }
    bool isOutstanding()
    {
        return (gpa > 3.5) ? true : false;
    }
};

// professor class
class professor : public person
{
private:
    int numPubs; // number of papers published
public:
    void getData()
    {
        person::getName();
        cout << "  Enter number of Professor's publicatons: ";
        cin >> numPubs;
    }
    bool isOutstanding()
    {
        return (numPubs > 100) ? true : false;
    }
};

int main()
{
    person *persPtr[100]; // array of pointers to persons
    int n = 0;
    char choice;

    do
    {
        cout << "Enter student or professor (s/p): ";
        cin >> choice;
        if (choice == 's')
        {
            persPtr[n] = new student;
        }
        else
        {
            persPtr[n] = new professor;
        }
        persPtr[n++]->getData();          // get data for person
        cout << "  Enter another (y/n)?"; // do another person?
        cin >> choice;
    } while (choice == 'y'); // cycle until not 'y'

    // print names of all persons, and say if outstanding
    for (int j = 0; j < n; ++j)
    {
        persPtr[j]->putName();
        if (persPtr[j]->isOutstanding())
        {
            cout << "  This person is outstanding\n";
        }
    }

    return 0;
}