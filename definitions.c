/** Function definitions for stack
 * Author: Shivam Dixit
 * Date : 05 Sep 2013
 */

#include"stack.h"

int isStackFull(stack *s1)
{
	if(s1->top == 10)
		return 1;
	return 0;
}

int isStackEmpty(stack *s1)
{
	if(s1->top == -1)
		return 1;
	return 0;
}

int pushInStack(stack *s1,char element)
{
	if(isStackFull(s1))
		return 0;
	s1->top++;
	s1->arr[s1->top] = element;
	return 1;
}

char popStack(stack *s1)
{
	if(isStackEmpty(s1))
		return 0;
	return s1->arr[s1->top--];
}