#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

struct node* newNode(int new_node)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=new_node;
	temp->next=NULL;
	return temp;
}

struct node* reverse(struct node* head)
{
	struct node* prev=NULL;
	struct node* next;
	struct node* current=head;
	while(current)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	return prev;
}

void printList(struct node* head)
{
	while(head)
	{
		printf("%d ",head->data);
		head=head->next;
	}
}

struct node* addOneUtil(struct node* head)
{
	int carry=1;
	int sum=0;
	struct node* res=head;
	struct node* temp;
	//struct node* head1=reverse(head);
	while(head)
	{
		sum+=carry+head->data;
		carry=(sum==10)?1:0;
		sum=sum%10;
		head->data=sum;
		temp=head;
		head=head->next;
	}
	if(carry>0)
	{
		temp->next=newNode(carry);
	}
	return res;
}

struct node* addOne(struct node* head)
{
	head=reverse(head);
	head=addOneUtil(head);
	return reverse(head);
}

int main() 
{ 
    struct node *head = newNode(1); 
    head->next = newNode(9); 
    head->next->next = newNode(9); 
    head->next->next->next = newNode(9); 
    printf("List is "); 
    printList(head); 
    head = addOne(head); 
    printf("\nResultant list is "); 
    printList(head); 
    return 0; 
} 
