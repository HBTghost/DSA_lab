#include "Sort.h"

int main(int argc, char** argv) {
    srand(time(0));
    LRef l = getList();

    createList(l);
    cout << "Before ..." << endl;
    showList(l);

    mergeSort(l, size(l));
    cout << "After ..." << endl;
    showList(l);
    delList(l);
    return 0;
}