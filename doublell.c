#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct node
{
	int data;
	struct node* next;
	struct node* prev;
};

struct node* newNode(int new_data)
{
	struct node* new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=new_data;
	new_node->next=NULL;
	new_node->prev=NULL;
	return new_node;
}
