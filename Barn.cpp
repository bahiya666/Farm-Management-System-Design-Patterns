#include <exception>
#include <string>
#include <stdexcept>
#include <iostream>
using namespace std;

#include "Barn.h"
#include "FarmUnit.h"

/**
 * @brief Constructor for the Barn class.
 * 
 * @param capacity The total storage capacity of the barn.
 * @param type The type of the barn.
 * @param location The location of the barn.
 */
Barn::Barn(int capacity, const string& type, const string& location)
    : storageCapacity(capacity), currentAmount(0), barnType(type), barnLocation(location) {}

/**
 * @brief Get the total storage capacity of the barn.
 * 
 * @return The total storage capacity.
 */
int Barn::getTotalCapacity() {
    return storageCapacity;
}

/**
 * @brief Store crops in the barn.
 * 
 * @param amount The amount of crops to store.
 * @throw std::runtime_error if the added amount exceeds the barn's capacity.
 */
void Barn::storeCrop(int amount) {
    if (currentAmount + amount <= storageCapacity) {
        currentAmount += amount;
    } else {
        throw runtime_error("Exceeds storage capacity!");
    }
}

/**
 * @brief Remove crops from the barn.
 * 
 * @param amount The amount of crops to remove.
 * @throw std::runtime_error if there are not enough crops to remove.
 */
void Barn::removeCrop(int amount) {
    if (currentAmount - amount >= 0) {
        currentAmount -= amount;
    } else {
        throw runtime_error("Not enough crops to remove!");
    }
}

/**
 * @brief Check if the barn is full.
 * 
 * @return true if the barn is full, false otherwise.
 */
bool Barn::isFull() {
    return currentAmount == storageCapacity;
}

/**
 * @brief Get the type of crop stored in the barn.
 * 
 * @return A string indicating that the barn does not store crops.
 */
string Barn::getCropType() {
    return "Barn does not store crop type";
}

/**
 * @brief Get the name of the soil state for the barn.
 * 
 * @return A string indicating that the barn does not have a soil state.
 */
string Barn::getSoilStateName() {
    return "Barn does not have a soil state";
}

/**
 * @brief Get the remaining storage capacity of the barn.
 * 
 * @return The remaining storage capacity.
 */
int Barn::getRemainingCapacity() const {
    return storageCapacity - currentAmount;
}
