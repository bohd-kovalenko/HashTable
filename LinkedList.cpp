#include "LinkedList.h"

using namespace std;

HashNode::HashNode(long long key, const Data &data) : key(key), data(data) {}


SinglyLinkedList::SinglyLinkedList() {
    head = nullptr;
}

bool SinglyLinkedList::eraseByKey(long long key) {
    if (head->key == key) {
        HashNode *headNext = head->next;
        delete head;
        head = headNext;
        return true;
    }

    HashNode *prevNode = head;
    HashNode *node = head->next;
    while (node != nullptr) {
        if (node->key == key) {
            prevNode->next = node->next;
            delete node;
            return true;
        }
        prevNode = prevNode->next;
        node = node->next;
    }
    return false;
}

SinglyLinkedList::~SinglyLinkedList() {
    HashNode *temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

void SinglyLinkedList::pushFront(long long key, const Data &data) {
    HashNode *node = new HashNode(key, data);
    node->next = head;
    head = node;
}

Data *SinglyLinkedList::findByKey(long long key) {
    Data *result = nullptr;
    HashNode *node = head;
    while (node != nullptr) {
        if (node->key == key) {
            result = &(node->data);
            break;
        }
        node = node->next;
    }
    return result;
}

void SinglyLinkedList::popFront() {
    HashNode *temp = head;
    head = head->next;
    delete temp;
}
