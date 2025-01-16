#include <exception>
#include <iostream>
using namespace std;

#include "DeliveryTruck.h"
#include "Truck.h"

// Constructor
/**
 * @brief Constructs a DeliveryTruck with the specified ID.
 * 
 * Initializes the DeliveryTruck by passing the ID to the base Truck class constructor.
 * 
 * @param id The unique identifier for the DeliveryTruck.
 */
DeliveryTruck::DeliveryTruck(const std::string& id) : Truck(id) {}

/**
 * @brief Responds to events in the CropField and checks for storage capacity nearing its limit.
 * 
 * This method monitors the capacity of the specified CropField and, if the capacity is nearing the limit
 * (80% or more), it notifies and initiates the truck's collection process.
 * 
 * @param cropField Pointer to the CropField object being monitored.
 */
void DeliveryTruck::update(CropField* cropField) {
    if (cropField->getTotalCapacity() * 0.8 <= cropField->getTotalCapacity()) {
        std::cout << "DeliveryTruck " << truckID << " notified: Storage capacity nearing limit in field " << cropField->getCropType() << "." << std::endl;
        callTruck();
    }
}

/**
 * @brief Starts the truck's engine.
 * 
 * Outputs a message indicating that the DeliveryTruck's engine has been started.
 */
void DeliveryTruck::startEngine() {
    std::cout << "DeliveryTruck " << truckID << ": Engine started." << std::endl;
}

/**
 * @brief Calls the truck to collect harvested crops.
 * 
 * Initiates the truck's collection process by starting the engine and outputting a message about the collection
 * of harvested crops.
 */
void DeliveryTruck::callTruck() {
    startEngine();
    std::cout << "DeliveryTruck " << truckID << " is collecting harvested crops." << std::endl;
}

