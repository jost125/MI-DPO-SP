/**
 * This class CANNOT be changed!
 */
#include "midpo_utils.h"
#include "WorldFacade.h"
#include "Agent.h"
#include "assert.h"

#include <iostream>

using namespace std;

void testLocations() {
	EventLogger* logger = new EventLogger("testLocations");

	WorldFacade *world = WorldFacade::createWorldFacade(logger);
	std::cout << "tady" << std::endl;
	world->createLocation("loc1");
	std::cout << "tu" << std::endl;
	world->createLocation("loc2");
	string locationsInTheWorld = serializeStringList(world->getLocationsInWorld());
	logger->logEvent(locationsInTheWorld);
	delete world;

	int i = 0;
	assert(logger->events[i++] == EventLogger::constructorString());
	assert(logger->events[i++] == EventLogger::constructorString("loc1"));
	assert(logger->events[i++] == EventLogger::constructorString("loc2"));
	assert(logger->events[i++] == "loc1, loc2");
	assert(isEventInRange(logger->events, EventLogger::destructorString("loc1"), i, i+1));
	assert(isEventInRange(logger->events, EventLogger::destructorString("loc2"), i, i+1));
	assert(logger->events[i+2] == EventLogger::destructorString());

	delete logger;
}

void testAgentsInLocation() {
	EventLogger* logger = new EventLogger("testAgentsInLocation");
	WorldFacade* world = WorldFacade::createWorldFacade(logger);

	world->createLocation("loc1");
	world->createAgent("agent1", "loc1");
	world->createAgent("agent11", "loc1");
	logger->logEvent(serializeStringList(world->getAgentsInLocation("loc1")));
	world->createLocation("loc2");
	world->createAgent("agent2", "loc2");
	logger->logEvent(serializeStringList(world->getAgentsInLocation("loc1")));
	logger->logEvent(serializeStringList(world->getAgentsInLocation("loc2")));
	logger->logEvent(serializeStringList(world->getAgentsInWorld()));

	delete world;

	int i = 0;
	assert(logger->events[i++] == EventLogger::constructorString());
	assert(logger->events[i++] == EventLogger::constructorString("loc1"));
	assert(logger->events[i++] == EventLogger::constructorString("agent1"));
	assert(logger->events[i++] == EventLogger::constructorString("agent11"));
	assert(logger->events[i++] == "agent1, agent11");
	assert(logger->events[i++] == EventLogger::constructorString("loc2"));
	assert(logger->events[i++] == EventLogger::constructorString("agent2"));
	assert(logger->events[i++] == "agent1, agent11");
	assert(logger->events[i++] == "agent2");
	assert(logger->events[i++] == "agent1, agent11, agent2");
	assert(isEventInRange(logger->events, EventLogger::destructorString("agent1"), i, i+4));
	assert(isEventInRange(logger->events, EventLogger::destructorString("agent11"), i, i+4));
	assert(isEventInRange(logger->events, EventLogger::destructorString("loc1"), i, i+4));
	assert(isEventInRange(logger->events, EventLogger::destructorString("agent2"), i, i+4));
	assert(isEventInRange(logger->events, EventLogger::destructorString("loc2"), i, i+4));
	assert(logger->events[i+5] == EventLogger::destructorString());

	delete logger;
}

void testAgentDeletion()
{
	EventLogger* logger = new EventLogger("testAgentDeletion");
	WorldFacade* world = WorldFacade::createWorldFacade(logger);

	world->createLocation("loc1");
	world->createAgent("agent1", "loc1");
	logger->logEvent(serializeStringList(world->getAgentsInWorld()));
	world->deleteLocation("loc1");
	logger->logEvent(serializeStringList(world->getAgentsInWorld()));

	delete world;

	int i = 0;
	assert(logger->events[i++] == EventLogger::constructorString());
	assert(logger->events[i++] == EventLogger::constructorString("loc1"));
	assert(logger->events[i++] == EventLogger::constructorString("agent1"));
	assert(logger->events[i++] == "agent1");
	assert(logger->events[i++] == EventLogger::destructorString("agent1"));
	assert(logger->events[i++] == EventLogger::destructorString("loc1"));
	assert(logger->events[i++] == "");
	assert(logger->events[i++] == EventLogger::destructorString());

	delete logger;
}

void testAgentDeletion2()
{
	EventLogger* logger = new EventLogger("testAgentsDeletion2");

	{
		WorldFacade* world = WorldFacade::createWorldFacade(logger);
		AgentPointer o;

		world->createLocation("loc1");
		world->createAgent("agent1", "loc1");
		logger->logEvent(serializeStringList(world->getAgentsInWorld()));
		o = world->getAgentWithId("agent1");
		world->deleteLocation("loc1");
		logger->logEvent(o->getId());
		delete world;
		// All the variables created within this block will be removed
		//	at this place
	}

	int i = 0;
	assert(logger->events[i++] == EventLogger::constructorString());
	assert(logger->events[i++] == EventLogger::constructorString("loc1"));
	assert(logger->events[i++] == EventLogger::constructorString("agent1"));
	assert(logger->events[i++] == "agent1");
	assert(logger->events[i++] == EventLogger::destructorString("loc1"));
	assert(logger->events[i++] == "agent1");
	assert(logger->events[i++] == EventLogger::destructorString());

	delete logger;
}

int main() {
	testLocations();

	testAgentsInLocation();

	testAgentDeletion();

	//For naive implementation this finish with seg fault
	testAgentDeletion2();

	cout << "FINISHED" << endl;

	return 0;
}

