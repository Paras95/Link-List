#include <stdio.h> 
#include <stdlib.h> 

struct Node { 
    int data; 
    struct Node* next; 
};

void printList(struct Node* node) 
{ 
    while (node != NULL) { 
        printf("%d ", node->data); 
        node = node->next; 
    } 
} 

void FrontBackSplit(struct Node* source,struct,struct Node** frontRef,struct Node** backRef)
{
	struct Node* fast;
	struct Node* slow;
	slow=source;
	fast=source->next;
	while(fast)
	{
		fast=fast->next;
		if(fast)
		{
			slow=slow->next;
			fast=fast->next;
		}
	}
	*frontRef=source;
	*backRef=slow->next;
	slow->next=NULL;
}

struct Node* SortedMerge(struct Node* a,struct Node* b)
{
	struct Node* result=NULL;
	if(!a)
	{
		return b;
	}
	else if(!b)
	{
		return a;
	}
	if(a->data<=b->data)
	{
		result=a;
		result->next=SortedMerge(a->next,b);
	}
	else
	{
		result=b;
		result->next=SortedMerge(a,b->next);
	}
	return(result);
}

void MergeSort(struct Node** headRef)
{
	struct Node* head=*headRef;
	struct Node* a;
	struct Node* b;
	if(!head || !head->next)
	{
		return;
	}
	FrontBackSplit(head,&a,&b);
	MergeSort(&a);
	MergeSort(&b);
	*headRef=SortedMerge(a,b);
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
	struct Node* res = NULL; 
    struct Node* a = NULL; 
    push(&a, 15); 
    push(&a, 10); 
    push(&a, 5); 
    push(&a, 20); 
    push(&a, 3); 
    push(&a, 2); 
    MergeSort(&a); 
    printf("Sorted Linked List is: \n"); 
    printList(a); 
    //getchar(); 
    return 0; 
}
