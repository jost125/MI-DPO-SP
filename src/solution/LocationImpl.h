/*
 * LocationImpl.h
 *
 *  Created on: 15 Sep 2010
 *      
 */

#ifndef LOCATIONIMPL_H_
#define LOCATIONIMPL_H_

#include "../Location.h"
#include "../midpo_utils.h"
#include "ITarget.h"
#include "IRefCounter.h"
#include "SmartPointer.h"
#include "../Agent.h"

using namespace std;

typedef list<AgentPointer> AgentList;

class LocationImpl: public Location, public RefCounter, public ITarget {
private:
	AgentList agents;

public:
	LocationImpl(EventLogger* logger, string name);
	virtual ~LocationImpl();

	void agentEnters(AgentPointer a);

	void agentLeaves(AgentPointer a);

	void virtual addRef();

	void virtual release();

	AgentList agentsInside();

};

#endif /* LOCATIONIMPL_H_ */
