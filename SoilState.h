#include <exception>
#include <string>
using namespace std;

#ifndef __SoilState_h__
#define __SoilState_h__

// #include "CropField.h"

class CropField;
class SoilState;

class SoilState
{
	// public: CropField* _unnamed_CropField_;

	public: 
		virtual ~SoilState() {};
		virtual int harvestCrops(CropField* cropField) = 0;
		virtual void rain(CropField* cropField) = 0;
		virtual string getName() = 0;
};

#endif
