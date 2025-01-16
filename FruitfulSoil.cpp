/**
 * @file FruitfulSoil.cpp
 * @brief Implements the behavior of a fruitful soil state in a crop field.
 */

#include <exception>
#include <string>
#include <iostream>
using namespace std;

#include "FruitfulSoil.h"
#include "SoilState.h"
#include "CropField.h"
#include "FloodedSoil.h"
#include "DrySoil.h"

/**
 * @brief Harvests crops from the crop field with fruitful soil.
 * 
 * This method simulates the harvesting process from a crop field that has
 * a fruitful soil state, providing the full capacity of crops as the harvest.
 * 
 * @param cropField Pointer to the crop field to harvest crops from.
 * @return The total harvest amount from the crop field in units.
 */
int FruitfulSoil::harvestCrops(CropField* cropField) {
	int harvestAmount = cropField->getTotalCapacity();  // Full capacity in FruitfulSoil
    std::cout << "Harvesting crops from fruitful soil: " << harvestAmount << " units." << std::endl;
    return harvestAmount;
}

/**
 * @brief Simulates rain falling on the crop field with fruitful soil.
 * 
 * If excessive rain occurs, the soil state transitions to a flooded state.
 * 
 * @param cropField Pointer to the crop field affected by the rain.
 */
void FruitfulSoil::rain(CropField* cropField) {
	std::cout << "Excessive rain, soil becomes flooded." << std::endl;
    cropField->setSoilState(new FloodedSoil());
}

/**
 * @brief Gets the name of the soil state.
 * 
 * Returns the string name representing the fruitful soil state.
 * 
 * @return A string representing the name of the soil state.
 */
string FruitfulSoil::getName() {
	return "Fruitful";
}
