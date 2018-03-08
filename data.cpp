
class dataG
{
public:
	vector<bitset<N> >B;
	int n,r;
	double fitness;
	//vector<double>fitness;
	dataG(int xn,int xr)
	{
		fitness=0;
		n=xn;
		r=xr;
		B.clear();
		B.resize(xn);
		int i;
		for (i=0;i<xn;i++)
			B[i].reset();
	}
	dataG(){
		fitness=0;
		B.clear();
	}

};