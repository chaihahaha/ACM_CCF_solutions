#include<stdio.h>
#include<malloc.h>
/*Problem Description:

Since milk packaging is such a low margin business, it is important to keep the price of the raw product (milk) as low as possible. Help Merry Milk Makers get the milk they need in the cheapest possible manner.

The Merry Milk Makers company has several farmers from which they may buy milk, and each one has a (potentially) different price at which they sell to the milk packing plant. Moreover, as a cow can only produce so much milk a day, the farmers only have so much milk to sell per day. Each day, Merry Milk Makers can purchase an integral amount of milk from each farmer, less than or equal to the farmer's limit.

Given the Merry Milk Makers' daily requirement of milk, along with the cost per gallon and amount of available milk for each farmer, calculate the minimum amount of money that it takes to fulfill the Merry Milk Makers' requirements.

Note: The total milk produced per day by the farmers will be sufficient to meet the demands of the Merry Milk Makers.


Input:

The first line contains two integers, N and M. The first value, N, (0 <= N <= 2,000,000) is the amount of milk that Merry Milk Makers' want per day. The second, M, (0 <= M <= 5,000) is the number of farmers that they may buy from.

The next M lines (Line 2 through M+1) each contain two integers, Pi and Ai. Pi (0 <= Pi <= 1,000) is price in cents that farmer i charges. Ai (0 <= Ai <= 2,000,000) is the amount of milk that farmer i can sell to Merry Milk Makers per day.


Output:

A single line with a single integer that is the minimum price that Merry Milk Makers can get their milk at for one day.
*/
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef struct {
    int data;
    int info;
}ElemType;
typedef struct {
    ElemType *elem;
    int length;
}SqList;
int partition(SqList *L, int low, int high) {
    L->elem[0] = L->elem[low];
    int pivotkey = L->elem[low].data;
    while(low < high) {
        while(low < high && L->elem[high].data>=pivotkey) --high;
        L->elem[low]=L->elem[high];
        while(low < high && L->elem[low].data<=pivotkey) ++low;
        L->elem[high]=L->elem[low];
    }
    L->elem[low] = L->elem[0];
    return low;
}
void qsort(SqList *L, int low, int high) {
    if(low<high) {
        int pivotloc = partition(L,low, high);
        qsort(L,low, pivotloc-1);
        qsort(L,pivotloc+1, high);
    }
}
void quick_sort(SqList *L) {
    //以data为主关键字进行快速排序
    qsort(L,1, L->length);
}


void create_list(SqList *L, int length) {
    L->elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    L->length = length;
}
int main() {
    //对线性表进行初始化和赋值
    SqList L;
    int milk,n;
    scanf("%d %d",&milk,&n);
    create_list(&L,n);
    for(int i = 0; i < 5; i++) {
        int price,pmilk;
        scanf("%d %d",&price,&pmilk);
        L.elem[i+1].data = price;
        L.elem[i+1].info = pmilk;
    }
    //快速排序
    quick_sort(&L);
    int left_milk = milk;
    int money = 0;
    int count = 0;
    while(left_milk>0) {
        count++;
        money += L.elem[count].data*L.elem[count].info;
        left_milk -= L.elem[count].info;
    }
    money -= L.elem[count].data*L.elem[count].info;
    left_milk += L.elem[count].info;
    printf("%d",money+left_milk*L.elem[count].data);
    return 0;
}
