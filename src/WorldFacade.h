#ifndef WORLDFACADE_H_
#define WORLDFACADE_H_

#include "midpo_utils.h"
#include "Object.h"
#include "logging/EventLogger.h"
#include "logging/Loggable.h"

using namespace std;


class WorldFacade : public Loggable {
public:
	virtual ~WorldFacade() {};

	/**
	 * Return the implementation of the WorldFacade interface
	 */
	static WorldFacade* createWorldFacade(EventLogger* logger);

	virtual void createLocation(string lName) = 0;
	virtual void createAgent(string aName, string lName) = 0;
	virtual void deleteLocation(string lName) = 0;

	virtual StringList getLocationsInWorld() = 0;
	virtual StringList getAgentsInWorld() = 0;

	virtual StringList getAgentsInLocation(string lName) = 0;
	virtual AgentPointer getAgentWithId(string id) = 0;
};

#endif /* WORLDFACADE_H_ */
