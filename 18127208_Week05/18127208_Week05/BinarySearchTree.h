#pragma once
#include <iostream>
#include <queue>

typedef class NODE_BST* Ref_BST;
class NODE_BST {
public:
    explicit NODE_BST() = default;
    explicit NODE_BST(int data);

    ~NODE_BST() = default;

    int key { 0 };
    Ref_BST p_left { nullptr };
    Ref_BST p_right { nullptr };
};

Ref_BST createNode(int data);
Ref_BST Min(Ref_BST root);

//============//

class BinarySearchTree {
public:
    explicit BinarySearchTree() = default;
    explicit BinarySearchTree(Ref_BST obj);
    explicit BinarySearchTree(int data);

    ~BinarySearchTree();

    void NLR();
    void LNR();
    void LRN();
    void LevelOrder();

    Ref_BST Search(int x);
    void Insert(int x);
    void Remove(int x);

    int Height();
    int CountNode();
    int Level(Ref_BST p);
    int CountLeaf();
    int CountLess(int x);
    int CountGreater(int x);

    bool isBST();

private:
    Ref_BST root { nullptr };

    //=========//

    void removeAll(Ref_BST root);

    void NLR(Ref_BST p_root);
    void LNR(Ref_BST p_root);
    void LRN(Ref_BST p_root);

    void Insert(Ref_BST& r, int k);
    Ref_BST Remove(Ref_BST& r, int key);

    int Height(Ref_BST p_root);
    int CountNode(Ref_BST p_root);
    int CountLeaf(Ref_BST p_root);
    int CountLess(Ref_BST p_root, int x);
    int CountGreater(Ref_BST p_root, int x);

    bool isBST(Ref_BST root, Ref_BST l=nullptr, Ref_BST r=nullptr);
};
