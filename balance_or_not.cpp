#include<iostream>
#include<stack>
#include<cmath>
#include<string>
#include<bits/stdc++.h>

using namespace std;

bool areParanthesisBalance(string expr,int n)
{
	stack<char>st;
	char x;
	for(int i=0;i<n;i++)
	{
		if(expr[i]=='{' || expr[i]=='[' || expr[i]=='(')
		{
			st.push(expr[i]);
			continue;
		}
		if(st.empty())
		{
			return false;
		}
		switch(expr[i])
		{
			case ')':
			x=st.top();
			st.pop();
			if(x=='[' || x=='{')
			{
				return false;
			}
			break;
			
			case ']':
			x=st.top();
			st.pop();
			if(x=='{' || x=='(')
			{
				return false;
			}
			break;
			
			case '}':
			x=st.top();
			st.pop();
			if(x=='[' || x=='(')
			{
				return false;
			}
			break;
		}
	}
	return (st.empty());
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string expr;
		cin>>expr;
		int n=expr.length();
		if(areParanthesisBalance(expr,n))
		{
			printf("balanced\n");
		}
		else
		{
			printf("not balanced\n");
		}
	}
	return 0;
}
