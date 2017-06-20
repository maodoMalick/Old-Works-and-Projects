#include "LinkList.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>    // std::any_of
#include "ctype.h"
#include <string>
#include <limits> // for ::max()
using namespace std;

// Constructor
LinkList::LinkList()
{
    head = nullptr;
    curr = nullptr;
    trail = nullptr;
}
// Cleaning the buffer
void LinkList::bufferCleaner(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n' );
}

// Clear the screen
void LinkList::clearScreen(){
    if(system("cls")){
        system("clear");
    }
}

// Validation to prevent illegal entries
int LinkList::validator(string data, int x){
    int result = 0;
    while(!cin){
        cout << "Error! You must enter a " << data << " not a word!" << endl;
        bufferCleaner();
        cin >> x;
    }
    result = x; // Receive and return the valid entry by user
    return result;
}
// Function Overloading for Validation
string LinkList::validator(string data, string s1){
    //bufferCleaner();
    string result;
    bool isExact = true;
    while(isExact){
        for(int i = 0; i < s1.length(); i++){
            // Entries being either uppercase or lower case
            if ((int)(s1[i]) < 65 || ((int)(s1[i]) > 90 && (int)(s1[i]) < 97) || (int)(s1[i]) > 122)
            {
                cout << "Error! You must enter a " << data << " not a number!" << endl;
                bufferCleaner();// Flush the buffer
                cin >> s1;
            } else{
                bufferCleaner();
                isExact = false;
                break;
            }
        }
    }
    result = s1;
    return result;
}

// Inserting a node
void LinkList::addNode(string iName, int iAge, string pos){
    // First create a new node
    node* n = new node;
    n->name = iName;
    n->age = iAge;
    n->job = pos;
    n->next = nullptr;

    // If list is empty, new node is first item
    if(head == nullptr){
        head = n;
    } else {
        // If list is not empty...
        curr = head; // ...first position curr to the head of the list..
        while(curr->next != nullptr){
            curr = curr->next; // ...then traverse all nodes to the end
        }
        curr->next = n; // At the end, append new node
    }
}

// Inserting a node before the head of the list
void LinkList::addToHead(string iName, int iAge, string pos){
    // Create a new node
    node* n = new node;
    n->name = iName;
    n->age = iAge;
    n->job = pos;
    n->next = nullptr;

    // Head is pointing to something, (first node in list)
    if(head != nullptr){
        n->next = head; // To avoid breaking the link, make new node point to head first...
        head = n; // ... then head will point to new node.
    }
}

// To insert in an alphabetically sorted list, or
// a list in an ascending/descending way
void LinkList::randomInsert(string iName, int iAge, string pos){
    // Create a new node
    node* n = new node;
    n->name = iName;
    n->age = iAge;
    n->job = pos;
    n->next = nullptr;

    // Make sure list is not empty
    if(head != nullptr){
        // Position pointers
        curr = head;
        trail = nullptr;

        // Traverse the list to find the right spot
        while(curr != nullptr){
            // You want to insert a name while following an alphabetically sorted list
            // If curr finds the correct place....
            if(curr->name >= n->name){
                break;
            } else {
                trail = curr;
                curr = curr->next;
            }
        }

        // ...it jumps here to insert it in head if list is empty, or...
        if(curr == head){
            n->next = head;
            head = n;
        } else{ // ...here after the triangle inter-connection
            n->next = curr;
            trail->next = n;
        }
    }
}

// Delete Node
void LinkList::delNode(string name){
    // Case of an empty list
    if(head == nullptr){
        cout << "Empty list! No deletion possible." << endl;
    } else{
        // Position pointers
        curr = head;
        trail = nullptr;

        while(curr != nullptr){
            if(curr->name == name){
                break; // Found in either the first node or in any subsequent node
            } else{
                trail = curr; // trail trails curr...
                curr = curr->next; // ...while curr always gets ahead one node
            }
        }
    }

    // Now curr has exited with two prospects: either it found the name or it found nothing

    if(curr == nullptr){ // Case curr reached the end with no result
        cout << name << " is not part of this list." << endl;
    } else { // Case curr found name...
        if(curr == head){ // ...in head,
            head = head->next; // ...it will move head out of the way...
        } else{ // ...or, if anywhere else...
            trail->next = curr->next; // ...it will get trail out of the way
        }
        delete curr;
        curr = nullptr; // To avoid dangling pointer
    }

}

// Print the list
void LinkList::printList(){
    // Position curr from beginning
    curr = head;
    while(curr != nullptr){
        cout << "Name: " << curr->name << endl;
        cout << "Age: " << curr->age << endl;
        cout << "Position: " << curr->job << endl;
        curr = curr->next;
        cout << "----------------" << endl;
    }
}

// Function Pointers have to have the same number of arguments and return type as member functions.
int LinkList::runList(LinkList &Lk, void(LinkList::*x)(string n1, int a, string j)){
    // Parameter variables
    int num, age;
    string name, job;
    cout << "Enter name: ";
    cin >> name;
    string i_name = Lk.validator("word", name); // This var will hold the valid data entered by user not garbage
    cout << "Enter age: ";
    cin >> age;
    int i_age = Lk.validator("number", age);
    cout << "Enter job: ";
    cin >> job;
    string i_job = Lk.validator("word", job);
    // Object will call any member function through the function pointer
    (Lk.*x)(i_name, i_age, i_job);

    // Clear screen
    Lk.clearScreen();
    // Print
    Lk.printList();
}

void LinkList::cutList(LinkList &Lk, void(LinkList::*x)(string)){
    string name;
    cout << "Enter the name of the entry to be deleted: " << endl;
    cin >> name;
    string i_name = Lk.validator("word", name);
    (Lk.*x)(i_name);
    cout << endl;
    // Print
    cout << "----------------" << endl;
    Lk.printList();
}

