#include <exception>
using namespace std;

#ifndef __CropFieldDecorator_h__
#define __CropFieldDecorator_h__

#include "CropField.h"

// class CropField;

class CropFieldDecorator: public CropField
{
	protected: 
		CropField* decoratedField;

	public: 
		CropFieldDecorator(CropField* field) : decoratedField(field) {}	;

		virtual void increaseProduction() = 0;
		virtual void harvest() = 0;
		virtual int getLeftOverCapacity() = 0;
};

#endif
