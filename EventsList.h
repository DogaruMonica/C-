#pragma once
#include"Events.h"
#include <vector>



class EventsList
{
protected:
	std::vector<Events> eventl;

public:

	//Events list *user list* constructor.
	EventsList() {};

	//Returns the position of an event in the list; -1 noth found,the position otherwise.
	int findPosition(const Events &e);

	//Adds an event to the list,if the event is already in the list it will not be added and returns 0 and  it returns 1 othrwise.
	//Also increases the number of people going with one person.
	int  addEL(const Events &ev);

	//Deletes an event from the list, returns -1 if the event is not in the list and 1 otherwise.
	//Also decreases the number of people going with one person.
	int deleteEL(const Events &ev);

	//Returns the list of Events the user attends.
	std::vector<Events> get()const { return eventl; }

	virtual ~EventsList() {}
};


