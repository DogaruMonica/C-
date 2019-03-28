#include "Events.h"
#include <Windows.h>
#include <shellapi.h>
#include <iostream>
#include "Utils.h"
#include <vector>
using namespace std;
Events::Events() : title(""), description(""), date(Date()), time(Time()), peopleGoing(0), link("") {}

Events::Events(const std::string &title, const std::string& description, const Date& date, const Time & time, const double& peopleGoing, const std::string& link)
{
	this->title = title;
	this->description = description;
	this->date = date;
	this->time = time;
	this->peopleGoing = peopleGoing;
	this->link = link;
}

void Events::see()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getLink().c_str(), NULL, SW_SHOWMAXIMIZED);
}

std::string Events::tostring()
{
	 std::stringstream s;
	 s << this->title << " | " << this->description << " | " << this->time.getHour()<<" : "<<this->time.getMinutes() << " | " << this->date.getDay()<<"."<<this->date.getMonth()<<"."<<this->date.getYear() << " | " << this->peopleGoing << " | " << this->link;
	 return std::string(s.str());
}

std::istream & operator>>(std::istream & is, Events & ev)
{
	std::string line;
	getline(is, line);

	std::vector<std::string> tokens = tokenize(line, ',');
	if (tokens.size() != 6) 
		return is;

	ev.title = tokens[0];
	ev.description = tokens[1];


	std::vector<std::string> dateTokens = tokenize(tokens[2], '.');
	if (dateTokens.size() != 3)
		return is;
	ev.date = Date{ stoi(dateTokens[0]), stoi(dateTokens[1]) , stoi(dateTokens[2]) };

	std::vector<std::string> durationTokens = tokenize(tokens[3], ':');
	if (durationTokens.size() != 2)
		return is;
	ev.time = Time{ stoi(durationTokens[0]), stoi(durationTokens[1]) };
	
	ev.peopleGoing =stod( tokens[4]);
	ev.link = tokens[5];

	return is;

}

std::ostream & operator<<(std::ostream & os, const Events & ev)
{
	os << ev.title << "," << ev.description << "," << ev.date.getDay() << "." << ev.date.getMonth() << "." << ev.date.getYear() <<","<<ev.time.getHour()<<":"<<ev.time.getMinutes()<<","<<ev.peopleGoing<<","<<ev.link<<"\n";
	return os;
}
