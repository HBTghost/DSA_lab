#include "AVLtree.h"

//==============//

NODE_AVL::NODE_AVL(int data) : key{ data } {};
NODE_AVL::NODE_AVL(int data, int height) : key{ data }, height{ height} {};

int NODE_AVL::calc_height() { return (this ? this->height : 0); }
int NODE_AVL::updateHeight() {
    return this->height = std::max(this->p_left->calc_height(), this->p_right->calc_height()) + 1;
}

//==============//

Ref_AVL createNode(int data) {
    Ref_AVL obj = new NODE_AVL(data);
    return obj;
}
Ref_AVL Min(Ref_AVL root) {
    Ref_AVL tmp = root;
    if (tmp) {
        while (tmp->p_left) {
            tmp = tmp->p_left;
        }
        return tmp;
    }
}
int getBalance(Ref_AVL obj) {  
    return (obj ? obj->p_left->calc_height() - obj->p_right->calc_height() : 0);
}

//==============//

AVLtree::AVLtree(Ref_AVL obj) : root{ obj } {}
AVLtree::AVLtree(int data) : root{ createNode(data) } {}

AVLtree::~AVLtree() { removeAll(root); }

void AVLtree::Insert(int x) { Insert(root, x); }
void AVLtree::Remove(int x) { Remove(root, x); }

void AVLtree::NLR() { NLR(root); }
void AVLtree::LNR() { LNR(root); }
void AVLtree::LRN() { LRN(root); }
void AVLtree::LevelOrder() {
    if (root) {
        std::queue<Ref_AVL> p1, tmp;
        p1.push(root);

        do {
            while (!p1.empty()) {
                std::cout << p1.front()->key << "-" << p1.front()->height << " ";
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

    //==============//

bool AVLtree::isAVL() { return isAVL(root); }

//====================//

void AVLtree::removeAll(Ref_AVL root) {
    if (root) {
        removeAll(root->p_left);
        removeAll(root->p_right);
        delete root;
        root = nullptr;
    }
}

Ref_AVL AVLtree::rightRotate(Ref_AVL& root) {
    Ref_AVL tmp = root;
    Ref_AVL x = tmp->p_left;
    Ref_AVL T2 = x->p_right;

    x->p_right = tmp;
    tmp->p_left = T2;

    tmp->updateHeight();
    x->updateHeight();

    root = x;

    return root;
}
Ref_AVL AVLtree::leftRotate(Ref_AVL& root) {
    Ref_AVL tmp = root;
    Ref_AVL y = tmp->p_right;
    Ref_AVL T2 = y->p_left;

    y->p_left = tmp;
    tmp->p_right = T2;

    tmp->updateHeight();
    y->updateHeight();

    root = y;

    return root;
}

Ref_AVL AVLtree::Insert(Ref_AVL& p_root, int x) {
    if (!p_root)  
        return createNode(x);

    if (x < p_root->key)  
        p_root->p_left = Insert(p_root->p_left, x);
    else if (x > p_root->key)  
        p_root->p_right = Insert(p_root->p_right, x);
    else
        return p_root;

    p_root->updateHeight();
    int balance = getBalance(p_root);

    if (balance > 1) {
        if (x > p_root->p_left->key) {
            leftRotate(p_root->p_left);
        }
        return rightRotate(p_root);
    }
    else if (balance < -1) {
        if (x < p_root->p_right->key) {
            rightRotate(p_root->p_right);
        }
        return leftRotate(p_root);
    }

    return p_root;
}
Ref_AVL AVLtree::Remove(Ref_AVL& root, int key) {  
    if (!root)
        return root;

    if (key < root->key)  
        root->p_left = Remove(root->p_left, key);  
    else if (key > root->key)  
        root->p_right = Remove(root->p_right, key);  
    else {  
        if (!root->p_left || !root->p_right) {  
            Ref_AVL temp = root->p_left ? root->p_left : root->p_right;  

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
            Ref_AVL temp = Min(root->p_right);  

            root->key = temp->key;  
            root->p_right = Remove(root->p_right, temp->key);  
        }  
    }  

    if (!root)  
        return root;  

    root->updateHeight();

    int balance = getBalance(root);  

    if (balance > 1) {
        if (getBalance(root->p_left) < 0) {
            leftRotate(root->p_left);
        }
        return rightRotate(root);
    }

    if (balance < -1) {
        if (getBalance(root->p_right) > 0) {
            rightRotate(root->p_right);
        }
        return leftRotate(root);
    }

    return root;  
}

void AVLtree::NLR(Ref_AVL p_root) {
    if (p_root) {
        std::cout << p_root->key << "-" << p_root->height << " ";
        NLR(p_root->p_left);
        NLR(p_root->p_right);
    }
}
void AVLtree::LNR(Ref_AVL p_root) {
    if (p_root) {
        LNR(p_root->p_left);
        std::cout << p_root->key << "-" << p_root->height << " ";
        LNR(p_root->p_right);
    }
}
void AVLtree::LRN(Ref_AVL p_root) {
    if (p_root) {
        LRN(p_root->p_left);
        LRN(p_root->p_right);
        std::cout << p_root->key << "-" << p_root->height << " ";
    }
}

bool AVLtree::isAVL(Ref_AVL root, Ref_AVL l, Ref_AVL r) { 
    if (root == nullptr) 
        return true; 

    if (l != nullptr and root->key <= l->key) 
        return false; 

    if (r != nullptr and root->key >= r->key) 
        return false; 

    if (std::abs(getBalance(root)) > 1) {
        return false;
    }

    return isAVL(root->p_left, l, root) && isAVL(root->p_right, root, r); 
}