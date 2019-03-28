#pragma once
#include "FileEvents.h"
#include <string>

class HTMLEvents : public FileEventslist
{
public:
	HTMLEvents(const std::string& filename) : FileEventslist{ filename } {}

	/*
	Writes the dogs to file.
	Throws: FileException - if it cannot write.
	*/
	void writeToFile() override;

	/*
	Displays the dogs using Microsof Excel.
	*/
	void displayEventlist() const override;
};