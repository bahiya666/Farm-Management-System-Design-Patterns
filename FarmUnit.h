#include <exception>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#ifndef __FarmUnit_h__
#define __FarmUnit_h__

// #include "Farmland.h"
// #include "Truck.h"
#include "FarmTypes.h"

// class Farmland;
class Truck;
class FarmUnit;

#include <string>


class FarmUnit
{
	private: 
		string farmName;
		std::vector<Truck*> observerList;

	public: 
		virtual int getTotalCapacity() = 0;
		virtual string getCropType() = 0;
		virtual string getSoilStateName() = 0;
		void attach(Truck* truck);
		void detach(Truck* truck);
		void notify(CropField* field);
		virtual ~FarmUnit(){};

	// FarmUnit();
};

#endif