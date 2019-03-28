#pragma once
#include <string>
#include "Events.h"
#include <vector>

class EventsException
{
private:
	std::vector<std::string> errors;

public:
	EventsException(std::vector<std::string> _errors);
	std::vector<std::string> getErrors() const;
};

class EventsValidator
{
public:
	EventsValidator() {}
	static void validate(const Events & ev);
};

