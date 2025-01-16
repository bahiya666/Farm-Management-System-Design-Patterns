#include <exception>
using namespace std;

#ifndef __Truck_h__
#define __Truck_h__

// #include "FarmUnit.h"
#include <string>
#include "CropField.h"

class CropField;

class FarmUnit;
class Truck;

class Truck
{
	protected: 
		string truckID;
	// public: FarmUnit* _unnamed_FarmUnit_;

	public: 
		virtual void update(CropField* cropField) = 0;
		virtual void startEngine() = 0;
		virtual void callTruck() = 0;
		Truck(const std::string& id);
		virtual ~Truck(){};
};

#endif