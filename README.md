# Farm-Management-System-Design-Patterns
Description
This project implements a simulation of farm management using various Design Patterns including Composite, State, Decorator, Observer, and Iterator patterns. The goal is to manage and optimize crop fields, barns, soil conditions, and farm-related resources while adhering to principles of software design patterns.

Key Features
Composite Pattern: Allows managing crops and barns as a unified whole, supporting individual and collective operations on farm units (e.g., fields and barns).
State Pattern: Simulates the dynamic state changes of soil (Dry, Fruitful, Flooded) that affect crop growth and harvesting.
Decorator Pattern: Enhances crop fields with additional functionalities like increased production (via fertilization) or extra storage capacity (via extra barns).
Observer Pattern: Facilitates the monitoring of farm operations (e.g., crop growth, fertilization, and delivery of crops) by trucks.
Iterator Pattern: Implements both Breadth-First and Depth-First traversal techniques to visit all units in a farm (fields, barns, and sub-farms) for processing or viewing.

Design Patterns Explained
Composite Pattern:
Used to treat individual units (crop fields, barns) and composite units (farmlands) uniformly.
The Farmland class acts as a composite, containing both CropField and Barn units.

State Pattern:
Implements different soil states (DrySoil, FruitfulSoil, FloodedSoil) that influence crop growth and harvesting.
Each soil state defines behavior for watering crops and harvesting based on its condition.

Decorator Pattern:
Allows dynamic additions to CropField objects, such as fertilization or adding extra barns.
Improves functionality without modifying existing objects directly, following the decorator pattern principles.

Observer Pattern:
Tracks and notifies farm managers (via trucks) about changes in crop status or the need for fertilizers.
FertilizerTruck and DeliveryTruck act as observers to monitor the crop fields.

Iterator Pattern:
Implements both breadth-first and depth-first traversal mechanisms to visit farm units in different orders (useful for inspections or processing all units).
BreadthFirstFarmIterator and DepthFirstFarmIterator allow traversal of hierarchical farm structures.

Files in the Project
Farmland.h - Represents the farmland, which can contain various farm units (crop fields, barns).
CropField.h - Represents a crop field, with information about crops and soil states.
Barn.h - Represents a barn where crops can be stored.
SoilState.h - Defines the base class for soil states (e.g., dry, fruitful, flooded).
DrySoil.h, FruitfulSoil.h, FloodedSoil.h - Concrete implementations of soil states.
CropFieldDecorator.h - Implements decorators for adding extra functionalities to crop fields.
ExtraBarn.h, FertilizedField.h - Decorators to add additional features to crop fields.
Truck.h, FertilizerTruck.h, DeliveryTruck.h - Represents trucks that monitor and deliver crop-related resources.
FarmIterator.h, BreadthFirstFarmIterator.h, DepthFirstFarmIterator.h - Iterator classes for traversing farm structures.
Main.cpp - Contains the main() function and tests for the various design patterns.

Main Functions
testComposite(): Tests the Composite Pattern by adding CropField and Barn objects into a Farmland and calculating the total capacity.

testState(): Tests the State Pattern by simulating the state changes of soil (from Dry to Fruitful to Flooded) and how they affect crop harvesting.

testDecorator(): Tests the Decorator Pattern by applying fertilizers and adding extra barns to crop fields and adjusting capacities.

testObserver(): Tests the Observer Pattern by creating trucks that monitor and act on changes in crop growth and fertilization.

testIterator(): Tests the Iterator Pattern by traversing through the farm's crop fields and sub-farms using breadth-first and depth-first iterators.

Compile the Code:
g++ -o farm_management main.cpp
Run the Executable:
./farm_management
