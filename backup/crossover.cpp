pair<dataG,dataG>crossover(pair<int,int>ch,vector<dataG> &v,double prob)
{
	int i,j;
	pair<dataG,dataG>ret;
	int sz=v[0].n;
	int remsz=max(1,(int)(sz*prob));
	for (i=0;i<remsz;i++)
	{
		ret.fi.B.push_back(v[ch.fi].B[i]);
		ret.se.B.push_back(v[ch.se].B[i]);
	}
	for (;i<sz;i++)
	{
		ret.fi.B.push_back(v[ch.se].B[i]);
		ret.se.B.push_back(v[ch.fi].B[i]);
	}
	ret.fi.n=sz;
	ret.fi.r=v[0].r;
	ret.se.n=sz;
	ret.se.r=v[0].r;
	return ret;
}