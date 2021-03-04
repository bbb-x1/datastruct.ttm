#include <iostream>
//The Declaration of BST
typedef struct {
    int value;
    BSTNode* left;
    BSTNode* right;
}BSTNode,*BSTree;

//Search Operation
bool SearchBSTNode(BSTree T, int value, BSTNode* parent, BSTNode* target)
{
    parent = nullptr, target = nullptr;
    if (!T)
        return false;
    target = T;
    while (target)
    {
        if (value == target->value)
        {
            return true;
        }
        else if (value < target->value)
        {
            parent = target;
            target = target->left;
        }
        else
        {
            parent = target;
            target = target->right;
        }
    }
    return false;
}

//Delete Operation
void DeleteBSTNode(BSTree& T, int value)
{

}

//Insert Opeartion
void InsertBSTNode(BSTree& T, int value)
{
    BSTNode* parent = nullptr, *target = nullptr;
    if (!SearchBSTNode(T, value, parent, target))
    {
        if (!T)
        {
            T = (BSTNode*)malloc(sizeof(BSTNode));
            T->value = value;
            T->left = nullptr;
            T->right = nullptr;
        }
        else
        {
            BSTNode* node = (BSTNode*)malloc(sizeof(BSTNode));
            node->value = value;
            node->left = nullptr;
            node->right = nullptr;
            if (value > parent->value)
                parent->right = node;
            else
                parent->left = node;
        }
    }
}


int main()
{
    std::cout << "Hello World!\n";
}
