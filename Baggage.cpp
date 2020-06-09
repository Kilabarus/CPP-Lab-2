#include <string>
#include "Baggage.h"
#include "SupportiveFunctions.h"

bool operator== (const Baggage& left, const Baggage& right)
{
	return (left.passangerLastName == right.passangerLastName &&
			left.flightNumber == right.flightNumber &&
			left.destination == right.destination &&
			left.flightDateAndTime == right.flightDateAndTime &&
			left.placeForBaggage == right.placeForBaggage &&
			abs(left.baggageWeight - right.baggageWeight) < WEIGHT_EPSILON);
}

bool operator!= (const Baggage& left, const Baggage& right)
{
	return !(left == right);
}

std::ostream& operator<< (std::ostream& out, const Baggage& baggage)
{
	if (&out == &std::cout)
	{
		out << "Фамилия владельца: " << baggage.passangerLastName << std::endl
			<< "Номер рейса: " << baggage.flightNumber << std::endl
			<< "Пункт назначения: " << baggage.destination << std::endl
			<< "Дата и время вылета: " << baggage.flightDateAndTime << std::endl
			<< "Количество мест багажа: " << baggage.placeForBaggage << std::endl
			<< "Вес багажа: " << baggage.baggageWeight << std::endl;
	}
	else
	{
		out << baggage.flightNumber << std::endl
			<< baggage.passangerLastName << std::endl
			<< baggage.destination << std::endl
			<< baggage.flightDateAndTime.day << " " << baggage.flightDateAndTime.month << " " << baggage.flightDateAndTime.year << " " << baggage.flightDateAndTime.hour << " " << baggage.flightDateAndTime.minute << std::endl
			<< baggage.placeForBaggage << std::endl
			<< baggage.baggageWeight;
	}

	return out;
}

std::istream& operator>> (std::istream& in, Baggage& baggage)
{
	if (&in == &std::cin)
	{
		std::cout << "Введите фамилию владельца багажа: ";
		in >> baggage.passangerLastName;
		std::cout << "Введите номер рейса: ";
		in >> baggage.flightNumber;
		std::cout << "Введите пункт назначения: ";
		in >> baggage.destination;
		std::cout << "Введите год: ";
		in >> baggage.flightDateAndTime.year;
		std::cout << "Введите номер месяца: ";
		in >> baggage.flightDateAndTime.month;
		std::cout << "Введите день: ";
		in >> baggage.flightDateAndTime.day;
		std::cout << "Введите час: ";
		in >> baggage.flightDateAndTime.hour;
		std::cout << "Введите минуту: ";
		in >> baggage.flightDateAndTime.minute;
		std::cout << "Введите количество мест багажа: ";
		in >> baggage.placeForBaggage;
		std::cout << "Введите вес багажа: ";
		in >> baggage.baggageWeight;
	}
	else
	{
		char buf[50];
		in >> baggage.flightNumber;

		in.ignore();
		in.getline(buf, 50);
		baggage.passangerLastName = CharArrayToString(buf);
		
		in.getline(buf, 50);
		baggage.destination = CharArrayToString(buf);

		in >> baggage.flightDateAndTime.day;
		in >> baggage.flightDateAndTime.month;
		in >> baggage.flightDateAndTime.year;
		in >> baggage.flightDateAndTime.hour;
		in >> baggage.flightDateAndTime.minute;
		in >> baggage.placeForBaggage;
		in >> baggage.baggageWeight;

		in.ignore();
	}
	
	return in;
}