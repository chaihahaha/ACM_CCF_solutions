#include<stdio.h>
#include<malloc.h>
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
