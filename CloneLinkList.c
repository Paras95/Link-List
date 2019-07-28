#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
	int data;
	struct node* next;
	struct node* random;
};

void print(struct node* head)
{
	while(head)
	{
		printf("%d and %d ",head->data,head->random->data);
		head=head->next;
	}
	return;
}
 
struct node* newNode(int new_data)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=new_data;
	temp->next=NULL;
	temp->random=NULL;
	return temp;
}

void setRandomPointer(struct node* head)
{
	struct node* currPtr=head;
	while(currPtr)
	{
		currPtr->next->random=currPtr->random->next;
		currPtr=currPtr->next->next;
	}
}

void splitAlternateNode(struct node* head,struct node** head1,struct node** head2)
{
	*head1=head;
	if(!head || !head->next)
	{
		return;
	}
	*head2=head->next;
	struct node* temp;
	while(head)
	{
		temp=head->next;
		head=head->next->next;
		head=temp;
	}
}

struct node* clone(struct node* head)
{
	struct node* temp,*currPtr,*mainList,*cloneList;
	currPtr=mainList=cloneList=head;
	while(currPtr)
	{
		temp=newNode(currPtr->data);
		temp->next=currPtr->next;
		currPtr->next=temp;
		currPtr=temp->next;
	}
	setRandomPointer(head);
	splitAlternateNode(head,&mainList,&cloneList);
	return cloneList;
}

int main() 
{ 
    struct node* head= newNode(1); 
    head->next = newNode(2); 
    head->next->next = newNode(3); 
    head->next->next->next = newNode(4); 
    head->next->next->next->next = newNode(5);  
    head->random = head->next->next;  
    head->next->random =head;  
    head->next->next->random = 
                    head->next->next->next->next; 
    head->next->next->next->random = 
                    head->next->next->next->next;  
    head->next->next->next->next->random = head->next; 
    struct node* cloned_list = clone(head); 
    print(cloned_list);
    return 0;
}
