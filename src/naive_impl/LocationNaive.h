/*
 * LocationNaive.h
 *
 *  Created on: 15 Sep 2010
 *      
 */

#ifndef LOCATIONNAIVE_H_
#define LOCATIONNAIVE_H_

#include "../Location.h"

using namespace std;

typedef list<Agent*> AgentList;

class LocationNaive: public Location {
private:
	AgentList agents;

public:
	LocationNaive(EventLogger* logger, string name) : Location(logger, name) {};
	virtual ~LocationNaive();

	void agentEnters(Agent* a);

	void agentLeaves(Agent* a);

	AgentList agentsInside();

};

#endif /* LOCATIONNAIVE_H_ */
