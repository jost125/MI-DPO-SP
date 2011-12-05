/*
 * loggable.h
 *
 *  Created on: 12 Sep 2010
 */

#ifndef LOGGABLE_H_
#define LOGGABLE_H_

#include "EventLogger.h"

class Loggable {
private:
	EventLogger* logger;
public:
	virtual void acceptLogger(EventLogger* newLogger) { logger = newLogger; }
	virtual EventLogger* getLogger() { return logger; }
};

#endif /* LOGGABLE_H_ */
