#include <iostream>
#include <cstdlib>
#include "LinkList.h"
using namespace std;

int main()
{
    LinkList linker; // Create object
    void (LinkList::*Ptr)(string, int, string); // Create a Function Pointer for use with most function members
    Ptr = &LinkList::addNode; // Set pointer to the address of Member Function

    cout << "First, Populate the list with at least one contact." << endl;
    int num;
    char select;
    while(cin){
       cout << "   Enter 'Y/N' to Add a New Member or to Go to Menu: " << endl;
       cin >> select;
       if(select == 'Y' || select == 'y'){
            linker.runList(linker, Ptr); // Use object and pointer as param of another member function
            linker.validator("number", num);
        } else if(select == 'N' || select == 'n'){
            break;
       }
    }

    int choice;
    while(choice != 5){
        cout << "\tEDIT CONTACT LIST." << endl;
        cout << "Enter 1: to Add a New Contact." << endl;
        cout << "Enter 2: to Insert a New Contact in front of list." << endl;
        cout << "Enter 3: to Insert a New Contact by Sorting." << endl;
        cout << "Enter 4: to Delete a Contact." << endl;
        cout << "Enter 5: to Exit." << endl;

        cout << endl << "Choice: ";
        cin >> choice;
        linker.validator("number", num);
        switch(choice){
            case 1:
                cout << ">> ADDING A NEW NAME IN LIST." << endl;
                Ptr = &LinkList::addNode; // Set pointer to the address of Member Function
                linker.runList(linker, Ptr); // Use object and pointer as param of another member function
                break;
            case 2:
                cout << ">> INSERTING AT THE HEAD OF LIST." << endl;
                Ptr = &LinkList::addToHead; // Redirect pointer to the address of another Member Function
                linker.runList(linker, Ptr);
                break;
            case 3:
                cout << ">> RANDOM INSERT BY NAME IN ALPHABETICAL ORDER." << endl;
                Ptr = &LinkList::randomInsert; // Redirect pointer to the address of another Member Function
                linker.runList(linker, Ptr);
                break;
            case 4:
                cout << ">> DELETING ENTRIES." << endl;
                void (LinkList::*Ptr1)(string); // Create another Function Pointer for a different member function
                Ptr1 = &LinkList::delNode; // Set pointer to the address of Member Function
                linker.cutList(linker, Ptr1);
                break;
        }

    }

    return 0;
}
