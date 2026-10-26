#include <bits/stdc++.h>
using namespace std;

class strCount {
private:
    int count; 
    char *str; 
    friend class String;

    // Changed argument to const char* to accept string literals
    strCount(const char *s) 
    {
        int length = strlen(s); 
        str = new char[length + 1]; 
        strcpy(str, s); 
        count = 1;
    }

    ~strCount() 
    {
        delete[] str; 
    }
};

class String {
private:
    strCount *psc; 
public:
    // Uses const char* for literal compatibility
    String() 
    {
        psc = new strCount("NULL");
    }

    // Uses const char* for literal compatibility
    String(const char *s) 
    {
        psc = new strCount(s);
    }

    // Pass by const reference is standard practice
    String(const String &S) 
    {
        psc = S.psc;
        (psc->count)++;
    }

    ~String() 
    {
        if (psc->count == 1) {
            delete psc;
        } else {
            (psc->count)--;
        }
    }

    void display() 
    {
        cout << psc->str;
        cout << "(addr=" << (void*)psc << ")"; // Cast to void* for accurate pointer address printing
    }

    // Fixed the allocation and assignment logic
    void operator=(const String &S) 
    {
        // 1. Guard against self-assignment
        if (this == &S) {
            return;
        }

        // 2. Decrement or delete current pointer tracking
        if (psc->count == 1) {
            delete psc;
        } else {
            (psc->count)--;
        }

        // 3. Bind to the new strCount pointer (Must happen for both cases)
        psc = S.psc;
        (psc->count)++;
    }
};

int main() {
    String s3 = "When the for preaches, look to your geese.";
    cout << "\ns3="; s3.display();

    String s1;
    s1 = s3;
    cout << "\ns1="; s1.display();

    String s2(s3);
    cout << "\ns2="; s2.display();
    cout << endl;

    return 0;
}
