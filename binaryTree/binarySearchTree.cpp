#include "binarySearchTree.h"
#include <iostream>
template <typename Type>
BinarySearchTree<Type>::BinarySearchTree()
{

}

template <typename Type>
BinarySearchTree<Type>::~BinarySearchTree()
{
    
}

template <typename Type>
void BinarySearchTree<Type>::TreeInsert(BinaryTree <Type> * & root,BinaryTree <Type> * node)
{
    BinaryTree <Type> * x = root;
    BinaryTree <Type> * y = nullptr;
    while(x != nullptr)
    {
        y = x;
        if(node->key < x->key)
        {
            x = x->left;
        }
        else 
        {
            x = x->right;
        }
    }

    node->parent = y;
    if(y == nullptr)
    {
        root = node;
        std::cout<<"root=node"<<std::endl;
    }
    else if(node->key < y->key)
    {
        y->left = node;
    }
    else
    {
        y->right = node;
    }

    std::cout<<"1111root->key="<<root->key<<std::endl;
}

template <typename Type>
void BinarySearchTree<Type>::InOrderTreeWalk(BinaryTree <Type> * root)
{
    if(root != nullptr)
    {
        InOrderTreeWalk(root->left);
        std::cout<<"node data is:"<<root->key<<std::endl;
        InOrderTreeWalk(root->right);
    }
}

int main()
{
    BinarySearchTree<int> * tree = new BinarySearchTree<int>();
    BinaryTree <int> * root = nullptr;
    BinaryTree <int> * node = new BinaryTree <int>();
    node->key = 5;
    tree->TreeInsert(root,node);
    std::cout<<"root->key="<<root->key<<std::endl;
    tree->InOrderTreeWalk(root);
    return 0;
}