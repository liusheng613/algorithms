#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

template <typename Type>
struct BinaryTree 
{
    Type key;
    struct BinaryTree * parent;
    struct BinaryTree * left;
    struct BinaryTree * right;
    BinaryTree()
    {
        parent = nullptr;
        left = nullptr;
        right = nullptr;
    };
};

template <typename Type>
class BinarySearchTree
{
public:
    BinarySearchTree();
    ~BinarySearchTree();
    void InOrderTreeWalk(BinaryTree <Type> * root);
    // BinaryTree <Type> * TreeSearch(BinaryTree <Type> * root,Type k);
    // BinaryTree <Type> * IterativeTreeSearch(BinaryTree <Type> * root,Type k);
    // BinaryTree <Type> * TreeMinimum(BinaryTree <Type> * root);
     //BinaryTree <Type> * TreeSucessor(BinaryTree <Type> * root);
     void TreeInsert(BinaryTree <Type> * & root,BinaryTree <Type> * node);
    // void TransPlant(BinaryTree <Type> * root,BinaryTree <Type> * pOld,BinaryTree <Type> * pNew);
    // void TreeDelete(BinaryTree <Type> * root，BinaryTree <Type> * node);
private:
    BinaryTree <Type> * m_pBinaryTree;
};

#endif