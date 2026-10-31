#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    ifstream file;
    file.open("a:test.dat");

    if (!file)
    {
        cout << "\nCan't open GROUP.DAT";
    }
    else
    {
        cout << "\nFile opened successfully.";
    }
    cout << "\nError state = " << file.rdstate();
    cout << "\ngood() = " << file.good();
    cout << "\neof() = " << file.eof();
    cout << "\nfail() = " << file.fail();
    cout << "\nbad() = " << file.bad() << endl;
    file.close();

    return 0;
}