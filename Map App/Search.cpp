#include "Search.h"

Search::Search()
{
}


Search::~Search()
{

}

Feature Search::start(vector<Feature> *features)
{
	Feature mostIsolated;
	Farm farm;
	int closestDistance = 0;

	//remove any 
	//find the distance between each feature and record the most isolated feature
	for (int i = 0; i < features->size(); i++)
	{
		//sets up tasks to calculate a line
		farm.addTask(new SearchTask(features, i, &mostIsolated, &closestDistance, &isolatedMutex));
		//cout << "Place" << feature.position << " " << feature.x << " " << feature.y << endl; 
	}
	
	farm.run();
	return mostIsolated;
}
