#pragma once

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

typedef struct node* Ref;
struct node {
    int key;
    Ref next = nullptr;
};

typedef struct list* LRef;
struct list {
    Ref head = nullptr;
    Ref tail = nullptr;
    LRef next = nullptr;
};

Ref getNode(int key) {
    Ref p = new node;
    p->key = key;
    p->next = nullptr;
    return p;
}
LRef getList() {
    LRef p = new list;
    p->head = nullptr;
    p->tail = nullptr;
    p->next = nullptr;
    return p;
}
void insertLast(LRef l, Ref p) {
    if (l->head == nullptr)
        l->head = l->tail = p;
    else {
        l->tail->next = p;
        l->tail = p;
    }
}
void createList(LRef l) {
    int n, i;
    Ref p;
    while (true) {
        cout << "Enter the number of elements: ";
        cin >> n;
        if (n)
            break;
        cout << "Wrong value!" << endl;
    }
    for (i = 0; i < n; i++) {
        int key = rand() % 10000;
        p = getNode(key);
        insertLast(l, p);
    }
}
void showList(LRef l) {
    for (Ref p = l->head; p; p = p->next)
        cout << p->key << " ";
    cout << endl;
}
void delList(LRef l) {
    Ref p;
    while (l->head) {
        p = l->head;
        l->head = l->head->next;
        p->next = nullptr;
        delete p;
    }
    l->head = l->tail = nullptr;
    delete l;
}

int size(LRef l) {
    int res = 0;
    Ref head = l->head;
    while (head) {
        ++res;
        head = head->next;
    }
    return res;
}

void mergeList(LRef a, LRef b, LRef c) {
    // delList(c);
    // c = new list;
    Ref a1 = a->head;
    Ref b1 = b->head;
    Ref temp;
    while (a1 && b1) {
        if (a1->key > b1->key) {
            temp = getNode(a1->key);
            a1 = a1->next;
        }
        else {
            temp = getNode(b1->key);
            b1 = b1->next;
        }
        insertLast(c, temp);
    }
    while (a1) {
        temp = getNode(a1->key);
        insertLast(c, temp);
        a1 = a1->next;
    }
    while (b1) {
        temp = getNode(b1->key);
        insertLast(c, temp);
        b1 = b1->next;
    }
}

void mergeSort(LRef l, int size) {
    if (size > 1) {
        int mid = size / 2;
        LRef a = new list;
        LRef b = new list;
        Ref temp = l->head;

        for (std::size_t i = 0; i < mid; ++i, temp = temp->next) {
            insertLast(a, getNode(temp->key));
        }
        for (std::size_t i = mid; i < size; ++i, temp = temp->next) {
            insertLast(b, getNode(temp->key));
        }

        mergeSort(a, mid);
        mergeSort(b, size - mid);

        mergeList(a, b, l);

        delList(a);
        delList(b);
    }
}