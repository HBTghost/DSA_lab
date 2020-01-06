#include "Examinee.h"

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
    std::vector<std::string> v { split(line_info, ',') };
    v.erase(v.begin() + 1);
    v.erase(v.end() - 2, v.end());
    for (auto& x : v) {
        if (x == "") {
            x = "0.0";
        }
    }
    Examinee res;
    res.id               = v[0];
    res.math             = std::stof(v[1]);
    res.literature       = std::stof(v[2]);
    res.physic           = std::stof(v[3]);
    res.chemistry        = std::stof(v[4]);
    res.biology          = std::stof(v[5]);
    res.history          = std::stof(v[6]);
    res.geography        = std::stof(v[7]);
    res.civic_education  = std::stof(v[8]);
    res.natural_science  = std::stof(v[9]);
    res.social_science   = std::stof(v[10]);
    res.foreign_language = std::stof(v[11]);
    return res;
}

void info(Examinee input) {
    std::cout << input.id               << "\n";
    std::cout << input.math             << "\n";
    std::cout << input.literature       << "\n";
    std::cout << input.physic           << "\n";
    std::cout << input.chemistry        << "\n";
    std::cout << input.biology          << "\n";
    std::cout << input.history          << "\n";
    std::cout << input.geography        << "\n";
    std::cout << input.civic_education  << "\n";	
    std::cout << input.natural_science  << "\n";
    std::cout << input.social_science   << "\n";
    std::cout << input.foreign_language << "\n";
}