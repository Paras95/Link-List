#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct node
{
	int data;
	struct node* next;
};

void push(struct node** head_ref,int new_data)
{
	struct node* new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=new_data;
	new_node->next=(*head_ref);
	(*head_ref)=new_node;
}

void printList(struct node* head)
{
	while(head)
	{
		printf("%d ",head->data);
		head=head->next;
	}
	return;
}

struct node* sortedMerge(struct node* head1,struct node* head2)
{
	struct node* temp;
	struct node* mergeList;
	if(head1->data<=head2->data)
	{
		mergeList=head1;
		head1=head1->next;
	}
	else
	{
		mergeList=head2;
		head2=head2->next;
	}
	temp=mergeList;
	while(head1 && head2)
	{
		if(head1->data <= head2->data)
		{
			temp->next=head1;
			temp=temp->next;
			head1=head1->next;
		}
		else
		{
			temp->next=head2;
			temp=temp->next;
			head2=head2->next;
		}
	}
	if(!head1)
	{
		temp->next=head2;
	}
	else
	{
		temp->next=head1;
	}
	return mergeList;
}

int main()
{
	struct node* res=NULL;
	struct node* head1=NULL;
	struct node* head2=NULL;
	push(&head1,15);
	push(&head1,10);
	push(&head1,5);
	//Next Link List
	push(&head2,20);
	push(&head2,3);
	push(&head2,2);
	res=sortedMerge(head1,head2);
	printList(res);
	return 0;
}
