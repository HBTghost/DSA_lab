#include "NODE.h"

std::vector<std::string> Split(std::string strToSplit, char delimeter) {
    std::stringstream ss(strToSplit);
    std::string item;
    std::vector<std::string> splittedStrings;
    while (std::getline(ss, item, delimeter)) {
        splittedStrings.push_back(item);
    }
    return splittedStrings;
}

STUDENT::STUDENT(std::string line_info) {
    std::vector<std::string> v { Split(line_info, ',') };

    this->id = v[0];
    this->math = std::stof(v[1]);
    this->literature = std::stof(v[2]);
    this->foreignLang = std::stof(v[3]);
    this->note = v[4];
}

float SumPoint(STUDENT stu) {
    float sum = (stu.math + stu.literature + stu.foreignLang);
    return sum;
}

bool equal(float a, float b) {
    return (std::fabs(a-b) < epsilon);
}

std::vector<STUDENT> ReadData(std::string file_name) {
    std::ifstream fin(file_name);
    std::vector<STUDENT> res;
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


Ref CreateNode(STUDENT stu) {
    Ref obj = new NODE;
    obj->stu = stu;
    obj->key = SumPoint(stu);
    return obj;
}

int UpdateHeight(Ref& obj) {
    int left = 0;
    int right = 0;
    if (obj->pLeft) {
        left = obj->pLeft->height;
    }
    if (obj->pRight) {
        right = obj->pRight->height;
    }
    return obj->height = (left > right ? left : right) + 1;
}
int GetBalance(Ref obj) {
    if (obj) {
        if (obj->pLeft and obj->pRight) {
            return obj->pLeft->height - obj->pRight->height;
        }
        return 1;
    }
    return 0;
}

Ref RightRotate(Ref& root) {
    Ref tmp = root;
    Ref x = tmp->pLeft;
    Ref T2 = x->pRight;

    x->pRight = tmp;
    tmp->pLeft = T2;

    UpdateHeight(tmp);
    UpdateHeight(x);

    root = x;

    return root;
}
Ref LeftRotate(Ref& root) {
    Ref tmp = root;
    Ref y = tmp->pRight;
    Ref T2 = y->pLeft;

    y->pLeft = tmp;
    tmp->pRight = T2;

    UpdateHeight(tmp);
    UpdateHeight(y);

    root = y;

    return root;
}

void Insert(Ref& p_root, STUDENT stu) {
    if (!p_root) {
        p_root = CreateNode(stu);
        return;
    }

    float x = SumPoint(stu);
    if (!equal(x, p_root->key) && p_root->key > x)  
        Insert(p_root->pLeft, stu);
    else
        Insert(p_root->pRight, stu);

    UpdateHeight(p_root);
    int balance = GetBalance(p_root);

    if (balance > 1) {
        if (x > p_root->pLeft->key || equal(x, p_root->pLeft->key)) {
            LeftRotate(p_root->pLeft);
        }
        RightRotate(p_root);
    }
    else if (balance < -1) {
        if (x < p_root->pRight->key && !equal(x, p_root->pRight->key)) {
            RightRotate(p_root->pRight);
        }
        LeftRotate(p_root);
    }
}

Ref StoreData(std::string file_name) {
    std::vector<STUDENT> students = ReadData(file_name);
    Ref root { nullptr };
    for (auto x : students) {
        Insert(root, x);
    }
    return root;
}

//=========== Các hàm yêu cầu ==============//

void DisplayIDs(Ref root) {
    if (root) {
        DisplayIDs(root->pLeft);
        std::cout << root->stu.id << "\n";
        DisplayIDs(root->pRight);
    }
}

int Height(Ref root) {
    return root ? root->height : 0;
}

std::vector<std::string> SearchEqual(Ref root, float s) {
    std::vector<std::string> res;
    Ref tmp = root;
    while (tmp) {
        if (equal(s, tmp->key)) {
            res.push_back(tmp->stu.id);
            tmp = tmp->pRight;
        }
        else if (tmp->key > s) {
            tmp = tmp->pLeft;
        }
        else {
            tmp = tmp->pRight;
        }
    }
    return res;
}

std::vector<std::string> SearchGreater(Ref root, float s) {
    std::vector<std::string> res;
    Ref tmp = root;
    while (tmp) {
        if (equal(tmp->key, s) || tmp->key > s) {
            res.push_back(tmp->stu.id);
            std::vector<std::string> b = SearchGreater(tmp->pRight, s);
            res.insert(std::end(res), std::begin(b), std::end(b));
            tmp = tmp->pLeft;
        }
        else {
            tmp = tmp->pRight;
        }
    }
    return res;
}

//========//
void Release(Ref& root) {
    if (root) {
        Release(root->pLeft);
        Release(root->pRight);
        delete root;
        root = nullptr;
    }
}
