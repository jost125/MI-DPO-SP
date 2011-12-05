/*
 * Object.cpp
 *
 *  Created on: 12 Sep 2010
 *      
 */

#include "Object.h"

using namespace std;

Object::Object() {
}

Object::~Object() {
}

string Object::getId()
{
	return id;
}

void Object::setId(string id)
{
	this->id = id;
}


ostream& operator<<(ostream &out, Object &o) {
	out << "@Object id: " << o.getId();
	return out;
}
