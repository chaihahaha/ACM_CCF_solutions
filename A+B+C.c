#include<stdio.h>
/*Problem Description:

For each pair of integers A B and C ( -2^31 <= A, B, C<= 2^31-1 ), Output the result of A+B+C on a single line. 

*/
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
