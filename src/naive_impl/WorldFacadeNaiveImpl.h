/*
 * WorldFacadeImpl.h
 *
 *  Created on: 10 Sep 2010
 *      
 */

#ifndef WORLDFACADEIMPL_H_
#define WORLDFACADEIMPL_H_
#include "../WorldFacade.h"
#include "LocationNaive.h"

using namespace std;

typedef LocationNaive* LocationPtr;
typedef map<string, LocationPtr> LocationMap;


class WorldFacadeNaiveImpl: public WorldFacade {
public:
	WorldFacadeNaiveImpl(EventLogger* logger);
	virtual ~WorldFacadeNaiveImpl();

	virtual void createLocation(string lName);
	virtual void createAgent(string aName, string lName);
	virtual void deleteLocation(string lName);

	virtual StringList getLocationsInWorld();
	virtual StringList getAgentsInWorld();

	virtual StringList getAgentsInLocation(string lName);
	virtual AgentPointer getAgentWithId(string id);

private:
	LocationMap locations;
    void freeUpLocations();
    Agent* findAgentByName(string name);
};




#endif /* WORLDFACADEIMPL_H_ */
