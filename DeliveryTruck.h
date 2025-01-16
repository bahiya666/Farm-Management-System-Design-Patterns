#include <exception>
using namespace std;

#ifndef __DeliveryTruck_h__
#define __DeliveryTruck_h__

#include "Truck.h"

// class Truck;
class DeliveryTruck;

class DeliveryTruck: public Truck
{

	public:
		DeliveryTruck(const std::string& id); 
		void update(CropField* cropField);
		void startEngine();
		void callTruck();
};

#endif