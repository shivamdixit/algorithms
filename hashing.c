/**
 *@author        : Shivam Dixit
 *@file          : hashing.c
 *@description   : Simple hashing implementation
 */


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SIZE 10

struct node
{
	char *	str;
	int count;
	struct node * next;
};

typedef struct node node;

/**
 *Function declarations
 */
int hashFunction(char * );
node * createNode(void);
char * getMemory(int);
int insertElement(node ** ,char * );
int printElements(node * );
int main(int argc, char const *argv[])
{
	system("clear");
	int i,j,k,n,c=1,index;
	node * a[SIZE];
	for(i=0;i<SIZE;i++)
	{
		a[i] = NULL;
	}
	char str[100];
	while(c!=3)
	{
		printf("Enter your choice \n\t1.Insert Element\n\t2.Print Frequencies of Element\n\t3.Exit\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1 : printf("Enter the string\n");
					 scanf("%s",str);
					 index = hashFunction(str);
					 insertElement(&a[index],str);
					  printf("Successfully inserted\n");
					 //else
					 	//printf("Some error occured\n");
					 break;
			case 2 : printf("\n");
					 for(i=0;i<SIZE;i++)
					 {
						if(a[i] != NULL)
							printElements(a[i]);
					 }
					 break;
			case 3 : break;

			default : printf("Invalid choice\n");
					  break;
		}
	}
	return 0;
}


int hashFunction(char * str)
{
	int i,sum=0;
	for(i=0;str[i]!='\0';i++)
		sum += (int) str[i];
	return sum%10;
}

node * createNode(void)
{
	node * temp;
	temp = (node *) malloc(sizeof(node));
	temp->count = 1;
	temp->next = NULL;
	temp->str = NULL;
}
char * getMemory(int len)
{
	return (char *) malloc(len);
}

int insertElement(node ** a,char * str)
{
	int index,len;
	node * temp,**p;
	node *c;
	p = a;
	//index = hashFunction(str);
	len = strlen(str);
	//p = *(a+index);
	if(*p == NULL)
	{
		temp = createNode();
		temp->str = getMemory(len);
		strcpy(temp->str,str);
		// if(temp == NULL)
		// 	return 0;
		*p = temp;
		//p->str = getMemory(len);
		//	strcpy(*p->str,str);
		return 1;
	}
	c=*p;
	if(strcmp(str,c->str) == 0)
	{
		c->count++;
		return 1;
	}
	while(c->next!=NULL)
	{
		if(strcmp(str,c->str) == 0)
		{
			c->count++;
			return 1;
		}
		c = c->next;
	}
	if(strcmp(str,c->str) == 0)
	{
		c->count++;
		return 1;
	}
	temp = createNode();
	if(temp == NULL)
		return 0;
	temp->str = getMemory(len);
	strcpy(temp->str,str);
	c->gonext = temp;
	//strcpy(p->str,str);
	return 1;
}

int printElements(node * a)
{
	int i,j;
	node *p;
	p=a;
	printf("Frequencies of elements are : \n");
	// for(i=0;i<SIZE;i++)
	// {
		//p = *(a+i);
		//p = p->next;
		while(p != NULL)
		{
			printf("String : ");
			puts(p->str);
			printf("  Frequency : %d\n",p->count);
			p=p->next;
		}
	//}
	return 1;
}