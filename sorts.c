/**
 *@author        : Shivam Dixit
 *@file          : sorts.c
 *@description   : Comparision beteen O(n^2) sorting algorithms
 *   			   Bubble, insertion and selection sort.
 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/**
 *Function declarations
 *bubbleSort()
 *insertionSort()
 *selectionSort()
 */
void bubbleSort(int *,int);
void insertionSort(int *,int);
void selectionSort(int *,int);

int main(int argc, char const *argv[])
{
	/**
	 *clock_t : To store calc time
	 */
	clock_t begin,end;
	begin = clock();
	int arr[1000000],i,size,choice=0;
	system("clear");   //To clear screen
	printf("Enter size of array (less than 1000000) \n");
	scanf("%d",&size);
	if(size >= 1000000 || size <=0)  //If size is more than size defined
	{
		printf("Invalid Input! Exiting\n");
		return 1;
	}
	printf("Enter elements\n");

	for(i=0;i<size;i++)  //Input elements
	{
		scanf("%d",&arr[i]);
	}

	printf("What sorting algorithm you want to use?\n1.Bubble Sort \n2.Insertion Sort\n3.Selection Sort\n4.Exit\n\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: bubbleSort(arr,size);
				break;
		case 2: insertionSort(arr,size);
				break;
		case 3: selectionSort(arr,size);
				break;
		case 4: break;
		default : printf("Invalid Input\n");
				break;
	}
	for(i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	end = clock();
	printf("Running time of algo is %lf\n",(double)(end-begin)/CLOCKS_PER_SEC);
	return 0;
}

/**
 *Function to sort an array using bubble sort
 *@return void
 *@params array, sizeof array
 */
void bubbleSort(int *a,int n)   //Bubble sort
{
	int i,j,temp;
	for(j=0;j<n-1;j++)
	{
		for(i=0;i<(n-j-1);i++)
		{
			if(*(a+i)>*(a+i+1)) //Comparing next element
			{
				temp = *(a+i);
				*(a+i) = *(a+i+1);
				*(a+i+1) = temp;
			}
		}
	}
}


/**
 *Function to sort an array using insertion sort
 *@return void
 *@params array, sizeof array
 */
void insertionSort(int *a, int size)
{
	int i,j,temp;
	for(i=1;i<size;i++)
	{
		for(j=i;j>0;j--)
		{
			if(*(a+j) < *(a+j-1))    //Inserting element to its correct place
			{
				temp = *(a+j);
				*(a+j) = *(a+j-1);
				*(a+j-1) = temp;
			}
		}
	}
}


/**
 *Function to sort an array using selection sort
 *@return void
 *@params array, sizeof array
 */
void selectionSort(int *a,int size)  //Selection Sort
{
	int i,j,min=*a,pos=0,temp;
	for(i=0;i<size;i++)
	{
		for(j=i;j<size;j++)
		{
			if(min>*(a+j))
			{
				min=*(a+j);
				pos = j;
			}
		}
		if(pos ==i)   //If min is already on its correct position
			continue;
		temp = *(a+i); //Place min to lowest position
		*(a+i) = *(a+pos);
		*(a+pos) = temp;
	}
}