#include <exception>
#include <queue>
using namespace std;

#ifndef __BreadthFirstFarmIterator_h__
#define __BreadthFirstFarmIterator_h__

// #include "Farmland.h"
#include "FarmIterator.h"
#include "Farmland.h"
#include "FarmUnit.h"

class Farmland;
// class FarmIterator;
class BreadthFirstFarmIterator;

class BreadthFirstFarmIterator: public FarmIterator
{

	private:
    Farmland* farmland;  // The farmland we are iterating over
    std::queue<FarmUnit*> farmQueue;  // Queue for breadth-first traversal
    FarmUnit* current;  // Current farm unit being visited

	public: 
		BreadthFirstFarmIterator(Farmland* farmland);

    FarmUnit* firstFarm() override;
    FarmUnit* next() override;
    bool isDone() override;
    FarmUnit* currentFarm() override;
};

#endif
