/**
 *@author        : Shivam Dixit
 *@file          : quick_sort.c
 *@description   : Quick Sort implementation
 */
#include<stdio.h>


/**
 *Function definition
 *partition()   to partition the array into two
 *quicksort()   to sort the array
 */
int partition(int *,int,int);
int quicksort(int *,int,int);

int main(int argc, char const *argv[])
{
	int a[10],i,j,n;
	printf("Enter number of elements of array (less than 10)\n");
	scanf("%d",&n);
	for ( i = 0; i < n; ++i)
	{
		printf("Enter element\n");
		scanf("%d",&a[i]);
	}
	quicksort(a,0,n-1);
	printf("\n");
	for (i = 0; i < n; ++i)
	{
		printf("%d ",a[i]);
	}
	return 0;
}


/**
 *@desc Function to sort an array using quick sort algorithm
 *@param array, left of array, right of array
 *@return int
 */
int quicksort(int *a,int l,int r)
{
	int j;
	if(r<=0 || l>=r)
		return;
	j= partition(a,l,r);
	quicksort(a,l,j-1);
	quicksort(a,j+1,r);
}


/**
 *@desc Function to place the piviot element at correct position and partition from that element
 *@param array, left of array, right of array
 *@return int
 */
int partition(int *a,int l,int r)
{
	int piviot,i,j,temp,flag=0;
	piviot = *(a+l);
	i=l;
	j=r+1;
	while(1)
	{
		do ++i;while(a[i] <= piviot && i<=r);
		do --j;while(a[j] > piviot);
		if(j<=i)
			break;
		temp = a[j];
		a[j] = a[i];
		a[i] = temp;
	}
	temp = a[l];
	a[l] = a[j];
	a[j] = temp;
	return j;

}