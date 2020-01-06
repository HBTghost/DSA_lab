#include <iostream>
#include <chrono>
#include <fstream>
#include <cmath>
#include <time.h>
#include <vector>
#include <fstream>

#include "Sort.h"
#include "DataGenerator.h"



int main(int argc, char const *argv[])
{
    std::ofstream out {"output.csv"};
    std::vector<int> size { 1000, 3000, 10000, 30000, 100000, 300000, 1000000 };
    std::vector<std::string> order { "Randomized Input", "Sorted Input", "Reversed Input", "Nearly Sorted Input" };

    int *_arr;
    int *_tempArr;

    for (int _order = 0; _order < 4; ++_order) {
        out << "\n\n\n" << order[_order] << "\n";
		out << ",Selection Sort,Insertion Sort,Binary Insertion Sort,Bubble Sort,Shaker Sort,Shell Sort,Heap Sort,Merge Sort,Quick Sort,Counting Sort,Counting Radix Sort,Flash Sort\n";

        for (auto _size : size) {
            std::string temp { std::to_string(_size) };

            _arr = new int [_size];
            _tempArr = new int [_size];

            GenerateData(_arr, _size, _order);
            std::copy(_arr, _arr + _size, _tempArr);

            for (int _sort = 0; _sort < 12; ++_sort) {
                temp += "," + std::to_string(RunSort(_arr, _size, _sort, false));

                std::copy(_tempArr, _tempArr + _size, _arr);
            }
            temp += "\n";
            out << temp;
            
            delete[] _arr;
            delete[] _tempArr;
        }
    }
    out.close();

    return 0;
}