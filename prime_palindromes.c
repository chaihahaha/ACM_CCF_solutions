#include<stdio.h>
#include<stdlib.h>
int is_prime(long x,int times){
    //Miller-Rabin算法
/*  x为待测试数，times为测试次数   */
    long a,b,r;
    for (srand(x+rand()); times--;){
        a = ((x-2)*rand()*1./RAND_MAX)+2;
        b = x - 1;
        for (r = 1; b; b >>= 1){
            b&1?r=r*a%x:0;
            a=a*a%x;
        }
        if (r%x!=1) return 0;
    }
    return 1;
}

int is_palindrome(long i) {
    //判断i是否为回文数
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
int main(){
    //输出从a到b的所有质回文数
    long a,b;
    scanf("%ld %ld",&a,&b);
    long i = a + (a%2 == 0);
    if(a<=2) printf("2\n");
    for(; i <= b; i+=2) {
        if(is_prime(i,2) && is_palindrome(i))
            printf("%ld,", i);
    }
    return 0;
}
