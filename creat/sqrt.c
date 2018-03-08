#include<stdio.h>
int main()
{
	int n,r;
	scanf("%d",&n);
	

	while  (n--)
	{
		int ctr[100]={0};
		int d;
		scanf("%d",&d);ctr[0]++;
		if (d>=85)
		{
			printf("A+\n");
		}
		else if (d>=75)
		{
			printf("A\n");
		}
		else if (d>=65)
		{
			printf("B+\n");
		}
		else if (d>=55)
		{
			printf("B\n");
		}
		else if (d>=35)
		{
			printf("C");
		}
		else if (d>=25)
		{
			printf("D\n");
		}
		else if (d>=0)
		{
			printf("E\n");
		}

	}
}