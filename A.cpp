#include <iostream>
#include <fstream>
#include<stdio.h> 
#include <vector>

using namespace std;

class Contact {
	string name;
	string surname;
	string phoneNumber;

public:

	Contact() {}

	Contact(string name, string surname, string phoneNumber)
	{
		SetName(name);
		SetSurname(surname);
		SetPhoneNumber(phoneNumber);
	}

#pragma region GETSET
	void SetName(string name) {
		this->name = name;
	}

	void SetSurname(string surname) {
		this->surname = surname;
	}

	void SetPhoneNumber(string phoneNumber) {
		this->phoneNumber = phoneNumber;
	}

	string GetName()const { return name; }

	string GetSurname()const { return surname; }

	string GetPhoneNumber()const { return phoneNumber; }
#pragma endregion

	friend class Database;
};



class Database : public Contact {
public:

	void AddContact(Contact contact) {
		ofstream phone("contact.txt", ios::app);
		if (phone.is_open()) {
			phone << contact.GetName() << " " << contact.GetSurname() << " "
				<< contact.GetPhoneNumber() << endl;
			cout << "\n\tContact saved successfully !";
		}
		else {
			throw "\n\tFile cant be opened";
		}

		cout << endl << endl;
		system("pause");
		system("cls");
		phone.close();
	}


	void DeleteByName(string name) {
		vector<Contact> contacts;

		ifstream phone("contact.txt", ios::in);

		while (phone.is_open()) {

			string namef;
			string surnamef;
			string phoneNumberf;

			while (!phone.eof()) {

				phone >> namef;
				phone >> surnamef;
				phone >> phoneNumberf;

				Contact c = Contact(namef, surnamef, phoneNumberf);

				contacts.push_back(c);
			}

			phone.close();
		}


		for (int i = 0; i < contacts.size(); i++) {
			if (contacts[i].name == name) {
				contacts.erase(contacts.begin() + i);
			}
		}


		ofstream phone1("contact.txt", ios::out);
		if (phone1.is_open()) {
			for (int i = 0; i < contacts.size(); i++) {
				phone1 << contacts[i].name << " " << contacts[i].surname << " " << contacts[i].phoneNumber << endl;
			}
		}
		phone1.close();
	}

	void SearchByName(string n)
	{
		bool found = false;
		ifstream phone("contact.txt");
		while (phone >> name >> surname >> phoneNumber) {
			if (name == n) {
				system("cls");
				cout << "\n\n\n\t\tCONTACT";
				cout << "\n\nFirst Name : " << name;
				cout << "\nLast Name : " << surname;
				cout << "\nPhone Number : " << phoneNumber;
				found = true;
				break;
			}
		}
		if (found == false)
			throw "\nNo such contact is found!";

		cout << endl << endl;
		system("pause");
		system("cls");
	}

};


void main() {


	Contact c1 = Contact("Allahverdi", "Ibrahimov", "0705639890");
	Contact c2 = Contact("C", "D", "01");
	Contact c3 = Contact("A", "B", "02");
	Database* d = new Database();


	
		d->AddContact(c1);
		d->AddContact(c2);
		d->AddContact(c3);
		d->SearchByName("A");
		d->DeleteByName("C");
	

}