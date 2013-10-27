/**
 *Name : Josephus Problem Implementation
 *Author : Shivam Dixit
 */

#include<stdio.h>
#include<stdlib.h>

/**
 *Node of a Circular Linked List
 *@var information, next node pointer
 */
struct node {
	char info;
	struct node * next;
};

/**
 *Typedef to use just "node" instead of "struct node"
 */
typedef struct node node;


/**
 *Function declarations
 */
node * createNode();
int insertInLinkedList(node ** ,char );
void createCircularLinkedList(node * );
char josephus(node * ,char ,int ,int );

/**
 *main() begins
 */
int main(int argc, char const *argv[])
{
	node * head = NULL;
	int i,n,count;
	char c,ans,start;
	system("clear");
	printf("Enter number of people\n");
	scanf("%d",&n);
	for (i = 0; i < n; ++i)
	{
		printf("Enter a letter for person (all must be distinct):\n");
		scanf("\n%c",&c);
		insertInLinkedList(&head,c);   //head passed as reference to change its value inside main from func
	}
	printf("Enter start person\n");
	scanf("\n%c",&start);
	printf("Enter number of skip\n");
	scanf("%d",&count);
	ans = josephus(head,start,count,n);
	printf("The person remaining is : %c\n",ans);
	return 0;
}


/**
 *Function to create a node dynamically of a C.L.L (Circular Linked List)
 *@param    void
 *@return   node pointer
 */
node * createNode()
{
	node * n;
	n = (node *) malloc(sizeof(node));
	return n;
}


/**
 *Function to insert node in L.L
 *@param pointer to head of L.L, element to be inserted
 *@return 1 if succesfully inserted
 */
int insertInLinkedList(node ** head,char c)
{
	node * temp,*p;
	p = *head;
	temp = createNode();
	temp->info = c;
	temp->next = NULL;
	if(*head == NULL)
	{
		*head = temp;
		return 1;
	}
	while(p->next !=NULL)
	{
		p = p->next;
	}
	p->next = temp;
	return 1;
}


/**
 *Function to convert a L.L to C.L.L
 *@param pointer to head
 *@return void
 */
void createCircularLinkedList(node * head)
{
	node * p =head;
	while(p->next != NULL)
		p=p->next;
	p->next = head;
}


/**
 *Function to return answer of Josephus problem
 *@param pointer to head of L.L, start person, Skip count, Total number of persons
 *@return final answer
 */
char josephus(node * head,char start,int c,int n)
{
	createCircularLinkedList(head);
	node *p = head;
	node *q = head;
	int count =c;
	while(1)
	{
		if(p->info == start)
			break;
		p=p->next;
	}
	while(1)
	{
		//Because the current node where I am standing will also be counted, hence decremented count
		count = c-1;
		while(1)
		{
			count--;
			if(count==0)
				break;
			p = p->next;      //To stop one node BEFORE which we have to delete
		}
		p->next = p->next->next;
		p = p->next;
		n--;
		if(n==1)
			break;
	}
	return p->info;
}