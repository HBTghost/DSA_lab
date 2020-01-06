#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>

struct Examinee
{
    Examinee() = default;
    Examinee(std::string line_info);
    std::string id;
    float math, literature, physic, chemistry, biology, history, geography, civic_education, natural_science, social_science, foreign_language;
};

std::vector<std::string> split(std::string strToSplit, char delimeter);
Examinee ReadExaminee(std::string line_info);
void info(Examinee input);

std::vector<Examinee> ReadExamineeList(std::string file_name);