//#include <iostream>
//using namespace std;
//
//class MyString {
//	char* str;
//	int len = 0;
//public:
//	char* GetStr()const { return str; }
//	void  Setstr(const char* s) {
//		delete[] str;
//		int len = strlen(s);
//		str = new char[len + 1];
//		strcpy_s(str, len + 1, s);
//	}
//	MyString(char* str) {
//		Setstr(str);
//	}
//	//1)1 ci xarakter qaytaran method
//	char GetFirstChar() {
//		return str[0];
//	}
//	//2)sonuncu xarakter qaytaran method 
//	char GetLastChar() {
//		return str[len];
//	}
//	//3) Append(const char* text)  
//	char* Append(const char* text) {
//		int lentext = strlen(text);
//		int totalsize = lentext + len;
//		char* temp = new char[totalsize];
//		for (int i = 0; i < len; i++)
//		{
//			temp[i] = str[i];
//		}
//		int s = 0;
//		for (int i = lentext; i < totalsize; i++)
//		{
//			temp[i] = text[s];
//			s++;
//		}
//		delete[] text;
//		text = temp;
//		temp = nullptr;
//	}
//	//4) s.rfind('a') 
//	int Find(char c) {
//		for (int i = 0; i < len; i++)
//		{
//			if (c == str[i])
//			{
//				return i;
//			}
//		}
//	}
//	//5)s.find('w')//6 xarakterin indexi qayitsin
//	int RFind(char c) {
//		for (int i = len; i > 0; i--)
//		{
//			if (c == str[i])
//			{
//				return i;
//			}
//		}
//	}
//	//6)s.clear()//string silinsin delete edi
//	void Clear() {
//		delete[] str;
//	}
//	~MyString() {
//		delete[]str;
//	}
//};
//
//
///*
//1. IntArray class-i yaradin. Bu class massiv rolunu
//oynamalidir.
//Novbeti imkanlar olsun:
//- Massivin evveline reqem elave eden method
//- Massivin sonuna reqem elave eden method
//- Massivi copy etmek imkani yaradin
//- Print
//*/
//
//class  IntArray {
//	int size;
//	int* array = new int[size];
//public:
//
//	//Get
//	int GetSize() const { return size; }
//	int* GetArray()const { return array; }
//	
//	//Set
//	void Setsize(int size) { this->size = size; }
//	void SetArray(int* array) {
//		delete[] this->array;
//		this->array = new int[size];
//		for (int i = 0; i < size; i++)
//		{
//			this->array[i] = array[i];
//		}
//	}
//	IntArray(){}
//	IntArray(int* arr,int size){
//		SetArray(arr);
//		Setsize(size);
//	}
//	//Massivin evveline reqem elave eden method
//	void AddElStart(int element) {
//		int* newarray = new int[size+1];
//		newarray[0] = element;
//		for (int i = 1; i < size; i++)
//		{
//			newarray[i] = array[i - 1];
//		}
//		SetArray(newarray);
//	}
//	//Massivin sonuna reqem elave eden method
//	void AddElEnd(int element) {
//		int* newarray = new int[size + 1];
//		newarray[size] = element;
//		for (int i = 0; i < size; i++)
//		{
//			newarray[i] = array[i];
//		}
//		SetArray(newarray);
//	}
//	//Massivi copy etmek imkani yaradin
//	IntArray(const IntArray& o)
//	{
//		Setsize(o.size);
//		SetArray(o.array);
//	}
//	//Print
//	void Print() {
//		for (int i = 0; i < size+1; i++)
//		{
//			cout<<array[i] << " ";
//		}
//	}
//	~IntArray() {
//		delete[]array;
//	}
//};

//int main() {
//}
