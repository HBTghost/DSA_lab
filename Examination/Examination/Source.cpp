#include "NODE.h"

const std::string file_name { "data.txt" };

int main(int argc, char const *argv[])
{
    // Doc file
    Ref root = StoreData(file_name);

    // Cau 1
    std::cout << "ID of students who has ascending oder average point:\n";
    DisplayIDs(root);

    // Cau 2
    std::cout << "Height: " << Height(root) << "\n";

    // Cau 3
    float s { 14.85 };
    std::cout << "ID of students who has average point is " << s << ": \n";
    std::vector<std::string> aver = SearchEqual(root, s);
    for (auto x : aver) {
        std::cout << x << "\n";
    }

    // Cau 4
    s = 14.3;
    std::cout << "ID of students who has average point greater than " << s << ": \n";
    std::vector<std::string> grea = SearchGreater(root, s);
    for (auto x : grea) {
        std::cout << x << "\n";
    }

    // Giai phong bo nho
    Release(root);

    return 0;
}