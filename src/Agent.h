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
#include "solution/RefCounter.h"
#include "solution/ITarget.h"
#include <string>

using namespace std;


class Agent: public Loggable, public Object, public RefCounter, public ITarget {
public:
	Agent(EventLogger* logger, string name);
	virtual ~Agent();

	string getName();
	void setName(string newName);

	virtual void addRef();
	virtual void release();
private:
};

#endif /* AGENT_H_ */
