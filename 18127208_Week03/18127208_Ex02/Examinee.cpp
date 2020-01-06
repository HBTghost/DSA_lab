#include "Examinee.h"
Examinee::Examinee(std::string line_info) {
    std::vector<std::string> v { split(line_info, ',') };
    v.erase(v.begin() + 1);
    v.erase(v.end() - 2, v.end());
    for (auto& x : v) {
        if (x == "") {
            x = "0.0";
        }
    }

    this->id               = v[0];
    this->math             = std::stof(v[1]);
    this->literature       = std::stof(v[2]);
    this->physic           = std::stof(v[3]);
    this->chemistry        = std::stof(v[4]);
    this->biology          = std::stof(v[5]);
    this->history          = std::stof(v[6]);
    this->geography        = std::stof(v[7]);
    this->civic_education  = std::stof(v[8]);
    this->natural_science  = std::stof(v[9]);
    this->social_science   = std::stof(v[10]);
    this->foreign_language = std::stof(v[11]);
}
std::vector<std::string> split(std::string strToSplit, char delimeter)
{
    std::stringstream ss(strToSplit);
    std::string item;
    std::vector<std::string> splittedStrings;
    while (std::getline(ss, item, delimeter)) {
        splittedStrings.push_back(item);
    }
    return splittedStrings;
}

Examinee ReadExaminee(std::string line_info) {
    Examinee res(line_info);
    return res;
}

void info(Examinee input) {
    std::cout << input.id               << ",";
    std::cout << input.math             << ",";
    std::cout << input.literature       << ",";
    std::cout << input.physic           << ",";
    std::cout << input.chemistry        << ",";
    std::cout << input.biology          << ",";
    std::cout << input.history          << ",";
    std::cout << input.geography        << ",";
    std::cout << input.civic_education  << ",";    
    std::cout << input.natural_science  << ",";
    std::cout << input.social_science   << ",";
    std::cout << input.foreign_language << "\n";
}

std::vector<Examinee> ReadExamineeList(std::string file_name) {
    std::ifstream fin;
    fin.open(file_name);
    std::vector<Examinee> res;
    if (fin) {
        std::string info;
        getline(fin, info);
        while (fin.good()) {
            getline(fin, info);
            res.emplace_back(Examinee(info));
        }
    }
    return res;
}

