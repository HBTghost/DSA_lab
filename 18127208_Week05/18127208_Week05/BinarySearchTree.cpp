#include "BinarySearchTree.h"

//==============//

NODE_BST::NODE_BST(int data) : key{ data } {};

//==============//

Ref_BST createNode(int data) {
    Ref_BST obj = new NODE_BST(data);
    return obj;
}
Ref_BST Min(Ref_BST root) {
    Ref_BST tmp = root;
    if (tmp) {
        while (tmp->p_left) {
            tmp = tmp->p_left;
        }
        return tmp;
    }
}

//==============//

BinarySearchTree::BinarySearchTree(Ref_BST obj) : root{ obj } {};
BinarySearchTree::BinarySearchTree(int data) : root{ createNode(data) } {};

BinarySearchTree::~BinarySearchTree() { removeAll(root); }

void BinarySearchTree::NLR() { NLR(root); }
void BinarySearchTree::LNR() { LNR(root); }
void BinarySearchTree::LRN() { LRN(root); }
void BinarySearchTree::LevelOrder() {
    if (root) {
        std::queue<Ref_BST> p1, tmp;
        p1.push(root);

        do {
            while (!p1.empty()) {
                std::cout << p1.front()->key << " ";
                if (p1.front()->p_left) {
                    tmp.push(p1.front()->p_left);
                }
                if (p1.front()->p_right) {
                    tmp.push(p1.front()->p_right);
                }
                p1.pop();
            }
            std::cout << "\n";
            p1.swap(tmp);
        } while (!p1.empty());
    }
}

Ref_BST BinarySearchTree::Search(int x) {
    Ref_BST tmp = root;
    while (tmp) {
        if (tmp->key == x) {
            return tmp;
        }
        else if (tmp->key > x) {
            tmp = tmp->p_left;
        }
        else {
            tmp = tmp->p_right;
        }
    }
    return nullptr;
}
void BinarySearchTree::Insert(int x) { Insert(root, x); }
void BinarySearchTree::Remove(int x) { Remove(root, x); }

int BinarySearchTree::Height() { return Height(root); }
int BinarySearchTree::CountNode() { return CountNode(root); }
int BinarySearchTree::Level(Ref_BST p) {
    if (root) {
        std::queue<Ref_BST> p1, tmp;
        p1.push(root);
        int level = 1;

        do {
            while (!p1.empty()) {
                if (p1.front()->key == p->key) {
                    return level;
                }
                if (p1.front()->p_left) {
                    tmp.push(p1.front()->p_left);
                }
                if (p1.front()->p_right) {
                    tmp.push(p1.front()->p_right);
                }
                p1.pop();
            }
            p1.swap(tmp);
            level++;
        } while (!p1.empty());
    }
    return 0;
}
int BinarySearchTree::CountLeaf() { return CountLeaf(root); }
int BinarySearchTree::CountLess(int x) { return CountLess(root, x); }
int BinarySearchTree::CountGreater(int x) { return CountGreater(root, x); }

bool BinarySearchTree::isBST() { return isBST(root); }

//============//

void BinarySearchTree::removeAll(Ref_BST root) {
    if (root) {
        removeAll(root->p_left);
        removeAll(root->p_right);
        delete root;
        root = nullptr;
    }
}

void BinarySearchTree::NLR(Ref_BST p_root) {
    if (p_root) {
        std::cout << p_root->key << " ";
        NLR(p_root->p_left);
        NLR(p_root->p_right);
    }
}
void BinarySearchTree::LNR(Ref_BST p_root) {
    if (p_root) {
        LNR(p_root->p_left);
        std::cout << p_root->key << " ";
        LNR(p_root->p_right);
    }
}
void BinarySearchTree::LRN(Ref_BST p_root) {
    if (p_root) {
        LRN(p_root->p_left);
        LRN(p_root->p_right);
        std::cout << p_root->key << " ";
    }
}

void BinarySearchTree::Insert(Ref_BST& r, int k) {
    if (r == nullptr)
        r = createNode(k);
    else if (r->key > k)
        Insert(r->p_left, k);
    else if (r->key < k)
        Insert(r->p_right, k);
    else
        return;
}
Ref_BST BinarySearchTree::Remove(Ref_BST& root, int key) {
    if (!root)  
        return root;  
    
    if (key < root->key)  
        root->p_left = Remove(root->p_left, key);  
    else if (key > root->key)  
        root->p_right = Remove(root->p_right, key);  
    else {  
        if (!root->p_left || !root->p_right) {  
            Ref_BST temp = root->p_left ? root->p_left : root->p_right;  
            
            if (!temp)  {  
                temp = root;  
                root = nullptr;  
            }  
            else {
                *root = *temp; 
            }

            delete temp;  
            temp = nullptr;
        }  
        else {  
            Ref_BST temp = Min(root->p_right);  
            
            root->key = temp->key;  
            root->p_right = Remove(root->p_right, temp->key);  
        }  
    }
    return root;
}

int BinarySearchTree::Height(Ref_BST p_root) {
    if (p_root) {
        int left = Height(p_root->p_left);
        int right = Height(p_root->p_right);

        return 1 + std::max(left, right);
    }
    return 0;
}
int BinarySearchTree::CountNode(Ref_BST p_root) {
    if (p_root) {
        return 1 + CountNode(p_root->p_left) + CountNode(p_root->p_right);
    }
    return 0;
}
int BinarySearchTree::CountLeaf(Ref_BST p_root) {
    if (p_root) {
        if (!p_root->p_left && !p_root->p_right) {
            return 1;
        }
        return CountLeaf(p_root->p_left) + CountLeaf(p_root->p_right);
    }
    return 0;
}
int BinarySearchTree::CountLess(Ref_BST p_root, int x) {
    if (p_root) {
        int left = CountLess(p_root->p_left, x);
        if (p_root->key >= x) {
            return left;
        }
        else {
            int right = CountLess(p_root->p_right, x);
            return 1 + left + right;
        }
    }
    return 0;
}
int BinarySearchTree::CountGreater(Ref_BST p_root, int x) {
    if (p_root) {
        int right = CountGreater(p_root->p_right, x);
        if (p_root->key <= x) {
            return right;
        }
        else {
            int left = CountGreater(p_root->p_left, x);
            return 1 + left + right;
        }
    }
    return 0;
}

bool BinarySearchTree::isBST(Ref_BST root, Ref_BST l, Ref_BST r) { 
    if (root == nullptr) 
        return true; 

    if (l != nullptr and root->key <= l->key) 
        return false; 

    if (r != nullptr and root->key >= r->key) 
        return false; 

    return isBST(root->p_left, l, root) && isBST(root->p_right, root, r); 
}