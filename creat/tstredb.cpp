#include<bits/stdc++.h>
using namespace std;

int main(){
	int t=1000;
	srand(time(NULL));
	printf("%d\n",t);
	while (t--){
		int x=5;
		printf("%d\n",x);
		set<int>ss;
		set<int>::iterator it;
		while (ss.size()<100)
		{
			ss.insert(rand()%10000+1);

		}
		vector<pair<int,int> >v;
		it=ss.begin();
		while (it!=ss.end()){
			v.push_back(make_pair(rand(),*it));
			it++;
		}
		sort(v.begin(),v.end());
		int i;
		for (i=0;i<x;i++){
			printf("%d ",v[i].second);
		}
		printf("\n");

	}
}