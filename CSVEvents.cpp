#include "CSVEvents.h"
#include <fstream>
#include <Windows.h>
#include "RepositoryExceptions.h"

using namespace std;

void CSVEventslist::writeToFile()
{
	ofstream f(this->filename);

	if (!f.is_open())
		throw FileException("The file could not be opened!");

	for (auto s : this->eventl)
		f << s;

	f.close();
}

void CSVEventslist::displayEventlist() const
{
	string aux = "\"" + this->filename + "\""; 
	ShellExecuteA(NULL, NULL, "notepad.exe", "CSVEvents.csv", NULL, SW_SHOWMAXIMIZED);
}
