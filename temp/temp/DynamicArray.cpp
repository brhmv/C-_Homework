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
	int count = len;

	//Default
	DynamicArray() {}

	//Coppy Constructor
	DynamicArray(const T& other) {
		arr = new T(*other.arr);
	}

	//Copy Assignment operator
	DynamicArray& operator=(const DynamicArray& o) {

		arr = new T[len];
		for (int i = 0; i < len; i++)
		{
			arr[i] = o.arr[i];

		}
		return *this;
	}

	//InitRandom()
	void InitRandom() {
		srand(time(0));
		for (int i = 0; i < len; i++)
		{
			arr[i] = rand() % 10;
		}
	}

	// [] operator overloading
	DynamicArray& operator[](int index) {
		return arr[index];
	}

	// AddElementToEnd
	void AddElementToEnd(T element) {
		if (len == count)
		{
			T* temp = new T[capacity + len];

			for (int i = 0; i < count; i++)
			{
				temp[i] = arr[i];
			}

		temp[count] = element;
		

			delete[] arr;
			arr = temp;
			temp = nullptr;
		}
		else
		{
			arr[count++] = element;
		}
	}

	// AddElementToHead
	void AddElementToHead(T element) {
		if (len == count)
		{
			T* temp = new T[capacity + len];
			temp[0] = element;

			for (int i = 0; i < count; i++)
			{
				temp[i + 1] = arr[i];
			}

			delete[] arr;
			arr = temp;
			temp = nullptr;
		}
		else
		{
			arr[0] = element;

			for (int i = 1; i < count; i++)
			{
				int temp = arr[i];
				arr[i + 1] = arr[i];
				arr[i] = temp;
			}
		}
	}


	// AddElementByIndex


	void  AddElementByIndex(T element, int index) {

		if (count < capacity)
		{
			T* temp = new T[capacity];

			for (int i = 0; i < index; i++)
			{
				temp[i] = arr[i];
			}

			temp[index] = element;

			for (int i = index + 1; i < count + 1; i++)
			{
				temp[i] = arr[i - 1];
			}

			delete[] arr;
			arr = temp;
			temp = nullptr;
		}
		else if (count == capacity) {
			capacity += len;
			T* temp = new T[capacity];

			for (int i = 0; i < index; i++)
			{
				temp[i] = arr[i];
			}

			temp[index] = element;

			for (int i = index + 1; i < count + 1; i++)
			{
				temp[i] = arr[i - 1];
			}

			delete[] arr;
			arr = temp;
			temp = nullptr;
		}
		count++;
	}

	void deleteElementByIndex(int index) {
		capacity = count - 1;
		T* temp = new T[capacity];

		for (int i = 0; i < index; i++)
		{
			temp[i] = arr[i];
		}

		for (int i = index; i < capacity; i++)
		{
			temp[i] = arr[i + 1];
		}

		delete[] arr;
		arr = temp;
		temp = nullptr;
		count--;
	}

	void Print() {
		for (int i = 0; i < capacity; i++)
		for (int i = 0; i < capacity; i++)
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
	DynamicArray<int,10> a;
	a.InitRandom();
	a.Print();
	
	
	a.AddElementToEnd(2222);
	a.Print();
	
	
	
	
	//a[3];
	//.AddElementToEnd(55);
	//a.Print();
	
	//a.AddElementToHead(99);
	//a.AddElementByIndex(3, 123);//error
	//a.Print();




}