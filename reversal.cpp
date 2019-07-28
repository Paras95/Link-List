using namespace std;
#include<string>
#include<stack>
#include<cmath>
#include<iostream>

int main()
{
	int t;
	//int un_balance_size;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		int n=str.length();
		int count=0;
		stack<char>s;
		if(n%2==0)
		{
			for(int i=0;i<n;i++)
			{
				if(str[i]=='}' && !s.empty())
				{
					char x=s.top();
					if(x=='{')
					{
						s.pop();
					}
					else
					{
						s.push(str[i]);
					}
				}
				else
				{
					s.push(str[i]);
				}
			}
		}
		float a=s.size();
		while(!s.empty() && s.top()=='{')
		{
			count++;
			s.pop();
		}
		cout<<(ceil(a/2)+ceil(count/2))<<endl;
		//printf("%d\n",ceil(un_balance_size/2)+ceil(count%2)));
	}
	return 0;
}
