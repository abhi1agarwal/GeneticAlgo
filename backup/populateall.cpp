vector<dataG> generatepopulation(int x,int s,dataG &masterdata) // x is the total number of chromosomes.
// s is the size of each chromosome.
{
	vector<dataG>genpopulation;
	genpopulation.clear();
	int i;
	for (i=0;i<x;i++)
	{
		genpopulation.push_back(populatesingle(s,masterdata));
	}	
	return genpopulation;
}