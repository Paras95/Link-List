#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next,*arbit;
};

void reverse(struct node** head)
{
	struct node* prev=NULL;
	struct node* next;
	struct node* current=*head;
	while(current)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	*head=prev;
}

struct node* newNode(int new_data)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=new_data;
	temp->next=NULL;
	temp->arbit=NULL;
	return temp;
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

void printNextArbitPointers(struct node* head)
{
	reverse(&head);
	struct node* maxnode=head;
	struct node* temp;
	for(temp=head->next;temp;temp=temp->next)
	{
		temp->arbit=head;
		if(temp > maxnode)
		{
			maxnode=temp;
		}
	}
	reverse(&head);
	printList(head);
	return;
}

int main() 
{ 
 
    struct node *head = newNode(5); 
    head->next = newNode(10); 
    head->next->next = newNode(2); 
    head->next->next->next = newNode(3); 
    printNextArbitPointers(head); 
  
    return 0; 
}
