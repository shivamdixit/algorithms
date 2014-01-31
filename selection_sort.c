/**
 *@author        : Shivam Dixit
 *@file          : selection_sort.c
 *@description   : Selection Sort implementation
 */

#include<stdio.h>

/**
 *Function declaration
 *selectionSort()   to sort an array
 */
void selectionSort(int *,int);

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
	selectionSort(a,size);
	printf("\n");
	for (i = 0; i <size; ++i)
	{
		printf("%d ",a[i]);
		/* code */
	}
	return 0;
}

/**
 *@desc Function to sort an array using selection sort algorithm
 *@param array, size of array
 *@return void
 */
void selectionSort(int *a,int size)
{
	int i,j,min,flag=0,temp,pos;
	for(i=0;i<size;i++)
	{
		min = *(a+i);
		pos = i;
		flag=0;
		for(j=i+1;j<size;j++)
		{
			if(*(a+j) < min)
			{
				flag =1;
				pos = j;
				min = *(a+j);
			}
		}
		if(flag == 1)
		{
			temp = *(a+pos);
			*(a+pos) = *(a+i);
			*(a+i) = temp;
		}
	}
}