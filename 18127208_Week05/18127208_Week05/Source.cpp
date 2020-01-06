#include "BinarySearchTree.h"
// #include "AVLtree.h"

int main(int argc, char const *argv[])
{
    Ref_BST root = createNode(5);
    Ref_BST left = createNode(3);
    Ref_BST right = createNode(7);
    root->p_left = left;
    root->p_right = right;
    left->p_left = createNode(2);
    left->p_right = createNode(4);
    right->p_left = createNode(6);
    right->p_right = createNode(8);

    BinarySearchTree tree(root);

    tree.Insert(-1);
    tree.Insert(0);
    tree.Insert(-2);

    tree.LevelOrder();

    tree.Remove(2);
    tree.LevelOrder();

    std::cout << "\n" << tree.isBST();

    // Ref_AVL root = createNode(9);
    // AVLtree tree(root);
    // tree.Insert(5);
    // tree.Insert(10);
    // tree.Insert(0);
    // tree.Insert(6);
    // tree.Insert(11);
    // tree.Insert(-1);
    // tree.Insert(1);
    // tree.Insert(2);

    // tree.NLR();

    // tree.Remove(10);
    // tree.Remove(0);
    // tree.Remove(6);
    // tree.Remove(-1);
    // std::cout << "\n" << tree.isAVL() << " ==============================\n";

    // tree.NLR();

    // std::cout << "\n" << tree.isAVL() << "\n";

    return 0;
}