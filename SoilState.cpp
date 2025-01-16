#include <exception>
#include <string>
#include <iostream>
using namespace std;

#include "SoilState.h"
#include "CropField.h"

/**
 * @brief Harvest crops based on the current soil state.
 * 
 * This method is intended to be overridden by concrete soil state classes to define
 * how much crop should be harvested based on the soil condition.
 * 
 * @param aCropField A pointer to the crop field where harvesting is taking place.
 * @return The amount of crops harvested.
 */
int SoilState::harvestCrops(CropField* aCropField) {
    std::cout << "Waiting" << std::endl;
    return 0;
}

/**
 * @brief Simulate rain on the crop field, which may affect the soil state.
 * 
 * This method is intended to be overridden by concrete soil state classes to define how
 * rain affects the current soil state.
 * 
 * @param aCropField A pointer to the crop field that is being affected by rain.
 */
void SoilState::rain(CropField* aCropField) {
    std::cout << "Waiting" << std::endl;
}

/**
 * @brief Get the name of the current soil state.
 * 
 * This method is intended to be overridden by concrete soil state classes to return the name
 * of the current soil state (e.g., "Dry", "Fruitful", etc.).
 * 
 * @return The name of the current soil state.
 */
string SoilState::getName() {
    std::cout << "Waiting" << std::endl;
    return "";
}
