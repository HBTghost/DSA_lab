#include "Company.h"

int main(int argc, char const *argv[])
{
    std::vector<Company> v { ReadCompanyList("MST.txt") };
    Company* table = CreateHashTable(v);

    Company tmp("Now|012345678|Q5, HCM city");

    Insert(table, tmp);

    Company* res = Search(table, "Now");
    if (res) {
        std::cout << *res;
    }
    else {
        std::cout << "This company does not exist in Hash Table\n";
    }

    delete[] table;
    return 0;
}