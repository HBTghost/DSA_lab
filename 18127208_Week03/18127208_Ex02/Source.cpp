#include "Examinee.h"

int main(int argc, char const *argv[])
{
    std::string file_path { "data.txt" };

    std::vector<Examinee> v { ReadExamineeList(file_path) };
    
    for (auto x : v) {
        info(x);
        std::cout << "######\n";
    }

    return 0;
}