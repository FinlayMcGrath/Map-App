#include "SearchTask.h"

SearchTask::SearchTask(vector<Feature> *mapFeatures, int featureCurrent, Feature *mostIsolated, int *closestDistance,  mutex *targetMutex)
{
	features = mapFeatures;
	currentFeature = featureCurrent;
	feature = &(features->at(currentFeature));
	isolated = mostIsolated;
	closest = closestDistance;
	isolatedMutex = targetMutex;
}


SearchTask::~SearchTask()
{
}

void SearchTask::run()
{
	//find closest feature to current feature 
	//skip features that have already been checked
	for (int j = currentFeature + 1; j < features->size(); j++)
	{
		//calculate distance between two points
		int distance = sqrt(pow(features->at(j).getX() - features->at(currentFeature).getX(), 2) + pow(features->at(j).getY() - features->at(currentFeature).getY(), 2));
		//compare the two features with their current furthest away feature
		features->at(currentFeature).compareDistance(distance, j);
		features->at(j).compareDistance(distance, currentFeature);
	}

	isolatedMutex->lock();
	//check if this feature is more isolated than the previously most isolated feature
	if (features->at(currentFeature).getClosestDistance() > *closest && features->at(currentFeature).getClosestDistance() != bigNumber)
	{
		//gets pointer to an element in the vector and sets isolated to that element
		*isolated = features->data()[currentFeature];
		*closest = features->data()[currentFeature].getClosestDistance();
	}
	isolatedMutex->unlock();

}
