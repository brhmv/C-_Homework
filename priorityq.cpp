#include <iostream>
#include <assert.h>
using namespace std;



class Student {

	string name;
	string surname;
	float gpa;

public:

	Student() {}

	Student(string name, string surname, float gpa) {
		SetName(name);
		SetSurname(surname);
		SetGpa(gpa);
	}


	friend ostream& operator<<(ostream& out, const Student& c) {
		out << "**Student**\n" << "Name: " << c.GetName() << endl << "Surname: " << c.GetSurname() << endl << "Gpa: " << c.GetGpa() << endl << endl;
		return out;
	}


	 bool operator>(Student const & o) {
		return this->gpa > o.GetGpa();
	}


#pragma region SETGET

	//Get
	string GetName() const { return name; }

	string GetSurname() const { return surname; }

	float GetGpa() const { return gpa; }

	//Set

	void SetName(string n) { name = n; }

	void SetSurname(string n) { surname = n; }

	void SetGpa(float n) { gpa = n; }

#pragma endregion

};





template<class T>
class PriorityQueue {
	T* arr;
	int capacity;
	int rear;
	int count;

	int GetMaxGpa() {
		int maxindex = 0;
		for (int i = 0; i < count; i++) {
			if (arr[i] > arr[maxindex]) {
				maxindex = i;
			}
		}
		return maxindex;
	}

public:

	PriorityQueue() {}

	PriorityQueue(int size) {
		arr = new T[size];
		capacity = size;
		rear = 0;
		count = 0;
	}

	bool IsFull() const { return count == capacity; }

	bool IsEmpty() const { return count == 0; }

	void Enqueue(T val) {
		assert(!IsFull() && "Queue is full");
		arr[rear++] = val;
		count++;
	}

	void Dequeue() {
		assert(!IsEmpty() && "Queue is empty");
		int index = GetMaxGpa();
		for (int i = index; i < count - 1; i++) {
			arr[i] = arr[i + 1];
		}
		count--;
		rear--;
	}

	T& Front() {
		assert(!IsEmpty() && "Queue is empty");
		return arr[GetMaxGpa()];
	}

	void Print() {
		for (int i = 0; i < count; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	~PriorityQueue() { delete[] arr; }
};


void main() {
	Student s1("Allahverdi", "Ibrahimov", 75.75f);
	Student s2("Hesen", "Hemidov", 91.5f);
	Student s3("W", "H", 63.5f);
	s1 > s2;
	PriorityQueue <Student> q(10);

	q.Enqueue(s1);
	q.Enqueue(s2);
	q.Enqueue(s3);

	q.Print();

	q.Dequeue();

	q.Print();
	q.Dequeue();
	q.Print();
}