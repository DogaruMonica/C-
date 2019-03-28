#include"EventsList.h"
#include"Events.h"

#include<vector>



int EventsList::findPosition(const Events &e)
{

	int i = 0;
	for (auto elem :  this->eventl)
	{
	
		if (elem.getLink() == e.getLink() && elem.getTitle() == e.getTitle())

			return i;
		i++;
	}
	return -1;
}
int EventsList::deleteEL(const Events& ev)
{
	int i = this->findPosition(ev);
	if (i == -1)
		return -1;


	this->eventl.erase(this->eventl.begin()+i);
	return 1;


}
int EventsList::addEL(const Events&  ev)
{
	int i = this->findPosition(ev);
	if (i != -1)
		return 0;
	int pos = eventl.size();

	this->eventl.push_back(ev);
	eventl[pos].setPeopleGoing(ev.getPeopleGoing() + 1);

	return 1;
}