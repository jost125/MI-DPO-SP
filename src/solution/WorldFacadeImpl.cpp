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

//void WorldFacadeImpl::freeUpLocations()
//{
//		for(LocationMap::iterator it = locations.begin();it != locations.end();it++)
//	{
//		delete it->;
//	}
//}

WorldFacadeImpl::~WorldFacadeImpl() {
//    freeUpLocations();
	getLogger()->logEvent(EventLogger::destructorString());
}

void WorldFacadeImpl::createLocation(string lName)
{
	LocationPtr l = new LocationImpl(getLogger(), lName);
	std::cout << "mezi" << std::endl;
	locations[lName] = l;
	std::cout << "po" << std::endl;

}

void WorldFacadeImpl::deleteLocation(string lName)
{
	locations.erase(lName);
}

void WorldFacadeImpl::createAgent(string aName, string lName)
{
	SmartPointer<Agent> a = new Agent(getLogger(), aName);
	locations[lName]->agentEnters(a);
}

AgentPointer WorldFacadeImpl::getAgentWithId(string id)
{
	return (AgentPointer)findAgentByName(id);
}


//Object* WorldFacadeImpl::getObjectWithId(string id)
//{
//	if (locations.find(id) != locations.end())
//	{
//		return locations[id];
//	}
//	return findAgentByName(id);
//
//}


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
