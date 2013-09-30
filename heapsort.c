/**
 *Name : Heapsort
 *Author : Shivam
 */
#include<stdio.h>

/**
 *Size of array
 */
#define SIZE 10

int heapsize = SIZE;

void maxHeapify(int *a,int index)
{
	int l,r,largest=0,temp;
	l = 2 * index;                        //Left Node
	r = 2 * index + 1;					  //Right Node
	if(l <= heapsize && a[l] > a[index])
		largest = l;
	else
		largest = index;
	if(r <= heapsize && a[r] > a[largest])
		largest = r;
	if(largest != index)
	{
		temp = a[largest];
		a[largest] = a[index];
		a[index] = temp;
		maxHeapify(a,largest);
	}
}

void buildMaxHeap(int *a)
{
	int n = heapsize /2,i;
	for(i=n;i>0;i--)
		maxHeapify(a,i);
}

void heapsort(int *a)
{
	int i,temp;
	buildMaxHeap(a);
	for(i=SIZE; i>=0;i--)
	{
		temp = a[i];
		a[i] = a[1];
		a[1] = temp;
		heapsize--;
		buildMaxHeap(a);
	}
}

int main(int argc, char const *argv[])
{
	int a[11],i;
	printf("Enter elements of an array (all elements must be distinct)\n");
	for (i = 1; i <= SIZE; ++i)
	{
		scanf("%d",&a[i]);
		/* code */
	}
	heapsort(a);
	printf("\n");
	for (i = 1; i <= SIZE; ++i)
	{
		printf("%d ",a[i]);
		/* code */
	}
	return 0;
}
