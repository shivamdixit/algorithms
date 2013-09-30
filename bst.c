/**
 *@author        : Shivam Dixit
 *@file          : btree.c
 *@description   : Binary Search Tree implementation
 */

#include<stdio.h>
#include<stdlib.h>

/**
 *ADT (node) to represent a node of BST
 *@var int
 *@var node pointer
 *@var node pointer
 */
struct node
{
	int info;
	struct node * left;
	struct node * right;
	/* data */
};

typedef struct node node;

/**
 *Function definitions
 *createNode
 *insertInBST
 *printBST
 */
node * createNode(void);
int insertInBST(node ** , int );
int printBST(node *);

/**
 *main() begins
 */
int main(int argc, char const *argv[])
{
	node * root =NULL;
	int choice =1,element;
	system("clear");
	printf("Program to implement Binary Search Tree\n");
	while(choice != 3)
	{
		printf("Enter your choice\n1.Insert element in Tree.\n2.Print Tree\n3.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter element\n");
					scanf("%d",&element);
					if(insertInBST(&root,element))
						printf("Successfully Inserted !!\n");
					break;
			case 2: printBST(root);
					break;
			case 3: break;

			default : printf("Invalid choice. Enter again\n");
					 break;
		}
	}
	return 0;
}

/**
 *@return  : Pointer to node created
 *@params  : void
 *@desc    : Function to dynamically create a node
 */
node * createNode()
{
	return ((node *)malloc(sizeof(node)));
}


/**
 *@return  : Int 1 if successfully inserted else 0
 *@params  : Root of BST, Element to be inserted
 *@desc    : Function to insert a node in BST
 */
int insertInBST(node ** root, int element)
{
	int i;
	node *p,*temp;
	p = *root;
	if(p == NULL)
	{
		temp = createNode();
		temp->left = NULL;
		temp->right = NULL;
		temp->info= element;
		*root = temp;
		return 1;
	}
	if(p->info == element)
		return 0;
	else if(element < p->info)
	{
		if(p->left == NULL)
		{
			temp = createNode();
			temp->left = NULL;
			temp->right = NULL;
			temp->info= element;
			p->left = temp;
			return 1;
		}
		insertInBST(&(p->left),element);
	}
	else
	{
		if(p->right == NULL)
		{
			temp = createNode();
			temp->left = NULL;
			temp->right = NULL;
			temp->info= element;
			p->right = temp;
			return 1;
		}
		insertInBST(&(p->right),element);
	}
}


/**
 *@return  : integer
 *@params  : Root of BST
 *@desc    : Function to print the BST in PREORDER TRAVERSAL
 */
int printBST(node * root)
{
	if(root == NULL)
		return;
	printf("%d ",root->info);
	if(root->left != NULL)
	{
		printBST(root->left);
	}
	if(root->right != NULL)
	{
		printBST(root->right);
	}
	return 1;
}