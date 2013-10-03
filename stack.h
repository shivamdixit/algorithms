/**
 *Header file for implementing stack
 *@author     : Shivam Dixit
 *@desc       : Contains stack ADT.
 */



/**
 *ADT stack to represent a STACK
 *@var top     points top of the stack
 *@var *arr    array of pointers, to store one array (containing low,mid,high,flag) as single element
 */
typedef struct stack
{
	int top;
    int *arr[20];
}stack;



/**
 *Function definitions
 *pushInstack()          to push an array into stack
 *popStack()             to pop an array from stack
 *isStackFull()          check if stack is full
 *isStackEmpty()         check if stack is empty
 */


/**
 *Function to push an array into stack
 *@params pointer to stack, pointer to array
 *@return int 1 if inserted successfully
 */
int pushInStack(stack *,int*);


/**
 *Function to pop an array into stack
 *@params pointer to stack
 *@return popped array
 */
int* popStack(stack *);

/**
 *Function to check if stack is full
 *@params pointer to stack
 *@return int 1 if stack is full else 0
 */
int isStackFull(stack *);


/**
 *Function to check if stack is empty
 *@params pointer to stack
 *@return int 1 if stack empty else 0
 */
int isStackEmpty(stack *);