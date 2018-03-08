class GA
{
public:
	int ini,n,r;
	double proc,prom;
	dataG geneticalgo(int sz,dataG &dat)
	{

		vector<dataG>v=generatepopulation(ini,sz,dat);
		//cerr<<"came out of ddebug!\n";
		int i,j;
		fitness(v);
		for(i=0;i<v.size();i++)
		{
			if (eq(v[i].fitness,100))
			{
				break;
			}
		}
		if(i<v.size()){
			return v[i];
		}
		dataG ret;
		int isright=0,iter=0;
		while (v.size()<max(mxiter,n))
		{
			//cerr<<"iteration:: "<<++iter<<endl;
			//cerr<<"->\n";

			pair<int,int>psel=selectparent(v);
			//cerr<<"parent selected\n";
			pair<dataG,dataG>gotback=crossover(psel,v,proc);
			//cerr<<"gotback\n";
			fitness(gotback.fi);
			fitness(gotback.se);
			//cerr<<"calculated fitness...\n";
			if(eq(gotback.fi.fitness,100))
			{
				ret=gotback.fi;
				isright=1;
				break;
			}
			if(eq(gotback.se.fitness,100))
			{
				ret=gotback.se;
				isright=1;
				break;
			}
			//cerr<<"yao\n";
			v.pb(gotback.fi);
			v.pb(gotback.se);
			//cerr<<"pubback!\n"<<v.size()<<endl;;
			//cerr<<"halllalsdsadsa\n";
		}
		//cerr<<"came out...\n";
		if (isright)
			return ret;
		else
		{
			ret.n=-1;
			return ret;
		}
	}	
};