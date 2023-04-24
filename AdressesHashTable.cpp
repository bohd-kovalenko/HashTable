#include "AdressesHashTable.h"

int AdressesHashTable::size() {
    return elementsCount;
}

AdressesHashTable::AdressesHashTable() {
    arraySize = M;
    elementsCount = 0;
    maximumStoredElementsCount = 0;
    loadFactor = 0.7;
    array = new Cell[arraySize];
}

int AdressesHashTable::hash(long long key) {
    return (int) (key % arraySize);
}

void AdressesHashTable::realloc() {
    Cell *oldArray = array;
    arraySize = arraySize * 2;
    array = new Cell[arraySize];
    elementsCount = maximumStoredElementsCount = 0;
    for (int i = 0; i < arraySize / 2; i++) {
        if (oldArray[i].state == FILLED) {
            insert(oldArray[i].key, oldArray[i].data);
        }
    }
    delete[] oldArray;
}

void AdressesHashTable::insert(long long key, const Data &data) {
    Data *data1 = find(key);
    int index;
    double currFillingFactor;
    if (data1 != nullptr) {
        *data1 = data;
        return;
    }
    currFillingFactor = (double) maximumStoredElementsCount / arraySize;

    if (currFillingFactor >= loadFactor) {
        realloc();
    }
    index = hash(key);
    while (array[index % arraySize].state == FILLED || array[index % arraySize].state == REMOVED) {
        index++;
    }
    array[index % arraySize].data = data;
    array[index % arraySize].key = key;
    array[index % arraySize].state = FILLED;
    elementsCount++;
    maximumStoredElementsCount++;
}

Data *AdressesHashTable::find(long long key) {
    Data *result = nullptr;
    int index, iter = 0;
    bool loopFlag = true;
    index = hash(key);
    while (loopFlag) {
        if (iter > arraySize) {
            break;
        }
        switch (array[index % arraySize].state) {
            case OPEN:
                loopFlag = false;
                break;
            case FILLED:
                if (array[index % arraySize].key == key) {
                    result = &array[index].data;
                    loopFlag = false;
                } else {
                    index++;
                    iter++;
                    break;
                }
            case REMOVED:
                index++;
                iter++;
        }
    }
    return result;
}

void AdressesHashTable::erase(long long int key) {
    int index, iter = 0;
    bool loopFlag = true;
    index = hash(key);
    while (loopFlag) {
        if (iter > arraySize) {
            break;
        }
        switch (array[index % arraySize].state) {
            case OPEN:
                loopFlag = false;
                break;
            case FILLED:
                if (array[index % arraySize].key == key) {
                    array[index % arraySize].state = REMOVED;
                    elementsCount--;
                    loopFlag = false;
                } else {
                    index++;
                    iter++;
                    break;
                }
            case REMOVED:
                index++;
                iter++;
        }
    }
}


Cell::Cell() {
    state = OPEN;
}
