#include<bits/stdc++.h>
using namespace std;
struct ele
{
	int start;
	int end;
};

bool compare(struct ele a,struct ele b)
{
	return (a.start<b.start);
}

void mergeInterval(struct ele arr[],int n)
{
	if(n<=0)
	{
		return;
	}
	sort(arr,arr+n,compare);
	stack<struct ele>s;
	s.push(arr[0]);
	for(int i=1;i<n;i++)
	{
		struct ele t=s.top();
		if(t.end<arr[i].start)
		{
			s.push(arr[i]);
		}
		else if(t.end<arr[i].end)
		{
			t.end=arr[i].end;
			s.pop();
			s.push(top);
		}
	}
	return;
}

int main()
{
	int t;
	cin >>t;
	while(t--)
	{
		int n;
		cin>>n;
		struct ele arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i].start>>arr[i].end;
		}
		mergeInterval(arr,n);
		printf("\n");
	}
	return 0;
}
