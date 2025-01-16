#include <exception>
#include <stack>
using namespace std;

#ifndef __DepthFirstFarmIterator_h__
#define __DepthFirstFarmIterator_h__

// #include "Farmland.h"
#include "FarmIterator.h"

class Farmland;
// class FarmIterator;
class DepthFirstFarmIterator;

class DepthFirstFarmIterator: public FarmIterator
{

	private:
		Farmland* farmland;  // The farmland we are iterating over
		std::stack<FarmUnit*> farmStack;  // Stack for depth-first traversal
		FarmUnit* current;  // Current farm unit being visited


	public: 
		DepthFirstFarmIterator(Farmland* farmland);

		FarmUnit* firstFarm() override;
		FarmUnit* next() override;
		bool isDone() override;
		FarmUnit* currentFarm() override;
};

#endif
