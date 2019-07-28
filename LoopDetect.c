#include <stdio.h> 
#include <stdlib.h> 

struct Node { 
	int data; 
	struct Node* next; 
}; 
void detectloop(struct Node* head)
{
	struct Node* slowPtr=head;
	struct Node* fastPtr=head;
	while(slowPtr && fastPtr && fastPtr->next)
	{
		slowPtr=slowPtr->next;
		fastPtr=fastPtr->next->next;
		if(slowPtr==fastPtr)
		{
			printf("True\n");
			break;
		}
	}
	printf("False\n");
}
void push(struct Node** head_ref, int new_data) 
{ 
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
	new_node->data = new_data; 
	new_node->next = (*head_ref); 
	(*head_ref) = new_node; 
} 
int main() 
{
	struct Node* head = NULL; 

	push(&head, 20); 
	push(&head, 4); 
	push(&head, 15); 
	push(&head, 10); 
	head->next->next->next->next = head; 
	detectloop(head); 

	return 0; 
} 

