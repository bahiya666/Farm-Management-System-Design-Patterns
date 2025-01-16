#include <exception>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

#ifndef __CropField_h__
#define __CropField_h__

// #include "CropFieldDecorator.h"
// #include "SoilState.h"
#include "FarmUnit.h"
// #include "Truck.h"

#include "FarmTypes.h"

// class CropFieldDecorator;
class SoilState;
class FarmUnit;

class CropField: public FarmUnit
{
	private: 
		std::string cropType;
		int totalCapacity;
		int currentAmount;
		SoilState* soilState;
		std::vector<Truck*> trucks; 
		 

	public: 
	
		CropField(const std::string& type, int capacity, SoilState* state);
		CropField();
		virtual ~CropField();
		int getTotalCapacity();
		std::string getCropType();
		std::string getSoilStateName();
		void growCrops(int amount);

		int harvestCrops();
		void rain();
		void setSoilState(SoilState* newState);
		void buyTruck(Truck* newTruck);
		void sellTruck(Truck* truck);
		void notifyTrucks(CropField* event);
};

#endif