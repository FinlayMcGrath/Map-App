#include <string>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <assert.h>

#include "Feature.h"
#include "Search.h"

using namespace std;

#define locationsize 10000000

void main()
{
	vector<Feature> features;

	string filename;
	ifstream infile;
	std::cout << "Enter name of the dataset file. small/big" << endl;
	std::cin >> filename;
	std::cout << endl;
	while (filename != "small" && filename != "big")
	{
		std::cout << "Enter name of the dataset file. small/big" << endl;
		std::cin >> filename;
		std::cout << endl;
	}

	if (filename == "small")
	{
		infile = ifstream("../data/problem_small.txt");
	}
	if (filename == "big")
	{
		infile = ifstream("../data/problem_big.txt");
	}
	//read file into 2d vector which includes blank spaces
	//also record the features in a vector that stores feature location
	//for each feature in the vector
	//find the nearest feature in the array starting from the feature's position and moving outwards
	
	//load data into vector from text file

	string line;
	while (getline(infile, line))
	{
		//istringstream iss(line);
		int x, y, position;
		position = -1;
		x = -1;
		y = -1;
		string number;
		//ignore first 5 letters
		for (int i = 5; i < line.length(); i++)
		{
			//if the next letter isn't a space
			if (line.compare(i, 1, " ") != 0)
			{
				//add to the string
				number.push_back(line.at(i));
			}		
			//the first numbers before a space will always be the position
			else if (position == -1)
			{
				istringstream buffer(number);
				buffer >> position;
				number.clear();
			}
			else
			{
				//get x value
				istringstream buffer(number);
				buffer >> x;
				number.clear();
			}
		}
		//leftover numbers will be y value
		istringstream buffer(number);
		buffer >> y;	
		features.push_back(Feature(x, y, position));
	}	

	//check whether it should be multithreaded with text entry
	Feature mostIsolated;
	char query;
	std::cout << "Multithread? Y/N" << endl;
	std::cin >> query;
	std::cout << endl;

	while (toupper(query) != 'Y' && toupper(query) != 'N')
	{
		std::cout << "Multithread? Y/N" << endl;
		std::cin >> query;
		std::cout << endl;
	}
	
	if (toupper(query) == 'Y')
	{
		Search search;
		mostIsolated = search.start(&features);
	}
	else
	{
		//single threaded solution for the problem
		int closest = 0;

		//find the distance between each feature and record the most isolated feature
		for (int i = 0; i < features.size(); i++)
		{
			//find closest feature to current feature 
			//skip features that have already been checked
			for (int j = i + 1; j < features.size(); j++)
			{
				//calculate distance between two points			
				int distance = sqrt(pow(features[j].getX() - features[i].getX(), 2) + pow(features[j].getY() - features[i].getY(), 2)); distance;
				features[i].compareDistance(distance, j);
				features[j].compareDistance(distance, i);
			}

			//check if this feature is more isolated than the previously most isolated feature
			if (features[i].getClosestDistance() > closest && features[i].getClosestDistance() != bigNumber)
			{
				mostIsolated = features[i];
				closest = features[i].getClosestDistance();
			}
		}
	}
	

	std::cout << "Place " << mostIsolated.getPosition() << " " << mostIsolated.getX() << " " << mostIsolated.getY() << endl;
	while (true)
	{
		//cout << "Place" << mostIsolated.position << " " << mostIsolated.x << " " << mostIsolated.y << endl;
	}
}