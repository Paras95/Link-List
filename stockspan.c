#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<stack>
using namespace std;

void printArray(int stack[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		cout << arr[i] << " ";
	}
}

void calculateSpan(int price[],int n,int stack[])
{
	stack<int> st;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int price[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d",&price[i]);
		}
		int stack[n];
		calculate(price,n,stack);
		printArray(stack,n);
	}
	return 0;
}
