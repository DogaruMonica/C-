#include "Repository.h"
#include"Events.h"
#include <string>
#include<stdio.h>
#include <vector>
#include<fstream>
#include<algorithm>
#include"RepositoryExceptions.h"
using namespace std;
EventsRepository::EventsRepository(const std::string filename)
{
	this->filename = filename;
	this->readFromFile();
}

std::vector<Events> EventsRepository::ascendingSort()
{
	int i = 0;
	int j = 1;
	Events aux{};
	
	sort(event.begin(), event.end(), [](const  Events &e1,const  Events & e2) {return  ((e1.getDate().getYear() <e2.getDate().getYear()) || (e1.getDate().getYear() == e2.getDate().getYear() && e1.getDate().getMonth() < e2.getDate().getMonth()) || (e1.getDate().getMonth() == e2.getDate().getMonth() && e1.getDate().getDay() < e2.getDate().getDay())); });
	//while (i != event.size() - 1)
	//{

	//	if ((this->event[i].getDate().getYear() > this->event[j].getDate().getYear()) || (this->event[i].getDate().getYear() == this->event[j].getDate().getYear() && this->event[i].getDate().getMonth() > this->event[j].getDate().getMonth()) || (this->event[i].getDate().getMonth() == this->event[j].getDate().getMonth() && this->event[i].getDate().getDay() > this->event[j].getDate().getDay()))
	//	{
	//		aux = event[i];
	//		event[i] = event[j];
	//		event[j] = aux;
	//	}
	//	i++;
	//	j++;
	//}
	return this->event;
}
std::vector<Events>  EventsRepository::seeEventsByMonth(int month)
{
	if (month == -1)

		return this->ascendingSort();

	std::vector<Events> list{};
	//for (auto elem: this->event)
	//	if (elem.getDate().getMonth() == month)
	//		list.push_back(elem);
	copy_if(event.begin(), event.end(), std::back_inserter(list), [month](Events e) {return e.getDate().getMonth() < month; });
	return list;
}


int EventsRepository::addEvent(const Events& e)
{
	int pos = this->findPosition(e.getLink(), e.getTitle());
	if (pos == -1)
	{
		this->event.push_back(e);
		this->writeToFile();
		return 1;
	}
	return 0;
}

Events EventsRepository::findEventByLink(const std::string& link, const std::string& title)
{



	for (auto elem: this->event)
	{
		if (elem.getLink() == link && elem.getTitle() == title)
			return elem;
	}

	return Events{};
}
void EventsRepository::increaseAdm(const Events& e)
{
	int i = this->findPosition(e.getLink(), e.getTitle());
	if(i!=-1)
	event[i].setPeopleGoing(e.getPeopleGoing() + 1);
}
int EventsRepository::decrease(const Events& e)
{
	int i = this->findPosition(e.getLink(), e.getTitle());
	if (i == -1)
		return -1;

	event[i].setPeopleGoing(e.getPeopleGoing() - 1);
	
	return 1;

}

int EventsRepository::findPosition( const std::string& link,const  std::string& title)
{
	int i = 0;
		for (auto elem:this->event)
		{
			
			if (elem.getLink() == link && elem.getTitle() == title)

				return i;
			i++;
		}

		return -1;
	
}


int EventsRepository::updateEventRepo(const  Events & e)
{
	int pos = this->findPosition(e.getLink(), e.getTitle());

	if (pos == -1)
		return 0;

	event[pos]=e;
	this->writeToFile();
			return 1;
		
}

int EventsRepository::DeleteAnEvent(const std::string& title, const std::string &link)
{
	int pos = this->findPosition(link, title);
	if (pos == -1)
		return 0;

	this->event.erase(this->event.begin() + pos );
	this->writeToFile();
	return 1;


}

void EventsRepository::readFromFile()
{
	ifstream file(this->filename);

	if (!file.is_open())
		throw FileException("The file could not be opened!");

	Events ev;
	while (file >> ev)
		this->event.push_back(ev);

	file.close();
}

void EventsRepository::writeToFile()
{
	ofstream file(this->filename);
	if (!file.is_open())
		throw FileException("The file could not be opened!");

	for (auto ev : this->event)
	{
		file << ev;
	}

	file.close();
}
