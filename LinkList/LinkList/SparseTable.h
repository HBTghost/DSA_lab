#pragma once

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

struct raw {
    int row;
    int col;
    int val;
};

void generte(raw& **a, int rows, int cols) {
    for (std::size_t i = 0; i < rows; ++i) {
        for (std::size_t j = 0; j < cols; ++j) {
            a[i].row = i;
            a[i].col = j;
            a[i].val = rand() % 10;
        }
    }
}

typedef struct node* Ref;
struct node {
    int col;
    int val;
    Ref next;
};
typedef struct list* LRef;
struct list {
    int row;
    Ref head;
    Ref tail;
    LRef next;
};

Ref getNode(int col, int val) {
    Ref p = new node;
    p->col = col;
    p->val = val;
    p->next = nullptr;
    return p;
}
LRef getList(int row) {
    LRef p = new list;
    p->row = row;
    p->head = p->tail = nullptr;
    p->next = nullptr;
    return p;
}
void insertLast(Ref& h, Ref& t, Ref p) {
    if (h == nullptr)
        h = t = p;
    else {
        t->next = p;
        t = p;
    }
}
void createList(Ref& h, Ref& t) {
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
        int col = rand() % 100;
        int val = rand() % 10;
        p = getNode(col, val);
        insertLast(h, t, p);
    }
}
void showList(Ref h) {
    for (Ref p = h; p; p = p->next)
        cout << p->col << "-" << p->val << " | ";
    cout << endl;
}
void delList(Ref & h, Ref & t) {
    Ref p;
    while (h) {
        p = h;
        h = h->next;
        p->next = nullptr;
        delete p;
    }
    h = t = nullptr;
}

void insertBin(LRef lists, int row, Ref p) {
    LRef q1, q2;
    q2 = lists;
    q1 = lists->next;
    while (q1 && q1->row < row) {
        q2 = q1;
        q1 = q1->next;
    }
    if (q1 && q1->row == row)
        insertLast(q1->head, q1->tail, p);
    else {
        LRef q = getList(row);
        q2->next = q;
        q->next = q1;
        insertLast(q->head, q->tail, p);
    }
}

void arange(raw& **a, int rows, int cols, LRef list) {
    Ref p;
    int row;
    LRef lists = getList(-1);

    // Split list
    while (h) {
        p = h;
        h = h->next;
        p->next = nullptr;
        row = rand() % 100;
        insertBin(lists, row, p);
    }
}
