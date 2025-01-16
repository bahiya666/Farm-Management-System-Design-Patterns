CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Targets
TARGET = main

# Object files
OBJECTS = main.o Farmland.o FarmUnit.o Barn.o CropField.o CropFieldDecorator.o \
          ExtraBarn.o FertilizedField.o Truck.o FertilizerTruck.o DeliveryTruck.o \
          SoilState.o DrySoil.o FruitfulSoil.o FloodedSoil.o \
          FarmIterator.o BreadthFirstFarmIterator.o DepthFirstFarmIterator.o

# Rules
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

# Object file generation for each class
main.o: main.cpp FarmUnit.h Farmland.h CropField.h Barn.h Truck.h FertilizerTruck.h DeliveryTruck.h SoilState.h DrySoil.h FruitfulSoil.h FloodedSoil.h FarmIterator.h BreadthFirstFarmIterator.h DepthFirstFarmIterator.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

Farmland.o: Farmland.cpp Farmland.h FarmUnit.h
	$(CXX) $(CXXFLAGS) -c Farmland.cpp -o Farmland.o

FarmUnit.o: FarmUnit.cpp FarmUnit.h
	$(CXX) $(CXXFLAGS) -c FarmUnit.cpp -o FarmUnit.o

Barn.o: Barn.cpp Barn.h FarmUnit.h
	$(CXX) $(CXXFLAGS) -c Barn.cpp -o Barn.o

CropField.o: CropField.cpp CropField.h FarmUnit.h SoilState.h
	$(CXX) $(CXXFLAGS) -c CropField.cpp -o CropField.o

CropFieldDecorator.o: CropFieldDecorator.cpp CropFieldDecorator.h CropField.h
	$(CXX) $(CXXFLAGS) -c CropFieldDecorator.cpp -o CropFieldDecorator.o

ExtraBarn.o: ExtraBarn.cpp ExtraBarn.h CropFieldDecorator.h
	$(CXX) $(CXXFLAGS) -c ExtraBarn.cpp -o ExtraBarn.o

FertilizeField.o: FertilizedField.cpp FertilizedField.h CropFieldDecorator.h
	$(CXX) $(CXXFLAGS) -c FertilizedField.cpp -o FertilizedField.o

Truck.o: Truck.cpp Truck.h
	$(CXX) $(CXXFLAGS) -c Truck.cpp -o Truck.o

FertilizerTruck.o: FertilizerTruck.cpp FertilizerTruck.h Truck.h
	$(CXX) $(CXXFLAGS) -c FertilizerTruck.cpp -o FertilizerTruck.o

DeliveryTruck.o: DeliveryTruck.cpp DeliveryTruck.h Truck.h
	$(CXX) $(CXXFLAGS) -c DeliveryTruck.cpp -o DeliveryTruck.o

SoilState.o: SoilState.cpp SoilState.h
	$(CXX) $(CXXFLAGS) -c SoilState.cpp -o SoilState.o

DrySoil.o: DrySoil.cpp DrySoil.h SoilState.h
	$(CXX) $(CXXFLAGS) -c DrySoil.cpp -o DrySoil.o

FruitfulSoil.o: FruitfulSoil.cpp FruitfulSoil.h SoilState.h
	$(CXX) $(CXXFLAGS) -c FruitfulSoil.cpp -o FruitfulSoil.o

FloodedSoil.o: FloodedSoil.cpp FloodedSoil.h SoilState.h
	$(CXX) $(CXXFLAGS) -c FloodedSoil.cpp -o FloodedSoil.o

FarmIterator.o: FarmIterator.cpp FarmIterator.h
	$(CXX) $(CXXFLAGS) -c FarmIterator.cpp -o FarmIterator.o

BreadthFirstFarmIterator.o: BreadthFirstFarmIterator.cpp BreadthFirstFarmIterator.h FarmIterator.h
	$(CXX) $(CXXFLAGS) -c BreadthFirstFarmIterator.cpp -o BreadthFirstFarmIterator.o

DepthFirstFarmIterator.o: DepthFirstFarmIterator.cpp DepthFirstFarmIterator.h FarmIterator.h
	$(CXX) $(CXXFLAGS) -c DepthFirstFarmIterator.cpp -o DepthFirstFarmIterator.o

clean:
	rm -f $(TARGET) $(OBJECTS)

run: $(TARGET)
	./$(TARGET)
