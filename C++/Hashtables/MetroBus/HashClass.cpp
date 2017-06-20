#include "HashClass.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // for system"cls")
using namespace std;
//#include <stdio.h> // toupper, islower
//#include <ctype.h> // toupper, islower

// Constructor
HashClass::HashClass()
{
    // Initialize all pointers to NULL
    head = nullptr;
    curr = nullptr;
    trail = nullptr;

    // First, fill table with 10 empty buckets
    for(int i = 0; i < Size; i++){
        hashtable[i] = new node;
        hashtable[i]->name = "/void";
        hashtable[i]->busNo = 0;
        hashtable[i]->shift = "/void";
        hashtable[i]->lane = "/void";
        hashtable[i]->next = nullptr;
    }
    // Some data on hash table are to be imported from external text file
    importData();
    // Some data on hash table are preset data from function
    insertData();
}

// Clear the screen
void HashClass::clearScreen(){
    if(system("cls")){
        system("clear");
    }
}

// Create hash number
int HashClass::hashMaker(string s1){
    int sum = 0;
    for(unsigned int i = 0; i < s1.length(); i++){
        sum += (int)s1[i]; // Typecasting to ASCII number
    }
    int hashVal = sum % Size;
    return hashVal; // Return hash number
}

// Importing data from external file
void HashClass::importData(){
    ifstream fileReader("text/busList.txt");
    // Create variables to hold imported data
    string name;
    int busNo;
    string shift;
    string lane;

    // Verify that text file exists first
    if(fileReader.is_open()){
        for(int i = 0; i < Size; i++){
            fileReader >> name >> busNo >> shift >> lane; // Writing data in vars
            int hashy = hashMaker(name); // Intercept 'name' and get its hash number
            for(int j = 0; j < Size; j++){
                if(j == hashy){ // If right bucket....
                    hashtable[hashy]->name = name; // ...start replacing "/void" value with new data
                    hashtable[hashy]->busNo = busNo;
                    hashtable[hashy]->shift = shift;
                    hashtable[hashy]->lane = lane;
                }
            }
        }

    } else{
        cout << "WARNING: you don't have any file stored.\nPlease provide a text file to be read." << endl;
    }
}

// Inserting More data locally
void HashClass::insertData(){
    // Injecting extra content
    addDriver("dave", 9011, "night", "manhattan");
    addDriver("patrick", 7877, "day", "queens");
    addDriver("mia", 3021, "day", "nassau");
    addDriver("john", 2219, "night", "bronx");
    addDriver("ali", 9504, "night", "brooklyn");
    addDriver("steve", 2278, "day", "bronx");
}

// Insert a new entry in hash table
void HashClass::addDriver(string name, int busNo, string shift, string lane){
    int dvr = hashMaker(name); // First get the hash number from the hash function
    if(hashtable[dvr]->name == "/void"){
        hashtable[dvr]->name = name;
        hashtable[dvr]->busNo = busNo;
        hashtable[dvr]->shift = shift;
        hashtable[dvr]->lane = lane;
    } else{
        node* Ptr = hashtable[dvr]; // Point to the selected bucket
        // Create a new node
        node* n = new node;
        n->name = name;
        n->busNo = busNo;
        n->shift = shift;
        n->lane = lane;
        n->next = nullptr;

        while(Ptr->next != nullptr){
            Ptr = Ptr->next; // traverse linked-list
        }
        Ptr->next = n; // Append new node to the end of list
    }
}

// Counting nodes in each bucket
int HashClass::countNodes(int x){
    int counter = 0;
    node* Ptr = hashtable[x];
    if(Ptr->name == "/void"){
        return counter;
    } else{
        counter++;
        while(Ptr->next != nullptr){
            counter++;
            Ptr = Ptr->next;
        }
    }
    return counter;
}

// Delete an entry from hash table
void HashClass::deleteDriver(string name){
    int index = hashMaker(name); // Get hash number
    node* head = hashtable[index]; // position head in first node in bucket
    curr = head; // position curr in first node also
    if(head->name == "/void"){ // If first node is an MT node
        cout << "You cannot delete an empty bucket!" << endl << endl;
    } else{ // Node is not MT
        bool isFound = false; // Boolean to display results
        if(head->next == nullptr && head->name == name){ // If name is in first and only node...
            head->name = "/void"; // ...just clean the whole node
            head->busNo = 0;
            head->shift = "/void";
            head->lane = "/void";
            isFound = true; // Confirm name has been found
        } else{
            node* delPtr = nullptr; // Create the delete pointer
            while(curr != nullptr){ // Start looping
                if(head->name == name){ // If name is found right away in first node...
                    delPtr = head; // ...position the delete pointer on it like head,
                    head = head->next; // ...move head to the following node
                    hashtable[index] = head; // Relink the list to the hash table's bucket
                    curr = curr->next; // Get curr out of the way also
                    delete delPtr; // Now delete the targeted node
                    delPtr = nullptr; // Avoid dangling pointer
                    isFound = true;
                    break; // Job Done! Get out of loop.
                } else if(curr->name == name){
                    delPtr = curr; // Position delete ptr
                    curr = curr->next; // Get curr out of the way
                    trail->next = curr; // Maneuver around isolated node to keep links active
                    delete delPtr; // Now delete the targeted node
                    delPtr = nullptr; // Avoid dangling pointer
                    isFound = true;
                    break; // Job Done! Get out of loop.
                } else{
                    // Not found yet? Keep on moving
                    trail = curr; // Bring trail into the mix, following curr
                    curr = curr->next; // Keep curr always one step ahead of trail
                }
            }
        }
        // Declare results
        if(isFound){
            cout << "DELETION:\nDriver " << name << " has been deleted from the system." << endl << endl;
            // Print new list
            printList();
            // Print the remaining nodes inside the bucket
            printBucketDeep(index);

        } else{
            cout << endl << "This driver " << name << " cannot be found in the company database." << endl << endl;
        }
    }

}

// Search Driver
void HashClass::searchDriver(string name){
    int index = hashMaker(name); // Run hash function
    node* Ptr = hashtable[index];
    bool isFound = false; // Boolean to display results
    cout << endl << "SEARCH RESULT:" << endl;
    if(Ptr->name == "/void" && Ptr->next == nullptr){

        //cout << "Found" << endl;
    } else{
        while(Ptr != nullptr){
            if(Ptr->name == name){
                cout << Ptr->name << " | ";
                cout << Ptr->busNo << " | ";
                cout << Ptr->shift << " | ";
                cout << Ptr->lane << endl;
                isFound = true;
                break;
            } else{
                Ptr = Ptr->next;
            }
        }
    }
    if(isFound){
        cout << name << " was found at location #" << index << " on the table" << endl << endl;
    } else{
        cout << "Name Not Found!\nThis person " << name << " is not a driver in this company." << endl << endl;
    }
}

// Printer
void HashClass::printList(){
    cout << "---------------------------------" << endl;
    cout << "    METROPOLITAN BUS DEPOT    " << endl;
    cout << "---------------------------------" << endl;
    cout << "NAME" << " | " << "BUS" << " | " << "SHIFT" << " | " << "LANE" << " | " << "LIST" << endl;
    cout << "---------------------------------" << endl;
    int nCount = 0;
    for(int k = 0; k < Size; k++){
        nCount = countNodes(k);
        node* Ptr = hashtable[k];
        cout << Ptr->name << " | ";
        cout << Ptr->busNo << " | ";
        cout << Ptr->shift << " | ";
        cout << Ptr->lane << " | ";
        cout << nCount << endl;
    }
    cout << "---------------------------------" << endl;
}

// Drill down any bucket to print all their nodes
void HashClass::printBucketDeep(int x){
    node* Ptr = hashtable[x];
    if(Ptr->name == "/void"){
        cout<< endl << "DEEP PRINTING:" << endl; //\nThis is the remainder of items in bucket " << x << ":" << endl;
        cout << "** This bucket is empty now! **" << endl << endl;
    } else{
        cout << endl << "DEEP PRINTING:\nThis is the remainder of items in bucket " << x << ":" << endl;
        while(Ptr != nullptr){
            cout << "Name: " << Ptr->name << endl;
            cout << "Bus No: " << Ptr->busNo << endl;
            cout << "Shift: " << Ptr->shift << endl;
            cout << "Lane: " << Ptr->lane << endl;
            cout << "----------" << endl;
            Ptr = Ptr->next;
        }
    }
}

// Run Hash table
void HashClass::runHashtable(){
    string name;
    int key;
    char select;

    while((select != 'X') && (select != 'x')){
        cout << "---------------------------------" << endl;
        cout << "Enter 'S' to search for a driver. " << endl;
        cout << "Enter 'D' to delete a driver. " << endl;
        cout << "Enter 'P' to print the list. " << endl;
        cout << "Enter 'x' to quit. " << endl;
        cout << "Choice: ";
        cin >> select;

        if(select == 'S' || select == 's'  ){
            cout << "Enter a name to search: ";
            cin >> name;
            clearScreen(); // Clear previous screen
            searchDriver(name); // Search for a specific node
        } else if(select == 'D' || select == 'd'){
            cout << "Enter a name to delete: ";
            cin >> name;
            // delete a driver
            deleteDriver(name);
        } else if(select == 'P' || select == 'p'){
            printList();
        }
    }
}
