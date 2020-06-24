#include "Baggage.h"
#include "HelpUtils.h"

Baggage::Baggage()
{
	flightNumber = -1;
	destination = "";
	passangerLastName = "";
	placeForBaggage = -1;
	baggageWeight = -1.;
}

Baggage::Baggage(int fNumber, DateTime fDateTime, std::string dest, std::string pLastName, int pForBaggage, double bWeight)
{
	flightNumber = fNumber;
	flightDateTime = fDateTime;
	destination = dest;
	passangerLastName = pLastName;
	placeForBaggage = pForBaggage;
	baggageWeight = bWeight;
}

bool operator== (const Baggage& left, const Baggage& right)
{
	return
		left.flightNumber == right.flightNumber &&
		left.flightDateTime == right.flightDateTime &&
		left.destination == right.destination &&
		left.passangerLastName == right.passangerLastName &&
		left.placeForBaggage == right.placeForBaggage &&
		abs(left.baggageWeight - right.baggageWeight) < WEIGHT_EPSILON;
}

bool operator!= (const Baggage& left, const Baggage& right)
{
	return !(left == right);
}

std::ostream& operator<< (std::ostream& out, const Baggage& baggage)
{
	if (&out == &std::cout)
	{
		out << "������� ���������: " << baggage.passangerLastName << std::endl
			<< "����� �����: " << baggage.flightNumber << std::endl
			<< "����� ����������: " << baggage.destination << std::endl
			<< "���� � ����� ������: " << baggage.flightDateTime << std::endl
			<< "���������� ���� ������: " << baggage.placeForBaggage << std::endl
			<< "��� ������: " << baggage.baggageWeight << std::endl;
	}
	else
	{
		out << baggage.flightNumber << std::endl
			<< baggage.passangerLastName << std::endl
			<< baggage.destination << std::endl
			<< baggage.flightDateTime << std::endl
			<< baggage.placeForBaggage << std::endl
			<< baggage.baggageWeight;
	}

	return out;
}

std::istream& operator>> (std::istream& in, Baggage& baggage)
{
	if (&in == &std::cin)
	{		
		baggage.passangerLastName = InputString("������� ������� ��������� ������: ");
		baggage.flightNumber = InputUnsigned("������� ����� �����: ", 1, 9999);
		baggage.destination = InputString("������� ����� ����������: ");
		in >> baggage.flightDateTime;
		baggage.placeForBaggage = InputUnsigned("������� ���������� ���� ������: ", 1, 10);
		baggage.baggageWeight = InputDouble("������� ��� ������: ", 1, 20);		
	}
	else
	{
		char buf[50];
		in >> baggage.flightNumber;

		in.ignore();
		in.getline(buf, 50);
		baggage.passangerLastName = std::string(buf);

		in.getline(buf, 50);
		baggage.destination = std::string(buf);

		in >> baggage.flightDateTime;
		in >> baggage.placeForBaggage;
		in >> baggage.baggageWeight;
	}

	return in;
}