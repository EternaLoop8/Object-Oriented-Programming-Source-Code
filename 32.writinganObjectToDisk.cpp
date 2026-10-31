#include <fstream> //for file streams
#include <iostream>
using namespace std;

class person
{
protected:
    char name[80];
    short age;

public:
    void getData()
    {

        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
    }
};

int main()
{
    person pers;
    pers.getData();
    // create ofstream object
    ofstream outfile("PERSON.DAT", ios::binary);
    // write to it
    outfile.write(reinterpret_cast<char *>(&pers), sizeof(pers));

    return 0;
}