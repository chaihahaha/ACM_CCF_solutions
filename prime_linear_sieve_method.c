#include<stdio.h>
#include<malloc.h>
long *pri_stk;
long init_pri_stk(long b){
    int *prime = NULL;
    prime = (int *)malloc(b*sizeof(int));
    long top = 0;
    prime[0] = prime[1] = 1;
    for(long i = 2 ; i < b ; i++){
        if(!prime[i]) pri_stk[top++] = i;
        for(long j = 0 ; j < top && i * pri_stk[j] <= b ; j++){
            prime[i * pri_stk[j]] = 1;
            if(i % pri_stk[j] == 0) break;
        }
    }
    return top;
}
long binary_search(long low, long high, long a) {
    long mid;
    while(low<=high) {
        mid=(low+high)/2;
        if(pri_stk[mid] < a) low = mid + 1;
        else if(pri_stk[mid] >a) high = mid -1;
        else return mid;
    }
    return mid;
}
int is_palindrome(long i) {
    int a[10], j = 0;
    for( ; j < 10; j++ , i/=10) {
        a[j] = i%10;
        if(i == 0) break;
    }
    for(int k = 0; k < j/2; k++) {
        if(a[k] != a[j - k - 1]) return 0;
    }
    return 1;
}
int main() {
    
    long a,b;
    scanf("%ld %ld",&a,&b);
    pri_stk = (long *)malloc(b*sizeof(long));
    long top = init_pri_stk(b);
    long i = binary_search(0,top,a);
    for(; i < top; i++)
        if(is_palindrome(pri_stk[i])) printf("%ld\n",pri_stk[i]);
    return 0;
}
