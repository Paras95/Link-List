#include<stdio.h> 
#include<stdlib.h> 
struct Node 
{ 
    int data; 
    struct Node* next; 
}; 
void removeLoop(struct Node *, struct Node *);

void printList(struct Node *node) 
{ 
    while (node != NULL) 
    { 
        printf("%d  ", node->data); 
        node = node->next; 
    } 
} 

void RemoveLoop(struct Node* slow_ptr,struct Node* head)
{
	struct Node* ptr1;
	struct Node* ptr2;
	ptr1=head;
	while(1)
	{
		ptr2=slow_ptr;
		while(ptr2->next!=slow_ptr)
		{
			ptr2=ptr2->next;
		}
		if(ptr2->next==ptr1)
		{
			break;
		}
		ptr1=ptr1->next;
	}
	ptr2->next=NULL;
}

void detectAndRemoveLoop(struct Node* head)
{
	struct Node* slowPtr;
	struct Node* fastPtr;
	while(slowPtr && fastPtr && fastPtr->next)
	{
		slowPtr=slowPtr->next;
		fastPtr=fastPtr->next->next;
		if(slowPtr==fastPtr)
		{
			RemoveLoop(slowPtr,head);
			break;
		}
	}
}

struct Node *newNode(int key) 
{ 
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node)); 
    temp->data = key; 
    temp->next = NULL; 
    return temp; 
} 
int main() 
{ 
    struct Node *head = newNode(50); 
    head->next = newNode(20); 
    head->next->next = newNode(15); 
    head->next->next->next = newNode(4); 
    head->next->next->next->next = newNode(10); 
  
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next; 
  
    detectAndRemoveLoop(head); 
  
    printf("Linked List after removing loop \n"); 
    printList(head); 
    return 0; 
} 
