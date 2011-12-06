/*
 * Room.h
 *
 *  Created on: 7 Sep 2010
 *      
 */

#ifndef ROOM_H_
#define ROOM_H_

#include "Object.h"
#include "logging/Loggable.h"
#include "logging/EventLogger.h"
#include <map>
#include <list>
#include <string>
#include "Agent.h"

using namespace std;

class Location:  public Loggable, public Object {
private:
public:
	Location(EventLogger* logger, string s);
	virtual ~Location();

	string getName();


	virtual void setName(string newName);
};

#endif /* ROOM_H_ */
