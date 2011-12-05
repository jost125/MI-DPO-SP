/*
 * WorldFacadeImpl.cpp
 *
 *  Created on: 10 Sep 2010
 *      
 */

#include "WorldFacadeNaiveImpl.h"
#include <iostream>

using namespace std;


WorldFacadeNaiveImpl::WorldFacadeNaiveImpl(EventLogger* logger) {
	cout << "Naive Implementation Of World Facade created!" << endl;
	acceptLogger(logger);
	getLogger()->logEvent(EventLogger::constructorString());
}

void WorldFacadeNaiveImpl::freeUpLocations()
{
    for(LocationMap::iterator it = locations.begin();it != locations.end();it++)
    {
    	delete it->second;
    }
}

WorldFacadeNaiveImpl::~WorldFacadeNaiveImpl() {
    freeUpLocations();
	getLogger()->logEvent(EventLogger::destructorString());
}

void WorldFacadeNaiveImpl::createLocation(string lName)
{
	LocationNaive* l = new LocationNaive(getLogger(), lName);
	locations[lName] = l;
}

void WorldFacadeNaiveImpl::deleteLocation(string lName)
{
	delete locations[lName];
	locations.erase(lName);
}

void WorldFacadeNaiveImpl::createAgent(string aName, string lName)
{
	Agent* a = new Agent(getLogger(), aName);
	locations[lName]->agentEnters(a);
}

AgentPointer WorldFacadeNaiveImpl::getAgentWithId(string id)
{
	return (AgentPointer)findAgentByName(id);

}


//Object* WorldFacadeNaiveImpl::getObjectWithId(string id)
//{
//	if (locations.find(id) != locations.end())
//	{
//		return locations[id];
//	}
//	return findAgentByName(id);
//
//}


Agent* WorldFacadeNaiveImpl::findAgentByName(string name)
{
	for (LocationMap::const_iterator it = locations.begin(); it != locations.end(); it++)
	{
		LocationNaive* location = it->second;
		//cout << "FOUND LOCATION: " << *location << endl;

		AgentList agentsInside = location->agentsInside();
		for (AgentList::const_iterator it2 = agentsInside.begin(); it2 != agentsInside.end(); it++)
		{
			Agent* agent = *it2;
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


StringList WorldFacadeNaiveImpl::getAgentsInLocation(string lName)
{
	AgentList agentsInside = locations[lName]->agentsInside();
	list<string> l;

	for(AgentList::iterator iter=agentsInside.begin(); iter != agentsInside.end(); iter++)
	{
		l.push_back((*iter)->getName());
	}

	return l;
}

StringList WorldFacadeNaiveImpl::getLocationsInWorld()
{
	StringList l;
	for (LocationMap::const_iterator it = locations.begin(); it != locations.end(); it++)
	{
		l.push_back(it->second->getName());
	}
	return l;
}

StringList WorldFacadeNaiveImpl::getAgentsInWorld()
{
	StringList l;
	cout << "locsInWorld size: " << locations.size() << endl;

	for (LocationMap::const_iterator it =locations.begin(); it != locations.end(); it++)
	{
		LocationNaive* location = it->second;
		list<Agent*> agentsInside = location->agentsInside();

		for (list<Agent*>::const_iterator it2 = agentsInside.begin(); it2 != agentsInside.end(); it2++)
		{
			Agent* agent = *it2;
			l.push_back(agent->getName());
		}
	}
	cout << "locsInWorld size: " << locations.size() << endl;
	return l;
}
