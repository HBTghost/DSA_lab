#include "Pointer.h"

void InputArray(int*& a, int& n) {
    if (a != nullptr) {
        for (int i = 0; i < n; ++i) {
            std::cout << "a[" << n << "]: ";
            std::cin >> a[i];
        }
    }
}

void DellocateArray(int*& a) {
    if (a != nullptr) {
        delete[] a;
        a = nullptr;
    }
}

void PrintArray(int* a, int n) {
    if (a != nullptr) {
        for (int i = 0; i < n; ++i) {
            std::cout << "a[" << n << "]: " << a[i] << "\n";
        }
    }
}

int FindMin(int* a, int n) {
    int min = a[0];
    for (int i = 0; i < n; ++i) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

int FindMaxModulus(int* a, int n) {
    int max = abs(a[0]);
    for (int i = 0; i < n; ++i) {
        if (abs(a[i]) > max) {
            max = abs(a[i]);
        }
    }
    return max;
}

bool IsAscending(int* a, int n) {
    for (int i = 0; i < n-1; ++i) {
        if (a[i+1] < a[i]) {
            return false;
        }
    }
    return true;
}

int SumOfArray(int* a, int n) {
    int sum { 0 };
    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }
    return sum;
}

bool IsPrime(int num) {
    if (num < 2) {
        return false;
    }
    int end { sqrt(num) };
    for (int i = 2; i < end; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int CountPrime(int* a, int n) {
    int primes { 0 };
    for (int i = 0; i < n; ++i) {
        if (IsPrime(a[i])) {
            ++primes;
        }
    }
    return primes;
}

void ReverseArray(int*& a, int*& b, int n) {
    for (int i = 0; i < n; ++i) {
        b[i] = a[n-i-1];
    }
}

int LinearSearch(int* a, int n, int key) {
    for (int i = 0; i < n; ++i) {
        if (a[i] == key) {
            return i;
        }
    }
    return -1;
}

int SentinelLinearSearch(int* a, int n, int key) {
    int end { n - 1 };
    bool endIsKey { a[end] == key };
    a[end] = key;
    int i { 0 };
    while (a[i] != key) {
        ++i;
    }
    return (i < end) ? i : endIsKey ? end : -1;
}

int BinarySearch(int* a, int n, int key) {
    int left { 0 };
    int right { n - 1 };
    int mid { 0 };
    while (left <= right) {
        mid = (left + right) / 2;
        if (a[mid] == key)
            return mid;
        if (a[mid] > key) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return -1;
}

int RecursiveBinarySearch(int* a, int left, int right, int key) {
    if (left > right) {
        return -1;
    }

    int mid { (right + left) / 2 };
    if (a[mid] == key) {
        return mid;
    }

    if (a[mid] > key) {
        RecursiveBinarySearch(a, left, mid-1, key);
    }
    else {
        RecursiveBinarySearch(a, mid+1, right, key);
    }
}