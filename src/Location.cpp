/*
 * Room.cpp
 *
 *  Created on: 7 Sep 2010
 *      
 */

#include "Location.h"
#include <iostream>
using namespace std;

Location::Location(EventLogger* logger, string name) {
	setName(name);
	acceptLogger(logger);
	getLogger()->logEvent(EventLogger::constructorString(getName()));
}

Location::~Location() {
	getLogger()->logEvent(EventLogger::destructorString(getName()));
}

string Location::getName()
{
	return getId();
}

void Location::setName(string name)
{
	setId(name);
}


