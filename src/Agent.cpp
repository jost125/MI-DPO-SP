/*
 * Agent.cpp
 *
 *  Created on: 6 Sep 2010
 *      
 */

#include "Agent.h"
#include <iostream>

using namespace std;

Agent::Agent(EventLogger* logger, string name) {
	setName(name);
	setId(name);
	acceptLogger(logger);
	getLogger()->logEvent(EventLogger::constructorString(getName()));
	this->addRef();
}

Agent::~Agent() {
	getLogger()->logEvent(EventLogger::destructorString(getName()));
	this->release();
}

string Agent::getName()
{
	return getId();
}

void Agent::setName(string name)
{
	setId(name);
}

void Agent::addRef() {
	this->addRefImpl();
}

void Agent::release() {
	this->releaseImpl();
}
