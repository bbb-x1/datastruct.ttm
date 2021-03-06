#include <iostream>
#include<time.h>
using namespace std;

//二叉搜索树的定义
typedef struct BSTNode{
    int value;
    BSTNode* left;
    BSTNode* right;
}BSTNode,*BSTree;

//查找操作
bool SearchBSTNode(BSTree T, int value, BSTNode*& parent, BSTNode*& target)
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

//删除操作
void DeleteBSTNode(BSTree& T, int value)
{
    BSTNode* parent = nullptr, * target=nullptr;

    if (SearchBSTNode(T, value, parent, target))    //目标结点存在则进行删除结点操作
    {
        if (!parent)
        {
            T = nullptr;
            return;
        }

        BSTNode* candidate = target, * candidateOfParent = target;

        if (!target->left && !target->right)    //目标结点为叶子结点则直接删除
        {
            if (target == parent->left)
                parent->left = nullptr;
            else
                parent->right = nullptr;
            return;
        }

        if (target->left)                       //目标结点1)有左子树,则找到左子树最右结点;2)有右子树,则找到右子树最左结点。
        {
            candidate = target->left;
            while (candidate->right)
            {
                candidateOfParent = candidate;
                candidate = candidate->right;
            }
        }
        else                                    
        {
            candidate = target->right;
            while (candidate->left)
            {
                candidateOfParent = candidate;
                candidate = candidate->left;
            }
        }
        target->value = candidate->value;
        if (candidate == candidateOfParent->left)
            candidateOfParent->left = candidate->right;
        else
            candidateOfParent->right = candidate->left;
    }
}

//插入操作
void InsertBSTNode(BSTree& T, int value)
{
    BSTNode* parent = nullptr, *target = nullptr;
    if (!SearchBSTNode(T, value, parent, target))   //找到目标结点的位置
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

void CreateBSTree(BSTree& T, int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        InsertBSTNode(T, arr[i]);
    }
}
//中序遍历
void InOrder(BSTree& T)
{
    if (T)
    {
        std::cout << T->value << " ";
        InOrder(T->left);
        InOrder(T->right);
    }
}
int main()
{
    BSTree T = nullptr;
    srand(time(0));
    int* arr = (int*)malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 100;
    }
    CreateBSTree(T, arr, 10);
    for (int i = 0; i < 10; i++)
    {
        int j = rand() % 10;
        DeleteBSTNode(T, arr[j]);
    }
    return 0;
}
