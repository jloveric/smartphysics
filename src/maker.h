#ifndef MAKER_H_
#define MAKER_H_

#include <map>
#include <sstream>
#include <string>
#include <iostream>

/**
 * Base class for creating new objects
 */
template <class TBASE>
class MakerBase
{
  public:
  virtual ~MakerBase()
  {}

  /**
   * Get a pointer to the object
   */
  virtual TBASE* get() = 0;

  private:
};

/**
 * Store the map that stores object constructors
 */
template <class TBASE>
class MakerMap
{
  public:
  static std::map<std::string, MakerBase<TBASE>*> map;
};

template <class TBASE>
std::map<std::string, MakerBase<TBASE>*> MakerMap<TBASE>::map;

/**
 * Simple function for retrieving and object
 * @param name is the name of the string of interest
 */
template <class TBASE>
TBASE* getNew(std::string name)
{
  NetLogger netLog;

  if (MakerMap<TBASE>::map.find(name) == MakerMap<TBASE>::map.end()) {

    for (auto it : MakerMap<TBASE>::map) {
      std::string thisName = it.first;
    }

    std::cout << "could not find " << name << "in map\n";
    throw;
  }

  TBASE* result = MakerMap<TBASE>::map[name]->get();
  if (result == NULL) {
    BOOST_LOG(netLog.getLogger()) << "getNew object name " << name << " not found ";
    netLog.logAndThrow("Error");
  }
  return result;
}

/**
 * Maker map for a specific type of object
 */
template <class TBASE, class T>
class Maker : public MakerBase<TBASE>
{
  public:
  /**
   * Constructor
   * @param the name of the object
   */
  Maker(std::string thisName)
  {
    name = thisName;
    MakerMap<TBASE> a;
    a.map[name] = this;
  }

  /**
   * @return the name of the object
   */
  std::string getName()
  {
    return name;
  }

  /**
   * @return handoff a pointer to the object
   */
  TBASE* get() override
  {
    return new T;
  }

  private:
  std::string name;
};

#endif