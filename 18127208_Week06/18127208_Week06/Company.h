#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

//==================//

const int TableSize = 2000;

std::vector<std::string> split(std::string strToSplit, char delimeter);

class Company {
public:
    Company() = default;
    Company(std::string line_info);

    ~Company() = default;

    long long HashString();
    std::string getName();

    friend std::ostream& operator<<(std::ostream& out, Company com);

private:
    std::string name { "" };
    std::string profit_tax { "" };
    std::string address { "" };
};

//==================//


std::vector<Company> ReadCompanyList(std::string file_name);

Company* CreateHashTable(std::vector<Company> list_company);
void Insert(Company* hash_table, Company company);
Company* Search(Company* hash_table, std::string company_name);