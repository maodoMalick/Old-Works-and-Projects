#ifndef HASHCLASS_H
#define HASHCLASS_H

#include <iostream>
using namespace std;

class HashClass
{
    private:
        // Items in hash table
        struct node{
            string name;
            int busNo;
            string shift;
            string lane;
            node* next;
        };
        // Hash table size
        static const int Size = 10;
        // Hash table
        node* hashtable[Size];
        // Create the pointers
        node* head;
        node* curr;
        node* trail;

    public:
        HashClass();
        void clearScreen();
        int hashMaker(string);
        void importData();
        void insertData();
        void addDriver(string, int, string, string);
        int countNodes(int);
        void deleteDriver(string);
        void searchDriver(string);
        void printList();
        void printBucketDeep(int);
        void runHashtable();
};

#endif // HASHCLASS_H
