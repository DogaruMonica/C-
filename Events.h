#pragma once
#include <iostream>
#include <sstream>
class Date
{
private:
	int day;
	int month;
	int year;

public:
	//Constructor for Date.
	Date() : day(0), month(0), year(0) {}
	//Another constructor for Date.
	Date(int day, int month, int year) : day(day), month(month), year(year) {}

	//Returns the day.
	int getDay() const { return day; }

	//Returns the month.
	int getMonth() const { return month; }

	//Returns the year.
	int getYear() const { return year; }

	//Sets the day with a new value.
	void setDay(int d) { day = d; }

	//Sets the month with a new value.
	void setMonth(int m) { month = m; }

	//Sets the year with a new value.
	void setYear(int y) { year = y; }
};

class Time
{
private:
	int hour;
	int minutes;
public:
	//Constructor for time,it represents the hour and the minutes;
	Time() :hour(0), minutes(0) {}

	//Another constructor for time.
	Time(int h, int m) : hour(h), minutes(m) {}

	//Returns the hour.
	int getHour()  const { return hour; }

	//Returns the minutes.
	int getMinutes() const { return minutes; }

	//Stes the hour with a new value.
	void setHour(int h) { hour = h; }

	//Sets the minutes with a new value.
	void setMinutes(int m) { minutes = m; }

};
class Events
{
private:
	std::string title;
	std::string description;
	Date date;
	Time time;
	double peopleGoing;
	std::string link;
public:

	//Constructor for Events.
	Events();

	//Another constructor for Events.
	Events(const std::string& title, const std::string& description, const Date& date, const Time & time, const double& PeopleGoing, const std::string &link);

	//Returns the title of an event.
	std::string getTitle()const { return title; };

	//Returns the description of an event.
	std::string getDescription() const { return description; }

	//Returns the Date.
	Date getDate() const { return date; }

	//Returns the Time.
	Time getTime() const { return time; }

	//Returns the number of people who ar participating to te event.
	double getPeopleGoing()const { return peopleGoing; }

	//Sets the number of people going with a new value.
	void setPeopleGoing(double people) { peopleGoing = people; }

	//Returns the link of the event.
	std::string getLink()const { return link; }

	//Opens a browser file with the link of the event.
	void see();


	friend std::istream& operator>>(std::istream& is, Events & ev);
	friend std::ostream& operator<<(std::ostream& os, const Events & ev);
	std::string tostring();
};