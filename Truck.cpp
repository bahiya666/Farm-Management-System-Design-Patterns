#include <exception>
using namespace std;

#include "Truck.h"
#include "FarmUnit.h"
#include <iostream>

/**
 * @brief Constructor for the Truck class.
 * 
 * Creates a truck with the specified ID and displays a message when the truck is created.
 * 
 * @param id The unique identifier for the truck.
 */
Truck::Truck(const std::string& id) : truckID(id) {
    std::cout << "Truck " << truckID << " created." << std::endl;
}

/**
 * @brief Update the truck based on an event in the crop field.
 * 
 * This method will be used to notify the truck about events in a crop field, such as 
 * when fertilization or crop collection is needed. Meant to be overridden by derived classes.
 * 
 * @param cropField A pointer to the crop field that triggered the event.
 * @throw std::exception if not implemented.
 */
void Truck::update(CropField* cropField) {
    throw "Not yet implemented";
}

/**
 * @brief Start the truck's engine to perform its operation.
 * 
 * This method will start the truck's operation, such as delivering fertilizer or collecting crops.
 * Meant to be overridden by derived classes.
 * 
 * @throw std::exception if not implemented.
 */
void Truck::startEngine() {
    throw "Not yet implemented";
}

/**
 * @brief Dispatch the truck to perform its designated operation.
 * 
 * This method will dispatch the truck for an operation, such as delivering fertilizer or collecting
 * crops. Meant to be overridden by derived classes.
 * 
 * @throw std::exception if not implemented.
 */
void Truck::callTruck() {
    throw "Not yet implemented";
}
