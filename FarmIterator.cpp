#include <exception>
using namespace std;

#include "FarmIterator.h"
#include "Client.h"
#include "FarmUnit.h"

/**
 * @brief Returns the first farm in the iterator.
 * 
 * This method is used to reset the iterator to the first farm and return the corresponding FarmUnit.
 * 
 * @return FarmUnit* Pointer to the first farm.
 * @throws const char* If not yet implemented.
 */
FarmUnit* FarmIterator::firstFarm() {
	throw "Not yet implemented";
}

/**
 * @brief Advances the iterator to the next farm.
 * 
 * This method is used to move the iterator to the next farm in the collection.
 * 
 * @return FarmUnit* Pointer to the next farm.
 * @throws const char* If not yet implemented.
 */
FarmUnit* FarmIterator::next() {
	throw "Not yet implemented";
}

/**
 * @brief Checks if the iterator has traversed all farms.
 * 
 * This method returns whether the iterator has completed its traversal of the collection of farms.
 * 
 * @return true If the iterator has finished traversing all farms.
 * @return false If there are more farms to traverse.
 * @throws const char* If not yet implemented.
 */
bool FarmIterator::isDone() {
	throw "Not yet implemented";
}

/**
 * @brief Returns the current farm in the iterator.
 * 
 * This method provides access to the current farm being pointed to by the iterator.
 * 
 * @return FarmUnit* Pointer to the current farm.
 * @throws const char* If not yet implemented.
 */
FarmUnit* FarmIterator::currentFarm() {
	throw "Not yet implemented";
}
