/**
 * @file FloodedSoil.cpp
 * @brief Implements the behavior of a flooded soil state in a crop field.
 */

#include <exception>
#include <string>
#include <iostream>
using namespace std;

#include "FloodedSoil.h"
#include "DrySoil.h"

/**
 * @brief Harvests crops from the crop field with flooded soil.
 * 
 * This method simulates the harvesting process from a crop field that has
 * a flooded soil state. Since the soil is flooded, no crops can be harvested.
 * 
 * @param cropField Pointer to the crop field to attempt harvesting crops from.
 * @return The harvest amount, which is 0 in the case of flooded soil.
 */
int FloodedSoil::harvestCrops(CropField* cropField) {
	std::cout << "No crops can be harvested from flooded soil." << std::endl;
    return 0; 
}

/**
 * @brief Simulates rain falling on the crop field with flooded soil.
 * 
 * Since the soil is already flooded, additional rain has no effect on the soil state.
 * 
 * @param cropField Pointer to the crop field affected by the rain.
 */
void FloodedSoil::rain(CropField* cropField) {
	std::cout << "The soil is already flooded. Rain has no effect." << std::endl;
}

/**
 * @brief Gets the name of the soil state.
 * 
 * Returns the string name representing the flooded soil state.
 * 
 * @return A string representing the name of the soil state.
 */
string FloodedSoil::getName() {
	return "Flooded";
}
