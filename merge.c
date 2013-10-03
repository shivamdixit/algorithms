/**
 *@author         Shivam Dixit
 *@file           merge.c
 *@description    Merge sort implementation WITH RECURSION
 */

#include<stdio.h>

/**
 *Function definitions
 *merge()         to merge 2 arrays
 *mergeSort()     to sort an array using merge()
 */
void merge(int*,int,int,int);
void mergeSort(int *,int,int);


/**
 *main() begins
 */
int main(int argc, char const *argv[])
{
	int a[15],size,i,d[30];
	system("clear");
	printf("\n");
	printf("Sorting using merge sort algorithm\n");
	printf("Enter size of unsorted array <=15 \n");
	scanf("%d",&size);
	if(size>15)
	{
		printf("Invalid input\n");
		return;
	}
	printf("Enter array\n");
	for(i=0;i<size;i++)
	{
		scanf("%d",&a[i]);
	}
	mergeSort(a,0,size-1);
	printf("Elements after sorting are :\n");
	for(i=0;i<size;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}



/**
 *Function to sort an array using merge sort
 *@params array,start of array, end of array
 *@return void
 */
void mergeSort(int *a,int low,int high)
{

	int mid;
	if(low!=high)
	{
		mid = (low + high)/2;
		/**
 	 	 *Recursive definition
	 	 */
		mergeSort(a,low,mid);
		mergeSort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}



/**
 *Function to merge two SORTED arrays in sorted order
 *Array 1 = 0 to mid
 *Array 2 = mid + 1 to high
 *@params array,low,mid,high
 *@return void
 */
void merge(int *a,int low,int mid, int high)
{
	int temp[300]={0},i,j,k;
	i = low;
	j = mid+1;
	k = low;

	/**
 	 *Compare and copy elements
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
 	 *Copy temp array to main array
	 */
	for(i=low;i<=high;i++)
	{
		a[i] = temp[i];
	}
}