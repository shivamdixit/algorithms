/**
 *@author        : Shivam Dixit
 *@file          : expression_tree.c
 *@description   : Generating expression tree from post order traversal
 */

#include<stdio.h>
#include<stdlib.h>
#include"stack_exp.h"

/**
 *Function declarations
 *createNode()
 *generateTree()
 *postOrderTraversal
 */
node * createNode(int );
int generateTree(char *);
int postOrderTraversal(node *);


/**
 *main() begins
 */
int main(int argc, char const *argv[])
{
	char a[100];
	int i,j,k;
	system("clear");
	printf("Program to generate expression tree from postorder expression\n");
	printf("Please enter post order expression. Allowed operators : +,-,*,/,$\n");
	gets(a);
	if(!generateTree(a))
		printf("Invalid expression\n");
	else
		printf("Successfully generated\n");
	//postOrderTraversal();
	return 0;
}


/**
 *Function to create a node of a tree
 *@return node pointer
 *@params integer
 */
node * createNode(int a)
{
	node * temp;
	temp = (node *)malloc(sizeof(node));
	temp->left = NULL;
	temp->right = NULL;
	temp->info = a;
	return (temp);
}

/**
 *Function to generate a tree
 *@return int
 *@params character pointer
 */
int generateTree(char *a)
{
	int i;
	stack s1;
	node * n, *b,*c;
	s1.top=-1;
	for(i=0;a[i]!='\0';i++)
	{
		n = createNode(a[i]);
		if(a[i]=='*' || a[i] == '+' || a[i] == '-' || a[i] == '/' || a[i] == '$')
		{
			/**
			 *If stack contains less than 2 operands, invalid expression
			 */
			if(s1.top <1)
			{
				return 0;
			}
			b = popStack(&s1);
			c = popStack(&s1);
			n->left = c;
			n->right = b;
			pushInStack(&s1,n);
		}
		else
		{
			pushInStack(&s1,n);
		}
	}
	/**
	 *After end of loop only final answer should remain in stack
	 */
	if(s1.top>0)
		return 0;   //i.e invalid expression
	printf("\n");
	postOrderTraversal(n);
	return 1;
}


/**
 *Post order traversal of a tree
 *@return int
 *@params node pointer
 */
int postOrderTraversal(node * root)
{
	if(root == NULL)
		return;
	if(root->left != NULL)
		postOrderTraversal(root->left);
	if(root->right != NULL)
		postOrderTraversal(root->right);
	printf("%c ",root->info);
}