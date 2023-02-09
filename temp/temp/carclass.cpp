//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
////class : Car
////
////	class : Manual
////	class : Automatic
////
////	Manaul ve Automatic - den de mashinlar yaransin.
////	Misal class Bmw : Automatic
////
////	funksiya yazirisiz, Parametr olaraq Base qebul edir.
////	Funksiya icersinde mashinlarin melumatlarni chap edirsiz.
////
////	Her mashina aid field - ler ve methodlar olsun.
////
////	Base class adi altinda butun mashinlari vector - da saxlamaq
////	Dersde kecdiylermizden istifade etmek
//
//class Car {
//	int milliage;
//	int year;
//	float engine;
//public:
//
//#pragma region GETSET
//	//GET
//	int GetMilliage() { return milliage; }
//	int GetYear() { return year; }
//	float GetEngine() { return engine; }
//	//SET
//	void SetMilliage(int n) { milliage = n; }
//	void SetYear(int y) { year = y; }
//	void SetEngine(float e) { engine = e; }
//#pragma endregion	
//
//	Car(int milliage, int year, float engine) {
//		SetMilliage(milliage);
//		SetYear(year);
//		SetEngine(engine);
//	}
//
//	virtual void Show() {
//		cout << "Milliage: " << milliage << "\nYear: " << year << "\nEngien volume: " << engine << endl;
//	}
//};
//
//class Manual :public Car {
//public:
//	bool ismanual;
//	Manual(int milliage, int year, float engine, bool manual) :Car(milliage, year, engine) {
//		ismanual = manual;
//	}
//
//	void Show() {
//		Car::Show();
//		cout << "Is Manual: " << ismanual << endl;
//	}
//};
//
//class Automatic :public Car {
//public:
//	bool isautomatic;
//	Automatic(int milliage, int year, float engine, bool automatic) :Car(milliage, year, engine) {
//		isautomatic = automatic;
//	}
//
//	void Show() {
//		Car::Show();
//		cout << "Is Automatic: " << isautomatic << endl;
//	}
//
//};
//
//class Tesla :public Automatic {
//public:
//	string model;
//
//	Tesla(string model, int milliage, int year, float engine, bool automatic) :Automatic(milliage, year, engine, automatic) {
//		this->model = model;
//	}
//
//	void Show()override {
//		cout << "Name: Tesla\n" << "Model: " << model << endl;
//		Automatic::Show();
//	}
//};
//
//class Vaz :public Manual {
//public:
//	string model;
//
//	Vaz(string model, int milliage, int year, float engine, bool manual) :Manual(milliage, year, engine, manual) {
//		this->model = model;
//	}
//
//	void Show()override {
//		cout << "Name: Tesla\n" << "Model: " << model << endl;
//		Manual::Show();
//	}
//};
//
//class Garrage {
//public:
//	vector <Car*> cars;
//};
//
//void main() {
//
//	Garrage* garrage = new Garrage();
//
//	Tesla* tesla=new Tesla("Model X", 0, 2022, 0.0, 1);
//
//	garrage->cars.push_back(tesla);
//}