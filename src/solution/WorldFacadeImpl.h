/*
 * WorldFacadeImpl.h
 *
 *  Created on: 10 Sep 2010
 *      
 */

#ifndef WORLDFACADEIMPL_H_
#define WORLDFACADEIMPL_H_
#include "../WorldFacade.h"
#include "SmartPointer.h"
#include "LocationImpl.h"

using namespace std;

typedef SmartPointer<LocationImpl> LocationPtr;
typedef map<string, LocationPtr> LocationMap;


class WorldFacadeImpl: public WorldFacade {
public:
	WorldFacadeImpl(EventLogger* logger);
	virtual ~WorldFacadeImpl();

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
    AgentPointer findAgentByName(string name);
};




#endif /* WORLDFACADEIMPL_H_ */
