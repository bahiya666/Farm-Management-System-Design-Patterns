
/**
 * @file FarmUnit.cpp
 * @brief Implements the basic operations of a farm unit in the farm management system.
 */

#include <exception>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#include "FarmUnit.h"
#include "Farmland.h"
#include "Truck.h"

/**
 * @brief Gets the total capacity of the farm unit.
 * 
 * This method is meant to be implemented by derived classes. It will throw an exception
 * if called directly from the base class.
 * 
 * @return The total capacity of the farm unit.
 * @throws Exception indicating the method is not yet implemented.
 */
int FarmUnit::getTotalCapacity() {
	throw "Not yet implemented";
}

/**
 * @brief Gets the crop type produced by the farm unit.
 * 
 * This method is meant to be implemented by derived classes. It will throw an exception
 * if called directly from the base class.
 * 
 * @return The type of crop produced by the farm unit.
 * @throws Exception indicating the method is not yet implemented.
 */
string FarmUnit::getCropType() {
	throw "Not yet implemented";
}

/**
 * @brief Gets the name of the current soil state of the farm unit.
 * 
 * This method is meant to be implemented by derived classes. It will throw an exception
 * if called directly from the base class.
 * 
 * @return The name of the soil state.
 * @throws Exception indicating the method is not yet implemented.
 */
string FarmUnit::getSoilStateName() {
	throw "Not yet implemented";
}

/**
 * @brief Attaches a truck (observer) to the farm unit.
 * 
 * This method adds a truck to the list of observers that monitor the farm unit.
 * 
 * @param truck Pointer to the truck to be attached.
 */
void FarmUnit::attach(Truck* truck) {
    observerList.push_back(truck);
}

/**
 * @brief Detaches a truck (observer) from the farm unit.
 * 
 * This method removes a truck from the list of observers monitoring the farm unit.
 * 
 * @param truck Pointer to the truck to be detached.
 */
void FarmUnit::detach(Truck* truck) {
    observerList.erase(std::remove(observerList.begin(), observerList.end(), truck), observerList.end());
}

/**
 * @brief Notifies all attached trucks of an event in the crop field.
 * 
 * This method iterates through the list of attached trucks and calls their update
 * method to notify them of a change or event in the crop field.
 * 
 * @param field Pointer to the crop field where the event occurred.
 */
void FarmUnit::notify(CropField* field) {
    for (Truck* truck : observerList) {
        truck->update(field);  // Notify each truck about the event in the CropField
    }
}
