#include <string>
#include "DateTime.h"

#pragma once

static constexpr double WEIGHT_EPSILON = 0.001;

class Baggage
{
public:
	int flightNumber;
	DateTime flightDateTime;

	std::string destination;
	std::string passangerLastName;

	int placeForBaggage;
	double baggageWeight;

	Baggage();

	Baggage(int flNum, DateTime flDateAndTime, std::string dest, std::string passLastName, int plForBaggage, double baggWeight);

	Baggage& operator= (const Baggage& baggage)
	{
		if (this == &baggage)
			return *this;

		flightNumber = baggage.flightNumber;
		flightDateTime = baggage.flightDateTime;
		destination = baggage.destination;
		passangerLastName = baggage.passangerLastName;
		placeForBaggage = baggage.placeForBaggage;
		baggageWeight = baggage.baggageWeight;

		return *this;
	}

	friend bool operator== (const Baggage& left, const Baggage& right);
	friend bool operator!= (const Baggage& left, const Baggage& right);

	friend std::ostream& operator<< (std::ostream& out, const Baggage& baggage);
	friend std::istream& operator>> (std::istream& in, Baggage& baggage);
};

