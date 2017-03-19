//
// Created by benja on 3/17/2017.
//

#ifndef GEOREGIONS_REGION_H
#define GEOREGIONS_REGION_H


#include <string>
#include <locale>

class Region {
public:
    typedef enum RegionType { UnknownRegionType, WorldType, NationType, StateType, CountyType, CityType } x;

protected:
    unsigned int    m_id = 0;
    RegionType      m_regionType = UnknownRegionType;
    std::string     m_name;
    unsigned int    m_population = 0;
    double          m_area = 0;
    bool            m_isValid = false;
    Region**        subRegion;
    unsigned int    subRegionCount = 0;
    int             subRegionAllocation = 0;
    // TODO: Add data members to manage sub-regions

private:
    static unsigned int m_nextId;

public:
    static Region* create(std::istream &in);
    static Region* create(const std::string& data);
    static Region* create(RegionType regionType, const std::string& data);
    static std::string regionLabel(RegionType regionType);

protected:
    Region();
    Region(RegionType type, const std::string data[]);

public:
    ~Region();
    unsigned int getId() const { return m_id; }
    RegionType  getType() const { return m_regionType; }
    std::string getRegionLabel() const;
    const std::string& getName() const { return m_name; }
    void setName(const std::string& name) { m_name = name; }
    unsigned int getPopulation() const { return m_population; }
    void setPopulation(unsigned int population) { m_population = population; }
    double getArea() const { return m_area; }
    void setArea(double area) { m_area = area; }
    bool getIsValid() const { return m_isValid; }
    double getSubRegionCount();
    Region* getSubRegionByIndex(int index);

    unsigned int computeTotalPopulation();

    void list(std::ostream& out);
    void display(std::ostream& out, unsigned int displayLevel, bool showChild);
    void save(std::ostream& out);

protected:
    virtual void validate();
    void loadChildren(std::istream& in);
    static unsigned int getNextId();
    void growRegionAllocation();

};


#endif //GEOREGIONS_REGION_H
