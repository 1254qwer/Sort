//
// Created by zxq on 2022/11/21.
//

#ifndef SORT_SORT_H
#define SORT_SORT_H
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

//规定最大长度
#define MAXSIZE 20000

//定义顺序表结构体
typedef struct {
    int r[MAXSIZE + 1];
    int length;
}SqList;

void swap(SqList *L, int i, int j); //交换L中数组r的下标为i和j的值
void BubbleSort(SqList *L); //冒泡排序
void SelectSort(SqList *L); //选择排序
void InsertSort(SqList *L); //插入排序
void QuickSort(SqList *L); //快速排序
void QSort(SqList *L, int low, int high); //快速排序的递归函数
int Partition(SqList *L,int low,int high); //快速排序的划分函数
void ShellSort(SqList *L); //希尔排序

#endif //SORT_SORT_H
