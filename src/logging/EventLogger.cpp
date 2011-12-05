/*
 * EventLogger.cpp
 *
 *  Created on: 12 Sep 2010
 */

#include "EventLogger.h"

#include <iostream>

#define DEBUG_OUTPUT

using namespace std;

const string EventLogger::CONSTRUCTOR_STRING = "CONSTRUCTOR";
const string EventLogger::DESTRUCTOR_STRING = "DESTRUCTOR";

EventLogger::EventLogger(string name) {
	this->name = name;
	cout << "EventLogger created for: " << name << endl;
}

EventLogger::~EventLogger() {
	cout << "EventLogger destructed for: " << name << endl;
}

StringVector EventLogger::getEvents()
{
	return events;
}

void EventLogger::logEvent(string event)
{
#ifdef DEBUG_OUTPUT
	cout << "logging: " + event << endl;
#endif /* DEBUG_OUTPUT */
	events.push_back(event);
}

string EventLogger::constructorString(string name)
{
	string s = CONSTRUCTOR_STRING;
	s += " " + name;
	return s;
}

string EventLogger::destructorString(string name)
{
	string s = DESTRUCTOR_STRING;
	s += " " + name;
	return s;
}

string EventLogger::constructorString()
{
	string s = CONSTRUCTOR_STRING;
	return s;
}

string EventLogger::destructorString()
{
	string s = DESTRUCTOR_STRING;
	return s;
}

