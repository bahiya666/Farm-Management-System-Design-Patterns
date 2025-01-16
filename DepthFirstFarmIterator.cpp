#include <exception>
using namespace std;

#include "DepthFirstFarmIterator.h"
#include "Farmland.h"
#include "FarmIterator.h"

// Constructor
/**
 * @brief Constructs a DepthFirstFarmIterator for traversing a Farmland.
 * 
 * Initializes the iterator with the specified Farmland and prepares the stack for depth-first traversal.
 * 
 * @param farmland Pointer to the Farmland object to be traversed.
 */
DepthFirstFarmIterator::DepthFirstFarmIterator(Farmland* farmland) : farmland(farmland), current(nullptr) {}

/**
 * @brief Gets the first farm for traversal and initializes the stack.
 * 
 * Pushes the main Farmland onto the stack and sets the current farm unit to the top of the stack.
 * 
 * @return FarmUnit* Pointer to the first farm unit in the traversal.
 */
FarmUnit* DepthFirstFarmIterator::firstFarm() {
    if (!farmland->farmUnits.empty()) {
        farmStack.push(farmland);  // Push the main farmland itself onto the stack
        current = farmStack.top();  // Set current to the first farm unit on top of the stack
    }
    return current;
}

/**
 * @brief Moves to the next farm in the stack and updates the current farm unit.
 * 
 * Pops the top farm unit from the stack, pushes any child units (if the current farm is a Farmland),
 * and updates the current farm unit to the top of the stack.
 * 
 * @return FarmUnit* Pointer to the next farm unit in the traversal.
 */
FarmUnit* DepthFirstFarmIterator::next() {
    if (!farmStack.empty()) {
        current = farmStack.top();  // Get the current farm unit on top of the stack
        farmStack.pop();  // Remove the current farm from the stack

        // If current is a Farmland, push its farm units for traversal (in reverse order)
        Farmland* farmland = dynamic_cast<Farmland*>(current);
        if (farmland) {
            for (auto it = farmland->farmUnits.rbegin(); it != farmland->farmUnits.rend(); ++it) {
                farmStack.push(*it);  // Push units in reverse order to maintain DFS order
            }
        }

        // Set current to the next farm on the stack
        if (!farmStack.empty()) {
            current = farmStack.top();
        } else {
            current = nullptr;
        }
    }
    return current;
}

/**
 * @brief Checks if the traversal is complete.
 * 
 * Determines if all farm units have been visited by checking if the stack is empty.
 * 
 * @return bool True if traversal is complete (stack is empty), otherwise false.
 */
bool DepthFirstFarmIterator::isDone() {
    return farmStack.empty();  // Traversal is done when the stack is empty
}

/**
 * @brief Returns the current farm unit being visited.
 * 
 * Provides access to the current farm unit on top of the stack.
 * 
 * @return FarmUnit* Pointer to the current farm unit.
 */
FarmUnit* DepthFirstFarmIterator::currentFarm() {
    return current;
}
