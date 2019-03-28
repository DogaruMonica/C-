#pragma once
#include "FileEvents.h"
#include <string>

class CSVEventslist : public FileEventslist
{
public:
	CSVEventslist(const std::string& filename) : FileEventslist{ filename } {}

	/*
	Writes the eventsList to file.
	Throws: FileException - if it cannot write.
	*/
	void writeToFile() override;

	/*
	Displays the Events using Microsof Excel.
	*/
	  void displayEventlist() const override;
};


