#ifndef __SORT_H__
#define __SORT_H__

#include "datalist.h"

template <typename Type>
class Sort
{
public:
    Sort();
    ~Sort();

    //插入排序
    void InsertSort(DataList<Type> & sortData);

    //归并排序
    void MergeSort(DataList<Type> & sortData);

    //堆排序
    void HeapSort(DataList<Type> & sortData);
private:
    void _MergeSort(DataList<Type> & sortData,int begin,int end);
    void Merge(DataList<Type> & sortData,int begin,int pivotpos,int end);  

    //堆操作
    //父节点索引
    int Parent(int i) { return (i-1)/2; }
    //左孩子索引
    int Left(int i) { return 2*i + 1; }
    //右孩子索引
    int Right(int i) { return 2*i + 2; }
    void BuildMaxHeap(DataList<Type> & dataList);
    //最大堆化
    void MaxHeapify(DataList<Type> & dataList,int index,int end);
    void Swap(Type & a,Type & b) { Type tmp; tmp = a ; a = b; b = tmp;}
};
#endif