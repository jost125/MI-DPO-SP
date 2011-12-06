/*
 * IRefCounter.h
 *
 *  Created on: Dec 5, 2011
 *      Author: honza
 */

#ifndef IREFCOUNTER_H_
#define IREFCOUNTER_H_

class IRefCounter {
public:
	virtual void addRef() = 0;
	virtual void release() = 0;
protected:
	virtual ~IRefCounter();
};

#endif /* IREFCOUNTER_H_ */
