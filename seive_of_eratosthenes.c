/*  
Algorithm : Seive of eratosthenes 
Purpose : To find all prime number upto n
Logic : Iterative marking of numbers as composite
*/

#include<stdio.h>
#include<time.h>
#include<math.h>

int main()
{
	int n,a[1000001]={0},i,j;   //a[i]==0 means prime, a[i]==1 means not prime
	clock_t begin,end;
	begin = clock();
	printf("Enter upto where you want prime numbers : ");
	scanf("%d",&n);
	if(n>1000001 || n<2)
		return;
	for(i=2;i<=n;i++)
	{
		if(a[i] == 1)
			continue;
		for(j=2;(j*i) <= n ;j++)
		{
			a[j*i] = 1;
		}
	}
	printf("Prime Numbers are :\n");
	for (i = 2; i <=n; ++i)
	{
		if(a[i]==0)
			printf("%d ",i);
	}
	printf("\n");
	end = clock();
	printf("%lf\n",(double)(end-begin)/CLOCKS_PER_SEC);
	return 0;
}