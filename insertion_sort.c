/**
 *@author        : Shivam Dixit
 *@file          : heapsort.c
 *@description   : Heap Sort implementation
 */
#include<stdio.h>


/**
 *Function definition
 *insertionSort()
 */
void insertionSort(int *,int);

int main(int argc, char const *argv[])
{
	int size,a[10],i;
	system("clear");
	printf("Enter size of array\n");
	scanf("%d",&size);
	printf("Enter elements\n");
	for(i=0;i<size;i++)
	{
		scanf("%d",&a[i]);
	}
	insertionSort(a,size);
	printf("\n");
	for (i = 0; i <size; ++i)
	{
		printf("%d ",a[i]);
		/* code */
	}
	return 0;
}


/**
 *@desc Function to sort an array using insertion sort algorithm
 *@param array, size of array
 *@return void
 */
void insertionSort(int *a,int size)
{
	int i,j,temp;
	for(i=1;i<size;i++)
	{
		temp = *(a+i);
		for(j=i;j>0 && temp < *(a+j-1);j--)
			a[j] = a[j-1];
		a[j] = temp;
	}
}