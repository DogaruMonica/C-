#include "EventsValidator.h"

using namespace std;

EventsException::EventsException(std::vector<std::string> _errors) : errors{ _errors }
{
}

std::vector<std::string> EventsException::getErrors() const
{
	return this->errors;
}

void EventsValidator::validate(const Events & ev)
{
	vector<string> errors;
	if (ev.getTitle().size() < 3)
		errors.push_back("The title name cannot be less than 2 characters!\n");
	if (!isupper(ev.getTitle()[0]))
		errors.push_back(string("The name of the title must start with a capital letter!\n"));
	if (ev.getDate().getDay() == 0 || ev.getDate().getMonth() == 0|| ev.getDate().getYear() == 0)
		errors.push_back(string("The date cannot be 0!\n"));

	if (ev.getTime().getMinutes() >59    )
		errors.push_back(string("The minutes cannot be greater than 59!\n"));
	if (ev.getTime().getHour() >24)
		errors.push_back(string("the hour cannot be greater than 24 hours"));
	if (ev.getTime().getMinutes() < 0 || ev.getTime().getHour() < 0)
		errors.push_back(string("the minutes or hours cannot be less than 0"));
	if(ev.getPeopleGoing()<0)
		errors.push_back(string("the no=umber of people going to the event cannot be less than 0"));

	size_t posWww = ev.getLink().find("www");
	size_t posHttp = ev.getLink().find("http");
	if (posWww != 0 && posHttp != 0)
		errors.push_back("The link source must start with one of the following strings: \"www\" or \"http\"");

	if (errors.size() > 0)
		throw EventsException(errors);
}
