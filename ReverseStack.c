#include<stdio.h>
#include<stdlib.h>
#define bool int

struct sNode
{
	char data;
	struct sNode* next;
};
void push(struct sNode** top_ref,int new_data);
int pop(struct sNode** top_ref);
bool isEmpty(struct sNode* top);
void print(struct sNode* top);

bool isEmpty(struct sNode* top)
{
	return(top==NULL)?1:0;
}

void print(struct sNode* top)
{
	while(top)
	{
		printf("%d ",top->data);
		top=top->next;
	}
	return;
}

int pop(struct sNode** top_ref)
{
	char res;
	struct sNode* top;
	if(*top_ref==NULL)
	{
		printf("Sorry!! I am in underflow Condition\n");
		return 0;
	}
	else
	{
		top=*top_ref;
		res=top->data;
		*top_ref=top->next;
		free(top);
		return res;
	}
}

void push(struct sNode** top_ref,int new_data)
{
	struct sNode* new_node=(struct sNode*)malloc(sizeof(struct sNode));
	if(!new_node)
	{
		return;
	}
	new_node->data=new_data;
	new_node->next=(*top_ref);
	(*top_ref)=new_node;
}

void insertAtBottom(struct sNode** top_ref,int item)
{
	if(isEmpty(*top_ref))
	{
		push(top_ref,item);
	}
	else
	{
		int top_Item=pop(top_ref);
		insertAtBottom(top_ref,item);
		push(top_ref,top_Item);
	}
}

void reverse(struct sNode** top_ref)
{
	if(!isEmpty(*top_ref))
	{
		int item=pop(top_ref);
		reverse(top_ref);
		insertAtBottom(top_ref,item);
	}
}
int main()
{
	struct sNode* s=NULL;
	push(&s,4);
	push(&s,3);
	push(&s,2);
	push(&s,1);
	printf("Original stack is:\n");
	print(s);
	printf("Reversal stack is:\n");
	print(s);
	return 0;
}
