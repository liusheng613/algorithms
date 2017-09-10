#ifndef __SORT_H__
#define __SORT_H__

#include "datalist.h"

template <typename Type>
class Sort
{
public:
    Sort();
    ~Sort();

    //随机生成num个随机数,并push 到random_data中
    //void GeneratorRandomNums(DataList<Type> & random_data,int num,int low,int high);

    //void PrintData(DataList<Type> & data);

    //插入排序
    void InsertSort(DataList<Type> & sortData);

    //归并排序
    void MergeSort(DataList<Type> & sortData);
private:
    void _MergeSort(DataList<Type> & sortData,int begin,int end);
    void Merge(DataList<Type> & sortData,int begin,int pivotpos,int end);  
};
#endif