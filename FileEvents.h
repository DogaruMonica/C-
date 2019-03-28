#pragma once
#include "EventsList.h"

class FileEventslist : public EventsList
{
protected:
	std::string filename;

public:
	FileEventslist(const std::string& filename);
	virtual ~FileEventslist() {}

	virtual void writeToFile() = 0;
	virtual void displayEventlist() const = 0;
};

