#include "Examinee.h"

int main(int argc, char const *argv[])
{
    std::string file_in_path { "data.txt" };
    std::string file_out_path { "result.txt" };
    std::vector<Examinee> v { ReadExamineeList(file_in_path) };
    WriteSumOfScore(v, file_out_path);
    std::cout << "Done!\n";
    
    return 0;
}