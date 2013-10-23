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
int preOrderTraversal(node *);
int postOrderTraversal(node *);
int inOrderTraversal(node *);
int breadthFirstSearch(node *);


int flag=0;

/**
 *main() begins
 */
int main(int argc, char const *argv[])
{
	node * root =NULL;
	int choice =1,element;
	system("clear");
	printf("Program to implement Binary Search Tree\n");
	while(choice != 6)
	{
		printf("Enter your choice\n\t1.Insert element in Tree.\n\t2.Print Tree in Preorder Traversal\n\t3.Print Tree in Postorder Traversal\n\t4.Print Tree in Inorder Traversal\n\t5.Search a element\n\t6.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter element\n");
					scanf("%d",&element);
					if(insertInBST(&root,element))
						printf("Successfully Inserted !!\n");
					else
						printf("Duplicate Element\n");
					break;
			case 2: preOrderTraversal(root);
					break;
			case 3: postOrderTraversal(root);
					break;
			case 4:	inOrderTraversal(root);
					break;
			case 5: printf("Enter element you want to search ?\n");
					scanf("%d",&element);
					if(searchInBST(root,element))
						printf("Element found\n");
					else
						printf("Not found\n");
					break;
			case 6:break;
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
int preOrderTraversal(node * root)
{
	if(root == NULL)
		return;
	printf("%d ",root->info);
	if(root->left != NULL)
	{
		preOrderTraversal(root->left);
	}
	if(root->right != NULL)
	{
		preOrderTraversal(root->right);
	}
	return 1;
}

/**
 *@return  : integer
 *@params  : Root of BST
 *@desc    : Function to print the BST in POSTORDER TRAVERSAL
 */
int postOrderTraversal(node * root)
{
	if(root == NULL)
		return;
	if(root->left != NULL)
		postOrderTraversal(root->left);
	if(root->right != NULL)
		postOrderTraversal(root->right);
	printf("%d ",root->info);
}



/**
 *@return  : integer
 *@params  : Root of BST
 *@desc    : Function to print the BST in INORDER TRAVERSAL
 */
int inOrderTraversal(node * root)
{
	if(root == NULL)
		return;
	if(root->left != NULL)
		inOrderTraversal(root->left);
	printf("%d ",root->info);
	if(root->right != NULL)
		inOrderTraversal(root->right);
}

/**
 *@return  : integer
 *@params  : Root of BST , element to be searched
 *@desc    : Function to search a node in a BST
 */
int searchInBST(node * root,int element)
{
	if(root == NULL)
		return 0;
	node *p;
	p = root;
	if(p->info == element)
	{
		flag = 1;
		return 1;
	}
	else if(p->info > element)
		searchInBST(p->left,element);
	else if(p->info < element)
		searchInBST(p->right,element);
	if(flag)
	{
		flag= 0;
		return 1;
	}
	else
	{
		return 0;
	}
}


/**
 *@return  : integer
 *@params  : Root of BST
 *@desc    : Function to print the BST in Breadth First
 *To be completed
 */
// int breadthFirstSearch(node * root)
// {
// 	if(root == NULL)
// 		return;
// 	printf("%d ",root->info);
// 	if(root->left != NULL)
// 		printf("%d ",root->left->info);
// 	if(root->right != NULL)
// 		printf("%d ",root->right->info);
// 	if(root->left != NULL)
// 		breadthFirstSearch(root->left);
// 	if(root->right != NULL)
// 		breadthFirstSearch(root->right);
// }