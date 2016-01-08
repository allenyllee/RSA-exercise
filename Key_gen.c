
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

unsigned long long inverse(unsigned long long a, unsigned long long m)
{
    unsigned long long d, x = 0, s = 1, q, r, t;
	//a=23;m=120;
	d = m;
    while (a != 0)
    {
        q = d / a, r = d % a;
        d = a, a = r;
        t = x - q * s, x = s, s = t;
    }
    if (d != 1) return -1;  // 沒有倒數、無法整除
	
    return (x + m) % m;
}

int GCD(unsigned long long a,unsigned long long b)
{
   int temp;
   while(a%b)
      {
         temp=a;
         a=b;
         b=temp%a;
      }
	  //printf("GCD %d\n",b);
   return b;
}
unsigned long long trial_division(unsigned long long n)
{
    unsigned long long sqrt_n ,d;
	sqrt_n = sqrt(n);
    for (d=2; d<=sqrt_n; ++d){
        while (n % d == 0)
        {
            n  = n/d;
        }
	}

    if (n > 1) 
		return n;
	else
		return 0;
}
unsigned long long FindRandPrime(unsigned long long Max){
	unsigned long long num;
	do{

	num=(rand()% Max)+1;	
	}
	while((num=trial_division(num))<Max/10);	
	return num;
}

unsigned long long Find_E(unsigned long long r){
	unsigned long long e, Ngcd;
	do{
	e=FindRandPrime(r/10000);
	}while(GCD(r,e)!=1);
	return e;
}






void main(void)
{
	unsigned long long prime[2],r,e,d,N;
	srand(time(NULL));
	prime[0]=FindRandPrime(100000);
	//printf("P0:%d\n",prime[0]);
	prime[1]=FindRandPrime(100000);
	//printf("P1:%d\n",prime[1]);
	N=prime[0] * prime[1];
	r=(prime[0]-1)*(prime[1]-1);
	printf("Mode=%d\n",N);
	e=Find_E(r);
	printf("Private Key=%d\n",e);	
	d=inverse(e,r);
	//d=inverse(23,120);
	printf("Public Key=%d\n",d);
	
	
	
	
}
