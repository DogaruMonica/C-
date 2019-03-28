#pragma once
#include "Repository.h"
#include "FileEvents.h"
#include"EventsValidator.h"
#include"EventsList.h"
class Controller
{
private:
	EventsRepository repo;
	FileEventslist* fileList;
	EventsValidator validator;

public:
	Controller(const EventsRepository& r, FileEventslist *l, EventsValidator v) : repo{ r }, fileList{ l }, validator{ v } {}


	//Returns the lsit from the eventsRepository*Administrator list*.
	std::vector<Events> getRepo() const { return repo.getEvent(); }

	//Returns the lsit from the eventList*user list*.
	std::vector<Events> getEventsList() const { return this->fileList->get(); }


	//Returns the event found with a given title and link;
	Events findEventByLinkCtrl(const std::string& link,const std::string& title);

	// Adds an event with the given data to the event repository.
	int addEventsCtrl(const std::string& title, const std::string& description, const int& day, const int& month, const int &year, const int &hour, const int &minutes, const double& peopleGoing, const  std::string &link);

	//Updates an event whith the given data to the event Repository.
	int updateCtrl(const std::string& title, const std::string& description, int day, int month, int year, int hour, int minutes, double peopleGoing, const  std::string &link);

	//Deletes an event from the event repository.
	int deleteAnEventCtrl(const std::string & link,const std::string & title);

	//Shows the list of events in the database for a given month.
    std::vector<Events> seeEventsByMonthCtrl(int month);

	//Adds an event in the event list *user list*.
	int addELCtrl(const Events &e);
	//Deletes an event from the event list * user list*.
	int deleteElCtrl(const Events & e);

	//Saves eventsList to file;
	void SaveFileList();

	void Display()const;
	void setEventsFile(const int& filemode);
};


