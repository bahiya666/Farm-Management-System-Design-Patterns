#include <exception>
#include <iostream>
using namespace std;

#include "ExtraBarn.h"
#include "CropFieldDecorator.h"
#include "CropField.h"

/**
 * @brief Harvests crops from the decorated crop field with extra barn storage.
 * 
 * This method calls the `harvestCrops` method of the decorated crop field and logs the total harvested crops, 
 * which is stored in an extra barn for additional capacity.
 */
void ExtraBarn::harvest() {
	int harvested = decoratedField->harvestCrops();
	std::cout << "Harvested " << harvested << " crops with extra storage." << std::endl;
}

/**
 * @brief Gets the remaining capacity of the crop field after harvesting, accounting for extra barn storage.
 * 
 * This method returns the leftover capacity by considering both the original crop field's capacity 
 * and the extra barn capacity, minus the harvested crops.
 * 
 * @return int The leftover capacity of the crop field including the extra barn's storage.
 */
int ExtraBarn::getLeftOverCapacity() {
	return decoratedField->getTotalCapacity() + extraCapacity - decoratedField->harvestCrops();
}

/**
 * @brief Increases the crop production (Not yet implemented).
 * 
 * This method is intended to increase the crop production of the field.
 * It can be extended to modify production parameters in future implementations.
 */
void ExtraBarn::increaseProduction() {
	// Not yet implemented
}

/**
 * @brief Gets the total capacity of the crop field with extra barn storage.
 * 
 * This method returns the total capacity of the decorated crop field, including the additional capacity 
 * provided by the extra barn.
 * 
 * @return int The total capacity of the crop field including the extra barn.
 */
int ExtraBarn::getTotalCapacity() {
	return decoratedField->getTotalCapacity() + extraCapacity;
}

// /**
//  * @brief Default constructor for ExtraBarn (Not yet implemented).
//  * 
//  * This constructor is intended to initialize the extra barn capacity.
//  */
// ExtraBarn::ExtraBarn() {
// 	_extraBarnCapacity = int;
// }
