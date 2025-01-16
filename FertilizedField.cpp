/**
 * @file FertilizedField.cpp
 * @brief Implements the behavior of a fertilized crop field in the farm management system.
 */

#include <exception>
#include <iostream>
using namespace std;

#include "FertilizedField.h"
#include "CropFieldDecorator.h"
#include "CropField.h"
#include "FruitfulSoil.h"
#include "SoilState.h"

/**
 * @brief Increases the production of the crop field by applying fertilizer.
 * 
 * If the soil state is "Dry", this method transitions the soil to a more productive
 * state, specifically the "FruitfulSoil" state.
 */
void FertilizedField::increaseProduction() {
	 if (decoratedField->getSoilStateName() == "Dry") {
            std::cout << "Applying fertilizer, transitioning DrySoil to FruitfulSoil." << std::endl;
            decoratedField->setSoilState(new FruitfulSoil());
        }
}

/**
 * @brief Harvests crops from the fertilized crop field.
 * 
 * This method calls the decorated crop field's harvest method and prints the number
 * of crops harvested from the fertilized field.
 */
void FertilizedField::harvest() {
	int harvested = decoratedField->harvestCrops();
        std::cout << "Harvested " << harvested << " crops from fertilized field." << std::endl;
}

/**
 * @brief Gets the leftover capacity of the crop field after harvesting.
 * 
 * Calculates the remaining capacity of the crop field by subtracting the number of
 * harvested crops from the total capacity of the field.
 * 
 * @return The leftover capacity of the crop field.
 */
int FertilizedField::getLeftOverCapacity() {
	return decoratedField->getTotalCapacity() - decoratedField->harvestCrops();
}
