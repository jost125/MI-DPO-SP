/*
 * Object.h
 *
 *  Created on: 12 Sep 2010
 *      
 */

#ifndef OBJECT_H_
#define OBJECT_H_

#include <string>
#include <iostream>

using namespace std;

class Object {
private:
	string id;
protected:
	void setId(string id);
public:
	Object();
	virtual ~Object();

	string getId();
	friend ostream& operator<< (ostream &out, Object &o);
};

ostream& operator<< (ostream &out, Object &o);


#endif /* OBJECT_H_ */
