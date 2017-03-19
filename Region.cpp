//
// Created by benja on 3/17/2017.
//

#include "Region.h"
#include "Utils.h"
#include "World.h"
#include "Nation.h"
#include "State.h"
#include "County.h"
#include "City.h"

#include <iomanip>

const std::string regionDelimiter = "^^^";
const int TAB_SIZE = 4;
unsigned int Region::m_nextId = 0;

Region* Region::create(std::istream &in)
{
    Region* region = nullptr;
    std::string line;
    std::getline(in, line);
    if (line!="")
    {
        region = create(line);
        if (region!= nullptr)
            region->loadChildren(in);
    }
    return region;
}
Region* Region::create(const std::string& data)
{
    Region* region = nullptr;
    std::string regionData;
    unsigned long commaPos = (int) data.find(",");
    if (commaPos != std::string::npos)
    {
        std::string regionTypeStr = data.substr(0,commaPos);
        regionData = data.substr(commaPos+1);

        bool isValid;
        RegionType regionType = (RegionType) convertStringToInt(regionTypeStr, &isValid);

        if (isValid)
        {
            region = create(regionType, regionData);
        }

    }

    return region;
}

Region* Region::create(RegionType regionType, const std::string& data)
{
    Region* region = nullptr;
    std::string fields[3];
    if (split(data, ',', fields, 3)) {

        // Create the region based on type
        switch (regionType) {
            case WorldType:
                region = new World();
                break;
            case NationType:
                region = new Nation(fields);
                break;
            case StateType:
                region = new State(fields);
                break;
            case CountyType:
                region = new County(fields);
                break;
            case CityType:
                region = new City(fields);
            default:
                break;
        }

        // If the region isn't valid, git ride of it
        if (region != nullptr && !region->getIsValid()) {
            delete region;
            region = nullptr;
        }
    }

    return region;
}

std::string Region::regionLabel(RegionType regionType)
{
    std::string label = "Unknown";
    switch (regionType)
    {
        case Region::WorldType:
            label = "World";
            break;
        case Region::NationType:
            label = "Nation";
            break;
        case Region::StateType:
            label = "State";
            break;
        case Region::CountyType:
            label = "County";
            break;
        case Region::CityType:
            label = "City";
            break;
        default:
            break;
    }
    return label;
}

Region::Region() { }

Region::Region(RegionType type, const std::string data[]) :
        m_id(getNextId()), m_regionType(type), m_isValid(true)
{
    m_name = data[0];
    m_population = convertStringToUnsignedInt(data[1], &m_isValid);
    if (m_isValid)
        m_area = convertStringToDouble(data[2], &m_isValid);
}

Region::~Region()
{
    for(int i = 0; i < subRegionCount; i++)
        delete subRegion[i];
    delete []subRegion;
}

std::string Region::getRegionLabel() const
{
    return regionLabel(getType());
}

unsigned int Region::computeTotalPopulation()
{

    int sumPopulation = 0;
    for(int i = 0; i < subRegionCount; i++)
        sumPopulation += subRegion[i]->getPopulation();
    return sumPopulation + m_population;
}

void Region::list(std::ostream& out)
{
    out << std::endl;
    out << "id: " << getId() << " ";
    out << getName() << ":" << std::endl;
    for(int i = 0; i < subRegionCount; i++)
        out << "id " << subRegion[i]->getId() << " " << "name " << subRegion[i]->getName() << std::endl;
}

void Region::display(std::ostream& out, unsigned int displayLevel, bool showChild)
{
    if (displayLevel>0)
    {
        out << std::setw(displayLevel * TAB_SIZE) << " ";
    }

    unsigned totalPopulation = computeTotalPopulation();
    double area = getArea();
    double density = (double) totalPopulation / area;


    out << std::setw(6) << getId() << "  "
        << getName() << ", population="
        << totalPopulation
        << ", area=" << area
        << ", density=" << density << std::endl;

    if (showChild)
    {
        for(int i = displayLevel + 1; i < subRegionCount; i++)
        {
            out << std::setw(6) << subRegion[i]->getId() << "  "
                << subRegion[i]->getName() << ", population="
                << subRegion[i]->getPopulation()
                << ", area=" << subRegion[i]->getArea()
                << ", density=" << subRegion[i]->getPopulation() / subRegion[i]->getArea() << std::endl;
        }
    }
}

void Region::save(std::ostream& out)
{
    out << getType()
        << "," << getName()
        << "," << getPopulation()
        << "," << getArea()
        << std::endl;

    for(int i = 0; i < subRegionCount; i++)
    {
        out << subRegion[i]->getType()
            << "," << subRegion[i]->getName()
            << "," << subRegion[i]->getPopulation()
            << "," << subRegion[i]->getArea()
            << std::endl;
    }

    out << regionDelimiter << std::endl;
}

void Region::validate()
{
    m_isValid = (m_area!=UnknownRegionType && m_name!="" && m_area>=0);
}

void Region::loadChildren(std::istream& in)
{
    std::string line;
    bool done = false;
    subRegionAllocation = 2;
    subRegion = new Region*[subRegionAllocation];
    while (!in.eof() && !done)
    {
        std::getline(in, line);
        if (line==regionDelimiter)
        {
            done = true;
        }
        else
        {
            Region* child = create(line);
            if (child!= nullptr)
            {
                if (subRegionCount == subRegionAllocation)
                    growRegionAllocation();
                subRegion[subRegionCount] = child;
                child->loadChildren(in);
                subRegionCount++;
            }
        }
    }
}

unsigned int Region::getNextId()
{
    if (m_nextId==UINT32_MAX)
        m_nextId=1;

    return m_nextId++;
}

double Region::getSubRegionCount()
{
    return subRegionCount;
}
Region* Region::getSubRegionByIndex(int index)
{
    return subRegion[index];
}

void Region::growRegionAllocation()
{
    subRegionAllocation = 2 * subRegionAllocation;
    Region** newArray = new Region* [subRegionAllocation];
    for (int i=0; i<subRegionCount; i++)
    {
        newArray[i] = subRegion[i];
    }
    delete[] subRegion;
    subRegion = newArray;
}
