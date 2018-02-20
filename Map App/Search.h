#pragma once

#include "Farm.h"
#include "SearchTask.h"

class Search
{
public:
	Search();
	~Search();
	Feature start(vector<Feature> *features);
private:
	mutex isolatedMutex;
};

