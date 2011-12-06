/*
 * RefCounter.cpp
 *
 *  Created on: Dec 6, 2011
 *      Author: honza
 */

#include "RefCounter.h"
#include <iostream>

RefCounter::RefCounter() {

}

RefCounter::~RefCounter() {

}

void RefCounter::addRefImpl() {
	std::cout << "adding reference" << std::endl;
	count++;
}

void RefCounter::releaseImpl() {
	std::cout << "releasing reference" << std::endl;
	if (--count == 0) {
		std::cout << "deleting" << std::endl;
		delete this;
	}
}
