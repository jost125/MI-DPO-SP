/*
 * RefCounter.h
 *
 *  Created on: Dec 6, 2011
 *      Author: honza
 */

#ifndef REFCOUNTER_H_
#define REFCOUNTER_H_

class RefCounter {
public:
	RefCounter();
protected:
	void addRefImpl();
	void releaseImpl();
	virtual ~RefCounter();
private:
	int count;
};

#endif /* REFCOUNTER_H_ */
