#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <cmath>

//==========//
const float epsilon { 0.0001 };

//==========//
struct STUDENT {
    STUDENT() = default;
    STUDENT(std::string line_info);

    std::string id { "" };
    float math { 0 };
    float literature { 0 };
    float foreignLang { 0 };
    std::string note { "" };
};

//============//
typedef struct NODE* Ref;
struct NODE {
    STUDENT stu;
    float key { 0.0 };
    Ref pLeft { nullptr };
    Ref pRight { nullptr };
    int height { 1 };
};

Ref StoreData(std::string file_name);
void Release(Ref& root);

//=========== Các hàm yêu cầu ==============//

void DisplayIDs(Ref root);
int Height(Ref root);
std::vector<std::string> SearchEqual(Ref root, float s);
std::vector<std::string> SearchGreater(Ref root, float s);

//===========//