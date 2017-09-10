#include "sort.h"
#include <iostream>

int main()
{
    Sort<int> sort;

    //InsertSort
    DataList<int> insertSortData(10);
    std::cout<<"Before insertSort:"<<std::endl;
    insertSortData.PrintList();
    sort.InsertSort(insertSortData);
    std::cout<<"After insertSort:"<<std::endl;
    insertSortData.PrintList();

    //MergeSort
    DataList<int> MergeSortData(10);
    std::cout<<"Before MergeSort:"<<std::endl;
    MergeSortData.PrintList();
    sort.MergeSort(MergeSortData);
    std::cout<<"After MergeSortData:"<<std::endl;
    MergeSortData.PrintList();

    return 0;
}