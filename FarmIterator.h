#include <exception>
using namespace std;

#ifndef __FarmIterator_h__
#define __FarmIterator_h__

// #include "Client.h"
#include "FarmUnit.h"

class Client;
class FarmIterator;

class FarmIterator
{
	public: 
		// Client* _unnamed_Client_;
		virtual FarmUnit* firstFarm() = 0;
		virtual FarmUnit* next() = 0;
		virtual bool isDone() = 0;
		virtual FarmUnit* currentFarm() = 0;
};

#endif
