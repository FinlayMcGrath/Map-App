#pragma once

#include <vector>
#include <iostream>
#include <mutex>
#include <assert.h>
#include "Feature.h"
#include "Task.h"

using namespace std;

class SearchTask : public Task
{
public:
	SearchTask(vector<Feature> *mapFeatures, int featureCurrent, Feature *mostIsolated, int *closestDistance, mutex *targetMutex);
	~SearchTask();

	void run();
private:
	vector<Feature> *features;
	Feature *isolated, *feature;
	int currentFeature;
	int *closest,  distance;
	mutex *isolatedMutex;
};

