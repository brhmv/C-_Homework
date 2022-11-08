#include <iostream>
#include <Windows.h>
#include <vector>

using namespace std;



class Worker {
public:
	static int idCounter;
	int id;
	string name;
	string surname;
	int age;
	int pageCount;

	Worker() {
		id = idCounter++;
		name = "";
		surname = "";
		age = 0;
		pageCount = 0;
	}

	Worker(string name, string surname, int age, int pageCount) {
		id = idCounter++;
		this->name = name;
		this->surname = surname;
		this->age = age;
		this->pageCount = pageCount;
	}

	void Show() {
		cout << "Id: " << id << "\nName: " << name << "\nSurname: " << surname << "\nAge: " << age << "\nPageCount: " << pageCount << "\n";
	}

};
int Worker::idCounter = 100;


class WorkerQueue {
public:
	vector<Worker> workers;

	bool IsEmpty() const { return workers.empty(); }

	void Enqueue(const Worker& worker) {
		workers.push_back(worker);
	}

	void Dequeue() {
		if (!workers.empty())
			workers.erase(workers.begin());
	}

	Worker& Front() { return workers.front(); }
};

class Printer {
public:
	WorkerQueue queue;

	void AddWorker(const Worker& worker) {
		queue.Enqueue(worker);
	}

	void Start() {
		while (!queue.IsEmpty())
		{
			Worker worker = queue.Front();
			while (0 < worker.pageCount) {
				system("cls");
				worker.Show();
				Sleep(1000);
				worker.pageCount--;
			}

			queue.Dequeue();
		}

	}

};

void main() {
	Printer pr;
	pr.AddWorker(Worker("Azad", "Mammadli", 18, 3));
	pr.AddWorker(Worker("Akif", "A", 30, 2));
	pr.AddWorker(Worker("Aqil", "B", 12, 10));

	pr.Start();


}