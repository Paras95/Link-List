#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char str1[2000],str2[2000];
		scanf("%s",str1);
		int len=strlen(str1);
		for(int i=0;i<len;i++)
		{
			str2[i]=str1[len-1-i];
		}
		int index2;
		for(int j=0;j<len;j++)
		{
			if(str2[j]=='.')
			{
				index2=j-1;
				while((str2[index2]!='.') && index2>=0)
				{
					printf("%c",str2[index2]);
					index2--;
				}
				printf(".");
			}
			else if(j==len-1)
			{
				index2=j;
				while((str2[index2]!='.') && index2>=0)
				{
					printf("%c",str2[index2]);
					index2--;
				}
			}
		}
		printf("\n");
	}
	return 0;
}
