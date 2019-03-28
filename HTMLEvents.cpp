#include "HTMLEvents.h"
#include <fstream>
#include <Windows.h>
#include "RepositoryExceptions.h"

using namespace std;

void HTMLEvents::writeToFile()
{

	ofstream f(this->filename);

	f << "<!DOCTYPE html><html><title>HTMLEvent</title><head></head><body>";
	f << "<table border = " << 1 << "><tr><td>Title</td><td>Description</td><td>Time</td><td>Date</td><td>People Going</td><td>Link</td></tr>";

	if (!f.is_open())
		throw FileException("The file could not be opened!");

	for (auto s : this->eventl)
	{if (s.getTime().getMinutes()==0)
		f << "<tr><td>" << s.getTitle() << "</td><td>" << s.getDescription() << "</td><td>" << s.getTime().getHour() << ": 00 "  << "</td><td>" << s.getDate().getDay() << "." << s.getDate().getMonth() << "." << s.getDate().getYear() << "</td><td>" << s.getPeopleGoing() << "</td><td><a href =" << s.getLink() << ">Link</a></tr>";
	else
		f << "<tr><td>" << s.getTitle() << "</td><td>" << s.getDescription() << "</td><td>"  << s.getTime().getHour()<<": "<< s.getTime().getMinutes()<< "</td><td>" << s.getDate().getDay() << "."<<s.getDate().getMonth()<< "."<<s.getDate().getYear()<< "</td><td>"<<s.getPeopleGoing()<< "</td><td><a href ="<<s.getLink()<<">Link</a></tr>";
	}

	f << "</table></body></html>";

	f.close();
}

void HTMLEvents::displayEventlist() const
{
	string aux = "\"" + this->filename + "\"";
	ShellExecuteA(NULL, NULL, "chrome.exe", "HTMLEvent.html", NULL, SW_SHOWMAXIMIZED);
}
