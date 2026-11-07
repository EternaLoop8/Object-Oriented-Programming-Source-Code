#include "Library_System.h"
#include "Upper_Case.h"
#include <iostream>
#include <ctime>
#include <fstream>
#include <sstream>
#include <limits>
#include <algorithm>
using namespace std;

Library_System::~Library_System()
{
    for (auto r : resources)
    {
        delete r;
    }
}

// Show Reservations
void Library_System::showMyReservations(User &u)
{
    cout << "\n--- My Reservations --- \n";
    bool found = false;

    for (auto &r : reservations)
    {
        if (r.username == u.getUsername())
        {
            r.display();
            found = true;
        }
    }

    if (!found)
    {
        cout << "No reservations found\n";
    }
}

// Reserve Resource
void Library_System::reserveResource(User &u)
{
    int resourceType;
    cout << "\nWhat would you like to reserve?\n";
    cout << "1 -> Book\n";
    cout << "2 -> Magazine\n";
    cout << "Choice: ";
    cin >> resourceType;

    if (resourceType != 1 && resourceType != 2)
    {
        cout << "Invalid choice\n";
        return;
    }

    string typeStr = (resourceType == 1) ? "book" : "magazine";

    int searchChoice;
    cout << "\nHow would you like to search?\n";
    if (resourceType == 1)
    {
        cout << "1 -> Search by ISBN\n";
    }
    else
    {
        cout << "1 -> Search by ISSN\n";
    }

    cout << "2 -> Search by Author\n";
    cout << "3 -> Search by Title\n";
    cout << "Choice: ";
    cin >> searchChoice;

    if (searchChoice < 1 || searchChoice > 3)
    {
        cout << "Invalid choice\n";
        return;
    }

    string searchQuery;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (searchChoice == 1)
    {
        if (resourceType == 1)
        {
            cout << "Enter ISBN: ";
        }
        else
        {
            cout << "Enter ISSN: ";
        }
    }
    else if (searchChoice == 2)
    {
        cout << "Enter Author: ";
    }
    else
    {
        cout << "Enter Title: ";
    }

    getline(cin, searchQuery);
    searchQuery = ToUpper(searchQuery);

    vector<Resource *> matched;

    for (auto r : resources)
    {
        if (r->getType() != typeStr)
        {
            continue;
        }
        bool found = false;

        if (searchChoice == 1 && r->getIdentifier() == searchQuery)
            found = true;

        else if (searchChoice == 2 && r->getAuthor() == searchQuery)
            found = true;

        else if (searchChoice == 3 && r->getTitle() == searchQuery)
            found = true;

        if (found)
        {
            matched.push_back(r);
        }
    }

    if (matched.empty())
    {
        cout << "No matching resource found. \n";
        return;
    }

    cout << "\n--- Search Results ---\n";
    for (int i = 0; i < (int)matched.size(); ++i)
    {
        cout << i + 1 << ". ";
        matched[i]->display();
    }

    int selectChoice;
    cout << "Which one do you want to reserve? 0 to cancel: ";
    cin >> selectChoice;

    if (selectChoice == 0)
    {
        cout << "Reservation cancelled. \n";
        return;
    }

    if (selectChoice < 1 || selectChoice > (int)matched.size())
    {
        cout << "Invalid selection. \n";
        return;
    }

    Resource *selected = matched[selectChoice - 1];

    // 1. User cannot reserve a resource already borrowed by himself
    for (auto &b : borrows)
    {
        if (b.username == u.getUsername() &&
            b.resourceIdentifier == selected->getIdentifier() &&
            b.resourceType == selected->getType() && !b.returned)
        {
            cout << "You already have this resource borrowed. No need to reserve. \n";
            return;
        }
    }

    // 2. If copies are available, user should borrow directly
    if (selected->getAvailableCopies() > 0)
    {
        cout << "This resource is currently available. Please borrow it directly. \n";
        return;
    }

    // 3. User cannot reserve the same resource twice
    for (auto &res : reservations)
    {
        if (res.username == u.getUsername() &&
            res.resourceIdentifier == selected->getIdentifier())
        {
            cout << "You have already reserved this resource. \n";
            return;
        }
    }

    // 4. Create reservation
    Reservation res;
    res.username = u.getUsername();
    res.resourceTitle = selected->getTitle();
    res.resourceIdentifier = selected->getIdentifier();
    res.resourceType = selected->getType();

    reservations.push_back(res);
    u.getAccount().reserveResourcesCount();

    cout << "Resources reserved successfully. You will get priority when it is returned. \n";
}

void Library_System::addResource()
{
    Resource *r = NULL;
    int choice;
    cout << "\n1 -> Book ";
    cout << "\n2 -> Magazine ";
    cout << "\nEnter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        r = new Book(); // Dynamic memory allocation
        r->input();     // Runtime polymorphism
    }
    else if (choice == 2)
    {
        r = new Magazine();
        r->input();
    }

    if (r != NULL)
    {
        // Checking duplication of ISBN or ISSN
        for (auto existing : resources)
        {
            if (existing->getIdentifier() == r->getIdentifier())
            {
                cout << "\nResource with ISBN/ISSN [ " << existing->getIdentifier() << " ] already exists!\n";
                delete r; // Freeing the memory
                return;
            }
        }
        resources.push_back(r);
        cout << "\nResource added successfully!\n";
    }
    else
    {
        cout << "\nInvalid choice!\n";
    }
}

// Viewing Available Resources
void Library_System::showAvailableResources()
{
    int ch;
    cout << "1 Books \n2 Magazines\nChoose:  ";
    cin >> ch;
    if (ch > 2 || ch < 1)
    {
        throw runtime_error("Choose Correct Option!");
    }
    string type = (ch == 1) ? "book" : "magazine";

    cout << "\n---Available Resources---" << endl;
    for (auto r : resources)
    {
        if (r->getType() == type && r->getAvailableCopies() > 0)
            r->display();
    }
}

// Borrow Resource
void Library_System::borrowResource(User &u)
{
    time_t t = time(0);
    tm now_tm;
    localtime_r(&t, &now_tm); // Linux-safe thread variant

    Date today;
    today.set(now_tm.tm_mday, now_tm.tm_mon + 1, now_tm.tm_year + 1900);

    cout << "Today's Date: ";
    today.display();

    int todayBorrows = 0;
    for (auto &b : borrows)
    {
        if (b.username == u.getUsername() &&
            b.issueDate.getDay() == today.getDay() &&
            b.issueDate.getMonth() == today.getMonth() &&
            b.issueDate.getYear() == today.getYear())
        {
            todayBorrows++;
        }
    }

    if (todayBorrows >= 2)
    {
        throw runtime_error("Borrow limit reached! Max 2 resources per day.");
    }

    int resourceType;
    cout << "\nWhat would you like to borrow?\n";
    cout << "1 -> Book\n";
    cout << "2 -> Magazine\n";
    cout << "Choice: ";
    cin >> resourceType;

    if (resourceType != 1 && resourceType != 2)
    {
        cout << "Invalid choice\n";
        return;
    }

    string typeStr = (resourceType == 1) ? "book" : "magazine";

    int searchChoice;
    cout << "\nHow would you like to search?\n";
    if (resourceType == 1)
    {
        cout << "1 -> Search by ISBN\n";
    }
    else
    {
        cout << "1 -> Search by ISSN\n";
    }

    cout << "2 -> Search by Author\n";
    cout << "3 -> Search by Title\n";
    cout << "Choice: ";
    cin >> searchChoice;

    if (searchChoice < 1 || searchChoice > 3)
    {
        cout << "Invalid choice\n";
        return;
    }

    string searchQuery;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (searchChoice == 1)
    {
        cout << ((resourceType == 1) ? "Enter ISBN: " : "Enter ISSN: ");
    }
    else if (searchChoice == 2)
    {
        cout << "Enter Author: ";
    }
    else
    {
        cout << "Enter Title: ";
    }

    getline(cin, searchQuery);
    searchQuery = ToUpper(searchQuery);

    Resource* selected = nullptr;
    for (auto r : resources)
    {
        if (r->getType() != typeStr) continue;

        if (searchChoice == 1 && r->getIdentifier() == searchQuery) { selected = r; break; }
        else if (searchChoice == 2 && r->getAuthor() == searchQuery) { selected = r; break; }
        else if (searchChoice == 3 && r->getTitle() == searchQuery) { selected = r; break; }
    }

    if (!selected)
    {
        cout << "Resource not found.\n";
        return;
    }

    if (selected->getAvailableCopies() <= 0)
    {
        cout << "No copies available to borrow right now.\n";
        return;
    }

    // Process borrowing logic
    selected->reduceAvailable();
    
    BorrowRecord rec; 
    rec.username = u.getUsername();
    rec.resourceTitle = selected->getTitle();
    rec.resourceIdentifier = selected->getIdentifier();
    rec.resourceType = selected->getType();
    rec.issueDate = today;   
    rec.returned = false;    
    
    borrows.push_back(rec);
    u.getAccount().borrowResourceCount();
    cout << "Resource borrowed successfully!\n";
}

/* ================= LINKER FIX IMPLEMENTATIONS ================= */

void Library_System::viewAllResources()
{
    cout << "\n--- View All Registered Resources ---\n";
    if (resources.empty())
    {
        cout << "No resources available in the system.\n";
        return;
    }
    for (auto r : resources)
    {
        r->display();
        cout << "-------------------------------------\n";
    }
}

void Library_System::returnResource(User &u) 
{ 
    cout << "\n  [INFO] Return Resource functionality called.\n"; 
}

void Library_System::showUserHistory(User &u) 
{ 
    cout << "\n  [INFO] Show User History functionality called.\n"; 
}

void Library_System::Account_Info(User &u) 
{ 
    cout << "\n  [INFO] Account Info functionality called.\n"; 
}

void Library_System::updateResource() 
{ 
cout << "\n  [INFO] Update Resource functionality called.\n";
}
void Library_System::deleteResource()
{
cout << "\n  [INFO] Delete Resource functionality called.\n";
}
void Library_System::issueReport()
{
cout << "\n  [INFO] Issue Report functionality called.\n";
}
void Library_System::printStudentReport(string username, vector<User *>& users)
{
cout << "\n  [INFO] Print Student Report functionality called for user: " << username << "\n";
}
// File Storage Implementations
void Library_System::saveResources() {}
void Library_System::loadResources() {}
void Library_System::saveBorrows() {}
void Library_System::loadBorrows() {}
void Library_System::saveReservations() {}
void Library_System::loadReservations() {}