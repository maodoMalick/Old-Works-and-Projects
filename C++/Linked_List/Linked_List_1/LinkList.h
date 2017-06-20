#ifndef LINKLIST_H
#define LINKLIST_H

#include <iostream>
using namespace std;

class LinkList
{
    private:
        struct node{
            string name;
            int age;
            string job;
            node* next;
        };
        // Pointers
        node* head;
        node* curr;
        node* trail;

    public:
        LinkList();
        void bufferCleaner();
        void clearScreen();
        int validator(string, int);
        string validator(string, string);
        void addNode(string, int, string);
        void addToHead(string, int, string);
        void randomInsert(string, int, string);
        void delNode(string);
        void printList();
        // parameters for these following functions are objects and function pointers
        // Object must be passed by ref so it reflects changes made by any member function
        int runList(LinkList &Lk, void(LinkList::*x)(string, int, string));
        void cutList(LinkList &Lk, void(LinkList::*x)(string));

};

#endif // LINKLIST_H
