/*
 * SmartPointer.h
 *
 *  Created on: Dec 5, 2011
 *      Author: honza
 */

#ifndef SMARTPOINTER_H_
#define SMARTPOINTER_H_

#include <iostream>

template <class T> class SmartPointer {
private:
	T* pointer;
public:
	SmartPointer(T* pointer = 0) {
		std::cout << "constructing pointer " << pointer << std::endl;
		this->pointer = pointer;
	}

	SmartPointer(const SmartPointer<T>& smartPointer) : pointer(smartPointer.pointer) {
	}

	~SmartPointer() {
		delete pointer;
	}

	T& operator * () {
		return *pointer;
	}

	T* operator -> () {
		return pointer;
	}

	SmartPointer<T>& operator=(const SmartPointer<T>& smartPointer) {
		if (this != &smartPointer) {
			this->pointer = smartPointer.pointer;
		}
		return *this;
	}

	bool operator==(const SmartPointer<T>& smartPointer) {
		std::cout << "comparing pointer" << std::endl;
		return this->pointer == smartPointer.pointer;
	}
};

#endif /* SMARTPOINTER_H_ */
