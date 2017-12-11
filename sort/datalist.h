#ifndef __DATA_LIST__
#define __DATA_LIST__

#include<iostream>
#include <ctime>
#include <random>

template <typename Type>
class DataList
{
public:
    typedef struct Node
    {
        Type data;
        struct Node * prev;
        struct Node * next;

        Node()
        {
            prev = NULL;
            next = NULL;
        }

        Node(const Type &val)
        {
            data = val;
            prev = NULL;
            next = NULL;
        }
    }Node;

    DataList(int dataSize=10);
    ~DataList();

    void GeneratorRandomData(int number,int low,int high);
    void PrintList();
    const int size() const {return _length;}

    Type & operator [] (int i);
    const Type & operator [] (int i) const; 

    Type & front();
    const Type & front() const;

    Type & back();
    const Type & back() const;

    void push_front(const Type & val);
    void push_back(const Type & val);

    void pop_front();
    void pop_back();

    bool empty() { return _length == 0; }

    void clear();
private:
    int _length;
    Node * _top;
    Node * _back;
};


template <typename Type>
DataList<Type>::DataList(int dataSize):
_length(0),
_top(NULL),
_back(NULL)
{
    //elements = new Type[dataSize]; 
    GeneratorRandomData(dataSize,0,200);
}

template <typename Type>
DataList<Type>::~DataList()
{
    clear();
}

template <typename Type>
void DataList<Type>::clear()
{
    for(int i = 0;i<_length;++i)
    {
        pop_front();
    }
}

//调用C++11产生更加随机的随机数
/*
1.一个给定的随机数发生器一直会生成相同的随机数序列。
一个函数如果定义了局部的随机数发生器，应该将其（包括引擎和分布对象）定义为static的，
否则每次调用函数都会生成相同的序列。也就是说定义成static后每次调用还是之前那个发生器，
第一次调用产生一批随机数，再次调用将产生接下来的随机数，否则每次调用产生的都是最前面的那些随机数。

2.依然需要使用time来做为种子产生每个不同时刻都不同的随机序列，但由于time默认返回的是以秒计的时间，
所以有可能多次使用的都是相同的种子。
*/
template <typename Type>
void DataList<Type>::GeneratorRandomData(int number,int low,int high)
{
    static std::default_random_engine engine(time(NULL));
    static std::uniform_int_distribution<Type> distribution(low,high);

    for(int i = 0;i<number;++i)
    {
        push_front(distribution(engine));
    }
}

template <typename Type>
void DataList<Type>::PrintList()
{
    Node * curData = NULL;
    int i = 0;
    for(i=0,curData=_top;i<_length;++i)
    { 
        std::cout<<curData->data<<" ";
        curData = curData->next;
    }

    std::cout<<std::endl;
}

template <typename Type>
Type & DataList<Type>::operator [] (int i)
{
    if(i<0 || i >= _length)
    {
        std::cout<<"1.0 out of bound,_length="<<_length<<",pos="<<i<<std::endl;
        exit(1);
    }

    Node * curData = NULL;
    int j = 0;
    for(j = 0,curData=_top;j < i;++j)
    {
        curData = curData->next;
    }
    return curData->data; 
}

template <typename Type>
const Type & DataList<Type>::operator [] (int i) const
{
    if(i<0 || i >= _length)
    {
        std::cout<<"2.0 out of bound,_length="<<_length<<",pos="<<i<<std::endl;
        exit(1);
    }
    
    Node * curData = NULL;
    int j = 0;
    for(j = 0,curData=_top;j < i;++j)
    {
        curData = curData->next;
    }
    return curData->data; 
}

template <typename Type>
Type & DataList<Type>::front()
{
    if(!empty())
    {
        return _top->data;
    }
    else
    {
        std::cout<<"Current DataList is empty"<<std::endl;
        exit(1);
    }
}

template <typename Type>
Type & DataList<Type>::back()
{
    if(!empty())
    {
        return _back->data;
    }
    else
    {
        std::cout<<"Current DataList is empty"<<std::endl;
        exit(1);
    }
}

template <typename Type>
void DataList<Type>::push_front(const Type & val)
{
    Node * node = new Node(val);

    if(_top == NULL)
    {
        _top = node;
        _back = node;
    }
    else
    {
        node->next = _top;
        _top->prev = node;
    }
    
    _top = node;

    ++_length;
}

template <typename Type>
void DataList<Type>::push_back(const Type & val)
{
    Node * node = new Node(val);

    if(_back == NULL)
    {
        _top = node;
        _back = node;
    }
    else 
    {
        node->prev = _back;
        _back->next = node;
    }

    _back = node;
    ++_length;
}

template <typename Type>
void DataList<Type>::pop_front()
{
    if(empty())
    {
        std::cout<<"the list is empty"<<std::endl;
        return;
    }

    Node * node = NULL;

    node = _top;
    _top = _top->next;

    delete node;
     
    --_length;
}

template <typename Type>
void DataList<Type>::pop_back()
{
    if(empty())
    {
        std::cout<<"the list is empty"<<std::endl;
        return;
    }

    Node * node = NULL;

    node = _back;
    _back = _back->prev;

    delete node;
     
    --_length;
}

#endif