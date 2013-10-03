/**
 *@author         Shivam Dixit
 *@file           merge_sort.c
 *@description    Merge sort implementation using stacks
 */

#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

/**
 *Function definitions
 *merge()         to merge 2 arrays
 *mergeSort()     to sort an array using merge()
 */
void merge(int *a,int low,int mid, int high);
int mergeSort(int *a,int size);


/**
 *main() begins
 */
int main(int argc, char const *argv[])
{
	int elements,i,a[20],size;
	system("clear");
	printf("*********************************************************\n");
	printf("*               Merge sort with stacks                  *\n");
	printf("*                                                       *\n");
	printf("*********************************************************\n");
	printf("Enter number of elements (less than 20)\n");
	scanf("%d",&size);
	if(size > 20)
	{
		printf("Invaild input !! Exiting ....!!\n");
	}
	printf("Enter elements :\n");
	for (i = 0; i < size; ++i)
	{
		scanf("%d",&a[i]);
	}
	/**
	 *Call mergeSort() to sort the array
	 */
	mergeSort(a,size);
	printf("\nSuccessfully sorted !! Array after sorting ....\n\t");
	for (i = 0; i < size; ++i)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}

/**
 *Function to sort array using merge sort
 *@params array to be sorted, size of array
 *@return int 1 if succesfully sorted
 */
int mergeSort(int *a,int size)
{
	/**
	 *Zero or one elements are already sorted
	 */
	if(size == 0 || size == 1)
		return;
	stack s1;
	s1.top = -1;
	int i,j,low=0,high,mid,*p,*q;
	high = size-1;
	while(1)
	{
		/**
	 	 *Create a dynamic array p
	 	 *p[0] contains low
	 	 *p[1] contains mid
	 	 *p[2] contains high
	 	 *p[3] contains flag
	 	 */
		p = (int*) malloc(4*sizeof(int));
		*p = 0;                           //low
		*(p+1) = high/2;                  //mid
		*(p+2) = high;                    //high
		*(p+3) = 0;                       //flag bit
		pushInStack(&s1,p);
		high = high/2;
		if(high == 0)
			break;
	}
	while(1)
	{
		if(s1.top == -1)
			break;
		p = popStack(&s1);

		/**
	 	 *Single element is already sorted
	 	 */
		if(*(p) == *(p+2))
			continue;

		/**
	 	 *If not "visited" this element before.
	 	 */
		if(((*(p+2) - *p) > 1) && *(p+3) == 0)
		{
			*(p+3) = 1;
			pushInStack(&s1,p);
			while(1)
			{
				q = (int*) malloc(4*sizeof(int));
				*q = *(p+1)+1;
				*(q+2) = *(p+2);
				mid = (*q + *(q+2))/2;
				*(q+1) = mid;
				*(q+3) = 0;
				pushInStack(&s1,q);

				q = (int*) malloc(4*sizeof(int));
				*q = *(p);
				*(q+2) = *(p+1);
				mid = (*q + *(q+2))/2;
				*(q+1) = mid;
				*(q+3) = 0;
				pushInStack(&s1,q);
				break;
			}
		}
		else
		{
			merge(a,*p,*(p+1),*(p+2));
		}
	}
	return 1;
}



/**
 *Function to merge two arrays (low,mid) and (mid+1,high)
 *@return void
 *@params array,low,mid,high
 */
void merge(int *a,int low,int mid, int high)
{
	int temp[300]={0},i,j,k;
	i = low;
	j = mid+1;
	k = low;
	/**
	 *Loop to compare
	 */
	while(i<=mid && j <=high)
	{
		if(a[i] <= a[j])
		{
			temp[k++] = a[i++];
		}
		else
		{
			temp[k++] = a[j++];
		}
	}
	/**
	 *If some elements are left out in first array
	 */
	while(i<=mid)
		temp[k++] = a[i++];
 	/**
	 *If some elements are left out in second array
	 */
 	while(j<=high)
		temp[k++] = a[j++];
	/**
	 *Copy the temp array to main array
	 */
	for(i=low;i<=high;i++)
	{
		a[i] = temp[i];
	}
}