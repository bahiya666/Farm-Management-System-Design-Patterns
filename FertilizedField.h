#include <exception>
using namespace std;

#ifndef __FertilizedField_h__
#define __FertilizedField_h__

#include "CropFieldDecorator.h"
#include "CropField.h"

class FertilizedField: public CropFieldDecorator
{

	public: 
		FertilizedField(CropField* field) : CropFieldDecorator(field) {}
		void increaseProduction();
		void harvest();
		virtual int getLeftOverCapacity();
};

#endif
