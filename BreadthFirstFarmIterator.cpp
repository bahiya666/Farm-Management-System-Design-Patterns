#include <exception>
using namespace std;

#include "BreadthFirstFarmIterator.h"
#include "Farmland.h"
#include "FarmIterator.h"

/**
 * @brief Constructor for the BreadthFirstFarmIterator class.
 * 
 * @param farmland A pointer to the Farmland that will be traversed.
 */
BreadthFirstFarmIterator::BreadthFirstFarmIterator(Farmland* farmland) : farmland(farmland), current(nullptr) {}

/**
 * @brief Initialize the traversal and return the first farm unit.
 * 
 * This method sets up the queue for breadth-first traversal by enqueuing all farm units 
 * in the farmland. It returns the first farm unit in the traversal.
 * 
 * @return A pointer to the first FarmUnit in the traversal.
 */
FarmUnit* BreadthFirstFarmIterator::firstFarm() {
    if (!farmland->farmUnits.empty()) {
        for (FarmUnit* unit : farmland->farmUnits) {
            farmQueue.push(unit);  // Add all farms to the queue
        }
        current = farmQueue.front();  // Set current to the first farm
    }
    return current;
}

/**
 * @brief Move to the next farm unit in the queue.
 * 
 * This method moves the traversal to the next farm unit in the queue. If the current 
 * farm unit is a Farmland, its farm units are enqueued for traversal.
 * 
 * @return A pointer to the next FarmUnit in the traversal.
 */
FarmUnit* BreadthFirstFarmIterator::next() {
    if (!farmQueue.empty()) {
        farmQueue.pop();  // Remove the current farm from the queue
        if (!farmQueue.empty()) {
            current = farmQueue.front();  // Set current to the next farm in the queue
        } else {
            current = nullptr;  // No more farms in the queue
        }

        // If current is a Farmland, enqueue its farm units for traversal
        Farmland* farmland = dynamic_cast<Farmland*>(current);
        if (farmland) {
            for (FarmUnit* unit : farmland->farmUnits) {
                farmQueue.push(unit);
            }
        }
    }
    return current;
}

/**
 * @brief Check if the traversal is complete.
 * 
 * @return true if the queue is empty and traversal is complete, false otherwise.
 */
bool BreadthFirstFarmIterator::isDone() {
    return farmQueue.empty();  // Traversal is done when the queue is empty
}

/**
 * @brief Get the current farm unit being visited.
 * 
 * @return A pointer to the current FarmUnit being visited.
 */
FarmUnit* BreadthFirstFarmIterator::currentFarm() {
    return current;
}
