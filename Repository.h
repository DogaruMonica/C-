#pragma once

#include "Events.h"
#include <vector>


class EventsRepository
{
private:
	std::vector<Events> event;
	std::string filename;

public:
	/*
	Default constructutor.
	Initializes an object of type repository.
	*/
	EventsRepository(const std::string filename);

	/*
	Adds en event to the repository.
	Input: e-event.
	Output: the event is added to the repository.
	*/
	int addEvent(const Events & e);

	/*
	Finds an event, by link of the event and title;
	Input: link, title - string
	Output: 1 if the event was addend,0 otherwise;
	*/
	Events findEventByLink(const std::string& link, const std::string& title);

	/*
	Returns an event from the dynamicVector;
	Input:-
	Output: the event;
	*/
	std::vector<Events> getEvent() const { return event; }

	/*
	Updates an event with the coresponding given data;
	input: a data of type event ;
	output:1 if the event was updated,0 otherwise;
	*/
	int updateEventRepo(const Events & e);
	/*
	Deletes an event from the dynamicVector;
	input:link-string,the link of the event,title-string,tetitle of the event;
	output:1 if the event was deleted,0 otherwise;
	*/
	int DeleteAnEvent(const std::string &title, const std::string &link);

	/*
	Finds the position of an event in the dynamicVector;
	input:link-string,the link of the event,title-string,tetitle of the event;
	output:-1 if the event was not found ,the position of the event otherwise;
	*/
	int findPosition(const std::string& link, const std::string& title);

	/*
	Increases the number of people going to an event.
	Input:e-envent
	Output-nothing.
	*/
	void increaseAdm(const Events &e);

	/*
	Decreases the number of people which are going to an event.
	Input:e-event,the event we want to decrease
	Output: -1 if the event is not in the list of events,1 otherwise.
	*/
	int decrease(const Events & e);

	/*
	Sorts the events repository list cronologically
	Input:nothing
	Output:list-type of dynamic vector list sorted.
	*/
	std::vector<Events> ascendingSort();

	/*
	Finds the events which happends in a given month and returns a list with those events,if te month is-1 then the Events repository list is sorted cronologically
	Input:month-integer,represents the month when the event takes place.
	Output:the list of events(sorted or not,or from a given month or not).
	*/
	std::vector<Events> seeEventsByMonth(int month);
private:
	void readFromFile();
	void writeToFile();

};