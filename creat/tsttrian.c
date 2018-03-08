#include<stdio.h>

int main()
{
	srand(time(NULL));
	int n=1000;
	printf("%d\n",n);
	while (n--){
		int a,b,c;
		a=rand()%10+1;
		if (rand()%10<5)
			b=a;
		else b=rand()%10+1;
		if (rand()%10<5)
		{
			c=b;
		}
		printf("%d %d %d\n",a,b,c);
	}
}