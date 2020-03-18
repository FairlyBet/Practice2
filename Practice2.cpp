#include <iostream>
using namespace std;

unsigned short currentday = 9;
unsigned short currentmonth = 3;
unsigned short currentyear = 2020;

struct BORNDATE
{
	unsigned short day;

	unsigned short month;

	unsigned short year;
	
	bool isCorrect()
	{
		bool result = false;

		switch (month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
		{
			if ((day <= 31) && (day > 0))
				result = true;
			break;
		}

		case 4:
		case 6:
		case 9:
		case 11:
		{
			if ((day <= 30) && (day > 0))
				result = true;
			break;
		}

		case 2:
		{
			if (year % 4 != 0)
			{
				if ((day <= 28) && (day > 0))
					result = true;
			}
			else
				if (year % 400 == 0)
				{
					if ((day <= 29) && (day > 0))
						result = true;
				}
				else
					if ((year % 100 == 0) && (year % 400 != 0))
					{
						if ((day == 28) && (day > 0))
							result = true;
					}
					else
						if ((year % 4 == 0) && (year % 100 != 0))
							if ((day <= 29) && (day > 0))
								result = true;
			break;
		}
		default:
			result = false;
		}
		return result;
	}

	void setDate()
	{
		cout << "Enter borndate" << endl;

		while (!(cin >> day >> month >> year))
		{
			cout << "Wrong input" << endl;
			cin.clear();
			cin.ignore(65535, '\n');
		}
	}

	void getBornDate()
	{
		cout << "Born date: " << day << "." << month << "." << year << endl;
	}
};

struct HOMEADDRESS
{
	char state[30];

	char region[30];

	char city[30];

	char district[30];

	char street[30];

	int zipcode;

	unsigned short homenumber;

	unsigned short apartment;

	void setHomeAddress()
	{
		cout << "Enter a zipcode" << endl;

		while (!(cin >> zipcode))
		{
			cout << "Wrong input" << endl;
			cin.clear();
			cin.ignore(65535, '\n');
		}

		cout << "Enter state" << endl;
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(state, 30);

		cout << "Enter region" << endl;
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(region, 30);

		cout << "Enter city" << endl;
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(city, 30);

		cout << "Enter district" << endl;
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(district, 30);

		cout << "Enter street" << endl;
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(street, 30);

		cout << "Enter home number" << endl;

		while (!(cin >> homenumber))
		{
			cout << "Wrong input" << endl;
			cin.clear();
			cin.ignore(65535, '\n');
		}

		cout << "Enter apartment number" << endl;

		while (!(cin >> apartment))
		{
			cout << "Wrong input" << endl;
			cin.clear();
			cin.ignore(65535, '\n');
		}
	}

	void getHomeAddress()
	{
		cout << "State: " << state << endl;

		cout << "Region: " << region << endl;

		cout << "City: " << city << endl;

		cout << "District: " << district << endl;

		cout << "Street: " << street << endl;

		cout << "Home number: " << homenumber << endl;

		cout << "Apartment number: " << apartment << endl;
	}
};

struct FULLNAME
{
	char lastname[56];

	char firstname[30];

	char middlename[30];

	void setFullName()
	{
		cout << "Enter lastname" << endl;
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(lastname, 30);

		cout << "Enter firstname" << endl;
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(firstname, 30);

		cout << "Enter middlename" << endl;
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(middlename, 30);
	}

	void getFullName()
	{
		cout << "Full name: " << lastname << " " << firstname << " " << middlename << endl;
	}
};

struct SERVICEMAN
{
	HOMEADDRESS address;

	FULLNAME name;

	char nationality[30];

	char position[30];

	char rank[30];

	BORNDATE date;

	unsigned short age;

	void setFullInfo()
	{
		name.setFullName();

		address.setHomeAddress();

		cout << "Enter nationality" << endl;
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(nationality, 30);

		date.setDate();

		while (!date.isCorrect())
		{
			date.setDate();
		}

		if (date.month < currentmonth)
		{
			age = currentyear - date.year;
		}
		else if (date.month == currentmonth)
		{
			if (currentday >= date.day)
				age = currentyear - date.year;
			else age = currentyear - date.year - 1;
		}
		else age = currentyear - date.year - 1;

		cout << "Enter position" << endl;
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(position, 30);

		cout << "Enter rank" << endl;
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(rank, 30);

		cout << endl;
	}

	void getFullInfo()
	{
		name.getFullName();

		address.getHomeAddress();

		cout << "Natioanlity: " << nationality << endl;

		date.getBornDate();

		cout << "Position: " << position << endl;

		cout << "Rank: " << rank << endl;
	}
};

void InitOfArray(SERVICEMAN* Array, unsigned short* dimension)
{
	for (size_t i = 0; i < *dimension; i++)
	{
		(Array + i)->setFullInfo();
	}
}

bool AlphabetComparison(SERVICEMAN* Array, size_t j)
{
	for (size_t i = 0; i < 56; i++)
	{
		if (int((Array + j)->name.lastname[i]) > int((Array + j + 1)->name.lastname[i]))
			return true;
		else if (int((Array + j)->name.lastname[i]) < int((Array + j + 1)->name.lastname[i]))
			return 0;
	}
	return 0;
}

void AlphabetSorting(SERVICEMAN* Array, unsigned short* dimension)
{
	for (size_t i = 0; i < *dimension; i++)
	{
		for (size_t j = 0; j < *dimension - 1; j++)
		{
			if (AlphabetComparison(Array, j))
				swap(*(Array + j), *(Array + j + 1));
		}
	}
}

SERVICEMAN* ExpandArray(SERVICEMAN* Array, unsigned short* dimension)
{
	(*dimension)++;

	SERVICEMAN* ExpArray = new SERVICEMAN[*dimension];

	for (size_t i = 0; i < *dimension - 1; i++)
	{
		*(ExpArray + i) = *(Array + i);
	}

	delete[]Array;

	Array = ExpArray;

	(Array + *dimension - 1)->setFullInfo();

	return Array;
}

void DispOfArray(SERVICEMAN* Array, unsigned short* dimension)
{
	system("cls");

	for (size_t i = 0; i < *dimension; i++)
	{
		cout << "Number in array: " << i + 1 << endl;

		(Array + i)->getFullInfo();

		cout << endl;
	}
}

void EditElement(SERVICEMAN* Array, int NumberInArray)
{
	cout << "Choose field to edit" << endl;

	cout << "1)Name\n2)Home address\n3)Nationality\n4)Born date\n5)Position\n6)Rank\n";

	int choice;

	while (!(cin >> choice))
	{
		cout << "Wrong input" << endl;
		cin.clear();
		cin.ignore(65535, '\n');
	}

	switch (choice)
	{
	case 1:
		(Array + (NumberInArray - 1))->name.setFullName();
		break;
	case 2:
		(Array + (NumberInArray - 1))->address.setHomeAddress();
		break;
	case 3:
		cout << "Enter new nationality" << endl;
		cin >> (Array + (NumberInArray - 1))->nationality;
		break;
	case 4:
		(Array + (NumberInArray - 1))->date.setDate();
		while (!((Array + (NumberInArray - 1))->date.isCorrect()))
		{
			(Array + (NumberInArray - 1))->date.setDate();
		}
		break;
	case 5: 
		cout << "Enter new position" << endl;
		cin >> (Array + (NumberInArray - 1))->position;
		break;
	case 6:
		cout << "Enter new rank" << endl;
		cin >> (Array + (NumberInArray - 1))->rank;
		break;
	default:
		cout << "Wrong input" << endl;
		break;
	}
}

int Interface(SERVICEMAN* Array, unsigned short* dimension)
{
	int choice;

	while (true)
	{
		cout << "Choose operation: 1)Display array 2)Add new element 3)Edit element 4)Alphabet sort 5)Search in age range 6)Close program" << endl;

		while (!(cin >> choice))
		{
			cout << "Wrong input" << endl;
			cin.clear();
			cin.ignore(65535, '\n');
		}

		switch (choice)
		{
		case 1:
			DispOfArray(Array, dimension);
			break;
		case 2:
			Array = ExpandArray(Array, dimension);
			break;
		case 3:			
			int number;
		again:
			cout << "Enter number of element to edit" << endl;
			while (!(cin >> number))
			{
				cout << "Wrong input" << endl;
				cin.clear();
				cin.ignore(65535, '\n');
			}
			if (number > * dimension || number < 1)
				goto again;
			EditElement(Array, number);
			break;
		case 4:
			if (*dimension > 1)
				AlphabetSorting(Array, dimension), cout << "Array is sorted" << endl;
			else cout << "Amount of elements is only 1" << endl;
			break;
		case 5:
			unsigned short lowerrange, upperrange;
		inputrange:
			cout << "Enter lower range, then upper range" << endl;
			while (!(cin >> lowerrange >> upperrange))
			{
				cout << "Wrong input" << endl;
				cin.clear();
				cin.ignore(65535, '\n');
			}
			if (lowerrange < upperrange)
			{
				system("cls");
				int counter = 0;
				for (size_t i = 0; i < *dimension; i++)
				{
					if ((Array + i)->age >= lowerrange && (Array + i)->age <= upperrange)
					{
						cout << "Number in array " << i + 1 << endl;
						(Array + i)->getFullInfo();
						cout << endl;
						counter++;
					}
				}
				if (counter < 0)
					cout << "Noone is in " << lowerrange << " - " << upperrange << "age range" << endl;
			}
			else
			{
				cout << "Wrong input" << endl;
				goto inputrange;
			}
			break;
		case 6:
			return 0;
		default:
			cout << "Wrong input";
			break;
		}		
	}
}

int main()
{
	unsigned short dimension;

	cout << "Enter dimension of the array" << endl;

	while (!(cin >> dimension))
	{
		cout << "Wrong input" << endl;
		cin.clear();
		cin.ignore(65535, '\n');
	}

	unsigned short* ptrdimension = &dimension;

	SERVICEMAN* Array = new SERVICEMAN[dimension];

	InitOfArray(Array, ptrdimension);

	Interface(Array, ptrdimension);
}