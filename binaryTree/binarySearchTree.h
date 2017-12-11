#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

template <typename Type>
struct BinaryTreeNode 
{
    Type key;
    struct BinaryTreeNode * parent;
    struct BinaryTreeNode * left;
    struct BinaryTreeNode * right;
    BinaryTreeNode()
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

    void InOrderTreeWalk(BinaryTreeNode <Type> * root);
    void InOrderTreeWalk();
    BinaryTreeNode <Type> * TreeSearch(BinaryTreeNode <Type> * root,Type k);//recursion search
    BinaryTreeNode <Type> * IterativeTreeSearch(BinaryTreeNode <Type> * root,Type k);//Iterative search
    BinaryTreeNode <Type> * TreeMinimum(BinaryTreeNode <Type> * root=nullptr);
    BinaryTreeNode <Type> * TreeMaxmum(BinaryTreeNode <Type> * root=nullptr);
    BinaryTreeNode <Type> * TreeSuccessor(BinaryTreeNode <Type> * node=nullptr);//find the successor of the Tree root

    void TreeInsert(BinaryTreeNode <Type> * node);
    void TreeDelete(BinaryTreeNode <Type> * & root,BinaryTreeNode <Type> * & node);

    BinaryTreeNode <Type> * GetRoot() const;
private:
    //replace the old node with the new,and adjust the tree
    void TransPlant(BinaryTreeNode <Type> * & root,BinaryTreeNode <Type> * & pOld,BinaryTreeNode <Type> * & pNew);
    void CreateTree();
    void DestroyTree(BinaryTreeNode <Type> * & root);
    Type GeneratorRandomData(int low,int high);
private:
    BinaryTreeNode <Type> * m_pRoot;
};

#endif