
#ifndef LAB2_2_2_HASHTABLE_H
#define LAB2_2_2_HASHTABLE_H

#endif //LAB2_2_2_HASHTABLE_H

#include "LinkedList.h"

#define M 17

struct HashTable {
    SinglyLinkedList *bucketsArray;
    int arraySize = M;
    int elementsCount;
    double loadFactor;

    HashTable();

    int hash(long long key);

    void insert(long long key, const Data &data);

    Data *find(long long key);

    void erase(long long key);

    int size();

    void realloc();
};