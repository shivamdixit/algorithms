/**
 *@author	Shivam Dixit
 *@file 	circular_db_ll.c
 *@description	Circular doubly linked list implementation
 */

#include<stdio.h>
#include<stdlib.h>


//ADT to represt a node of doubly linked list
struct node {
	int info;
	struct node * next;
	struct node * prev;
};

typedef struct node node;

/**
 *Function to insert a node in linked list
 */
int insertInLinkedList(node**, int);

/**
 *Function to display a node in linked list
 */
int displayLinkedList(node * );

/**
 *Function to create a node
 */
node * createNode(int );


/**
 *Function to delete a node
 */
int deleteFromLinkedList(node **, int );


int main(int argc, char const *argv[])
{
	int ch,element;
	node *head =NULL;
	while(1)
	{
		printf("Enter you choice\n1.Insert\n2.Print\n3.Delete\n4.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter element you want to insert\n");
					scanf("%d",&element);
					if(insertInLinkedList(&head,element))
						printf("Successfully inserted\n");
					else
						printf("Some error occured\n");
					break;
			case 2: if(!displayLinkedList(head))
						printf("Linked list is empty\n");
					break;

			case 3: printf("Enter element to be deleted\n");
					scanf("%d",&element);
					if(!deleteFromLinkedList(&head,element))
						printf("Element not found\n");
					else
						printf("Element succesfully deleted\n");
					break;

			case 4: return;

			default: printf("Invalid Input\n");
		}
	}
	return 0;
}


/**
 *@return node *  i.e new created node
 *@param int  i.e value of node
 */
node * createNode(int element)
{
	node * temp;
	temp = (node *) malloc(sizeof(node));
	if(temp == NULL) //Not enough memory
		return 0;
	temp->next = NULL;
	temp->prev = NULL;
	temp->info = element;
}


/**
 *@return int , 1 if succesfully inserted else 0
 *@params node**, int
 */
int insertInLinkedList(node **head, int element)
{
	node *p,*temp,*q;
	p=*head;	//alias of head
	temp = createNode(element);
	if(temp == NULL) //Not enough memory
		return 0;

	if(p == NULL) //If linked list D.N.E
	{
		*head = temp;  //Assign the head to the first node
		temp->next = temp;
		temp->prev = temp;
		return 1;
	}
	else
	{
		q = p->prev;	//Since prev of head points to the last node
		q->next = temp;
		temp->prev = q;
		temp->next = p;
		p->prev = temp;
		return 1;
	}
}


/**
 *@return void
 *@param node*  i.e the head of linked list
 */
int displayLinkedList(node * head)
{
	node * q;
	q=head;

	if(q == NULL)
		return 0;
	do
	{
		printf("%d -> ",q->info);
		q=q->next;
	}while(q!=head);		//Since it is circular linked list
	printf("\n");
}



/**
 *@return int  0 or 1
 *@params node **, int
 */
int deleteFromLinkedList(node **head, int element)
{
	node *q;
	int flag=0;

	q= *head;
	do
	{
		if(q->info == element)
		{
			q->prev->next = q->next;
			q->next->prev = q->prev;
			if(q == *head)
			{
				if(q->next != *head)
					*head = q->next;
				else
					*head = NULL;
			}
			free(q);
			flag =1;
			break;
		}
		q=q->next;
	}while(q!=*head);

	if(!flag)
		return 0;
	else
		return 1;
}