#include <exception>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#include "CropField.h"
#include "CropFieldDecorator.h"
#include "SoilState.h"
#include "FarmUnit.h"
#include "Truck.h"

/**
 * @brief Default constructor for CropField class.
 * 
 * Initializes the crop type as "Unknown" and sets capacity and current amount to 0.
 */
CropField::CropField() : cropType("Unknown"), totalCapacity(0), currentAmount(0), soilState(nullptr) {
    std::cout << "" << std::endl;
}

/**
 * @brief Parameterized constructor for CropField class.
 * 
 * @param type The type of crop in the field.
 * @param capacity The total capacity of the field.
 * @param state The initial soil state of the field.
 */
CropField::CropField(const std::string& type, int capacity, SoilState* state)
    : cropType(type), totalCapacity(capacity), currentAmount(0), soilState(state) {}

/**
 * @brief Destructor for CropField class.
 * 
 * Frees the memory allocated for the soil state.
 */
CropField::~CropField() {
    delete soilState;
}

/**
 * @brief Get the total capacity of the crop field.
 * 
 * @return The total capacity of the crop field.
 */
int CropField::getTotalCapacity() {
    return this->totalCapacity;
}

/**
 * @brief Get the type of crop in the crop field.
 * 
 * @return The type of crop.
 */
string CropField::getCropType() {
    return this->cropType;
}

/**
 * @brief Get the name of the current soil state.
 * 
 * @return The name of the current soil state.
 */
string CropField::getSoilStateName() {
    return soilState->getName();
}

/**
 * @brief Add crops to the field.
 * 
 * @param amount The amount of crops to add.
 */
void CropField::growCrops(int amount) {
    currentAmount += amount;
    if (currentAmount > totalCapacity) {
        currentAmount = totalCapacity;  
    }
}

/**
 * @brief Harvest crops from the field based on the current soil state.
 * 
 * If no crops are available, it returns 0.
 * 
 * @return The amount of crops harvested.
 */
int CropField::harvestCrops() {
    if (currentAmount == 0) {
        std::cout << "No crops available for harvesting!" << std::endl;
        return 0;
    }

    int harvestedAmount = soilState->harvestCrops(this);
    currentAmount -= harvestedAmount;
    return harvestedAmount;
}

/**
 * @brief Simulate rain on the crop field, which may alter the soil state.
 */
void CropField::rain() {
    soilState->rain(this);
}

/**
 * @brief Set a new soil state for the crop field.
 * 
 * Frees the old soil state and assigns a new one.
 * 
 * @param newState The new soil state to be applied to the crop field.
 */
void CropField::setSoilState(SoilState* newState) {
    if (soilState != newState) {
        delete this->soilState;
        this->soilState = newState;
    }
}

/**
 * @brief Purchase and register a truck for the crop field.
 * 
 * @param newTruck The truck to be registered for the field.
 */
void CropField::buyTruck(Truck* newTruck) {
    trucks.push_back(newTruck);
    std::cout << "Truck bought and registered." << std::endl;
}

/**
 * @brief Sell and unregister a truck from the crop field.
 * 
 * @param truck The truck to be removed from the field.
 */
void CropField::sellTruck(Truck* truck) {
    trucks.erase(std::remove(trucks.begin(), trucks.end(), truck), trucks.end());
    std::cout << "Truck sold and unregistered." << std::endl;
}

/**
 * @brief Notify all trucks about an event in the crop field.
 * 
 * @param event The event that occurred in the crop field.
 */
void CropField::notifyTrucks(CropField* event) {
    for (Truck* truck : trucks) {
        truck->update(event);  // Notify each truck about the event
    }
}
