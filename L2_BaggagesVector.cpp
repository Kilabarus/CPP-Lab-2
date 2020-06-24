#include <string>
#include <iostream>
#include "DateTime.h"
#include "Baggage.h"
#include "MyVector.h"
#include "HelpUtils.h"
#pragma once

/*

Лабораторная 10:
	Выбранный оптимальный (надеюсь) контейнер - std::vector

	Добавление, изменение и удаление элементов контейнера.

	Ввод и вывод элементов контейнера с использованием потоковых итераторов на экран и в файл

	Запись о багаже пассажира авиарейса содержит поля:
		- Номер рейса;
		- Дата и время вылета;
		- Пункт назначения;
		- Фамилия пассажира;
		- Количество мест багажа;
		- Суммарный вес багажа.

	Поиск элемента и подвыборки элементов по номеру рейса, дате вылета, пункту назначения, весу багажа.
	Подсчет общего веса багажа.

Данильченко Роман, 9 гр.

*/

using namespace std;

function<int(const Baggage&)> GetFunctionWithBaggageCriteriaForBinarySearch(int numOfField)
{
	cout << "Выберите критерий, по которому будет найден багаж авиарейса:" << endl
		<< "1 - Номер авиарейса" << endl
		<< "2 - Дата вылета" << endl
		<< "3 - Пункт назначения" << endl
		<< "4 - Вес багажа" << endl
		<< "--> ";

	switch (InputUnsigned("", 1, 4))
	{
	case 1:
	{
		numOfField = 1;
		cout << "Выберите какой багаж нужно найти:" << endl
			<< "1 - Багаж с номером рейса равным нужному" << endl
			<< "2 - Багаж с номером рейса меньше нужного" << endl
			<< "3 - Багаж с номером рейса больше нужного" << endl
			<< "4 - Багаж с номером рейса меньше одного, но больше другого" << endl
			<< "--> ";

		switch (InputUnsigned("", 1, 4))
		{
		case 1:
		{
			int flightNumber = InputUnsigned("Введите нужный номер багажа: ");

			return [flightNumber](const Baggage& baggage) {
				if (baggage.flightNumber == flightNumber)
					return 0;
				else if (baggage.flightNumber > flightNumber)
					return 1;
				else return -1;
			};
		}
		case 2:
		{
			int flightNumber = InputUnsigned("Введите нужный номер багажа: ");

			return [flightNumber](const Baggage& baggage) {
				if (baggage.flightNumber < flightNumber)
					return 0;
				else
					return 1;
			};
		}
		case 3:
		{
			int flightNumber = InputUnsigned("Введите нужный номер багажа: ");

			return [flightNumber](const Baggage& baggage) {
				if (baggage.flightNumber > flightNumber)
					return 0;
				else
					return -1;
			};
		}
		case 4:
		{
			int flightNumberLeft = InputUnsigned("Введите первый номер багажа: ");
			int flightNumberRight = InputUnsigned("Введите второй номер багажа: ");

			return [flightNumberLeft, flightNumberRight](const Baggage& baggage) {
				if (baggage.flightNumber > flightNumberLeft && baggage.flightNumber < flightNumberRight)
					return 0;
				else if (baggage.flightNumber < flightNumberRight)
					return -1;
				else
					return 1;
			};
		}
		}
	case 2:
	{
		numOfField = 2;
		cout << "Выберите какой багаж нужно найти:" << endl
			<< "1 - Багаж с датой вылета равной нужной" << endl
			<< "2 - Багаж с датой вылета меньшей нужной" << endl
			<< "3 - Багаж с датой вылета большей нужной" << endl
			<< "4 - Багаж с датой вылета между двумя датами" << endl
			<< "--> ";

		switch (InputUnsigned("", 1, 4))
		{
		case 1:
		{
			DateTime flightDateTime;

			cout << "Введите нужную дату: " << endl;
			cin >> flightDateTime;

			return [flightDateTime](const Baggage& baggage) {
				if (baggage.flightDateTime == flightDateTime)
					return 0;
				else if (baggage.flightDateTime > flightDateTime)
					return 1;
				else
					return -1;
			};
		}
		case 2:
		{
			DateTime flightDateTime;

			cout << "Введите нужную дату: " << endl;
			cin >> flightDateTime;

			return [flightDateTime](const Baggage& baggage) {
				if (baggage.flightDateTime < flightDateTime)
					return 0;
				else
					return 1;
			};
		}
		case 3:
		{
			DateTime flightDateTime;

			cout << "Введите нужную дату: " << endl;
			cin >> flightDateTime;

			return [flightDateTime](const Baggage& baggage) {
				if (baggage.flightDateTime > flightDateTime)
					return 0;
				else
					return -1;
			};
		}
		case 4:
		{
			DateTime flightDateTimeLeft;
			cout << "Введите первую дату" << endl;
			cin >> flightDateTimeLeft;

			DateTime flightDateTimeRight;
			cout << "Введите вторую дату" << endl;
			cin >> flightDateTimeRight;

			return [flightDateTimeLeft, flightDateTimeRight](const Baggage& baggage) {
				if (baggage.flightDateTime > flightDateTimeLeft && baggage.flightDateTime < flightDateTimeRight)
					return 0;
				else if (baggage.flightDateTime < flightDateTimeRight)
					return -1;
				else
					return 1;
			};
		}
		}
	}
	case 3:
	{
		numOfField = 3;
		string destination = InputString("Введите нужный пункт назначения");

		return [destination](const Baggage& baggage) {
			if (baggage.destination == destination)
				return 0;
			else if (baggage.destination > destination)
				return 1;
			else
				return -1;
		};
	}
	case 4:
	{
		numOfField = 4;
		cout << "Выберите какой багаж нужно найти:" << endl
			<< "1 - Багаж с весом равным нужному" << endl
			<< "2 - Багаж с весом меньшим нужного" << endl
			<< "3 - Багаж с весом большим нужного" << endl
			<< "4 - Багаж с весом меньшим одного, но большим другого" << endl
			<< "--> ";

		switch (InputUnsigned("", 1, 4))
		{
		case 1:
		{
			double baggageWeight = InputDouble("Введите нужный вес багажа");

			return [baggageWeight](const Baggage& baggage) {
				if (abs(baggage.baggageWeight - baggageWeight) < WEIGHT_EPSILON)
					return 0;
				else if (baggage.baggageWeight > baggageWeight)
					return 1;
				else
					return -1;
			};
		}
		case 2:
		{
			double baggageWeight = InputDouble("Введите нужный вес багажа");

			return [baggageWeight](const Baggage& baggage) {
				if (baggage.baggageWeight < baggageWeight)
					return 0;
				else
					return 1;
			};
		}
		case 3:
		{
			double baggageWeight = InputDouble("Введите нужный вес багажа");

			return [baggageWeight](const Baggage& baggage) {
				if (baggage.baggageWeight > baggageWeight)
					return 0;
				else
					return -1;
			};
		}
		case 4:
		{
			double baggageWeightLeft = InputDouble("Введите первый вес багажа: ");
			double baggageWeightRight = InputDouble("Введите второй вес багажа: ");

			return [baggageWeightLeft, baggageWeightRight](const Baggage& baggage) {
				if (baggage.baggageWeight > baggageWeightLeft && baggage.baggageWeight < baggageWeightRight)
					return 0;
				else if (baggage.baggageWeight < baggageWeightRight)
					return -1;
				else
					return 1;
			};
		}
		}
	}
	}
	}
}

function<bool(const Baggage&)> GetFunctionWithBaggageCriteria()
{
	cout << "Выберите критерий, по которому будут отобраны багажи авиарейса:" << endl
		<< "1 - Номер авиарейса" << endl
		<< "2 - Дата вылета" << endl
		<< "3 - Пункт назначения" << endl
		<< "4 - Вес багажа" << endl
		<< "--> ";

	switch (InputUnsigned("", 1, 4))
	{
	case 1:
		cout << "Выберите, какие багажи будут отобраны:" << endl
			<< "1 - Багажи с номером авиарейса равным нужному" << endl
			<< "2 - Багажи с номером больше нужного" << endl
			<< "3 - Багажи с номером меньше нужного" << endl
			<< "4 - Багажи с номером больше одного, но меньше другого" << endl;

		switch (InputUnsigned("", 1, 3))
		{
		case 1:
		{
			int flightNumber = InputUnsigned("Введите нужный номер багажа: ");

			return [flightNumber](const Baggage& baggage) { return baggage.flightNumber == flightNumber; };
		}
		case 2:
		{
			int flightNumberLeft = InputUnsigned("Введите нужный номер багажа: ");

			return [flightNumberLeft](const Baggage& baggage) { return baggage.flightNumber > flightNumberLeft; };
		}
		case 3:
		{
			int flightNumberRight = InputUnsigned("Введите нужный номер багажа: ");

			return [flightNumberRight](const Baggage& baggage) { return baggage.flightNumber < flightNumberRight; };
		}
		case 4:
		{
			int flightNumberLeft = InputUnsigned("Введите первый номер багажа: ");
			int flightNumberRight = InputUnsigned("Введите второй номер багажа: ");

			return [flightNumberLeft, flightNumberRight](const Baggage& baggage) { return baggage.flightNumber > flightNumberLeft && baggage.flightNumber < flightNumberRight; };
		}
		}
	case 2:
	{
		cout << "Выберите, какие авиарейсы будут отобраны:" << endl
			<< "1 - Авиарейсы с датой вылета равной нужной"
			<< "2 - Авиарейсы с датой вылета позднее нужной" << endl
			<< "3 - Авиарейсы с датой вылета раньше нужной" << endl
			<< "4 - Авиарейсы с датой вылета между двумя датами" << endl;

		switch (InputUnsigned("", 1, 4))
		{
		case 1:
		{
			DateTime flightDateTime;

			cout << "Введите нужную дату: " << endl;
			cin >> flightDateTime;

			return [flightDateTime](const Baggage& baggage) { return baggage.flightDateTime == flightDateTime; };
		}
		case 2:
		{
			DateTime flightDateTimeLeft;

			cout << "Введите нужную дату: " << endl;
			cin >> flightDateTimeLeft;

			return [flightDateTimeLeft](const Baggage& baggage) { return baggage.flightDateTime > flightDateTimeLeft; };
		}
		case 3:
		{
			DateTime flightDateTimeRight;

			cout << "Введите нужную дату: " << endl;
			cin >> flightDateTimeRight;

			return [flightDateTimeRight](const Baggage& baggage) { return baggage.flightDateTime < flightDateTimeRight; };
		}
		case 4:
		{
			DateTime flightDateTimeLeft;
			DateTime flightDateTimeRight;

			cout << "Введите первую дату: " << endl;
			cin >> flightDateTimeLeft;

			cout << "Введите вторую дату: " << endl;
			cin >> flightDateTimeRight;

			return [flightDateTimeLeft, flightDateTimeRight](const Baggage& baggage) { return baggage.flightDateTime > flightDateTimeLeft && baggage.flightDateTime < flightDateTimeRight; };
		}
		}
	}
	case 3:
	{
		string destination = InputString("Введите нужный пункт назначения");

		return [destination](const Baggage& baggage) { return baggage.destination == destination; };
	}
	case 4:
		cout << "Выберите, какие багажи будут отобраны:" << endl
			<< "1 - Багажи с весом равным нужному" << endl
			<< "2 - Багажи с весом больше нужного" << endl
			<< "3 - Багажи с весом меньше нужного" << endl
			<< "4 - Багажи с весом больше одного, но меньше другого" << endl;

		switch (InputUnsigned("", 1, 4))
		{
		case 1:
		{
			int baggageWeight = InputUnsigned("Введите нужный вес багажа: ");

			return [baggageWeight](const Baggage& baggage) { return abs(baggage.baggageWeight - baggageWeight) < WEIGHT_EPSILON; };
		}
		case 2:
		{
			int baggageWeightLeft = InputUnsigned("Введите нужный вес багажа: ");

			return [baggageWeightLeft](const Baggage& baggage) { return baggage.baggageWeight > baggageWeightLeft; };
		}
		case 3:
		{
			int baggageWeightRight = InputUnsigned("Введите нужный вес багажа: ");

			return [baggageWeightRight](const Baggage& baggage) { return baggage.baggageWeight < baggageWeightRight; };
		}
		case 4:
		{
			int baggageWeightLeft = InputUnsigned("Введите первый вес багажа: ");
			int baggageWeightRight = InputUnsigned("Введите второй вес багажа: ");

			return [baggageWeightLeft, baggageWeightRight](const Baggage& baggage) { return baggage.baggageWeight > baggageWeightLeft && baggage.baggageWeight < baggageWeightRight; };
		}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	MyVector<Baggage> baggages;

	while (true)
	{
		cout << "Выберите действие:" << endl
			<< "1 - Ввести багаж в консоль" << endl
			<< "2 - Ввести багажи из файла" << endl
			<< "3 - Добавить багаж" << endl
			<< "4 - Изменить багаж" << endl
			<< "5 - Удалить багаж" << endl
			<< "6 - Найти багаж по критериям" << endl
			<< "7 - Найти выборку багажей по критериям" << endl
			<< "8 - Вывести все багажи в консоль" << endl
			<< "9 - Вывести все багажи в файл" << endl
			<< "10 - Подсчитать суммарный вес багажей" << endl
			<< "0 - Выйти из программы" << endl
			<< "--> ";

		switch (InputUnsigned("", 1, 10))
		{
		case 1:
			baggages.ReadFromConsole();
			break;
		case 2:
			baggages.ReadFromFile(InputString("Введите имя файла"));			
			break;
		case 3:
		{
			Baggage newBaggage;
			cout << "Выберите вид добавления:" << endl
				<< "1 - В конец контейнера" << endl
				<< "2 - По индексу" << endl
				<< "--> ";

			if (InputUnsigned("", 1, 2) == 1)
			{
				cout << "Введите багаж" << endl;
				cin >> newBaggage;
				baggages.AddElement(newBaggage);
			}
			else
			{
				int index = InputUnsigned("Введите индекс, по которому требуется добавить багаж", 0, baggages.GetSize());
				cout << "Введите багаж" << endl;
				cin >> newBaggage;
				baggages.AddElementAt(index, newBaggage);
			}
			break;
		}
		case 4:
		{
			int index = InputUnsigned("Введите индекс багажа, который требуется изменить", 0, baggages.GetSize());

			cout << "Выберите поля, которые будете изменять:" << endl
				<< "1 - Все" << endl
				<< "2 - Номер авиарейса" << endl
				<< "3 - Дату вылета" << endl
				<< "4 - Фамилию пассажира" << endl
				<< "5 - Вес багажа" << endl
				<< "--> ";

			switch (InputUnsigned("", 1, 5))
			{
			case 1:
			{
				Baggage newBaggage;
				cout << "Введите новый багаж" << endl;
				cin >> newBaggage;

				baggages.ReplaceElementWith(index, newBaggage);
				break;
			}
			case 2:
			{
				int flightNumber = InputUnsigned("Введите новый номер рейса");

				baggages.ModifyElement(index, [flightNumber](Baggage& baggage) { baggage.flightNumber = flightNumber; });
				break;
			}
			case 3:
			{
				DateTime flightDateTime;
				cout << "Введите новую дату" << endl;
				cin >> flightDateTime;

				baggages.ModifyElement(index, [flightDateTime](Baggage& baggage) { baggage.flightDateTime = flightDateTime; });
				break;
			}
			case 4:
			{
				string passangerLastName = InputString("Введите новую фамилию пассажира");

				baggages.ModifyElement(index, [passangerLastName](Baggage& baggage) { baggage.passangerLastName = passangerLastName; });
				break;
			}
			case 5:
			{
				double baggageWeight = InputDouble("Введите новый вес багажа");

				baggages.ModifyElement(index, [baggageWeight](Baggage& baggage) { baggage.baggageWeight = baggageWeight; });
				break;
			}
			}
			break;
		}
		case 5:
		{
			cout << "Выберите вид удаления:" << endl
				<< "1 - Сравнением с вводимым багажом" << endl
				<< "2 - По индексу" << endl
				<< "--> ";

			if (InputUnsigned("", 1, 2) == 1)
			{
				Baggage baggageToRemove;
				cout << "Введите багаж, который требуется удалить" << endl;
				cin >> baggageToRemove;

				baggages.RemoveElement(baggageToRemove);
			}
			else
			{
				int index;
				index = InputUnsigned("Введите индекс багажа, который требуется удалить", 0, baggages.GetSize());

				baggages.RemoveElementAt(index);
			}
			break;
		}
		case 6:
		{
			cout << "Выберите вид поиска: " << endl
				<< "1 - Линейный" << endl
				<< "2 - Бинарный" << endl;
			
			if (InputUnsigned("", 1, 2) == 1)
			{
				Baggage foundBaggage = baggages[baggages.FindElementLinear(GetFunctionWithBaggageCriteria())];

				cout << "Найденный багаж" << endl 
					<< foundBaggage << endl;				
			}
			else
			{
				int i = 0;
				function<int(const Baggage&)> f = GetFunctionWithBaggageCriteriaForBinarySearch(i);

				switch (i)
				{
				case 1:
				{
					Baggage foundBaggage = baggages[baggages.FindElementBinary([](const Baggage& baggageLeft, const Baggage& baggageRight) { return baggageLeft.flightNumber < baggageRight.flightNumber; }, f)];
				
					cout << "Найденный багаж" << endl
						<< foundBaggage << endl;
					break;
				}		
				case 2:
				{
					Baggage foundBaggage = baggages[baggages.FindElementBinary([](const Baggage& baggageLeft, const Baggage& baggageRight) { return baggageLeft.flightDateTime < baggageRight.flightDateTime; }, f)];

					cout << "Найденный багаж" << endl
						<< foundBaggage << endl;
					break;
				}
				case 3:
				{
					Baggage foundBaggage = baggages[baggages.FindElementBinary([](const Baggage& baggageLeft, const Baggage& baggageRight) { return baggageLeft.destination < baggageRight.destination; }, f)];

					cout << "Найденный багаж" << endl
						<< foundBaggage << endl;
					break;
				}
				case 4:
				{
					Baggage foundBaggage = baggages[baggages.FindElementBinary([](const Baggage& baggageLeft, const Baggage& baggageRight) { return baggageLeft.baggageWeight < baggageRight.baggageWeight; }, f)];

					cout << "Найденный багаж" << endl
						<< foundBaggage << endl;
					break;
				}
				}
			}
			break;
		}
		case 7:
		{
			MyVector<Baggage> selectedBaggages = baggages.SelectElements(GetFunctionWithBaggageCriteria());
			
			selectedBaggages.PrintToConsole();

			cout << "Вывести найденные багажи в файл? (y/n)" << endl;
			switch (std::cin.get())
			{
			case 'y':
			case 'Y':
			case 'н':
			case 'Н':
				selectedBaggages.PrintToFile(InputString("Введите название файла для сохранения"));				
				break;			
			}
			break;
		}
		case 8:
			baggages.PrintToConsole();
			break;
		case 9:
			baggages.PrintToFile(InputString("Введите название файла для сохранения"));			
			break;
		case 10:
		{
			double sumWeight = 0;
			baggages.ForEach([&sumWeight](Baggage& baggage) { sumWeight += baggage.baggageWeight; });

			cout << "Суммарный вес багажа: " << sumWeight << endl;
		}
		case 0:
			exit(0);
		}
	}
}
