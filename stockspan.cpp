
#include <iostream> 
#include <stack> 
using namespace std; 

void calculateSpan(int price[], int n, int S[]) 
{ 
	stack<int> st; 
	st.push(0);  
	S[0] = 1; 
	for (int i = 1; i < n; i++) { 
		while (!st.empty() && price[st.top()] <= price[i]) 
			st.pop(); 
		S[i] = (st.empty()) ? (i + 1) : (i - st.top()); 
		st.push(i); 
	} 
} 

void printArray(int arr[], int n) 
{ 
	for (int i = 0; i < n; i++) 
		cout << arr[i] << " "; 
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
		calculateSpan(price,n,stack);
		printArray(stack,n);
	}
	return 0;
}
