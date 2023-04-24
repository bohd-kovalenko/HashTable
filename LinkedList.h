#include <string>
#include "Data.h"

#ifndef LAB2_2_2_LINKEDLIST_H
#define LAB2_2_2_LINKEDLIST_H

#endif //LAB2_2_2_LINKEDLIST_H

using namespace std;


struct HashNode {
    long long key;
    Data data;
    HashNode *next;

    HashNode(long long key, const Data &data);

};

struct SinglyLinkedList {
    HashNode *head;

    SinglyLinkedList();

    bool eraseByKey(long long key);

    void pushFront(long long key, const Data &data);

    Data *findByKey(long long key);

    void popFront();

    virtual ~SinglyLinkedList();

};
