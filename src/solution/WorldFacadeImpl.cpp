/*
 * WorldFacadeImpl.cpp
 *
 *  Created on: 10 Sep 2010
 *      
 */

#include "WorldFacadeImpl.h"
#include <iostream>

using namespace std;


WorldFacadeImpl::WorldFacadeImpl(EventLogger* logger) {
	acceptLogger(logger);
	getLogger()->logEvent(EventLogger::constructorString());
}

/**
 * Unfortunately the tests in Main.cpp expects deleting of elements in ordered way :-(, so
 * method creates vector, goes through locations and delete them in that order.
 */
void WorldFacadeImpl::freeUpLocations() {
	vector<string> keys = vector<string>();
	for(LocationMap::iterator it = locations.begin();it != locations.end();it++)
	{
		keys.push_back(it->first);
	}

	for (vector<string>::iterator it = keys.begin(); it != keys.end(); it++) {
		locations.erase(*it);
	}

}

WorldFacadeImpl::~WorldFacadeImpl() {
	freeUpLocations();
	getLogger()->logEvent(EventLogger::destructorString());
}

void WorldFacadeImpl::createLocation(string lName)
{
	locations[lName] = new LocationImpl(getLogger(), lName);;
}

void WorldFacadeImpl::deleteLocation(string lName)
{
	locations.erase(lName);
}

void WorldFacadeImpl::createAgent(string aName, string lName)
{
	locations[lName]->agentEnters(new Agent(getLogger(), aName));
}

AgentPointer WorldFacadeImpl::getAgentWithId(string id)
{
	return (AgentPointer)findAgentByName(id);
}

AgentPointer WorldFacadeImpl::findAgentByName(string name)
{
	for (LocationMap::const_iterator it = locations.begin(); it != locations.end(); it++)
	{
		LocationPtr location = it->second;
		//cout << "FOUND LOCATION: " << *location << endl;

		AgentList agentsInside = location->agentsInside();
		for (AgentList::const_iterator it2 = agentsInside.begin(); it2 != agentsInside.end(); it++)
		{
			SmartPointer<Agent> agent = *it2;
			//cout << "FOUND AGENT: " << *agent << endl;
			if (name == agent->getName())
			{
				//cout << "AGENT MATCH NAME: " << name << endl;
				return agent;
			}
		}
	}
	return NULL;
}


StringList WorldFacadeImpl::getAgentsInLocation(string lName)
{
	AgentList agentsInside = locations[lName]->agentsInside();
	list<string> l;

	for(AgentList::iterator iter=agentsInside.begin(); iter != agentsInside.end(); iter++)
	{
		l.push_back((*iter)->getName());
	}

	return l;
}

StringList WorldFacadeImpl::getLocationsInWorld()
{
	StringList l;
	for (LocationMap::iterator it = locations.begin(); it != locations.end(); it++)
	{
		l.push_back(it->second->getName());
	}
	return l;
}

StringList WorldFacadeImpl::getAgentsInWorld()
{
	StringList l;
	cout << "locsInWorld size: " << locations.size() << endl;

	for (LocationMap::const_iterator it =locations.begin(); it != locations.end(); it++)
	{
		LocationPtr location = it->second;
		list<AgentPointer> agentsInside = location->agentsInside();

		for (list<AgentPointer>::const_iterator it2 = agentsInside.begin(); it2 != agentsInside.end(); it2++)
		{
			AgentPointer agent = *it2;
			l.push_back(agent->getName());
		}
	}
	cout << "locsInWorld size: " << locations.size() << endl;
	return l;
}
