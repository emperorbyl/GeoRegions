//
// Created by benja on 3/17/2017.
//

#include "RegionTester.h"
#include "../Region.h"

#include <iostream>
#include <fstream>

void RegionTester::testCreateFromStream()
{
    std::cout << "RegionTester::testCreateFromStream" << std::endl;

    // Load a file with just the world in it
    {
        std::string inputFile = "Testing/SampleData/sampleData-1.txt";
        std::ifstream inputStream(inputFile);
        Region* region = Region::create(inputStream);
        if (region==nullptr)
        {
            std::cout << "Failed to create a region from " << inputFile << std::endl;
            return;
        }

        if (region->getType()!=Region::RegionType::WorldType)
        {
            std::cout << "Failed to create correct type of region from " << inputFile << std::endl;
            std::cout << "\tExpected World region type, but created a " << region->getRegionLabel() << std::endl;
            return;
        }
    }

    // Load a file with the and four nations
    {
        std::string inputFile = "Testing/SampleData/sampleData-2.txt";
        std::ifstream inputStream(inputFile);
        Region* world = Region::create(inputStream);
        if (world==nullptr)
        {
            std::cout << "Failed to create a region from " << inputFile << std::endl;
            return;
        }

        if (world->getType()!=Region::RegionType::WorldType)
        {
            std::cout << "Failed to create correct type of region from " << inputFile << std::endl;
            std::cout << "\tExpected World region type, but created a " << world->getRegionLabel() << std::endl;
            return;
        }

        if (world->getSubRegionCount()!=4)
        {
            std::cout << "Failed to load the four expected nations from " << inputFile << std::endl;
            std::cout << "\tExpected 4 nations, but loaded a " << world->getSubRegionCount() << std::endl;
            return;
        }

        for (unsigned int nationIndex=0; nationIndex < world->getSubRegionCount(); nationIndex++)
        {
            Region* nation = world->getSubRegionByIndex(nationIndex);
            if (nation->getType()!=Region::RegionType::NationType)
            {
                std::cout << "Failed to create correct type of sub-region in the world from " << inputFile << std::endl;
                std::cout << "\tExpected nation sub-region type, but created a " << nation->getRegionLabel() << std::endl;
                return;
            }
        }
    }

}

void RegionTester::testCreateFromString()
{
    std::cout << "RegionTester::testCreateFromString" << std::endl;

    {
        std::string inputString = "2,Tiny Country,30,20";
        Region *region = Region::create(inputString);
        if (region == nullptr) {
            std::cout << "Failed to create a region from " << inputString << std::endl;
            return;
        }

        if (region->getType() != Region::RegionType::NationType) {
            std::cout << "Failed to create correct type of region from " << inputString << std::endl;
            std::cout << "\tExpected Country region type, but got " << region->getRegionLabel() << std::endl;
            return;
        }

        if (region->getName() != "Tiny Country") {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected \"Tiny Country\", but got \"" << region->getPopulation() << "\"" << std::endl;
            return;
        }

        if (region->getPopulation() != 30) {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected 30, but created a " << region->getPopulation() << std::endl;
            return;
        }

        if (region->getArea() != 20) {
            std::cout << "Failed to initialize the area for region from " << inputString << std::endl;
            std::cout << "\tExpected 20, but created a " << region->getArea() << std::endl;
            return;
        }
    }

    {
        std::string inputString = "3,Tiny State,30,20";
        Region *region = Region::create(inputString);
        if (region == nullptr) {
            std::cout << "Failed to create a region from " << inputString << std::endl;
            return;
        }

        if (region->getType() != Region::RegionType::StateType) {
            std::cout << "Failed to create correct type of region from " << inputString << std::endl;
            std::cout << "\tExpected State region type, but got " << region->getRegionLabel() << std::endl;
            return;
        }

        if (region->getName() != "Tiny State") {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected \"Tiny State\", but got \"" << region->getPopulation() << "\"" << std::endl;
            return;
        }

        if (region->getPopulation() != 30) {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected 30, but created a " << region->getPopulation() << std::endl;
            return;
        }

        if (region->getArea() != 20) {
            std::cout << "Failed to initialize the area for region from " << inputString << std::endl;
            std::cout << "\tExpected 20, but created a " << region->getArea() << std::endl;
            return;
        }
    }

    {
        std::string inputString = "4,Tiny County,30,20";
        Region *region = Region::create(inputString);
        if (region == nullptr) {
            std::cout << "Failed to create a region from " << inputString << std::endl;
            return;
        }

        if (region->getType() != Region::RegionType::CountyType) {
            std::cout << "Failed to create correct type of region from " << inputString << std::endl;
            std::cout << "\tExpected County region type, but got " << region->getRegionLabel() << std::endl;
            return;
        }

        if (region->getName() != "Tiny County") {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected \"Tiny County\", but got \"" << region->getPopulation() << "\"" << std::endl;
            return;
        }

        if (region->getPopulation() != 30) {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected 30, but created a " << region->getPopulation() << std::endl;
            return;
        }

        if (region->getArea() != 20) {
            std::cout << "Failed to initialize the area for region from " << inputString << std::endl;
            std::cout << "\tExpected 20, but created a " << region->getArea() << std::endl;
            return;
        }
    }

    {
        std::string inputString = "5,Tiny City,30,20";
        Region *region = Region::create(inputString);
        if (region == nullptr) {
            std::cout << "Failed to create a region from " << inputString << std::endl;
            return;
        }

        if (region->getType() != Region::RegionType::CityType) {
            std::cout << "Failed to create correct type of region from " << inputString << std::endl;
            std::cout << "\tExpected City region type, but got " << region->getRegionLabel() << std::endl;
            return;
        }

        if (region->getName() != "Tiny City") {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected \"Tiny City\", but got \"" << region->getPopulation() << "\"" << std::endl;
            return;
        }

        if (region->getPopulation() != 30) {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected 30, but created a " << region->getPopulation() << std::endl;
            return;
        }

        if (region->getArea() != 20) {
            std::cout << "Failed to initialize the area for region from " << inputString << std::endl;
            std::cout << "\tExpected 20, but created a " << region->getArea() << std::endl;
            return;
        }
    }

    {
        std::string inputString = "Tiny Country,30,20";
        Region *region = Region::create(inputString);
        if (region != nullptr) {
            std::cout << "Failed to recognize a bad data string in create method, inputString=" << inputString << std::endl;
            return;
        }
    }

    {
        std::string inputString = "2,30,20";
        Region *region = Region::create(inputString);
        if (region != nullptr) {
            std::cout << "Failed to recognize a bad data string in create method, inputString=" << inputString << std::endl;
            return;
        }
    }

}

void RegionTester::testCreateFromTypeAndString()
{
    std::cout << "RegionTester::testCreateFromTypeAndString" << std::endl;

    {
        std::string inputString = "Tiny Country,30,20";
        Region *region = Region::create(Region::NationType,inputString);
        if (region == nullptr) {
            std::cout << "Failed to create a region from " << inputString << std::endl;
            return;
        }

        if (region->getType() != Region::RegionType::NationType) {
            std::cout << "Failed to create correct type of region from " << inputString << std::endl;
            std::cout << "\tExpected Nation region type, but got " << region->getRegionLabel() << std::endl;
            return;
        }

        if (region->getName() != "Tiny Country") {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected \"Tiny County\", but got \"" << region->getPopulation() << "\"" << std::endl;
            return;
        }

        if (region->getPopulation() != 30) {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected 30, but created a " << region->getPopulation() << std::endl;
            return;
        }

        if (region->getArea() != 20) {
            std::cout << "Failed to initialize the area for region from " << inputString << std::endl;
            std::cout << "\tExpected 20, but created a " << region->getArea() << std::endl;
            return;
        }
    }

    {
        std::string inputString = "Tiny State,30,20";
        Region *region = Region::create(Region::RegionType::StateType, inputString);
        if (region == nullptr) {
            std::cout << "Failed to create a region from " << inputString << std::endl;
            return;
        }

        if (region->getType() != Region::RegionType::StateType) {
            std::cout << "Failed to create correct type of region from " << inputString << std::endl;
            std::cout << "\tExpected State region type, but got " << region->getRegionLabel() << std::endl;
            return;
        }

        if (region->getName() != "Tiny State") {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected \"Tiny State\", but got \"" << region->getPopulation() << "\"" << std::endl;
            return;
        }

        if (region->getPopulation() != 30) {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected 30, but created a " << region->getPopulation() << std::endl;
            return;
        }

        if (region->getArea() != 20) {
            std::cout << "Failed to initialize the area for region from " << inputString << std::endl;
            std::cout << "\tExpected 20, but created a " << region->getArea() << std::endl;
            return;
        }
    }

    {
        std::string inputString = "Tiny County,30,20";
        Region *region = Region::create(Region::RegionType::CountyType, inputString);
        if (region == nullptr) {
            std::cout << "Failed to create a region from " << inputString << std::endl;
            return;
        }

        if (region->getType() != Region::RegionType::CountyType) {
            std::cout << "Failed to create correct type of region from " << inputString << std::endl;
            std::cout << "\tExpected County region type, but got " << region->getRegionLabel() << std::endl;
            return;
        }

        if (region->getName() != "Tiny County") {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected \"Tiny County\", but got \"" << region->getPopulation() << "\"" << std::endl;
            return;
        }

        if (region->getPopulation() != 30) {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected 30, but created a " << region->getPopulation() << std::endl;
            return;
        }

        if (region->getArea() != 20) {
            std::cout << "Failed to initialize the area for region from " << inputString << std::endl;
            std::cout << "\tExpected 20, but created a " << region->getArea() << std::endl;
            return;
        }
    }

    {
        std::string inputString = "Tiny City,30,20";
        Region *region = Region::create(Region::RegionType::CityType, inputString);
        if (region == nullptr) {
            std::cout << "Failed to create a region from " << inputString << std::endl;
            return;
        }

        if (region->getType() != Region::RegionType::CityType) {
            std::cout << "Failed to create correct type of region from " << inputString << std::endl;
            std::cout << "\tExpected City region type, but got " << region->getRegionLabel() << std::endl;
            return;
        }

        if (region->getName() != "Tiny City") {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected \"Tiny City\", but got \"" << region->getPopulation() << "\"" << std::endl;
            return;
        }

        if (region->getPopulation() != 30) {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected 30, but created a " << region->getPopulation() << std::endl;
            return;
        }

        if (region->getArea() != 20) {
            std::cout << "Failed to initialize the area for region from " << inputString << std::endl;
            std::cout << "\tExpected 20, but created a " << region->getArea() << std::endl;
            return;
        }
    }

    {
        std::string inputString = "Tiny Country,30";
        Region *r1 = Region::create(Region::NationType,inputString);
        if (r1 != nullptr) {
            std::cout << "Failed to recognize a bad data string in create method, inputString=" << inputString << std::endl;
            return;
        }
    }

    {
        std::string inputString = "2";
        Region *r1 = Region::create(Region::NationType, inputString);
        if (r1 != nullptr) {
            std::cout << "Failed to recognize a bad data string in create method, inputString=" << inputString << std::endl;
            return;
        }
    }

}

void RegionTester::testGettersAndSetters()
{
    std::cout << "RegionTester::testGettersAndSetters" << std::endl;

    {
        std::string inputString = "Tiny Country,30,20";
        Region *region = Region::create(Region::NationType,inputString);
        if (region == nullptr) {
            std::cout << "Failed to create a region from " << inputString << std::endl;
            return;
        }

        if (region->getType() != Region::RegionType::NationType) {
            std::cout << "Failed to create correct type of region from " << inputString << std::endl;
            std::cout << "\tExpected Nation region type, but got " << region->getRegionLabel() << std::endl;
            return;
        }

        if (region->getName() != "Tiny Country") {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected \"Tiny County\", but got \"" << region->getPopulation() << "\"" << std::endl;
            return;
        }

        if (region->getPopulation() != 30) {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected 30, but created a " << region->getPopulation() << std::endl;
            return;
        }

        if (region->getArea() != 20) {
            std::cout << "Failed to initialize the area for region from " << inputString << std::endl;
            std::cout << "\tExpected 20, but created a " << region->getArea() << std::endl;
            return;
        }

        region->setName("Really Tiny County");
        if (region->getName() != "Really Tiny County") {
            std::cout << "Failed to set the name for region from " << inputString << std::endl;
            std::cout << "\tExpected \"Really Tiny County\", but got \"" << region->getName() << "\"" << std::endl;
            return;
        }

        region->setPopulation(5);
        if (region->getPopulation()!=5) {
            std::cout << "Failed to set the population for region from " << inputString << std::endl;
            std::cout << "\tExpected 5, but got \"" << region->getPopulation() << "\"" << std::endl;
            return;
        }

        region->setArea(2);
        if (region->getArea()!=2) {
            std::cout << "Failed to set the area for region from " << inputString << std::endl;
            std::cout << "\tExpected 2, but got \"" << region->getArea() << "\"" << std::endl;
            return;
        }
    }
}

void RegionTester::testSubRegions()
{
    std::cout << "RegionTester::testSubRegions" << std::endl;
    std::string inputFile = "Testing/SampleData/sampleData-2.txt";
    std::ifstream inputStream(inputFile);
    Region* region = Region::create(inputStream);
    if(region == nullptr)
    {
        std::cout << "Failed to create a region from " << inputFile << std::endl;
        return;
    }
    Region* subReg = region->getSubRegionByIndex(0);
    if(subReg == nullptr)
        std::cout << "Failed in create a subregion." << std::endl;
    if(subReg->getRegionLabel() != "Nation")
        std::cout << "Failed in creating a subregion." << std::endl;
    if(subReg->getName() != "United States")
        std::cout << "Failed in creating a subregion with the right name." << std::endl;

}

void RegionTester::testComputeTotalPopulation()
{
    std::cout << "RegionTester::testComputeTotalPopulation" << std::endl;
    std::string inputString = "Tiny Country, 30, 20";
    Region* region = Region::create(Region::RegionType::CountyType, inputString);
    if(region->getPopulation() != 30)
        std::cout << "Failed in creating a subregion or in calculating the population." << std::endl;
    std::string inputFile = "Testing/SampleData/sampleData-2.txt";
    std::ifstream inputStream(inputFile);
    Region* region1 = Region::create(inputStream);
    if(region1->computeTotalPopulation() != 484600305)
        std::cout << "Failed in calculating the population" << std::endl;
}

void RegionTester::testList()
{
    std::cout << "RegionTester::testList" << std::endl;
    std::string inputString = "Tiny Country, 30, 20";
    Region* region = Region::create(Region::RegionType::CountyType, inputString);
    region->list(std::cout);
    if(std::cout.bad())
        std::cout << "Failed in listing the Region" << std::endl;
    std::string inputFile = "Testing/SampleData/sampleData-2.txt";
    std::ifstream inputStream(inputFile);
    Region* region1 = Region::create(inputStream);
    region1->list(std::cout);
    if(std::cout.bad())
        std::cout << "Failed in listing the Region" << std::endl;
}
void RegionTester::testDisplay()
{
    std::cout << "RegionTester::testDisplay" << std::endl;
    std::string inputFile = "Testing/SampleData/sampleData-2.txt";
    std::ifstream inputStream(inputFile);
    Region* region1 = Region::create(inputStream);
    std::string outputFile = "Testing/displayFile.txt";
    std::ofstream outputStream(outputFile);
    region1->display(outputStream, 1, true);
    if(outputStream.fail() || outputStream.bad())
        std::cout << "Failed in displaying the Region" << std::endl;
}
void RegionTester::testSave()
{
    std::cout << "RegionTester::testSave" << std::endl;
    std::cout << "RegionTester::testDisplay" << std::endl;
    std::string inputFile = "Testing/SampleData/sampleData-2.txt";
    std::ifstream inputStream(inputFile);
    Region* region = Region::create(inputStream);
    std::string outputFile = "Testing/saveFile.txt";
    std::ofstream outputStream(outputFile);
    region->save(outputStream);
    if(outputStream.fail() || outputStream.bad())
        std::cout << "Failed in saving the Region" << std::endl;
}