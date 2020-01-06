#pragma once
#include <iostream>
#include <queue>


typedef class NODE_AVL* Ref_AVL;
class NODE_AVL {
public:
    explicit NODE_AVL() = default;
    explicit NODE_AVL(int data);
    explicit NODE_AVL(int data, int height);

    ~NODE_AVL() = default;

    int calc_height();
    int updateHeight();

//===============//

    int key { 0 };
    NODE_AVL* p_left { nullptr } ;
    NODE_AVL* p_right { nullptr } ;
    int height { 1 };
};

Ref_AVL createNode(int data);
Ref_AVL Min(Ref_AVL root);
int getBalance(Ref_AVL obj);

//==============//

class AVLtree {
public:
    explicit AVLtree() = default;
    explicit AVLtree(Ref_AVL obj);
    explicit AVLtree(int data);

    ~AVLtree();

    void Insert(int x);
    void Remove(int x);

    void NLR();
    void LNR();
    void LRN();
    void LevelOrder();

    bool isAVL();

private:
    Ref_AVL root { nullptr };
    
    //==============//

    void removeAll(Ref_AVL root);

    Ref_AVL rightRotate(Ref_AVL& root);
    Ref_AVL leftRotate(Ref_AVL& root);

    Ref_AVL Insert(Ref_AVL& p_root, int x);
    Ref_AVL Remove(Ref_AVL& root, int key);

    void NLR(Ref_AVL p_root);
    void LNR(Ref_AVL p_root);
    void LRN(Ref_AVL p_root);

    bool isAVL(Ref_AVL root, Ref_AVL l = nullptr, Ref_AVL r = nullptr);
};