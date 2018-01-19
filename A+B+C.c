#include<stdio.h>
int main(void) {
    long long int a,b,c;
    while(1) {
        if(scanf("%lld %lld %lld",&a,&b,&c)!=3)
            break;
        else
            printf("%lld\n",a+b+c);
    }
    return 0;
}
