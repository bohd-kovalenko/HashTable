#include "HashTable.h"

using namespace std;

HashTable::HashTable() {
    bucketsArray = new SinglyLinkedList[arraySize];
    elementsCount = 0;
    loadFactor = 0.7;
}

int HashTable::hash(long long key) {
    return key % arraySize;
}

void HashTable::insert(long long key, const Data &data) {
    double currentLoadFactor = (double) elementsCount / arraySize;

    if (currentLoadFactor > loadFactor) {
        realloc();
    }

    int index = hash(key);
    Data *d = find(key);
    if (d != nullptr) {
        *d = data;
        return;
    }

    bucketsArray[index].pushFront(key, data);
    elementsCount++;
}

Data *HashTable::find(long long key) {
    int index = hash(key);
    return bucketsArray[index].findByKey(key);
}

void HashTable::erase(long long key) {
    int index = hash(key);
    if (bucketsArray[index].findByKey(key) != nullptr) {
        elementsCount--;
        bucketsArray[index].eraseByKey(key);
    }
}

int HashTable::size() {
    return elementsCount;
}

void HashTable::realloc() {
    arraySize = arraySize * 2;
    SinglyLinkedList *oldArray = bucketsArray;
    bucketsArray = new SinglyLinkedList[arraySize];
    elementsCount = 0;
    for (int i = 0; i < arraySize / 2; i++) {
        SinglyLinkedList *list = &oldArray[i];
        while (list->head != nullptr) {
            insert(list->head->key, list->head->data);
            list->popFront();
        }
    }
    delete[] oldArray;
}




