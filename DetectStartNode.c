#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

struct node* newNode(int key)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=key;
	temp->next=NULL;
	return temp;
}

struct node* detectAndRemoveLoop(struct node* head)
{
	int loopexist=0;
	struct node* slowPtr=head;
	struct node* fastPtr=head;
	while(slowPtr && fastPtr && fastPtr->next)
	{
		slowPtr=slowPtr->next;
		fastPtr=fastPtr->next->next;
		if(slowPtr==fastPtr)
		{
			loopexist=1;
			break;
		}
	}//This is heart of the above code
	if(loopexist)
	{
		for(slowPtr=head;slowPtr!=fastPtr;slowPtr=slowPtr->next,fastPtr=fastPtr->next);
		return slowPtr;
	}
}

void printList(struct node* head)
{
	while(head)
	{
		printf("%d ",head->data);
		head=head->next;
	}
}

int main()
{
	struct node* head=NewNode(50);
	head->next = newNode(20); 
    head->next->next = newNode(15); 
    head->next->next->next = newNode(4); 
    head->next->next->next->next = newNode(10); 
    head->next->next->next->next->next = head->next->next;
    struct node* res=detectAndRemoveLoop(head);
    if(res==NULL)
    {
		printf("Loop is detected\n");
	}
	else
	{
		printf("Loop is not existed here\n");
	}
	return 0;
}
