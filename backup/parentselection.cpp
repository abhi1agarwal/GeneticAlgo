pair<int,int> selectparent(vector<dataG> &v)
{
	int i,j,f=0;
	int giv[2];
	giv[0]=giv[1]=-1;
	int r=v[0].r,sm=0;
	int *hs=new int[v.size()];
	for (i=0;i<v.size();i++)
	{

		hs[i]=(int)v[i].fitness*r/100;
		sm+=hs[i];
		if(i>0)
		{
			hs[i]+=hs[i-1];
		}
	}
	assert(sm>0);
	for (;f<2;f++)
	{
		//vector<int>ind;
		int x=rand()%(sm);
		for (i=0;i<v.size();i++)
		{
			if (i!=giv[f^1])
			{
				if (x<hs[i])
					break;
			}
		}
		//i--;
		giv[f]=i;
	}
	assert(giv[0]>=0&&giv[0]<v.size());
	assert(giv[1]>=0&&giv[1]<v.size());
	delete(hs);
	return make_pair(giv[0],giv[1]);
}