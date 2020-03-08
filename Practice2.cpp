#include <iostream>

using namespace std;

struct BORNDATE
{
	unsigned short day;

	unsigned short month;

	unsigned short year;

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

	void setFullInfo()
	{
		name.setFullName();

		address.setHomeAddress();

		cout << "Enter nationality" << endl;
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(nationality, 30);

		date.setDate();

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
		(Array + i)->getFullInfo();

		cout << endl;
	}
}

void Interface(SERVICEMAN* Array, unsigned short* dimension)
{
	int choice;

	while (true)
	{
		cout << "Choose operation: 1)Display array 2)Expand array" << endl;

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
		default:
			cout << "Wrong input";
			break;
		}		
	}
}

int main()
{
	unsigned short dimension;

	cout << "Enter dimension of array" << endl;

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