void mutateit(dataG&ed, dataG&dat)
{
	{
		int xx=rand()%100000+1;
		if (1.0*xx/100000>prom)
			return ;
	}
	int i,j;
	vector<int>occ;
	for (i=0;i<dat.B.size();i++)
	{
		int f=0;
		for(j=0;j<ed.B.size();j++)
		{
			if (dat.B[i]==ed.B[j])
			{
				f=1;
				break;
			}
		}
		if (!f)
		{
			occ.pb(i);
		}
	}
	for (i=0;i<ed.B.size();i++)
	{
		{
			int xx=rand()%100000+1;
			if (1.0*xx/100000>prom)
				continue ;
		}
		if (occ.size()>0)
		{
			ed.B.erase(ed.B.begin()+i);
			ed.B.pb(dat.B[occ[rand()%occ.size()]]);
		}
		break;
	}	
}