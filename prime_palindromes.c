#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int QuickMultiplication(register int base, register int times, const int kMod) {
	register int ret=0;
	base %= kMod;
	while (times) {
		if (times & 1) ret = (ret + base) % kMod;
		base = (base << 1) % kMod,
		times >>= 1;
	}
	return ret % kMod;
}
int QuickPower(register int base, register int times, const int kMod) {
  register int ret=1;
	base %= kMod;
	while (times) {
		if (times & 1) ret = QuickMultiplication(ret, base, kMod);
		base = QuickMultiplication(base, base, kMod),
		times >>= 1;
	}
	return ret % kMod;
}
bool MillerRabin(const int n) {
	if (n <= 2) return n == 2;
	if (!(n & 1)) return false;
	register int times=0;
	register int a, x, y, u=n - 1;
	while (!(u & 1)) ++times, u >>= 1;
	for (register int i=0; i < 10; ++i) {
		a = rand() % (n - 1) + 1,
		x = QuickPower(a, u, n);
		for (register int j=0; j < times; ++j) {
			y = QuickMultiplication(x, x, n);
			if (y == 1 && x != 1 && x != n - 1) return false;
			x = y;
		}
		if (x != 1) return false;
	}
	return true;
}
int power(int base, int times)
{
    return times<=0?1:base*power(base, times-1);
}

int nDigits(int n)
{
    int nd=0;
    while(n/power(10,nd) != 0)
    {
        nd++;
    }
    return nd;
}
int reverse(int n)
{
    int r=0;
    while(n!=0)
    {
        r *= 10;
        r += n%10;
        n /= 10;
    }
    return r;
}
int nextPalindrome(int n)
{
    if(n==0)
        return 1;
    int nd=nDigits(n);
    int upper, lowerLevel;
    lowerLevel=power(10,nd/2);
    upper = n/lowerLevel;
    if(nd%2==0)
    {
        if(n%lowerLevel>=reverse(upper))
            upper++;
        return reverse(upper) + upper * lowerLevel;
    }
    else
    {
        if(n%(lowerLevel*10)>=reverse(upper))
            upper++;
        return reverse(upper/10) + upper * lowerLevel;
    }
}
void printPrimePalindromes(int min, int max)
{
    // print all prime palindromes in [min, max]
    for(int i=min; i<=max; i=nextPalindrome(i))
    {
        if(MillerRabin(i))
            printf("%d\n",i);
    }
}
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    printPrimePalindromes(a,b);
}
