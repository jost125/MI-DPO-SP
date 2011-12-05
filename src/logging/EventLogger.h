/*
 * EventLogger.h
 *
 *  Created on: 12 Sep 2010
 */

#ifndef EVENTLOGGER_H_
#define EVENTLOGGER_H_

//#include "../midpo_utils.h"
#include <list>
#include <string>
#include <vector>

using namespace std;

typedef list<string> StringList;
typedef vector<string> StringVector;

class EventLogger {
private:
	string name;
	static const string CONSTRUCTOR_STRING;
	static const string DESTRUCTOR_STRING;

public:
	StringVector events;

	EventLogger(string name);
	virtual ~EventLogger();


	void logEvent(string event);
	void logEvent(string event, string name);
	StringVector getEvents();

	static string constructorString();

	static string destructorString();

	static string constructorString(string name);

	static string destructorString(string name);

};

#endif /* EVENTLOGGER_H_ */
