/**
 *@author	Shivam Dixit
 *@file		graphs.c
 *@description	Program to generate a graph using Adjacency list
 *					and find degree of a node in a graph
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
 *Structure for a single node
 *@var char to represent a vertex of a graph
 *$var pointer to next vertex
 */
struct node
{
	char a;
	struct node * next;
};

typedef struct node node;

node * createNode(void);
int degreeOfNode(char ,node *,int );

int main(int argc, char const *argv[])
{
	int numberOfVertices,numberOfEdges,c=1,i,j;
	char edge[10],s;
	node graph[100];
	node * temp,*root,*temp2;
	system("clear");
	while(c!=4)
	{
		printf("\nEnter your choice\n\n\t1.Create a graph\n\t2.Find degree of a node\n\t3.BFS of graph\n\t4.Exit\n\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1: printf("Enter number of vertices of graph\n");
					scanf("%d",&numberOfVertices);
					printf("Enter vertices one at a time. (Represent by a char)\n");
					for(i=0;i<numberOfVertices;i++)
					{
						scanf("\n%c",&graph[i].a);
						graph[i].next = NULL;
					}
					printf("Enter number of edges\n");
					scanf("%d",&numberOfEdges);
					printf("Enter edges one at a time. (Ex: \"ab\" represent an edge between a and b)\n");
					for(j=0;j<numberOfEdges;j++)
					{
						scanf("%s",edge);
						if(strlen(edge) > 2)
						{
							printf("Invalid edge\n");
							continue;
						}
						if(edge[0] == edge[1])
							continue;
						temp = createNode();
						temp->next = NULL;
						temp->a = edge[0];

						temp2 = createNode();
						temp2->next = NULL;
						temp2->a = edge[1];

						for(i=0;i<numberOfVertices;i++)
						{
							if(graph[i].a == edge[0])
							{
								root = &graph[i];
								while(root->next != NULL)
									root = root->next;
								root->next = temp2;
							}
							//Because for undirected graph edge between a & b also means an edge between b & a
							if(graph[i].a == edge[1])
							{
								root = &graph[i];
								while(root->next != NULL)
									root = root->next;
								root->next = temp;
							}
						}
					}
					printf("Graph succesfully generated !\n");
					break;
			case 2: printf("Enter node\n");
					scanf("\n%c",&s);
					printf("\nDegree of node is %d",degreeOfNode(s,graph,numberOfVertices));
					break;
			case 3: break;

			case 4: break;

			default: printf("Invalid choice");
					break;
		}
	}
	return 0;
}


/**
 *Function to allocate memory to a node
 */
node * createNode(void)
{
	return (node *)malloc(sizeof(node));
}

/**
 *Function to return degree of node
 *@param char representing a node
 *@param node * to represent a graph
 *@param int number of vertex in a graph
 */
int degreeOfNode(char e,node * graph,int n)
{
	int i,degree=0;
	node * root;
	for(i=0;i<n;i++)
	{
		if(graph[i].a == e)
		{
			root = &graph[i];
			while(root->next != NULL)
			{
				degree++;
				root = root->next;
			}
			return degree;
		}
	}
	return 0;
}