#include "Feature.h"

Feature::Feature()
{
	x = -1;
	y = -1;
	position = -1;
	closestDistance = bigNumber;
	closestElement = -1;
	distanceMutex = new mutex();
}

Feature::Feature(int x_, int y_, int position_)
{
	x = x_;
	y = y_;
	position = position_;
	closestDistance = bigNumber;
	closestElement = -1;
	distanceMutex = new mutex();
}


Feature::~Feature()
{

}

void Feature::compareDistance(int distance, int elementNumber)
{
	distanceMutex->lock();
	if (distance < closestDistance)
	{
		//record which is closest, and how close
		closestDistance = distance;
		closestElement = elementNumber;
	}
	distanceMutex->unlock();
}
