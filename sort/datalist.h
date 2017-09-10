#ifndef __DATA_LIST__
#define __DATA_LIST__
#include<iostream>
#include <ctime>
#include <random>

template <typename Type>
class DataList
{
public:
    DataList(int dataSize=10):_length(dataSize) { elements = new Type[_length]; GeneratorRandomData(0,200);};
    ~DataList() { if (elements) delete [] elements;}

    void GeneratorRandomData(int low,int high);
    void PrintList();
    const int size() const {return _length;}

    Type & operator [] (int i);
    const Type & operator [] (int i) const; 
private:
    Type * elements;
    int _length;
};

//调用C++11产生更加随机的随机数
template <typename Type>
void DataList<Type>::GeneratorRandomData(int low,int high)
{
    std::default_random_engine engine(time(NULL));
    std::uniform_int_distribution<Type> distribution(low,high);

    for(int i = 0;i<_length;++i)
    {
        elements[i] = distribution(engine);
    }
}

template <typename Type>
void DataList<Type>::PrintList()
{
    for(int i=0;i<_length;++i)
    {
        std::cout<<elements[i]<<" ";
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
    return elements[i]; 
}

template <typename Type>
const Type & DataList<Type>::operator [] (int i) const
{
    if(i<0 || i >= _length)
    {
        std::cout<<"2.0 out of bound,_length="<<_length<<",pos="<<i<<std::endl;
        exit(1);
    }
    return elements[i]; 
}

#endif