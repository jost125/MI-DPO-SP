/*
 * LocationImpl.cpp
 *
 *  Created on: 15 Sep 2010
 */

#include "LocationImpl.h"

using namespace std;


LocationImpl::~LocationImpl() {
	this->release();
}

LocationImpl::LocationImpl(EventLogger* logger, string name) : Location(logger, name) {
	this->addRef();
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


void LocationImpl::addRef() {
	this->addRefImpl();
}

void LocationImpl::release() {
	this->releaseImpl();
}

