/**
 * @file FertilizerTruck.cpp
 * @brief Implements the behavior of a fertilizer truck in the farm management system.
 */

#include <exception>
using namespace std;

#include "FertilizerTruck.h"
#include "Truck.h"

/**
 * @brief Constructor for the FertilizerTruck class.
 * 
 * Initializes a fertilizer truck with a unique ID by calling the base class constructor.
 * 
 * @param id The unique identifier for the fertilizer truck.
 */
FertilizerTruck::FertilizerTruck(const std::string& id) : Truck(id) {}

/**
 * @brief Update method to respond to soil state changes in a crop field.
 * 
 * If the soil in the crop field is dry, the fertilizer truck is notified, and 
 * it is called to deliver fertilizer.
 * 
 * @param cropField Pointer to the crop field that the fertilizer truck monitors.
 */
void FertilizerTruck::update(CropField* cropField) {
    if (cropField->getSoilStateName() == "Dry") {
        std::cout << "FertilizerTruck " << truckID << " notified: Soil is dry in field " << cropField->getCropType() << "." << std::endl;
        callTruck();
    }
}

/**
 * @brief Starts the engine of the fertilizer truck.
 * 
 * This method simulates the process of starting the truck's engine before it can
 * deliver fertilizer.
 */
void FertilizerTruck::startEngine() {
    std::cout << "FertilizerTruck " << truckID << ": Engine started." << std::endl;
}

/**
 * @brief Calls the truck to deliver fertilizer to a crop field.
 * 
 * This method starts the truck's engine and simulates the delivery of fertilizer
 * to the crop field.
 */
void FertilizerTruck::callTruck() {
    startEngine();
    std::cout << "FertilizerTruck " << truckID << " is delivering fertilizer." << std::endl;
}
