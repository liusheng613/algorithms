#include "binarySearchTree.h"
#include <iostream>
#include <random>

template <typename Type>
BinarySearchTree<Type>::BinarySearchTree()
{
    CreateTree();
}

template <typename Type>
BinarySearchTree<Type>::~BinarySearchTree()
{
    DestroyTree(m_pRoot);
}

template <typename Type>
void BinarySearchTree<Type>::CreateTree()
{
    BinaryTreeNode <Type> * node = nullptr;
    //随机产生10个数,构造初始的二叉搜索数
    for(int i = 0;i<10;i++)
    {
        node = new BinaryTreeNode<Type> ();
        node->key = GeneratorRandomData(1,200);
        TreeInsert(node);
    }
}

/*
1.一个给定的随机数发生器一直会生成相同的随机数序列。
一个函数如果定义了局部的随机数发生器，应该将其（包括引擎和分布对象）定义为static的，
否则每次调用函数都会生成相同的序列。也就是说定义成static后每次调用还是之前那个发生器，
第一次调用产生一批随机数，再次调用将产生接下来的随机数，否则每次调用产生的都是最前面的那些随机数。

2.依然需要使用time来做为种子产生每个不同时刻都不同的随机序列，但由于time默认返回的是以秒计的时间，
所以有可能多次使用的都是相同的种子。
*/
template <typename Type>
Type BinarySearchTree<Type>::GeneratorRandomData(int low,int high)
{
    static std::default_random_engine engine(time(NULL));
    static std::uniform_int_distribution<Type> distribution(low,high);

    return distribution(engine);
}

//Delete the tree 
template <typename Type>
void BinarySearchTree<Type>::DestroyTree(BinaryTreeNode <Type> * & root)
{
    
    if(root != nullptr)
    {
        BinaryTreeNode <Type> * pLeft = root->left;
        BinaryTreeNode <Type> * pRight = root->right;
        DestroyTree(pLeft);
        std::cout<<"delete node key="<<root->key<<std::endl;
        delete root;
        root = nullptr;
        DestroyTree(pRight);
    }
}

template <typename Type>
void BinarySearchTree<Type>::TreeInsert(BinaryTreeNode <Type> * node)
{
    BinaryTreeNode <Type> * x = m_pRoot;
    BinaryTreeNode <Type> * y = nullptr;
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
        m_pRoot = node;
        std::cout<<"m_pRoot=node"<<std::endl;
    }
    else if(node->key < y->key)
    {
        y->left = node;
    }
    else
    {
        y->right = node;
    }
}

template <typename Type>
void BinarySearchTree<Type>::InOrderTreeWalk()
{
    InOrderTreeWalk(m_pRoot);
}

template <typename Type>
void BinarySearchTree<Type>::InOrderTreeWalk(BinaryTreeNode <Type> * root)
{
    if(root != nullptr)
    {
        InOrderTreeWalk(root->left);
        std::cout<<"node data is:"<<root->key<<std::endl;
        InOrderTreeWalk(root->right);
    }
}

template <typename Type>
BinaryTreeNode <Type> * BinarySearchTree<Type>::TreeSearch(BinaryTreeNode <Type> * root,Type k)
{
    if(root == nullptr ||  root->key == k )
    {
        return root;
    }

    if(k < root->key)
    {
        return TreeSearch(root->left,k);
    }
    else
    {
        return TreeSearch(root->right,k);
    }
}

template <typename Type>
BinaryTreeNode <Type> * BinarySearchTree<Type>::IterativeTreeSearch(BinaryTreeNode <Type> * root,Type k)
{
    BinaryTreeNode <Type> * node = root;
    while(node != nullptr && node->key != k)
    {
        if(k < node->key)
        {
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }

    return node;
}

template <typename Type>
BinaryTreeNode <Type> * BinarySearchTree<Type>::TreeMinimum(BinaryTreeNode <Type> * root)
{
    //如果root不传值,默认为根节点
    if(root == nullptr)
    {
        root = m_pRoot;
    }

    BinaryTreeNode <Type> * node = root;
    while(node->left != nullptr)
    {
        node = node->left;
    }

    return node;
}

template <typename Type>
BinaryTreeNode <Type> * BinarySearchTree<Type>::TreeMaxmum(BinaryTreeNode <Type> * root)
{
    //如果root不传值,默认为根节点
    if(root == nullptr)
    {
        root = m_pRoot;
    }

    BinaryTreeNode <Type> * node = root;
    while(node->right != nullptr)
    {
        node = node->right;
    }

    return node;
}

template <typename Type>
BinaryTreeNode <Type> * BinarySearchTree<Type>::TreeSuccessor(BinaryTreeNode <Type> * node)
{
    //如果node不传值,默认为根节点
    if(node == nullptr)
    {
        node = m_pRoot;
    }

    if(node->right != nullptr)
    {
        return TreeMinimum(node->right);
    }

    BinaryTreeNode <Type> * parent = node->parent;
    while(parent != nullptr && node == parent->right)
    {
        node = parent;
        parent = node->parent;
    }

    return parent;
}

template <typename Type>
void BinarySearchTree<Type>::TreeDelete(BinaryTreeNode <Type> * & root,BinaryTreeNode <Type> * & node)
{
    if(node->left == nullptr)
    {
        TransPlant(root,node,node->right);
    }
    else if(node->right == nullptr)
    {
        TransPlant(root,node,node->left);
    }
    else
    {
        //y is the successor of node,doesn't hava left child
        BinaryTreeNode <Type> * y = TreeMinimum(node->right);
        if(y->parent != node)
        {
            TransPlant(root,y,y->right);
            y->right = node->right;
            y->right->parent = y;
        }
        TransPlant(root,node,y);
        y->left = node->left;
        y->left->parent = y;
    }
}

template <typename Type>
void BinarySearchTree<Type>::TransPlant(BinaryTreeNode <Type> * & root,BinaryTreeNode <Type> * & pOld,BinaryTreeNode <Type> * & pNew)
{
    if(pOld->parent == nullptr)
    {
        root = pNew;
    }
    else if(pOld == pOld->parent->left)
    {
        pOld->parent->left = pNew;
    }
    else
    {
        pOld->parent->right = pNew;
    }

    if(pNew != nullptr)
    {
        pNew->parent = pOld->parent;
    }
    delete pOld;
    pOld = nullptr;
}

template <typename Type>
BinaryTreeNode <Type> * BinarySearchTree<Type>::GetRoot() const
{
    return m_pRoot;
}

int main()
{
    BinarySearchTree<int> * tree = new BinarySearchTree<int>();

    tree->InOrderTreeWalk();
    std::cout<<"----------------------------"<<std::endl;
    BinaryTreeNode <int> * pMax = tree->TreeMaxmum();
    std::cout<<"Max node value is:"<<pMax->key<<std::endl;

    std::cout<<"----------------------------"<<std::endl;
    BinaryTreeNode <int> * pMin = tree->TreeMinimum();
    std::cout<<"Min node value is:"<<pMin->key<<std::endl;

    std::cout<<"----------------------------"<<std::endl;
    BinaryTreeNode <int> * pMinSuccessor = tree->TreeSuccessor(pMin);
    std::cout<<"pMinSuccessor node value is:"<<pMinSuccessor->key<<std::endl;

    std::cout<<"----------------------------"<<std::endl;
    BinaryTreeNode <int> * pRootSuccessor = tree->TreeSuccessor();
    std::cout<<"Root's Successor node value is:"<<pRootSuccessor->key<<std::endl;

    std::cout<<"----------------------------"<<std::endl;
    BinaryTreeNode <int> * pRoot = tree->GetRoot();
    BinaryTreeNode <int> * pIterSearch = tree->IterativeTreeSearch(pRoot,pRoot->key);
    BinaryTreeNode <int> * pRecSearch = tree->TreeSearch(pRoot,pRoot->key);
    if(pRoot->key==pIterSearch->key && pIterSearch->key==pRecSearch->key)
    {
        std::cout<<"Search Success and the root node value is:"<<pIterSearch->key<<std::endl;
    }

    std::cout<<"----------------------------"<<std::endl;
    tree->TreeDelete(pRoot,pRoot->right);
    std::cout<<"After delete pRoot->right,treeWalk"<<std::endl;
    tree->InOrderTreeWalk();

    std::cout<<"----------------------------"<<std::endl;
    delete tree;
    return 0;
}