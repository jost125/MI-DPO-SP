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
	/**
	 * Reference counter.
	 */
	struct Counter {
		T* pointer;
		unsigned int count;

		Counter(T* pointer = 0, unsigned int count = 1) : pointer(pointer), count(count) {}
	}* counter;

	/**
	 * Adding reference and increment counter.
	 */
	void addRef(Counter* counter) {
		this->counter = counter;
		if (this->counter) {
			this->counter->count++;
		}
	}

	/**
	 * Release reference and decrement counter. If its zero, delete it.
	 */
	void release() {
		if (this->counter) {
			if (--this->counter->count == 0) {
				delete this->counter->pointer;
				delete this->counter;
			}

			this->counter = 0;
		}
	}

public:
	SmartPointer(T* pointer = 0) : counter(0) {
		if (pointer) {
			this->counter = new Counter(pointer);
		}
	}

	SmartPointer(const SmartPointer<T>& smartPointer) {
		this->addRef(smartPointer.counter);
	}

	~SmartPointer() {
		this->release();
	}

	T& operator * () {
		return *this->counter->pointer;
	}

	T* operator -> () {
		return this->counter->pointer;
	}

	SmartPointer<T>& operator=(const SmartPointer<T>& smartPointer) {
		if (this != &smartPointer) {
			this->release();
			this->addRef(smartPointer.counter);
		}
		return *this;
	}

	bool operator==(const SmartPointer<T>& smartPointer) {
		return this->counter->pointer == smartPointer.counter->pointer;
	}
};

#endif /* SMARTPOINTER_H_ */
