#include <iostream>
#include <string>
#include <list>
#include <conio.h>
#include <Windows.h>
using namespace std;


enum Color {
	Green = 2,
	Red = 4,
	White = 15
};

enum Keys
{
	Up = 72,
	Down = 80,
	Enter = 13,
	Backspace = 8
};

class Car {
	string vendor;
	string model;
	float engineVolume;
	int year;

public:

#pragma region GETSEST
	//Get
	string GetVendor() { return vendor; }

	string GetModel() { return model; }

	float GetEngineVolume() { return engineVolume; }

	int GetYear() { return year; }

	//Set
	void SetVendor(string vendor) { this->vendor = vendor; }

	void SetModel(string model) { this->model = model; }

	void SetEngineVolume(float engineVolume) { this->engineVolume = engineVolume; }

	void SetYear(int year) { this->year = year; }

#pragma endregion

	Car(string vendor, string model, float engineVolume, int year) {
		SetVendor(vendor);
		SetModel(model);
		SetEngineVolume(engineVolume);
		SetYear(year);
	}

	friend ostream& operator<<(ostream& out, const Car& car) {
		out << "=============== Car Info===============\n"
			<< "Vendor: " << car.vendor
			<< "\nModel: " << car.model
			<< "\nEngine Volume: " << car.engineVolume
			<< "\nYear: " << car.year << endl;
		return out;
	}

	bool operator==(const Car& o) { return this->vendor == o.vendor; }

	void Show() {
		cout << "**********CAR************\n" << "Vendor: " << vendor << endl << "Model: " << model << endl << "Engine Volume: " << engineVolume << endl << "Year: " << year;
	}
};


#pragma region Menu
void changeColor(int i) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, i);
}

void printMenu(char* arr, int index) {

	system("cls");

	string array[5] = { "Show all Cars ", "Add New Car ", "Search ","Delete ", "Exit" };

	int j = 0;

	for (int i = 0; i < 5; i++)
	{
		if (i == index)
		{
			changeColor(Red);
			cout << array[i] << arr[j] << endl;
			changeColor(White);
		}
		else
		{
			cout << array[i] << arr[j] << endl;
		}
		j++;
	}

}

int changeArr(char* arr, int index, int size) {
	for (int i = 0; i < size; i++)
	{
		if (i == index) {
			arr[i] = '<';
		}
		else arr[i] = ' ';
	}
	return index;
}

////////////////////////////////////////////////////////////////////
list<Car>cars;

int loop = 1;

void AddCar() {

	string w;
	string m;
	int y;
	float e;

	cout << "Insert Vendor: ";
	cin >> w;
	cout << endl;
	cout << "Insert Model: ";
	cin >> m;
	cout << endl;
	cout << "Insert Engine Volume: ";
	cin >> e;
	cout << endl;
	cout << "Insert Year: ";
	cin >> y;

	Car objct(w, m, e, y);
	cars.push_back(objct);

	system("cls");

	cout << "Car added Succesfully :)";
}

void Searching() {
	int Schoice;
	cout << "1)Search by Vendor" << endl << "2)Search by Model" << endl << "3)Search by Engine volume" << endl << "4)Search by Year" << endl;
	cin >> Schoice;

	system("cls");

	string V, M;
	int Y;
	float E;
	bool exist = 0;

	switch (Schoice)
	{
	case 1:
		cout << "Insert Vendor: ";
		cin >> V;

		for (auto i : cars) {
			if (i.GetVendor() == V)
			{
				cout << i << endl;
				exist = 1;
			}
		}
		if (exist == 0) {
			cout << "Car isn't exist :) ";
		}


		break;
	case 2:
		cout << "Insert Model: ";
		cin >> M;

		for (auto i : cars) {
			if (i.GetModel() == M)
			{
				cout << i << endl;
				exist = 1;
			}
		}
		if (exist==0)
		{
			cout << "Car isn't exist :) ";
		}
		break;
	case 3:
		cout << "Insert Engine volume: ";
		cin >> E;

		for (auto i : cars) {
			if (i.GetEngineVolume() == E)
			{
				cout << i << endl;
				exist = 1;
			}
		}

		if (exist == 0)
		{
			cout << "Car isn't exist :) ";
		}
			
		break;
	case 4:
		cout << "Insert Year: ";
		cin >> Y;

		for (auto i : cars) {
			if (i.GetYear() == Y)
			{
				cout << i << endl;
				exist = 1;
			}
		}

		if (exist==0)
		{
			cout << "Car isn't exist :) ";

		}
		break;
	default:
		break;
	}
}

void menu() {

	while (loop)
	{
		if (loop == 1) {
			char ch;
			ch = _getch();
			int i = 0;
			char* arr = new char[3];
			int choice;

			while (true)
			{
				int temp = changeArr(arr, i, 4);

				printMenu(arr, temp);

				ch = _getch();

				if (int(ch) == -32) {
					ch = _getch();
					switch (int(ch))
					{
					case Up: i = i == 0 ? 4 : i - 1; break;
					case Down: i = i == 4 ? 0 : i + 1; break;
					}
				}

				else if (int(ch) == Enter) {
					choice = i;
					break;
				}
			}

			switch (choice)
			{
			case 0:
				system("cls");
				cout << "Amount of cars: " << cars.size() << endl;
				for (auto i : cars) {
					cout << i << endl;
				}
				break;
			case 1:
				system("cls");
				AddCar();
				break;
			case 2:
				system("cls");
				Searching();
				break;
			case 3:
				system("cls");
				break;
			case 4:
				system("cls");
				changeColor(Red);
				cout << "Bye :)";
				changeColor(White);
				loop = 0;
				break;
			default:
				break;
			}
		}
	}
}

#pragma endregion



void main() {


	Car obj1("mers", "s class", 6.3f, 2021);
	Car obj2("tesla", "model x", 0.0f, 2022);
	Car obj3("bmw", "model w", 0.0f, 2022);


	cars.push_back(obj1);
	cars.push_back(obj2);
	cars.push_back(obj3);


	menu();


	////////////////////////////////////

	//for (auto i : cars) {
	//	cout << i << " ";
	//}

	//string a = "tesla";
	////string t = "s class";
	////int c = 2021;

	////bool K=0;

	//for (auto i : cars) {
	//

	//	if (i.GetVendor()==a)
	//	{
	//		cars.remove(i);			
	//	}
	//}

	//for (auto i : cars) {
	//	cout << i;
	//}

	////////////////////////////////




}

