#include "sort.h"

template <typename Type>
Sort<Type>::Sort()
{

}

template <typename Type>
Sort<Type>::~Sort()
{

}

template <typename Type> 
void Sort<Type>::InsertSort(DataList<Type> & sortData)
{
    for(int i = 1 ; i < sortData.size(); ++i)
    {
        Type key = sortData[i];
        int j = i - 1;
        while(j>=0 && sortData[j] > key)
        {
            sortData[j+1] = sortData[j];
            j--;
        }
        sortData[j+1] = key;
    }
}

template <typename Type>
void Sort<Type>::MergeSort(DataList<Type> & sortData)
{
    _MergeSort(sortData,0,sortData.size());
}

template <typename Type>
void Sort<Type>::_MergeSort(DataList<Type> & sortData,int begin,int end)
{
    int pivotpos = 0;
    if(begin < end)
    {
        pivotpos = (begin + end)/2;
        std::cout<<"pivotpos="<<pivotpos<<std::endl;
        _MergeSort(sortData,begin,pivotpos);
        _MergeSort(sortData,pivotpos+1,end);
        Merge(sortData,begin,pivotpos,end);
    }
}

//assume begin<=pivotpos<end
template <typename Type>
void Sort<Type>::Merge(DataList<Type> & sortData,int begin,int pivotpos,int end)
{
    int n1 = pivotpos - begin + 1;
    int n2 = end - pivotpos -1 ;

    DataList<int> L(n1+1);
    DataList<int> R(n2+1);

    int i = 0;
    int j = 0;
    for(i=0;i < n1;++i)
    {
        L[i] = sortData[begin + i];
    }

    for(j=0;j< n2;++j)
    {
        R[j] = sortData[pivotpos + 1 + j];
    }

    L[n1] = 65535;
    R[n2] = 65535;
    i = 0;
    j = 0;

    for(int k = begin;k<end;++k)
    {
        if(L[i] <= R[j])
        {
            sortData[k] = L[i];
            ++i;
        }
        else
        {
            sortData[k] = R[j];
            ++j;
        }
    }
}

//模板类在编译时如果不显示实例化则编译时不会将具体的模板编译到.o中，导致链接不到
//还可以把main函数放到同一个cpp文件中，如下
//常用的方法是模板类的函数实现均放到.h中，这种可能的弊端是重复编译
template class Sort<int>;
