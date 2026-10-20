#include <bits/stdc++.h>
using namespace std;

class String{
private:
    char* str; // pointer to string
public:
    String(char* s) // constructor, one arg
    {
        int length = strlen(s);
        str = new char[length+1];
        strcpy(str,s); // copy argument to it
    }
    ~String() // destructor
    {
        cout << "Deleting str." << endl;
        delete[] str; // release memory
    }
    void display() // display the String
    { 
        cout << str << endl;
    }
};

int main() {

    String s1 = "Who knows nothing doubts nothing.";

    cout << "s1="; 
    s1.display();
    
    return 0;
}