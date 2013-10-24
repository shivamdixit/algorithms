/** Header file for implementing stack and node FOR EXPRESSION TREE
 * Author: Shivam Dixit
 * Date : 05 Sep 2013
 */

/**
 *ADT (node) to represent a node of an expression Tree
 *@var char
 *@var node pointer
 *@var node pointer
 */
struct node
{
	char info;
	struct node * left;
	struct node * right;
	/* data */
};

typedef struct node node;

typedef struct stack
{
	int top;
    node * arr[100];
	/* data */
}stack;

int pushInStack(stack *,node *);

node * popStack(stack *);

int isStackFull(stack *);

int isStackEmpty(stack *);