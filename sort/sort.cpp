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
    //must be size()-1,use index for 0 to sortData.size()-1
    //otherwise the Merge can be merge one element,like Merge(0,0,1)
    _MergeSort(sortData,0,sortData.size()-1);
}

template <typename Type>
void Sort<Type>::_MergeSort(DataList<Type> & sortData,int begin,int end)
{
    int pivotpos = 0;
    // std::cout<<"in _MergeSort before if begin="<<begin<<",end="<<end<<std::endl;
    if(begin < end)
    {
        pivotpos = (begin + end)/2;
        // std::cout<<"in _MergeSort pivotpos="<<pivotpos<<std::endl;
        _MergeSort(sortData,begin,pivotpos);
        _MergeSort(sortData,pivotpos+1,end);
        Merge(sortData,begin,pivotpos,end);
        // std::cout<<"---------------------------"<<std::endl;
        // for(int i = begin;i < end; ++i)
        // {
        //     std::cout<<"sortData["<<i<<"]="<<sortData[i]<<std::endl;
        // }
        // std::cout<<"---------------------------"<<std::endl;
    }
}

//assume begin<=pivotpos<end
template <typename Type>
void Sort<Type>::Merge(DataList<Type> & sortData,int begin,int pivotpos,int end)
{
    // std::cout<<"in Merge begin="<<begin<<",pivotpos="<<pivotpos<<",end="<<end<<std::endl;
    int n1 = pivotpos - begin + 1;
    int n2 = end - pivotpos;

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

    //set the last element as a guard
    L[n1] = 65535;
    R[n2] = 65535;
    i = 0;
    j = 0;

    //here must be <= not <,because here the 
    //end is the index of SortData,not the length
    for(int k = begin;k<=end;++k)
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

template <typename Type>
void Sort<Type>::HeapSort(DataList<Type> & sortData)
{
    BuildMaxHeap(sortData);
    for(int i = sortData.size()-1;i >= 1; --i)
    {
        Swap(sortData[0],sortData[i]);
        MaxHeapify(sortData,0,i);
    }
}

template <typename Type>
void Sort<Type>::BuildMaxHeap(DataList<Type> & dataList)
{
    for(int i = dataList.size()/2; i >= 0; --i)
    {
        MaxHeapify(dataList,i,dataList.size());
    }
}

template <typename Type>
void Sort<Type>::MaxHeapify(DataList<Type> & dataList,int index,int end)
{
    int l = Left(index);
    int r = Right(index);

    int largest = 0;
    if(l < end && dataList[l] > dataList[index])
    {
        largest = l;
    }
    else
    {
        largest = index;
    }

    if(r < end && dataList[r] > dataList[largest])
    {
        largest = r;
    }

    if(largest != index)
    {
        Swap(dataList[largest],dataList[index]);
        MaxHeapify(dataList,largest,end);
    }
}

//begin,end is the sortData begin and end position(index)
template <typename Type>
void Sort<Type>::QuickSort(DataList<Type> & sortData,int begin,int end)
{
    if(begin < end)
    {
        int pivotpos = Partition(sortData,begin,end);
        QuickSort(sortData,begin,pivotpos-1);
        QuickSort(sortData,pivotpos+1,end);
    }
}

template <typename Type>
int Sort<Type>::Partition(DataList<Type> & sortData,int begin,int end)
{
    Type x = sortData[end];
    int i = begin - 1;
    for(int j=begin;j<end;++j)
    {
        if(sortData[j] <= x)
        {
            ++i;
            Swap(sortData[i],sortData[j]);
        }
    }
    Swap(sortData[i+1],sortData[end]);
    return i+1;
}

template <typename Type>
void Sort<Type>::CountingSort(DataList<Type> & sortData,DataList<Type> & OutputData,Type maxData)
{
    DataList<Type> tmpData(maxData);
    for(int i=0;i<tmpData.size();++i)
    {
        tmpData[i] = 0;
    }

    for(int j=0;j<sortData.size();++j)
    {
        tmpData[sortData[j]] = tmpData[sortData[j]] + 1;
    }

    for(int i = 1;i < maxData;++i)
    {
        tmpData[i] = tmpData[i] + tmpData[i-1];
    }

    for(int j = sortData.size()-1;j >= 0;--j)
    {
        OutputData[tmpData[sortData[j]]-1] = sortData[j];
        //如果有相同元素则下次插入到对应的位置在现在位置的下一位置
        tmpData[sortData[j]] = tmpData[sortData[j]] - 1;
    }
}

//模板类在编译时如果不显示实例化则编译时不会将具体的模板编译到.o中，导致链接不到
//还可以把main函数放到同一个cpp文件中，如下
//常用的方法是模板类的函数实现均放到.h中，这种可能的弊端是重复编译
template class Sort<int>;
