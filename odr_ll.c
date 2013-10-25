/**
 *@description   Ordered Linked list implementation
 *@author        Shivam Dixit
 */

#include<stdio.h>
#include<stdlib.h>

struct node {
	int info;
	struct node * next;
};

typedef struct node node;

node * createNode();
int printList(node * );
int insertInLinkedList(node ** ,int );

int main(int argc, char const *argv[])
{
	node * head=NULL;
	int i,j,element,c=1;
	system("clear");

	while(c!=4)
	{
		printf("Enter your choice\n\t1.Insert in L.L\n\t2.Delete from L.L\n\t3.Print L.L\n\t4.Exit\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1: printf("Enter element\n");
					scanf("%d",&element);
					if(insertInLinkedList(&head,element))
						printf("Sucessfully Inserted!!\n");
					else
						printf("Element could not be Inserted\n");
					break;

			case 2: printf("Enter element to be deleted\n");
					scanf("%d",&element);
					if(!deleteFromList(&head,element))
					{
						printf("Sorry element not found !!\n");
					}
					break;
			case 3: printf("Your Link List is :\n");
					if(!printList(head))
					{
						printf("Link List is empty!! Insert some elements!\n");
					}

					break;
			case 4: break;
			default :	printf("Invalid input\n");
					break;
		}
	}
	return 0;
}

node * createNode()
{
	node * n;
	n = (node *) malloc(sizeof(node));
	return n;
}

int insertInLinkedList(node ** head,int element)
{
	node *p,*temp,*q;
	p = *head;
	q = *head;
	int flag =1 ;
	temp = createNode();
	temp->next = NULL;
	temp->info = element;
	if(p == NULL)
	{
		*head = temp;
		return;
	}
	while(p!= NULL)
	{
		if(p->info > element)
		{
			if(flag == 1)
			{
				temp->next = *head;
				*head = temp;
				break;
			}
			temp->next = q->next;
			q->next = temp;
			break;
		}
		p = p->next;
		if(!flag)
		{
			q = q->next;
		}
		flag = 0;
	}
	if(p == NULL)
	{
		temp->next = NULL;
		q->next = temp;
	}
	return 1;
}

int deleteFromList(node ** head,int element)
{
	node *p,*temp,*q;
	p = *head;
	q = *head;
	int flag = 1;

	while(p!=NULL)
	{
		if(p->info == element)
		{
			if(flag)
			{
				*head = p->next;
				free(p);
				break;

			}
			q->next = p->next;
			free(p);
			break;
		}
		p= p->next;
		if(!flag)
			q=q->next;
		flag =0;
	}
	if(p == NULL)
		return 0;
	return 1;
}

int printList(node * head)
{
	node * p;
	p = head;
	if(p == NULL)
		return 0;
	printf("\n\n");
	while(p!= NULL)
	{
		printf("%d->",p->info);
		p= p->next;
	}
	//printf("\b\b");
	printf("\n");
	return 1;
}