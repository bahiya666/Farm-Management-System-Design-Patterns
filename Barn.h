#include <exception>
#include <string>
using namespace std;

#ifndef __Barn_h__
#define __Barn_h__

#include "FarmUnit.h"

// class FarmUnit;

class Barn: public FarmUnit
{
	private: 
		int storageCapacity;
		
		string barnType;
		string barnLocation;

	public: 
		int getRemainingCapacity() const;
		int currentAmount;
		Barn(int capacity, const string& type, const string& location);
		int getTotalCapacity();
		void storeCrop(int amount);
		void removeCrop(int amount);
		bool isFull();
		string getCropType();
		string getSoilStateName();
};

#endif
