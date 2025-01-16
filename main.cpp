#include <iostream>
#include "Farmland.h"
#include "CropField.h"
#include "Barn.h"
#include "SoilState.h"
#include "DrySoil.h"
#include "FruitfulSoil.h"
#include "FloodedSoil.h"
#include "CropFieldDecorator.h"
#include "ExtraBarn.h"
#include "FertilizedField.h"
#include "FertilizerTruck.h"
#include "DeliveryTruck.h"
#include "Truck.h"
#include "BreadthFirstFarmIterator.h"
#include "DepthFirstFarmIterator.h"
#include "FarmIterator.h"

using namespace std;

// Mock SoilState class for testing purposes
class MockSoilState : public SoilState {
public:
    string getName()  override{
        return "Fruitful";
    }

    int harvestCrops(CropField* cropField) override {
        return 0;}

    void rain(CropField* cropField) override {
        cout << "Rain improved the soil!" << endl;
    }

    // void rainEffect() override {
    //     cout << "Rain improved the soil!" << endl;
    // }
};

void testComposite(){
    // Create soil state objects
    SoilState* fruitfulSoil = new MockSoilState();

    // Create CropField objects (Leaf nodes in Composite pattern)
    CropField* wheatField = new CropField("Wheat", 100, fruitfulSoil);
    CropField* cornField = new CropField("Corn", 150, fruitfulSoil);

    // Create Barn objects (Leaf nodes in Composite pattern)
    Barn* smallBarn = new Barn(200, "Small Barn", "East Wing");
    Barn* largeBarn = new Barn(500, "Large Barn", "West Wing");

    // Create Farmland object (Composite node in Composite pattern)
    Farmland* farmland1 = new Farmland("Main Farmland");

    // Add CropFields and Barns to the farmland
    farmland1->addUnit(wheatField);
    farmland1->addUnit(cornField);
    farmland1->addUnit(smallBarn);
    farmland1->addUnit(largeBarn);

    // Testing Farmland's total capacity calculation
    cout << "Total capacity of the farmland: " << farmland1->getTotalCapacity() << " units" << endl;

    // Testing getCropType() for a farmland (should output "Farmland doesn't directly have a crop type!")
    // try {
    //     cout << "Crop type in farmland: " << farmland1->getCropType() << endl;
    // } catch (const std::exception& e) {
    //     cout << e.what() << endl;
    // }

    // // Testing getSoilStateName() for a farmland (should output "Farmland doesn't have a soil state!")
    // try {
    //     cout << "Soil state of farmland: " << farmland1->getSoilStateName() << endl;
    // } catch (const std::exception& e) {
    //     cout << e.what() << endl;
    // }

    // Testing the individual CropFields for crop type and soil state
    cout << "Crop type in wheat field: " << wheatField->getCropType() << endl;
    cout << "Soil state in wheat field: " << wheatField->getSoilStateName() << endl;

    cout << "Crop type in corn field: " << cornField->getCropType() << endl;
    cout << "Soil state in corn field: " << cornField->getSoilStateName() << endl;

    // Testing the Barn's capacity
    cout << "Small barn capacity: " << smallBarn->getTotalCapacity() << endl;
    cout << "Large barn capacity: " << largeBarn->getTotalCapacity() << endl;

    // Testing adding and removing crops in a Barn
    smallBarn->storeCrop(50);
    cout << "Stored 50 units in small barn. Remaining capacity: " << smallBarn->getRemainingCapacity()  << endl;

    smallBarn->removeCrop(20);
    cout << "Removed 20 units from small barn. Remaining stored: " << smallBarn->getRemainingCapacity() << endl;

    // Clean up
    // delete farmland1;
    // delete fruitfulSoil;
}

void testState(){
    // Initial state: DrySoil
    SoilState* initialSoil = new DrySoil();
    
    // Create CropField with 1000 capacity
    CropField* wheatField = new CropField("Wheat", 1000, initialSoil);
    
    // Display initial soil state
    cout << "Initial soil state: " << wheatField->getSoilStateName() << endl;

    cout<< "Crop capacity: " << wheatField->getTotalCapacity() << endl;

    // Simulate crop growth to fill the field
    wheatField->growCrops(1000);  // Grow 1000 units of crops
    
    // Harvest in DrySoil (should yield 1/3 of the capacity)
    int harvestedCrops = wheatField->harvestCrops();
    cout << "Harvested crops in dry soil: " << harvestedCrops << endl;
    
    // Simulate rain on DrySoil (should change to FruitfulSoil)
    wheatField->rain();
    cout << "Soil state after rain: " << wheatField->getSoilStateName() << endl;

    // Harvest in FruitfulSoil (should yield the full capacity)
    harvestedCrops = wheatField->harvestCrops();
    cout << "Harvested crops in fruitful soil: " << harvestedCrops << endl;
    
    // Simulate excessive rain on FruitfulSoil (should change to FloodedSoil)
    wheatField->rain();
    cout << "Soil state after excessive rain: " << wheatField->getSoilStateName() << endl;
    
    // Attempt to harvest in FloodedSoil (no crops should be harvested)
    harvestedCrops = wheatField->harvestCrops();
    cout << "Harvested crops in flooded soil: " << harvestedCrops << endl;

    // Simulate rain on FloodedSoil (rain should have no effect)
    wheatField->rain();
    cout << "Soil state after rain on flooded soil: " << wheatField->getSoilStateName() << endl;

    // Clean up
    delete wheatField; 
}


void testDecorator(){
    // Initial state: DrySoil
    SoilState* drySoil = new DrySoil();

    // Create a CropField with 1000 capacity and DrySoil state
    CropField* wheatField = new CropField("Wheat", 1000, drySoil);
    cout << "Initial crop field capacity: " << wheatField->getTotalCapacity() << endl;
    cout << "Initial soil state: " << wheatField->getSoilStateName() << endl;

    // Simulate crop growth to fill the field
    wheatField->growCrops(1000);
    cout << "Crops grown in field: 333 units" << endl;

    // Apply fertilizer to the field (use decorator)
    FertilizedField* fertilizedField = new FertilizedField(wheatField);
    fertilizedField->increaseProduction();
    cout << "Soil state after applying fertilizer: " << wheatField->getSoilStateName() << endl;

    // Harvest crops from the fertilized field
    fertilizedField->harvest();

    // Add an extra barn to the field (use decorator)
    ExtraBarn* fieldWithExtraBarn = new ExtraBarn(wheatField, 500);
    cout << "Total capacity after adding extra barn: " << fieldWithExtraBarn->getTotalCapacity() << endl;

    // wheatField->growCrops(1200);
    // cout << "Crops grown in field: 1200 units" << endl;

    // wheatField->harvestCrops();

    // Test leftover capacity after harvest
    int leftoverCapacity = fieldWithExtraBarn->getLeftOverCapacity();
    cout << "Leftover capacity after harvest: " << leftoverCapacity << endl;

    // Clean up
    delete fieldWithExtraBarn;
    delete fertilizedField;
    delete wheatField;
}


void testObserver(){
    // Initial soil state: DrySoil
    SoilState* drySoil = new DrySoil();
    
    // Create a CropField with 1000 capacity and DrySoil state
    CropField* wheatField = new CropField("Wheat", 1000, drySoil);
    cout << "Initial crop field created with capacity: " << wheatField->getTotalCapacity() << " and soil state: " << wheatField->getSoilStateName() << endl;

    // Create trucks
    FertilizerTruck* fertilizerTruck = new FertilizerTruck("F-001");
    DeliveryTruck* deliveryTruck = new DeliveryTruck("D-001");

    // Test buyTruck for both trucks
    cout << "\nBuying trucks...\n";
    wheatField->buyTruck(fertilizerTruck);
    wheatField->buyTruck(deliveryTruck);

    // Grow crops and test DeliveryTruck when capacity is nearing the limit
    cout << "\nGrowing crops in the field...\n";
    wheatField->growCrops(800);  // 80% of capacity, should trigger DeliveryTruck notification
    cout << "Crops grown. Current amount of crops: 800\n";
    
    // Simulate rain and test fertilization needed
    cout << "\nSimulating rainfall...\n";
    wheatField->rain();  // In DrySoil, this should trigger the FertilizerTruck

    // Test sellTruck for fertilizer truck
    cout << "\nSelling the fertilizer truck...\n";
    wheatField->sellTruck(fertilizerTruck);

    // Simulate another rain, but no FertilizerTruck should be available this time
    cout << "\nSimulating rainfall again after selling FertilizerTruck...\n";
    wheatField->rain();  // No fertilization should happen

    // Grow more crops to reach near full capacity and trigger DeliveryTruck again
    cout << "\nGrowing more crops...\n";
    wheatField->growCrops(100);  // Should reach full capacity and trigger DeliveryTruck
    cout << "Crops grown. Current amount of crops: 900\n";
    
    // Show explicit callTruck and startEngine for delivery truck (manual test)
    cout << "\nTesting callTruck and startEngine for DeliveryTruck...\n";
    deliveryTruck->callTruck();  // Manually calling the truck for collection
    
    // Clean up
    delete wheatField;
    delete fertilizerTruck;  // Although sold, we need to manually delete it
    delete deliveryTruck;
    
}



void testBreadthFirstTraversal(Farmland* farmland) {
    cout << "\nTesting Breadth-First Traversal:\n";

    // Create the Breadth-First Iterator
    BreadthFirstFarmIterator* bfIterator = new BreadthFirstFarmIterator(farmland);

    // Start traversal
    FarmUnit* current = bfIterator->firstFarm();
    while (!bfIterator->isDone()) {
        cout << "Visiting farm unit with crop: " << current->getCropType() << endl;
        current = bfIterator->next();
    }

    delete bfIterator;
}

void testDepthFirstTraversal(Farmland* farmland) {
    cout << "\nTesting Depth-First Traversal:\n";

    // Create the Depth-First Iterator
    DepthFirstFarmIterator* dfIterator = new DepthFirstFarmIterator(farmland);

    // Start traversal
    FarmUnit* current = dfIterator->firstFarm();
    while (!dfIterator->isDone()) {
        cout << "Visiting farm unit with crop: " << current->getCropType() << endl;
        current = dfIterator->next();
    }

    delete dfIterator;
}




void testIterator(){
     // Create a hierarchical structure of Farmland and CropFields
    Farmland* mainFarmland = new Farmland("Main Farm");

    // Create crop fields with different soils
    CropField* cornField = new CropField("Corn", 100, new DrySoil());
    CropField* wheatField = new CropField("Wheat", 150, new FruitfulSoil());

    // Add crop fields to the main farmland
    mainFarmland->addUnit(cornField);
    mainFarmland->addUnit(wheatField);

    // Create a sub-farm
    Farmland* subFarmland = new Farmland("Sub Farm");
    CropField* riceField = new CropField("Rice", 200, new DrySoil());
    subFarmland->addUnit(riceField);

    // Add the sub-farm to the main farmland
    mainFarmland->addUnit(subFarmland);

    // Test Breadth-First Traversal
    testBreadthFirstTraversal(mainFarmland);

    // Test Depth-First Traversal
    testDepthFirstTraversal(mainFarmland);

    // Clean up memory
    delete mainFarmland;

}


int main(){

    std::cout<<"****************************"<<std::endl;
    std::cout<<"Testing Composite Pattern"<<std::endl;
    std::cout<<"\n****************************\n"<<std::endl;
    testComposite();
    std::cout<<"\n****************************\n"<<std::endl;

    std::cout<<"****************************"<<std::endl;
    std::cout<<"Testing State Pattern"<<std::endl;
    std::cout<<"\n****************************\n"<<std::endl;
    testState();
    std::cout<<"\n****************************\n"<<std::endl;

    std::cout<<"****************************"<<std::endl;
    std::cout<<"Testing Decorator Pattern"<<std::endl;
    std::cout<<"\n****************************\n"<<std::endl;
    testDecorator();
    std::cout<<"\n****************************\n"<<std::endl;

    std::cout<<"****************************"<<std::endl;
    std::cout<<"Testing Observer Pattern"<<std::endl;
    std::cout<<"\n****************************\n"<<std::endl;
    testObserver();
    std::cout<<"\n****************************\n"<<std::endl;

    std::cout<<"****************************"<<std::endl;
    std::cout<<"Testing Iterator Pattern"<<std::endl;
    std::cout<<"\n****************************\n"<<std::endl;
    testIterator();
    std::cout<<"\n****************************\n"<<std::endl;

    return 0;
}