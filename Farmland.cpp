/**
 * @file Farmland.cpp
 * @brief Implements the behavior and management of farmland units in the farm management system.
 */

#include <exception>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

#include "Farmland.h"
#include "Client.h"
#include "FarmUnit.h"
#include "BreadthFirstFarmIterator.h"
#include "DepthFirstFarmIterator.h"

/**
 * @brief Constructor for the Farmland class.
 * 
 * Initializes the farmland with a given name.
 * 
 * @param name The name of the farmland.
 */
Farmland::Farmland(const std::string& name) : name(name) {}

/**
 * @brief Destructor for the Farmland class.
 * 
 * Cleans up by deleting all the farm units within the farmland.
 */
Farmland::~Farmland() {
    for (FarmUnit* unit : farmUnits) {
        delete unit;
    }
}

/**
 * @brief Adds a farm unit to the farmland.
 * 
 * This method adds a new farm unit to the list of farm units managed by the farmland.
 * 
 * @param unit Pointer to the farm unit to be added.
 * @return Pointer to the added farm unit.
 */
FarmUnit* Farmland::addUnit(FarmUnit* unit) {
    farmUnits.push_back(unit);
    return unit;
}

/**
 * @brief Removes a farm unit from the farmland.
 * 
 * This method removes an existing farm unit from the list of farm units managed by the farmland.
 * 
 * @param unit Pointer to the farm unit to be removed.
 * @return Pointer to the removed farm unit.
 */
FarmUnit* Farmland::removeUnit(FarmUnit* unit) {
    farmUnits.erase(std::remove(farmUnits.begin(), farmUnits.end(), unit), farmUnits.end());
    return unit;
}

/**
 * @brief Gets the total capacity of all farm units in the farmland.
 * 
 * This method iterates through all the farm units and sums their capacities to provide the total capacity.
 * 
 * @return The total capacity of all farm units in the farmland.
 */
int Farmland::getTotalCapacity() {
    int totalCapacity = 0;
    for (FarmUnit* unit : farmUnits) {
        totalCapacity += unit->getTotalCapacity();
    }
    return totalCapacity;
}

/**
 * @brief Gets the crop type for the farmland.
 * 
 * Since farmland itself does not store a specific crop type, this method returns a message indicating this.
 * 
 * @return A string indicating that the farmland does not store a crop type.
 */
string Farmland::getCropType() {
    return "Farmland does not store crop type";
}

/**
 * @brief Gets the soil state name for the farmland.
 * 
 * Since farmland itself does not have a soil state, this method returns a message indicating this.
 * 
 * @return A string indicating that the farmland does not have a soil state.
 */
string Farmland::getSoilStateName() {
    return "Farmland does not have a soil state";
}

/**
 * @brief Creates an iterator for traversing the farm units in the farmland.
 * 
 * Depending on the type specified, this method returns either a breadth-first or depth-first iterator.
 * 
 * @param type The type of iterator to create ("breadth-first" or "depth-first").
 * @return A pointer to the created iterator.
 * @throws std::invalid_argument If the type is not recognized.
 */
FarmIterator* Farmland::createIterator(string type) {
    if (type == "breadth-first") {
        return new BreadthFirstFarmIterator(this);
    } else if (type == "depth-first") {
        return new DepthFirstFarmIterator(this);
    } else {
        throw std::invalid_argument("Unknown iterator type!");
    }
}
