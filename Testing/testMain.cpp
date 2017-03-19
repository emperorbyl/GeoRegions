#include <iostream>
#include "UtilsTester.h"
#include "RegionTester.h"
//#include "WorldTester.h"

int main() {

    std::cout << "Execute Test Cases" << std::endl;

    UtilsTester utilsTester;
    utilsTester.testSplit();
    utilsTester.testConvertToInt();
    utilsTester.testConvertToUnsignedInt();
    utilsTester.testConvertToDouble();
    utilsTester.testLeftTrim();
    utilsTester.testRightTrim();
    utilsTester.testTrim();

    RegionTester regionTester;
    regionTester.testCreateFromStream();
    regionTester.testCreateFromString();
    regionTester.testCreateFromTypeAndString();
    regionTester.testGettersAndSetters();
    regionTester.testSubRegions();
    regionTester.testComputeTotalPopulation();
    regionTester.testList();
    regionTester.testDisplay();
    regionTester.testSave();
}//
// Created by benja on 3/17/2017.
//

