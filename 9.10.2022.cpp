#include <iostream>
using namespace std;


// Task 1:
class Fraction {
private:
	int numerator; // suret
	int denominator; // mexrec
public:
	int getN() { return numerator; }
	int getD() { return denominator; }


	void SetN(int arg) { numerator = arg; }
	void SetD(int arg) { denominator = arg; }

	Fraction(int numerator, int denominator) {
		this->numerator = numerator;
		this->denominator = denominator;
	}

	// Kesri kesre vurub yeni kesr qaytarir
	Fraction Multiply(const Fraction& other) {
		int num = this->numerator * other.numerator;
		int den = this->denominator * other.denominator;
		return Fraction(num, den);
	}

	// Kesri kesrle toplayib yeni kesr qaytarir
	Fraction Add(const Fraction& other) {
		if (this->denominator == other.denominator)
		{
			int num = this->numerator + other.numerator;
			int den = this->denominator;
			return Fraction(num, den);
		}
		else
		{
			this->numerator = numerator * other.denominator;
			int num = other.numerator * this->denominator;
			int den = this->denominator * other.denominator;
			num = this->numerator + other.numerator;
			return Fraction(num, den);
		}
	}
	// Kesri kesrden chixib yeni kesr qaytarir

	Fraction Minus(const Fraction& other) {
		if (this->denominator == other.denominator)
		{
			int num = this->numerator - other.numerator;
			int den = this->denominator;
			return Fraction(num, den);
		}
		else
		{
			this->numerator = numerator * other.denominator;
			int num = other.numerator * this->denominator;
			int den = this->denominator * other.denominator;
			num = this->numerator - other.numerator;
			return Fraction(num, den);
		}
	}

	// Kesri kesre bolub yeni kesr qaytarir

	Fraction Divide(const Fraction& other) {
		int num = this->numerator * other.denominator;
		int den = this->denominator * other.numerator;
		return Fraction(num, den);
	}

	// Kesri ixtisar edir

	Fraction Simplify(const Fraction& other) {
		if (this->denominator % this->numerator == 0)
		{
			int num = this->numerator / this->numerator;
			int den = this->denominator / this->numerator;
			return Fraction(num, den);
		}
		else
		{
			for (int i = 2; i <= this->numerator; i++)
			{
				if (this->numerator % i == 0 && this->denominator % i == 0)
				{
					int num = this->numerator / i;
					int den = this->denominator / i;
					return Fraction(num, den);
				}
			}
		}
	}
};

// Task 2:

//Point class yazilsin
//x, y fieldleri olsun ve her bir field uchun getter setterler yazilsin.
//constructor parametric, default
//Print method - u yazilsin

class Point {
	int x, y;
public:

	//Get
	int GetX() { return x; }
	int GetY() { return y; }

	//Set
	void SetX(int x) { this->x = x; }
	void SetY(int y) { this->y = y; }

	//default
	Point() {
		x = 0;
		y = 0;
	}

	//constructor parametric
	Point(int x, int y) {
		SetX(x);
		SetX(y);
	}

	//Print method 
	void Print() {
		cout << "x: " << x << " " << "y: " << y;
	}
};



//Task: 2.1
//
//Counter c(0, 100);//min,max,currentData
//c.increment();
//cout << getCurrent();//1
//c.increment();
//cout << getCurrent();//2
//2.Rəqəmsal sayğac məhdud diapazonlu dəyişəndir.Onun tam qiyməti təyin edilmiş maksimum qiymət həddinə
//(məsələn, k 0 - 100 diapazonunda qiymət alır) çatdığı zaman sıfırlanır.
//Bu cür sayğacın parametri kimi rəqəmsal saatı, kilometrölçən sayğacı nümunə göstərmək olar.
//Bu cür sayğac üçün sinfi təyin edin.Maksimal və minimal qiymətlərin verilməsini,
//sayğacın qiymətinin 1 vahid artırılmasını, cari qiymətin qaytarılmasını təmin edin.

class Counter {
public:
	int min, max, CurrentData = min;

	Counter() {}
	Counter(int min, int max) {
		this->min = min;
		this->max = max;
	}
	int increment() {
		if (CurrentData < max)
		{
			CurrentData += 1;
			return CurrentData;
		}
		else
		{
			CurrentData = min;
			return min;
		}
	}
};



//Task: 2.2
//Tələbələr qrupunu əks etdirən class təyin edin.
//Student : name, surname, age, group_no, speciality, city
//Print method - u yazilsin.

class Student {
	int age;
public:
	char* name;
	char* surname;
	int group_no;
	char* speciality;
	char* city;

	Student() {}

	Student(char* name, char* surname,int age, int group_no, char* speciality, char* city) {
		this->name = name;
		this->surname = surname;
		this->group_no = group_no;
		this->speciality = speciality;
		this->city = city;
		SetAge(age);
	}

	void SetAge(int age) { this->age = (age < 16 || age > 22) ? 16 : age; }

	int GetAge() { return age; }

};
	