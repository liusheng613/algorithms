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
    std::cout<<"After MergeSort:"<<std::endl;
    MergeSortData.PrintList();

    //HeapSort
    DataList<int> HeapSortData(10);
    std::cout<<"Before HeapSort:"<<std::endl;
    HeapSortData.PrintList();
    sort.HeapSort(HeapSortData);
    std::cout<<"After HeapSort:"<<std::endl;
    HeapSortData.PrintList();

    //QuickSort
    DataList<int> QuickSortData(50);
    std::cout<<"Before QuickSort:"<<std::endl;
    QuickSortData.PrintList();
    sort.QuickSort(QuickSortData,0,49);
    std::cout<<"After QuickSort:"<<std::endl;
    QuickSortData.PrintList();

    return 0;
}