#include "Controller.h"
#include"EventsValidator.h"
#include"CSVEvents.h"
#include"HTMLEvents.h"

int Controller::addEventsCtrl(const std::string & title,const std::string& description,const int& day,const int& month,const int& year,const int& hour,const int& minutes,const double &peopleGoing,const  std::string&link)
{
	Events e{ title,description, Date{ day,month,year },Time{ hour,minutes },peopleGoing,link };
	this->validator.validate(e);
	int res = this->repo.addEvent(e);



	return res;
}

int Controller::updateCtrl(const std::string& title, const std::string& description, int day, int month, int year, int hour, int minutes, double peopleGoing, const  std::string &link)
{
	Events ev{ title,description, Date{ day,month,year },Time{ hour,minutes },peopleGoing,link };
	this->validator.validate(ev);
	int res= this->repo.updateEventRepo(ev);

	return res;

}


Events Controller::findEventByLinkCtrl( const std::string& link, const  std::string& title)
{
	return this->repo.findEventByLink(link, title);
}

int Controller::deleteAnEventCtrl(const std::string & link,const std::string & title)
{
	int res= this->repo.DeleteAnEvent(title, link);

	return res;
}


int Controller::addELCtrl(const Events & e)
{int res= this->fileList->addEL(e);
	this->repo.increaseAdm(e);
	this->validator.validate(e);

	return res;

}
int Controller::deleteElCtrl(const  Events & e)
{
	int res= this->fileList->deleteEL(e);
	if (res!=-1)
	this->repo.decrease(e);
	this->validator.validate(e);

	return res;

}
void Controller::SaveFileList()
{
	if (this->fileList == nullptr)
		return;

	this->fileList->writeToFile();
}
void Controller::Display() const
{
	if (this->fileList == nullptr)
		return;
	this->fileList->displayEventlist();
}
std::vector<Events> Controller::seeEventsByMonthCtrl(int month)
{
	return this->repo.seeEventsByMonth(month);
}
void Controller::setEventsFile(const int& filemode)
{
	if (filemode == 1)
		this->fileList = new CSVEventslist{ "CSVEvents.csv" };
	else
		this->fileList = new HTMLEvents{ "HTMLEvent.html" };
}