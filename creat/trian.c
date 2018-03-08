#include<stdio.h>
int main()
{
	int n,r;
	scanf("%d",&n);
	r=7;
	fprintf(stderr,"%d %d\n",n,r);
	while(n--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		int ctr[1000]={0};
		ctr[0]++;
		if (a>0&&b>0&&c>0)
		{
			ctr[1]++;if (a+b>c&&b+c>a&&a+c>b)
			{
				ctr[2]++;if (a==b&&b==c)
				{
					printf("Equilateral triangle\n");
				}
				else if ((ctr[3]++,0)||a==b||b==c||c==a)
				{
					printf("Isosceles\n");
				}
				else
				{
					ctr[4]++;
					printf("Scalene\n");
				}
			}
			else
			{
				ctr[5]++;
				printf("Not a correct traingle\n");
			}
		}
		else
		{
			ctr[6]++;
			printf("Not a traingle!\n");
		}
		{
			int i;
			for (i=0;i<7;i++)
			{
				fprintf(stderr,"%d ",(ctr[i]>0?1:0));
			}
			fprintf(stderr,"\n");
		}

	}
	return 0;
}