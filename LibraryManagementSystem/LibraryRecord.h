#pragma once
#include <string>
#include "Date.h"
using namespace std;

// Library Record
class LibraryRecord
{
public:
    string username;
    string resourceTitle;
    string resourceIdentifier;
    string resourceType;

    LibraryRecord(string u = "", string rt = "", string ri = "", string type = "");

    virtual void display();
    virtual ~LibraryRecord() {}
};

// Borrow Record
class BorrowRecord : public LibraryRecord
{
public:
    Date issueDate;
    Date dueDate;
    Date returnDate;
    bool returned;

    BorrowRecord();
    void display() override;
};

// Reservation
class Reservation : public LibraryRecord
{
public:
    Reservation();
    void display() override;
};