/*
 * SmartPointer.h
 *
 *  Created on: Dec 5, 2011
 *      Author: honza
 */

#ifndef SMARTPOINTER_H_
#define SMARTPOINTER_H_

#include <iostream>

/**
 * Generic smart pointer with internal reference counting. (Intrusive pointer)
 *
 * According to http://www.cplusplus.com/doc/tutorial/templates/ the implementation
 * of generic classes has to be inside header files because of limitations of compiler.
 */

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
	/**
	 * Normal constuctor.
	 */
	SmartPointer(T* pointer = 0) : counter(0) {
		if (pointer) {
			this->counter = new Counter(pointer);
		}
	}

	/**
	 * Copy constructor.
	 */
	SmartPointer(const SmartPointer<T>& smartPointer) {
		this->addRef(smartPointer.counter);
	}

	/**
	 * Destruct (releases pointer)
	 */
	~SmartPointer() {
		this->release();
	}

	/**
	 * Operator dereference.
	 */
	T& operator * () {
		return *this->counter->pointer;
	}

	/**
	 * Operator ->
	 */
	T* operator -> () {
		return this->counter->pointer;
	}

	/**
	 * Operator assign
	 */
	SmartPointer<T>& operator=(const SmartPointer<T>& smartPointer) {
		if (this != &smartPointer) {
			this->release();
			this->addRef(smartPointer.counter);
		}
		return *this;
	}

	/**
	 * Operator compare
	 */
	bool operator==(const SmartPointer<T>& smartPointer) {
		return this->counter->pointer == smartPointer.counter->pointer;
	}
};

#endif /* SMARTPOINTER_H_ */
