#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
int eq(double x,double y){
	if(abs(x-y)<0.0001)
		return 1;
	return 0;
}
int mxiter;
const int N=20;
#include "data.cpp"
#include "./modd2.cpp"
#include "initialp.cpp"
#include "populateall.cpp"
#include "fitness.cpp"
#include "parentselection.cpp"
#include "crossover.cpp"
#include "GA.cpp"
char s[100];


int main()
{
	printf("Enter the file name :");
	scanf("%s",s);
	FILE *f=fopen(s,"r");
	int n,r,i,j;
	fscanf(f,"%d%d",&n,&r);
	dataG dat(n,r);
	GA thisis;
	thisis.n=n;
	thisis.r=r;
	bitset<N>ex;
	ex.reset();
	for (i=0;i<n;i++){
		for (j=0;j<r;j++)
		{
			int x;
			fscanf(f,"%d",&x);
			if (x)
			{
				dat.B[i].set(j);
			}
		}
		ex=ex|dat.B[i];
	}
	fitness(dat);
	if (ex.count()<r){
		printf("A covering set can never be reached ! \n");
		return 0;
	}
	int ini;
	double proc,prom;
	printf("Enter the initial population size::");
	scanf("%d",&ini);
	printf("Enter the crossover probability ::");
	scanf("%lf",&proc);
	printf("Enter the mutation probability ::");
	scanf("%lf",&prom);
	printf("Maximum number of population allowed to reach::");
	scanf("%d",&mxiter);
	thisis.ini=ini;
	thisis.proc=proc;
	thisis.prom=prom;
	dataG got;
	for (i=1;i<=n;i++)
	{
		cerr<<"calling genetic for :"<<i<<endl;
		got=thisis.geneticalgo(i,dat);
		//cerr<<"finished genetic for :"<<i<<endl;
		if (got.n==-1)
			continue;

		fitness(got);
		if (eq(got.fitness,100))
		{
			break;
		}
	}
	if (i>n){
		printf("No such test case suite found!");

	}
	else
	{
		printf("test case suite of %d tests found ! \n",got.n);
		for(i=0;i<got.n;i++)
		{
			for (j=0;j<got.r;j++)
			{
				printf("%d ",(got.B[i].test(j))?1:0);
			}
			printf("\n");
		}
	}
	return 0;
}