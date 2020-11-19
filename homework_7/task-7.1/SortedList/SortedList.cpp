#include "SortedList.h"
#include <stdio.h>

struct Element {
    ValueType value; 
    Element* next;
};

struct SortedList {
    Element* begin = nullptr;
    int size = 0;
};

SortedList* createList() {
    return new SortedList;
}

void deleteList(SortedList* list) {
    Element* currentElement = list->begin;
    delete list;

    while (currentElement != nullptr) {
        Element* elementToDelete = currentElement;
        currentElement = currentElement->next;
        delete elementToDelete;
    }
}

void addElement(SortedList* list, ValueType value) {   
    Element* newElement = new Element;
    newElement->value = value;
    newElement->next = nullptr;

    Element* currentElement = list->begin;
    Element* previousElement = nullptr;

    while (currentElement != nullptr
            && currentElement->value < value) {
        
        previousElement = currentElement;
        currentElement = currentElement->next;
    }
    
    newElement->next = currentElement;

    if (previousElement != nullptr) {
        previousElement->next = newElement;
    }
    else {
        list->begin = newElement;
    }

    list->size++;
}

bool removeElement(SortedList* list, ValueType value) {
    Element* currentElement = list->begin;
    Element* previousElement = nullptr;

    if (currentElement == nullptr) {
        return false;
    }
    
    while (currentElement->value != value) {
        if (currentElement->next == nullptr) {
            return false;
        }

        previousElement = currentElement;
        currentElement = currentElement->next;
    }

    if (previousElement != nullptr) {
        previousElement->next = currentElement->next;
    }
    else {
        list->begin = currentElement->next;
    }
    
    delete currentElement;
    return true;
}

void printList(SortedList* list) {
    Element* currentElement = list->begin;

    printf("\n");
    while (currentElement != nullptr) {
        printf("%i ", currentElement->value);
        currentElement = currentElement->next;
    }
    printf("\n");
}