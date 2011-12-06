/*
 * Agent.h
 *
 *  Created on: 6 Sep 2010
 *      
 */

#ifndef AGENT_H_
#define AGENT_H_

#include "logging/Loggable.h"
#include "Object.h"
#include <string>

using namespace std;


class Agent: public Loggable, public Object {
public:
	Agent(EventLogger* logger, string name);
	virtual ~Agent();

	string getName();
	void setName(string newName);

private:
};

#endif /* AGENT_H_ */
