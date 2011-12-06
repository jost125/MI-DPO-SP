/*
 * LocationImpl.cpp
 *
 *  Created on: 15 Sep 2010
 */

#include "LocationImpl.h"

using namespace std;


LocationImpl::~LocationImpl() {
}

LocationImpl::LocationImpl(EventLogger* logger, string name) : Location(logger, name) {
}

void LocationImpl::agentEnters(AgentPointer a) {
	agents.push_back(a);
}

void LocationImpl::agentLeaves(AgentPointer a) {
	agents.remove(a);
}

AgentList LocationImpl::agentsInside()
{
	return agents;
}
