#include<cmath>
#include<string>
#include<stack>
#include<iostream>

using namespace std;
bool findDuplicateParenthesis(string str)
{
	stack<char>st;
	for(char ch:str)
	{
		if(ch==')')
		{
			char top=st.top();
			st.pop();
			int element_inside=0;
			while(st.top()!='(')
			{
				char top=st.top();
				st.pop();
				element_inside++;
			}
			if(element_inside<1)
			{
				return 1;
			}
		}
		else
		{
			st.push(ch);
		}
	}
	return false;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		int n=str.length();
		if(findDuplicateParenthesis(str))
		{
			printf("Duplicates Found:\n");
		}
		else
		{
			printf("Duplicates Not Found:\n");
		}
	}
	return 0;
}
