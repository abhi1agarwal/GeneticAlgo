dataG populatesingle(int s,dataG &masterdata) // creates an initial population of size n 
{

	int i;
	assert(s<=masterdata.n);
	int x=masterdata.r;
	dataG populate(s,x);
	//cerr<<masterdata.r<<endl;
	set<int>xx;
	set<int>::iterator it;
	while (xx.size()<s)
	{
		xx.insert(rand()%masterdata.n);
	}
	it=xx.begin();
	populate.n=masterdata.n;
	populate.r=masterdata.r;
	
	for (i=0;i<s;i++)
	{
		populate.B[i]=masterdata.B[*it];

		it++;
	}	
	populate.n=s;
	populate.r=masterdata.r;
	return populate;
}
