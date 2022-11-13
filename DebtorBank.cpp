#include <iostream>
#include <string>
using namespace std;

class Debtor
{
	int objectId, salary, debt;
	string name, surname, workAddress, phoneNumber, liveAddress;
	bool  hasLatePayment;
	static int Id()
	{
		static int Id = 0;
		return Id++;
	}

public:
	#pragma region SETGET
	//Get
	string GetName() { return name; }

	string GetSurname() { return surname; }

	string GetWorkAddress() { return workAddress; }

	string GetPhoneNumber() { return phoneNumber; }

	string GetLiveAddress() { return liveAddress; }

	int GetSalary() { return salary; }

	int GetDebt() { return debt; }

	int GetObjectId() { return objectId; }

	bool GetHasLatePayment() { return hasLatePayment; }

	//Set
	void SetName(string n) { name = n; }

	void SetSurname(string s) { surname = s; }

	void SetWorkAddress(string w) { workAddress = w; }

	void SetPhoneNumber(string p) { phoneNumber = p; }

	void SetLiveAddress(string l) { liveAddress = l; }

	void SetSalary(int s) { salary = s; }

	void SetDebt(int d) { debt = d; }

	void SetHasLatePayment(bool h) { hasLatePayment = h; }

	void SetObjectId(static int i) { objectId = i; }

	#pragma endregion

	Debtor() :name(nullptr), surname(nullptr), workAddress(nullptr), phoneNumber(nullptr), liveAddress(nullptr), salary(0), debt(0), hasLatePayment(0) {};

	Debtor(string name, string surname, string workAdress, string phonenum, string liveadress, int salary, int d, bool hasLatePayment) {
		SetName(name);
		SetSurname(surname);
		SetWorkAddress(workAdress);
		SetPhoneNumber(phonenum);
		SetLiveAddress(liveadress);
		SetSalary(salary);
		SetDebt(d);
		SetHasLatePayment(hasLatePayment);

		SetObjectId(Id());
	}
	
	Debtor(Debtor& obj) {
		obj.SetDebt(this->GetDebt());
		obj.SetLiveAddress(this->GetLiveAddress());
		obj.SetName(this->GetName());
		obj.SetPhoneNumber(this->GetPhoneNumber());
		obj.SetSurname(this->GetSurname());
		obj.SetWorkAddress(this->GetWorkAddress());
		obj.SetSalary(this->GetSalary());
		obj.SetHasLatePayment(this->GetHasLatePayment());
		obj.SetObjectId(this->GetObjectId());
	}
	
	void showDebtor() {
		cout << "Id: " << GetObjectId() << endl << "Name: " << name << endl << "Surname: " << surname << endl
			<< "WorkAddress: " << workAddress << endl << "PhoneNumber: " << phoneNumber << endl
			<< "LiveAddress: " << liveAddress << endl << "Salary: " << salary << endl
			<< "Debt: " << debt << endl << "LatePayment: " << hasLatePayment << endl<<endl;
	}
};

class Bank {
public:
	int size = 15;
	Debtor* debtors;
	Bank() {
		debtors = new Debtor[size]{};
	}

	void showAllDebtorsName() {
		for (int i = 0; i < size; i++)
		{
			debtors[i].GetName();
		}
	}

	void showAllDebtorsInfo() {
		for (int i = 0; i < size; i++)
		{
			debtors[i].showDebtor();
		}
	}

	void debtMoreThan1000() {
		for (int i = 0; i < size; i++)
		{
			if (debtors[i].GetDebt() > 1000) {
				debtors[i].showDebtor();
			}
		}
	}

	void whohasLatePayment() {
		for (int i = 0; i < size; i++)
		{
			if (debtors[i].GetHasLatePayment()) {
				debtors[i].showDebtor();
			}
		}
	}


};
 

int main() {

	Debtor d("ibr", "surn", "wrokadrs", "phonum", "liveadres", 45, 12, 1);
	d.showDebtor();
	Debtor c("ibr", "surn", "wrokadrs", "phonum", "liveadres", 45, 12, 1);
	c.showDebtor();
	d = c;
	d.showDebtor();
}
