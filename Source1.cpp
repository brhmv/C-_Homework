#include <iostream>
#include <string>
#include <stack>
using namespace std;


class Engine {
	string engineNo = "";
	float volume = 0;
	string company = "";
public:

#pragma region GetSet

	//GET
	string GetEngineNo() { return engineNo; }
	float GetVolume() { return volume; }
	string GetCompany() { return company; }
	//SET
	void SetEngineNo(string v) { engineNo = v; }
	void SetVolume(double m) { volume = m; }
	void SetCompany(string e) { company = e; }

#pragma endregion

	Engine() {}

	Engine(string eNo, string comp, double vol) : engineNo(eNo), company(comp), volume(vol) {}

	friend ostream& operator<<(ostream& out, const Engine obj) {
		out << "*****Engine***** \nEngine Number: " << obj.engineNo << "\nCompany: " << obj.company << "\nVolume: " << obj.volume;
		return out;
	}
};


class Vehicle {
	static int staticId;
	int id;
	string vendor;
	string model;
	Engine engine;
public:
#pragma region GetSet
	//Get
	string GetVendor() { return vendor; }
	string GetModel() { return model; }
	Engine GetEngine() { return engine; }
	//Set
	void SetVendor(string v) { vendor = v; }
	void SetModel(string m) { model = m; }
	void SetEngine(Engine e) { engine = e; }
	void Setid(int i) { id = i; }
#pragma endregion


	Vehicle(string vend, string mod, Engine eng) {
		Setid(staticId++);
		SetVendor(vend);
		SetModel(mod);
		SetEngine(eng);
	}

	virtual void Show() {
		cout << "Id: " << id << "\nVendor: " << vendor << "\nModel: " << model << "\n" << engine << endl;
	}

};

int Vehicle::staticId = 1;

class Car :public Vehicle {
	bool hasSpoiler;
public:

#pragma region GetSet
	bool GetHasSpoiler() { return hasSpoiler; }
	void SetHasSpoiler(bool b) { hasSpoiler = b; }
#pragma endregion


	Car(string vend, string mod, Engine eng, bool hasSpoiler) : Vehicle(vend, mod, eng) {
		SetHasSpoiler(hasSpoiler);
	}

	void Show() override {
		cout << "*******Car*******\n";
		Vehicle::Show();
		cout << "Spoiler: " << (GetHasSpoiler() ? "exist" : "not exist.") << endl;
	}
};


class Ship : public Vehicle {

	bool hasSail;

public:

#pragma region GetSet
	bool GetHasSail() { return hasSail; }
	void SetHasSail(bool b) { hasSail = b; }
#pragma endregion


	Ship(string vend, string mod, Engine eng, bool hasSail) : Vehicle(vend, mod, eng) {
		SetHasSail(hasSail);
	}

	void Show() override {
		cout << "*******Ship*******\n";
		Vehicle::Show();
		cout << "Sail: " << (GetHasSail() ? "exist." : "not exist.") << endl;
	}
};

class Airplane : public Vehicle {

	int engineCount;
	int passangerCapacity;

public:

#pragma region GetSet

	int GetEngineCount() { return engineCount; }
	void SetEngineCount(int b) { engineCount = b; }

	int GetPassangerCapacity() { return passangerCapacity; }
	void SetPassangerCapacity(int b) { passangerCapacity = b; }
#pragma endregion


	Airplane(string vend, string mod, Engine eng, int engCount,int passCapacity) : Vehicle(vend, mod, eng) {
		SetPassangerCapacity(passCapacity);
		SetEngineCount(engCount);
	}

	void Show() override {
		cout << "*******Airplane*******\n";
		Vehicle::Show();
		cout << "Passanger Capacity: " << GetPassangerCapacity() << "\nEngine Count: " <<GetEngineCount() << endl;
	}
};

class Depo {
public:
	stack<Vehicle*> vehicles;

	void ShowAllVehicles() {
		while (!vehicles.empty()) {
			vehicles.top()->Show();
			vehicles.pop();
		}
	}

};


int main() {

	Depo* garrage = new Depo();
	garrage->vehicles.push(new Car("bmw", "m8", Engine("100", "volvo", 4.4), true));
	garrage->vehicles.push(new Ship("yamaha", "2522SD", Engine("256", "Yamaha", 1.8), false));
	garrage->ShowAllVehicles();
	delete garrage;

}