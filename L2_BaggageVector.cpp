#include <string>
#include <iostream>
#include "DateAndTime.h"
#include "Baggage.h"
#include "VectorOperations.h"
#include "SupportiveFunctions.h"
#pragma once

/*

Лабораторная 10:
	Выбранный оптимальный (надеюсь) контейнер - std::vector

	Запись о багаже пассажира авиарейса содержит поля: 
		- Номер рейса; 
		- Дата и время вылета; 
		- Пункт назначения;
		- Фамилия пассажира; 
		- Количество мест багажа;
		- Суммарный вес багажа.

	Поиск по номеру рейса, дате вылета, пункту назначения, весу багажа. 
	Подсчет общего веса багажа.

Данильченко Роман, 9 гр.

*/

using namespace std;

void FindElementsMenu(VectorOperations<Baggage>& vOp, bool many)
{
	cout << "Выберите критерий:" << endl
		 << "1 - Номер рейса" << endl 
		 << "2 - Дата вылета" << endl 
		 << "3 - Пункт назначения" << endl 
		 << "4 - Вес багажа" << endl 
		 <<	"--> ";

	switch (InputUnsigned("", 1, 4))
	{
	case 1:
	{
		int flightNumber = InputUnsigned("Введите номер рейса");

		if (!many)
		{
			cout << "Выберите какую запись нужно найти по введенному номеру рейса:" << endl
				 << "1 - Запись с номером рейса равным введенному" << endl
				 << "2 - Запись с номером рейса меньше введенного" << endl
				 << "3 - Запись с номером рейса больше введенного" << endl				 
				 << "--> ";

			switch (InputUnsigned("", 1, 3))
			{
			case 1:
			{
				cout << "Выберите вид поиска" << endl
					 << "1 - Линейный" << endl
					 << "2 - Бинарный (контейнер будет отсортирован по номерам рейсов)" << endl					
					 << "--> ";

				if (InputUnsigned("", 1, 2) == 1)
					cout << *vOp.FindElementLinear([flightNumber](const Baggage& baggage) { return baggage.flightNumber == flightNumber; });
				else
					cout << *vOp.FindElementBinary([](const Baggage& baggagel, const Baggage& baggager) { return baggagel.flightNumber < baggager.flightNumber; },
						[flightNumber](const Baggage& baggage) 
						{
							if (baggage.flightNumber == flightNumber)
								return 0;
							else if (baggage.flightNumber > flightNumber)
								return 1;
							else
								return -1;
						});
				break;
			}
			case 2:
			{
				cout << "Выберите вид поиска" << endl
					 << "1 - Линейный" << endl
					 << "2 - Бинарный (контейнер будет отсортирован по номерам рейсов)" << endl
					 << "--> ";

				if (InputUnsigned("", 1, 2) == 1)
					cout << *vOp.FindElementLinear([flightNumber](const Baggage& baggage) { return baggage.flightNumber < flightNumber; });
				else
					cout << *vOp.FindElementBinary([](const Baggage& baggagel, const Baggage& baggager) { return baggagel.flightNumber < baggager.flightNumber; },
						[flightNumber](const Baggage& baggage)
						{
							if (baggage.flightNumber < flightNumber)
								return 0;
							else
								return 1;
						});
				break;
			}
			case 3:
			{
				cout << "Выберите вид поиска" << endl
					 << "1 - Линейный" << endl
					 << "2 - Бинарный (контейнер будет отсортирован по номерам рейсов)" << endl
					 << "--> ";

				if (InputUnsigned("", 1, 2) == 1)
					cout << *vOp.FindElementLinear([flightNumber](const Baggage& baggage) { return baggage.flightNumber > flightNumber; });
				else
					cout << *vOp.FindElementBinary([](const Baggage& baggagel, const Baggage& baggager) { return baggagel.flightNumber < baggager.flightNumber; },
						[flightNumber](const Baggage& baggage)
						{
							if (baggage.flightNumber > flightNumber)
								return 0;
							else
								return -1;
						});
				break;
			}
			}
		}
		else
		{
			cout << "Выберите какие записи нужно найти по введенному номеру рейса:" << endl
				 << "1 - Записи с номером рейса равным введенному" << endl
				 << "2 - Записи с номером рейса меньше введенного" << endl
				 << "3 - Записи с номером рейса больше введенному" << endl
				 << "--> ";

			switch (InputUnsigned("", 1, 3))
			{
			case 1:			
				vOp.SelectElements([flightNumber](const Baggage& baggage) { return baggage.flightNumber == flightNumber; });		
				break;
			case 2:
				vOp.SelectElements([flightNumber](const Baggage& baggage) { return baggage.flightNumber < flightNumber; });
				break;
			case 3:		
				vOp.SelectElements([flightNumber](const Baggage& baggage) { return baggage.flightNumber > flightNumber; });
				break;			
			}
		}
		break;
	}
	case 2:
	{
		DateAndTime flightDateAndTime;
		cin >> flightDateAndTime;

		if (!many)
		{
			cout << "Выберите какую запись нужно найти по введенной дате вылета:" << endl
				 << "1 - Запись с датой вылета равной введенной" << endl
				 << "2 - Запись с датой вылета меньшей введенной" << endl
				 << "3 - Запись с датой вылета большей введенной" << endl
			 	 << "--> ";

			switch (InputUnsigned("", 1, 3))
			{
			case 1:
			{
				cout << "Выберите вид поиска" << endl
					 << "1 - Линейный" << endl
					 << "2 - Бинарный (контейнер будет отсортирован по датам вылета)" << endl
					 << "--> ";

				if (InputUnsigned("", 1, 2) == 1)
					cout << *vOp.FindElementLinear([flightDateAndTime](const Baggage& baggage) { return baggage.flightDateAndTime == flightDateAndTime; });
				else
					cout << *vOp.FindElementBinary([](const Baggage& baggagel, const Baggage& baggager) { return baggagel.flightDateAndTime < baggager.flightDateAndTime; },
						[flightDateAndTime](const Baggage& baggage)
						{
							if (baggage.flightDateAndTime == flightDateAndTime)
								return 0;
							else if (baggage.flightDateAndTime > flightDateAndTime)
								return 1;
							else
								return -1;
						});
				break;
			}
			case 2:
			{
				cout << "Выберите вид поиска" << endl
					 << "1 - Линейный" << endl
					 << "2 - Бинарный (контейнер будет отсортирован по номерам рейсов)" << endl
					 << "--> ";

				if (InputUnsigned("", 1, 2) == 1)
					cout << *vOp.FindElementLinear([flightDateAndTime](const Baggage& baggage) { return baggage.flightDateAndTime < flightDateAndTime; });
				else
					cout << *vOp.FindElementBinary([](const Baggage& baggagel, const Baggage& baggager) { return baggagel.flightDateAndTime < baggager.flightDateAndTime; },
						[flightDateAndTime](const Baggage& baggage)
						{
							if (baggage.flightDateAndTime < flightDateAndTime)
								return 0;
							else
								return 1;
						});
				break;
			}
			case 3:
			{
				cout << "Выберите вид поиска" << endl
					<< "1 - Линейный" << endl
					<< "2 - Бинарный (контейнер будет отсортирован по номерам рейсов)" << endl
					<< "--> ";

				if (InputUnsigned("", 1, 2) == 1)
					cout << *vOp.FindElementLinear([flightDateAndTime](const Baggage& baggage) { return baggage.flightDateAndTime > flightDateAndTime; });
				else
					cout << *vOp.FindElementBinary([](const Baggage& baggagel, const Baggage& baggager) { return baggagel.flightDateAndTime < baggager.flightDateAndTime; },
						[flightDateAndTime](const Baggage& baggage)
						{
							if (baggage.flightDateAndTime > flightDateAndTime)
								return 0;
							else
								return -1;
						});
				break;
			}
			}
		}
		else
		{
			cout << "Выберите какие записи нужно найти по введенной дате вылета:" << endl
				<< "1 - Записи с датой вылета равной введенной" << endl
				<< "2 - Записи с датой вылета меньшей введенной" << endl
				<< "3 - Записи с датой вылета большей введенной" << endl
				<< "--> ";

			switch (InputUnsigned("", 1, 3))
			{
			case 1:
				vOp.SelectElements([flightDateAndTime](const Baggage& baggage) { return baggage.flightDateAndTime == flightDateAndTime; });
				break;
			case 2:
				vOp.SelectElements([flightDateAndTime](const Baggage& baggage) { return baggage.flightDateAndTime < flightDateAndTime; });
				break;
			case 3:			
				vOp.SelectElements([flightDateAndTime](const Baggage& baggage) { return baggage.flightDateAndTime > flightDateAndTime; });
				break;			
			}
		}
		break;
	}
	case 3:
	{
		string destination = InputString("Введите пункт назначения");

		if (!many)
		{
			cout << "Выберите вид поиска" << endl
			     << "1 - Линейный" << endl
				 << "2 - Бинарный (контейнер будет отсортирован по датам вылета)" << endl
				 << "--> ";

			if (InputUnsigned("", 1, 2) == 1)
				cout << *vOp.FindElementLinear([destination](const Baggage& baggage) { return baggage.destination == destination; });
			else
				cout << *vOp.FindElementBinary([](const Baggage& baggagel, const Baggage& baggager) { return baggagel.destination < baggager.destination; },
					[destination](const Baggage& baggage)
					{
						if (baggage.destination == destination)
							return 0;
						else if (baggage.destination > destination)
							return 1;
						else
							return -1;
					});			
		}		
		else
			vOp.SelectElements([destination](const Baggage& baggage) { return baggage.destination == destination; });
		break;
	}
	case 4:
	{
		double baggageWeight;
		cin >> baggageWeight;

		if (!many)
		{
			cout << "Выберите какую запись нужно найти по введенному весу багажа:" << endl
				<< "1 - Запись с весом багажа равным введенному" << endl
				<< "2 - Запись с весом багажа меньшим введенного" << endl
				<< "3 - Запись с весом багажа большим введеннго" << endl
				<< "--> ";

			switch (InputUnsigned("", 1, 3))
			{
			case 1:
			{
				cout << "Выберите вид поиска" << endl
					<< "1 - Линейный" << endl
					<< "2 - Бинарный (контейнер будет отсортирован по датам вылета)" << endl
					<< "--> ";

				if (InputUnsigned("", 1, 2) == 1)
					cout << *vOp.FindElementLinear([baggageWeight](const Baggage& baggage) { return abs(baggage.baggageWeight - baggageWeight) < WEIGHT_EPSILON; });
				else
					cout << *vOp.FindElementBinary([](const Baggage& baggagel, const Baggage& baggager) { return (baggagel.baggageWeight - baggager.baggageWeight) < -WEIGHT_EPSILON; },
						[baggageWeight](const Baggage& baggage)
						{
							if (abs(baggage.baggageWeight - baggageWeight) < WEIGHT_EPSILON)
								return 0;
							else if ((baggage.baggageWeight - baggageWeight) > WEIGHT_EPSILON)
								return 1;
							else
								return -1;
						});
				break;
			}
			case 2:
			{
				cout << "Выберите вид поиска" << endl
					<< "1 - Линейный" << endl
					<< "2 - Бинарный (контейнер будет отсортирован по номерам рейсов)" << endl
					<< "--> ";

				if (InputUnsigned("", 1, 2) == 1)
					cout << *vOp.FindElementLinear([baggageWeight](const Baggage& baggage) { return (baggage.baggageWeight - baggageWeight) < -WEIGHT_EPSILON; });
				else
					cout << *vOp.FindElementBinary([](const Baggage& baggagel, const Baggage& baggager) { return (baggagel.baggageWeight - baggager.baggageWeight) < -WEIGHT_EPSILON; },
						[baggageWeight](const Baggage& baggage)
						{
							if ((baggage.baggageWeight - baggageWeight) < -WEIGHT_EPSILON)
								return 0;
							else
								return 1;
						});
				break;
			}
			case 3:
			{
				cout << "Выберите вид поиска" << endl
					<< "1 - Линейный" << endl
					<< "2 - Бинарный (контейнер будет отсортирован по номерам рейсов)" << endl
					<< "--> ";

				if (InputUnsigned("", 1, 2) == 1)
					cout << *vOp.FindElementLinear([baggageWeight](const Baggage& baggage) { return (baggage.baggageWeight - baggageWeight) > WEIGHT_EPSILON; });
				else
					cout << *vOp.FindElementBinary([](const Baggage& baggagel, const Baggage& baggager) { return (baggagel.baggageWeight - baggager.baggageWeight) < -WEIGHT_EPSILON ; },
						[baggageWeight](const Baggage& baggage)
						{
							if ((baggage.baggageWeight - baggageWeight) > WEIGHT_EPSILON)
								return 0;
							else
								return -1;
						});
				break;
			}
			}
		}
		else
		{
			cout << "Выберите какие записи нужно найти по введенной дате вылета:" << endl
				<< "1 - Записи с датой вылета равной введенной" << endl
				<< "2 - Записи с датой вылета меньшей введенной" << endl
				<< "3 - Записи с датой вылета большей введенной" << endl
				<< "--> ";

			switch (InputUnsigned("", 1, 3))
			{
			case 1:
				vOp.SelectElements([baggageWeight](const Baggage& baggage) { return abs(baggage.baggageWeight - baggageWeight) < WEIGHT_EPSILON; });
				break;
			case 2:
				vOp.SelectElements([baggageWeight](const Baggage& baggage) { return (baggage.baggageWeight - baggageWeight) < -WEIGHT_EPSILON; });
				break;
			case 3:
				vOp.SelectElements([baggageWeight](const Baggage& baggage) { return (baggage.baggageWeight - baggageWeight) > WEIGHT_EPSILON; });
				break;
			}
		}
		break;
	}
	}
}

int MenuOptions()
{
	cout << "Выберите действие:" << endl
		 << "1 - Ввести элементы в консоль" << endl
		 <<	"2 - Ввести элементы из файла" << endl
		 <<	"3 - Добавить элемент" << endl
		 <<	"4 - Изменить элемент" << endl
		 <<	"5 - Удалить элемент" << endl
		 <<	"6 - Найти элемент по критериям" << endl
		 <<	"7 - Найти подмножество элементов по критериям" << endl
		 <<	"8 - Вывести содержимое в консоль" << endl
		 <<	"9 - Вывести содержимое в файл" << endl
		 << "10 - Подсчитать суммарный вес багажа" << endl
		 <<	"0 - Выйти из программы" << endl
		 <<	"--> ";

	return InputUnsigned("", 0, 9);
}

int main()
{
	setlocale(LC_ALL, "Russian");

	VectorOperations<Baggage> vOp;

	while (true)
		switch (MenuOptions())
		{
		case 1:
			vOp.ReadFromConsole();
			break;
		case 2:
			vOp.ReadFromFile(InputString("Введите имя файла"));
			cout << "Данные были успешно введены из файла" << endl;
			break;
		case 3:
		{
			Baggage item;
			cout << "Выберите вид добавления:" << endl 
				 <<	"1 - В конец контейнера" << endl
				 <<	"2 - По индексу" << endl
				 <<	"--> ";

			if (InputUnsigned("", 1, 2) == 1)
			{
				cout << "Введите элемент" << endl;
				cin >> item;
				vOp.AddElement(item);
			}
			else
			{
				int index = InputUnsigned("Введите индекс", 0, vOp.GetSize());
				cout << "Введите элемент" << endl;
				cin >> item;
				vOp.AddElementAt(index, item);
			}
			break;
		}
		case 4:
		{
			int index = InputUnsigned("Введите индекс", 0, vOp.GetSize());
			
			cout << "Выберите поля, которые будете изменять:" << endl
				 << "1 - Все" << endl
				 << "2 - Номер рейса" << endl
				 << "3 - Дату вылета" << endl 
				 << "4 - Фамилию пассажира" << endl
				 << "--> ";
		
			switch (InputUnsigned("", 1, 4))
			{
			case 1:
			{
				Baggage item;
				cin >> item;

				vOp.ReplaceElementWith(index, item);
				break;
			}				
			case 2:
			{
				int flightNumber = InputUnsigned("Введите номер рейса");

				vOp.ModifyElement(index, [flightNumber](Baggage& baggage) { baggage.flightNumber = flightNumber; });
				break;
			}
			case 3:
			{
				DateAndTime flightDateAndTime;
				cin >> flightDateAndTime;

				vOp.ModifyElement(index, [flightDateAndTime](Baggage& baggage) { baggage.flightDateAndTime = flightDateAndTime; });
				break;
			}
			case 4:
			{
				string passangerLastName = InputString("Введите фамилию пассажира");

				vOp.ModifyElement(index, [passangerLastName](Baggage& baggage) { baggage.passangerLastName = passangerLastName; });
				break;
			}
			}
			break;
		}
		case 5:
		{
			cout << "Выберите вид удаления:" << endl
				 << "1 - Сравнением с вводимым элементом" << endl
				 << "2 - По индексу" << endl
				 << "--> ";

			if (InputUnsigned("", 1, 2) == 1)
			{
				Baggage item;				
				cin >> item;

				vOp.RemoveElement(item);
			}
			else
			{
				int index;
				index = InputUnsigned("Введите индекс", 0, vOp.GetSize());

				vOp.RemoveElementAt(index);
			}
			break;
		}
		case 6:
		{
			FindElementsMenu(vOp, false);
			break;
		}
		case 7:
		{
			FindElementsMenu(vOp, true);
			break;
		}
		case 8:
			vOp.PrintToConsole();
			break;
		case 9:
			vOp.PrintToFile(InputString("Введите название файла для сохранения"));
			cout << "Данные были успешно сохранены" << endl;
			break;
		case 10:
		{
			double sumWeight = 0;
			vOp.ForEach([&sumWeight](Baggage& baggage) { sumWeight += baggage.baggageWeight; });

			cout << "Суммарный вес багажа: " << sumWeight << endl;
		}
		case 0:
			exit(0);
		}
}