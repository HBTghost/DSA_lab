#include "Company.h"


//==================//

std::vector<std::string> split(std::string strToSplit, char delimeter) {
    std::stringstream ss(strToSplit);
    std::string item;
    std::vector<std::string> splittedStrings;
    while (std::getline(ss, item, delimeter)) {
        splittedStrings.push_back(item);
    }
    return splittedStrings;
}

//==================//

Company::Company(std::string line_info) {
    std::vector<std::string> v { split(line_info, '|') };

    this->name = v[0];
    this->profit_tax = v[1];
    this->address = v[2];
}

long long Company::HashString() {
    int size = this->name.size();
    std::string s { size < 20 ? this->name : this->name.substr(size-20) };

    int p { 31 };
    long double m { pow(10, 9) + 9 };
    long double sum { 0.0 };

    for (int i = 0, size = s.size(); i < size; ++i) {
        sum += int(s[i]) * pow(p, i);
    }

    return static_cast<long long>(std::fmod(sum, m));
}
std::string Company::getName() { return this->name; }

std::ostream& operator<<(std::ostream& out, Company com) {
    out << com.name << "\n";
    out << com.profit_tax << "\n";
    out << com.address << "\n";
    return out;
}

std::vector<Company> ReadCompanyList(std::string file_name) {
    std::ifstream fin;
    fin.open(file_name);
    std::vector<Company> res;
    if (fin) {
        std::string info;
        getline(fin, info);
        while (fin.good()) {
            getline(fin, info);
            res.emplace_back(info);
        }
    }
    fin.close();
    return res;
}

Company* CreateHashTable(std::vector<Company> list_company) {
    Company* table = new Company[TableSize];

    for (int i = 0, size = list_company.size(); i < size; ++i) {
        int pos { list_company[i].HashString() % TableSize };
        while ((pos < TableSize) and (table[pos].getName() != "")) {
            ++pos;
        }
        if (pos < TableSize) {
            table[pos] = list_company[i];
        }
    }
    return table;
}
void Insert(Company* hash_table, Company company) {
    int pos = { company.HashString() % TableSize };
    while ((pos < TableSize) and (hash_table[pos].getName() != "")) {
        ++pos;
    }
    if (pos < TableSize) {
        hash_table[pos] = company;
    }
}
Company* Search(Company* hash_table, std::string company_name) {
    int pos { Company(company_name+"|0|0").HashString() % TableSize };
    int tmp { pos };
    while ((tmp < TableSize) and (hash_table[tmp].HashString() % TableSize != pos)) {
        ++tmp;
    }
    if (tmp < TableSize) {
        return hash_table + tmp;
    }
    return nullptr;
}
