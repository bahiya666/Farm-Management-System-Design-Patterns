#include <exception>
using namespace std;

#include "CropFieldDecorator.h"
#include "CropField.h"

/**
 * @brief Increase the production capacity of the crop field.
 * 
 * This method is meant to be overridden by concrete decorators to enhance the crop field's
 * production.
 * 
 * @throw std::exception if not implemented by the concrete decorator.
 */
void CropFieldDecorator::increaseProduction() {
    throw "Not yet implemented";
}

/**
 * @brief Harvest crops from the crop field.
 * 
 * This method is intended to be overridden by concrete decorators to enhance the harvesting
 * process of the crop field.
 * 
 * @throw std::exception if not implemented by the concrete decorator.
 */
void CropFieldDecorator::harvest() {
    throw "Not yet implemented";
}

/**
 * @brief Get the remaining storage capacity of the crop field after applying an enhancement.
 * 
 * This method is intended to be overridden by concrete decorators to provide information on 
 * leftover storage capacity after enhancements.
 * 
 * @return The remaining storage capacity.
 * @throw std::exception if not implemented by the concrete decorator.
 */
int CropFieldDecorator::getLeftOverCapacity() {
    throw "Not yet implemented";
}
