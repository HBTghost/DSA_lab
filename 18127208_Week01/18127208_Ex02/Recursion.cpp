#include "Recursion.h"

int SumOfSquares(int n) {
    return (n > 1) ? SumOfSquares(n-1) : (n > 0) ? 1 : -1;
}

int GCD(int a, int b) {
    return (b == 0) ? a : GCD(b, a % b);
}

int FIB(int n) {
    return (n < 2) ? n : (FIB(n-1) + FIB(n-2));
}