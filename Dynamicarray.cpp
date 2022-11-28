#include <iostream>
#include <time.h>
using namespace std;
//Task 
// Class DynamicArray (template<class t, int len>)
// Example: DynamicArray<double, 20> da;
// Copy Constructor, Copy Assignment operator, Default Constructor
// InitRandom()
// [] operator overloading
// AddElementToEnd
// AddElementToHead
// AddElementByIndex
// DeleteElementByIndex
// Print()

template<class T, int len>
class DynamicArray {
public:
	T* arr = new T[len];
	int capacity = len;
	int count = 0;

	//Default
	DynamicArray() {
		arr = new T[capacity];
	}

	//Coppy Constructor
	DynamicArray(DynamicArray const& other) {
		delete[] arr;
		arr = other.arr;
		arr = new T(*other.arr);
		for (int i = 0; i < other.count; i++)
		{
			arr[i] = other.arr[i];
		}
		count = other.count;
	}

	//Copy Assignment operator
	DynamicArray& operator=(const DynamicArray& other) {
		delete[] arr;
		arr = other.arr;
		arr = new T(*other.arr);
		for (int i = 0; i < other.count; i++)
		{
			arr[i] = other.arr[i];
		}
		count = other.count;
	}

	//InitRandom()
	void InitRandom() {
		srand(time(0));
		for (int i = 0; i < len; i++)
		{
			arr[i] = rand() % 10;
		}
		count = len;

	}

	// [] operator overloading
	DynamicArray& operator[](int index) {
		return arr[index];
	}

	// AddElementToEnd
	void AddElementToEnd(T element) {
		if (capacity == count)
		{
			capacity += len;
			T* temp = new T[capacity];
			for (int i = 0; i < count; i++)
			{
				temp[i] = arr[i];
			}
			delete[] arr;
			arr = temp;
			temp = nullptr;
		}
		arr[count] = element;
		count += 1;
	}

	// AddElementToHead
	void AddElementToHead(T element) {
		if (capacity == count)
		{
			capacity += len;
			T* temp = new T[capacity];
			for (int i = 0; i < count; i++)
			{
				temp[i + 1] = arr[i];
			}
			delete[] arr;
			arr = temp;
			temp = nullptr;
		}
		else if (capacity != count)
		{
			T* temp = new T[capacity];
			for (int i = 0; i < count; i++)
			{
				temp[i + 1] = arr[i];
			}
			delete[] arr;
			arr = temp;
			temp = nullptr;
		}
		arr[0] = element;
		count += 1;
	}


	void AddElementByIndex(int index, T element) {
		if (count != capacity) {
			T* temp = new T[capacity];
			for (int i = 0; i < index; i++) {
				temp[i] = arr[i];
			}
			for (int i = index + 1; i < count + 1; i++) {
				temp[i] = arr[i - 1];
			}
			delete[] arr;
			arr = temp;
			temp = nullptr;
		}
		else if (count == capacity) {
			capacity += len;
			T* temp = new T[capacity];
			for (int i = 0; i < index; i++) {
				temp[i] = arr[i];
			}
			for (int i = index + 1; i < count + 1; i++) {
				temp[i] = arr[i - 1];
			}
			delete[] arr;
			arr = temp;
			temp = nullptr;
		}
		arr[index] = element;
		count++;
	}

	void DeleteElementByIndex(int index) {
		T* temp = new T[count - 1];
		for (int i = 0; i < index; i++) {
			temp[i] = arr[i];
		}
		for (int i = index; i < count - 1; i++) {
			temp[i] = arr[i + 1];
		}
		delete[] arr;
		arr = temp;
		temp = nullptr;
		count--;
	}

	void Show() {
		for (int i = 0; i < count; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	~DynamicArray() {
		delete[] arr;
	}

};

void main() {
	DynamicArray <int, 10> w;
	w.InitRandom();
	w.Show();
	w.AddElementToHead(9991);
	w.Show();
	w.AddElementToEnd(999);
	w.Show();


}