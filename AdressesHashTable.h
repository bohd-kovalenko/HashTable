#include "Data.h"

#ifndef LAB2_2_2_ADRESSESHASHTABLE_H
#define LAB2_2_2_ADRESSESHASHTABLE_H

#endif //LAB2_2_2_ADRESSESHASHTABLE_H
#define M 17

enum State {
    REMOVED,
    OPEN,
    FILLED
};

struct Cell {
    State state;
    Data data;
    long long key;

    Cell();
};

struct AdressesHashTable {
    int arraySize;
    int elementsCount;
    int maximumStoredElementsCount;
    double loadFactor;
    Cell *array;

    AdressesHashTable();

    int hash(long long key);

    void insert(long long key, const Data &data);

    Data *find(long long key);

    void erase(long long key);

    int size();

    void realloc();
};