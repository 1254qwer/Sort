//
// Created by zxq on 2022/11/21.
//
#include <iostream>
#include "Sort.h"

//交换L中数组r的下标为i和j的值
void swap(SqList *L,int i,int j){
    int temp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
}

//冒泡排序
void BubbleSort(SqList *L){
    int i,j;
    int flag = 1;
    for(i=1; i<=L->length && flag; i++){
        flag = 0;
        for(j=L->length; j>=i; j--){
            if(L->r[j] < L->r[j-1]){
                flag = 1;
                swap(L,j,j-1);
            }
        }
    }
}

//选择排序
void SelectSort(SqList *L){
    int i,j,min;
    for(i=1; i<L->length; i++){
        min = i;
        for(j=i+1; j<=L->length; j++){
            if(L->r[j] < L->r[min]){
                min = j;
            }
        }
        if(i != min){
            swap(L,i,min);
        }
    }
}

//插入排序
void InsertSort(SqList *L){
    int i,j;
    for(i=2; i<=L->length; i++){
        if(L->r[i] < L->r[i-1]){
            L->r[0] = L->r[i];
            for(j=i-1;L->r[j] > L->r[0];j--){
                L->r[j+1] = L->r[j];
            }
            L->r[j+1] = L->r[0];
        }
    }
}

//快速排序
void QuickSort(SqList *L){
    QSort(L,1,L->length);
}

//快速排序的递归函数
void QSort(SqList *L,int low,int high){
    int pivot;
    if(low < high){
        pivot = Partition(L,low,high);
        QSort(L,low,pivot-1);
        QSort(L,pivot+1,high);
    }
}

//快速排序的划分函数
int Partition(SqList *L,int low,int high){
    int pivotkey;
    pivotkey = L->r[low];
    while(low < high){
        while(low < high && L->r[high] >= pivotkey){
            high--;
        }
        swap(L,low,high);
        while(low < high && L->r[low] <= pivotkey){
            low++;
        }
        swap(L,low,high);
    }
    return low;
}

//希尔排序
void ShellSort(SqList *L){
    int i,j;
    int increment = L->length;
    do{
        increment = increment/3+1;
        for(i=increment+1;i<=L->length;i++){
            if(L->r[i] < L->r[i-increment]){
                L->r[0] = L->r[i];
                for(j=i-increment; j>0 && L->r[j] > L->r[0]; j-=increment){
                    L->r[j+increment] = L->r[j];
                }
                L->r[j+increment] = L->r[0];
            }
        }
    } while(increment > 1);
}


void LinkInsertsort(LinkList &L)
{
    LinkList p, q, pre, temp;
    p = L->next->next;
    L->next->next = nullptr;
    while (p) {
        q = p->next;
        pre = L;
        while (pre->next && pre->next->data < p->data)
            pre = pre->next;
        p->next = pre->next;
        pre->next = p;
        p = q;
    }
    L = L->next;
    temp = L;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}