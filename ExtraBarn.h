#include <exception>
#include <string>
#include <iostream>
using namespace std;

#ifndef __ExtraBarn_h__
#define __ExtraBarn_h__

#include "CropFieldDecorator.h"

// class CropFieldDecorator;
class ExtraBarn;

class ExtraBarn: public CropFieldDecorator
{
	private:
		int extraCapacity;

	public: 
		ExtraBarn(CropField* field, int extraCapacity) : CropFieldDecorator(field), extraCapacity(extraCapacity) {}
		void harvest();
		int getLeftOverCapacity();
		virtual void increaseProduction();
		ExtraBarn();
		int getTotalCapacity();
};

#endif
