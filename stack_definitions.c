/**
 *Function definitions for stack
 *@author: Shivam Dixit
 *@file : definitions.c
 */

#include"stack.h"

int isStackFull(stack *s1)
{
	if(s1->top == 20)
		return 1;
	return 0;
}

int isStackEmpty(stack *s1)
{
	if(s1->top == -1)
		return 1;
	return 0;
}

int pushInStack(stack *s1,int *p)
{
	if(isStackFull(s1))
		return 0;
	s1->top++;
	s1->arr[s1->top] = p;
	return 1;
}

int* popStack(stack *s1)
{
	if(isStackEmpty(s1))
		return 0;
	return s1->arr[s1->top--];
}