/*
 * WorldFacade.cpp
 *
 *  Created on: 6 Sep 2010
 *      
 */

#include "midpo_utils.h"

string serializeStringList(StringList list)
{
	string s = "";
	if (list.size() == 0) return s;

	s += *list.begin();

	for (StringList::const_iterator it = ++list.begin(); it != list.end(); it++)
	{
		s += ", " + *it;
	}
	return s;
}

bool isEventInRange(StringVector events, string event, int from, int to)
{
	for (int i = from; i <= to; i++)
	{
		if (events[i] == event)
		{
			return true;
		}
	}
	return false;
}
