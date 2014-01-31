/**
 *@author        : Shivam Dixit
 *@file          : circular_db_ll.c
 *@description   : Circular doubly linked list implementation
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
void displayLinkedList(node * head);

int main(int argc, char const *argv[])
{
	int ch,element;
	node *head =NULL;
	while(1)
	{
		printf("Enter you choice\n1.Insert\n2.Print\n3.Exit\n");
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
			case 2: displayLinkedList(head);
					break;

			case 3: return;

			default: printf("Invalid type\n");
		}
	}
	return 0;
}


/**
 *@return int , 1 if succesfully inserted else 0
 *@params node**, int
 */
int insertInLinkedList(node **head, int element)
{
	node *p,*temp,*q;
	p=*head;	//alias of head
	temp = (node *)malloc(sizeof(node));
	temp->next = NULL;
	temp->prev = NULL;
	temp->info = element;

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
 *@return voide
 *@param node*  i.e the head of linked list
 */
void displayLinkedList(node * head)
{
	node * q;
	q=head;
	do
	{
		printf("%d -> ",q->info);
		q=q->next;
	}while(q!=head);		//Since it is circular linked list
}