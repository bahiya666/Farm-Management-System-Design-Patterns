#include <exception>
#include <string>
using namespace std;

#ifndef __FruitfulSoil_h__
#define __FruitfulSoil_h__

#include "SoilState.h"

// class SoilState;
class FruitfulSoil;

class FruitfulSoil: public SoilState
{

	public: 
		int harvestCrops(CropField* cropField);
		void rain(CropField* cropField);
		string getName();
};

#endif
