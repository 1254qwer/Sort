#include <iostream>
#include <random>
#define LEN 20000
#include "Sort.h"

int main() {
    int a[20] = {0, 49, 38, 65, 97, 76, 13, 27, 49, 55, 4, 5, 7, 78, 34, 12, 64, 1, 8, 9};
    int b[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int c[20] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    int d[LEN];
    for(int i=0; i<LEN; i++){
        d[i] = rand()%32767;
    }
//    //输出数组d
//    for(int i=0; i<LEN; i++){
//        std::cout << d[i] << " ";
//    }
//    std::cout << std::endl;
    SqList L;
    L.length = LEN;
//    L.length = 20;
    for(int i=1; i<=L.length; i++){
        L.r[i] = d[i-1];
    }
//    BubbleSort(&L);
//    SelectSort(&L);
//    InsertSort(&L);
    QuickSort(&L);
//    ShellSort(&L);
    for(int i=1; i<=L.length; i++){
        std::cout << L.r[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
