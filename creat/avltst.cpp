#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t=1000;
	printf("%d\n",t);
	while(t--)
	{
		int n=rand()%5+1,i,j;
		printf("%d\n",n );
		for (i=0;i<n;i++)
		{
			printf("%d ",rand()%((int)1e9)+1);
		}
		printf("\n");
	}
}