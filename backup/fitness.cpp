double fitness(dataG &dat)
{
	int i,j,sz=dat.n;
	double ret=0;
	bitset<N>x;	
	x.reset();
	assert(dat.n>0);
	assert(dat.r>0);
	for (i=0;i<sz;i++){
		x=x|dat.B[i];
	}
	ret=100.0*x.count()/dat.r;
	return dat.fitness=ret;
}
void fitness(vector<dataG> &dat)
{
	int i,j;

	for (i=0;i<dat.size();i++)
	{
		fitness(dat[i]);
	}
}
