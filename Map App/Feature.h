#pragma once
#include <vector>
#include <mutex>

using namespace std;

const int bigNumber = 100000000;
class Feature
{
public:
	Feature();
	Feature(int x_, int y_, int position_);
	~Feature();
	void compareDistance(int distance, int elementNumber);
	int getX() { return x; };
	int getY() { return y; };
	int getPosition() { return position; };
	int getClosestDistance() { return closestDistance; };
	int getClosestElement() { return closestElement; };
private: 
	mutex* distanceMutex;
	int x, y, position, closestDistance, closestElement;
};

