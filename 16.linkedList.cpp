#include <iostream>

// Renamed from 'link' to 'Node' to avoid standard library collisions on Linux
struct Node 
{
    int data;   
    Node *next; 
};

class linklist 
{
private:
    Node *first; // Pointer to the first node

public:
    linklist() 
    {
        first = nullptr; // Modern C++ best practice replacing NULL
    }
    void additem(int d); 
    void display();      
};

void linklist::additem(int d) 
{
    Node *newlink = new Node; 
    newlink->data = d;        
    newlink->next = first;    
    first = newlink;          
}

void linklist::display() 
{
    Node *current = first;  
    while (current != nullptr) 
    {
        // Explicitly use std::cout and std::endl instead of 'using namespace std'
        std::cout << current->data << std::endl; 
        current = current->next;       
    }
}

int main()
{
    linklist li; 

    li.additem(25); 
    li.additem(36);
    li.additem(49);
    li.additem(64);

    li.display(); 

    return 0;
}