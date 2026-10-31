#include <iostream>
#include <string>
#include <cstdlib> //for atoi(), atof()
using namespace std;

int isFeet(string); // declaration

class Distance
{
private:
    int feet;
    float inches;

public:
    Distance()
    {
        feet = 0;
        inches = 0.0;
    }
    Distance(int ft, float in)
    {
        feet = ft;
        inches = in;
    }
    void showdist()
    {
        cout << feet << "\'-" << inches << '\"';
    }
    void getdist();
};

void Distance::getdist()
{
    string instr;

    // cycle until feet are right
    while (true)
    {
        cout << "\n \nEnter feet: ";
        cin.unsetf(ios::skipws); // do not ski white spaces
        cin >> instr;            // get feet as a string
        // is it a correct feet value?
        if (isFeet(instr))
        {
            cin.ignore(10, '\n');
            feet = atoi(instr.c_str()); // convert to integer
            break;
        }
        cin.ignore(10, '\n'); // eat chars, including newline
        cout << "Feet must be an integer less than 1000\n";
    }

    // cycle until inches are right
    while (true)
    {
        cout << "Enter inches: ";
        cin.unsetf(ios::skipws);
        cin >> inches;
        if (inches >= 12.0 || inches < 0.0)
        {
            cout << "Inches must be between 0.0 and 11.99\n";
            cin.clear(ios::failbit); // artifically set fail bit
        }
        if (cin.good())
        {
            cin.ignore(10, '\n');
            break;
        }
        cin.clear();                         // error; clear the error state
        cin.ignore(10, '\n');                // eat chars, including newline
        cout << "Incorrect  inches input\n"; // start again
    }
}

int isFeet(string str)
{
    int slen = str.size();
    // if no i/p or too long
    if (slen == 0 || slen > 5)
    {
        return 0;
    }
    for (int j = 0; j < slen; ++j)
    {
        if ((str[j] < '0' || str[j] > '9') && str[j] != '-')
        {
            return 0;
        }
        // convert to double
        double n = atof(str.c_str());
        if (n < -999.0 || n > 999.0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    Distance d;
    char ans;
    do
    {
        d.getdist();
        cout << "\nDistance = ";
        d.showdist();
        cout << "\nDo another (y/n)?";
        cin >> ans;
        cin.ignore(10, '\n');
    } while (ans != 'n');
    return 0;
}
