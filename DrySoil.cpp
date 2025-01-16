#include <exception>
#include <string>
#include <iostream>
using namespace std;

#include "DrySoil.h"
#include "FloodedSoil.h"
#include "FruitfulSoil.h"

/**
 * @brief Harvests crops from a crop field with dry soil conditions.
 * 
 * In dry soil, the harvest is reduced to 1/3 of the total capacity of the crop field.
 * This method calculates the harvest amount based on the soil condition and outputs the result.
 * 
 * @param cropField Pointer to the CropField object from which crops are harvested.
 * @return int The number of crops harvested from the dry soil.
 */
int DrySoil::harvestCrops(CropField* cropField) {
	int harvestAmount = cropField->getTotalCapacity() / 3;  // 1/3 of capacity in DrySoil
	std::cout << "Harvesting crops from dry soil: " << harvestAmount << " units." << std::endl;
	return harvestAmount;
}

/**
 * @brief Simulates rainfall on the dry soil, transforming it into fruitful soil.
 * 
 * When rain falls on dry soil, the soil state changes to a more productive state, specifically fruitful soil.
 * This method updates the soil state of the crop field to `FruitfulSoil`.
 * 
 * @param cropField Pointer to the CropField object on which the rain event is applied.
 */
void DrySoil::rain(CropField* cropField) {
	std::cout << "Rain fell on dry soil, soil becomes fruitful." << std::endl;
	cropField->setSoilState(new FruitfulSoil());
}

/**
 * @brief Retrieves the name of the soil state.
 * 
 * This method returns the string name representing the current soil state, which is "Dry" for this class.
 * 
 * @return string The name of the soil state.
 */
string DrySoil::getName() {
	return "Dry";
}
