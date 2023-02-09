//Function Overloading


//	4. Bubble sort edən funksiya yazın. (Funksiya massiv, ölçüsü və bool
//		qəbul edir.Əgər funksiyaya true göndərilərsə sort - azalandan artana,
//		false qəbul edirsə artandan azalana sort olur)




#include <iostream>
using namespace std;

//1. Massivin random ədədlərlə doldurulmasını realizasiya edin. (int,
//	double, float, char)  

void massivfill(int a[], int size) {
	for (int i = 0; i < size; i++)
	{
		a[i] = rand() % 10;
	}

}
void massivfill(float a[], int size) {
	for (int i = 0; i < size; i++)
	{
		a[i] = (rand() % 10) / 10.0;
	}

}void massivfill(double a[], int size) {
	for (int i = 0; i < size; i++)
	{
		a[i] = (rand() % 10) / 10.0;
	}

}
void massivfill(char a[], int size) {
	for (int i = 0; i < size; i++)
	{
		a[i] = char(rand() % 256);
	}

}

//2. Massivin verilən diapazonda ədədlərlə dolduruması. (Funksiya,
//massiv, onun ölçüsü, min və max qiymətlər qəbul edir) (Overload
//lazım deyil)


void fillingarrbetween(int arr[], int size, int max, int min) {

	int i = 0;
	for (int j = 10; j < 20; j++)
	{

		arr[i] = j;
		i++;
	}

	for (int k = 0; k < size; k++)
	{
		cout << arr[k] << " ";
	}
	cout << endl;


}

//	3. Massivi ekrana çıxaran funksiya. (int, double, float, char)

void printarray(int a[], int size) {
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
}


void printarray(float a[], int size) {
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
}

void printarray(char a[], int size) {
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
}
void printarray(double a[], int size) {
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
}

//	5. Massivdəki elementi axtaran funksiya yazın.(Funksiyaya massiv,
//		ölçüsü və axtarılan rəqəm göndərilir.) Funksiya tapılan elementin
//	indexini qaytarır. (int, double, float, char)


int findnum(int arr[], int size, int number) {

	for (int i = 0; i < size; i++)
	{
		if (number == arr[i]) {
			return i;
		}
	}
}
float findnum(float arr[], int size, float number) {

	for (int i = 0; i < size; i++)
	{
		if (number == arr[i]) {
			return i;
		}
	}
}
double findnum(double arr[], int size, double number) {

	for (int i = 0; i < size; i++)
	{
		if (number == arr[i]) {
			return i;
		}
	}
}
char findnum(char arr[], int size, char number) {

	for (int i = 0; i < size; i++)
	{
		if (number == arr[i]) {
			return i;
		}
	}
}


//	6. Massivdəki ən kiçik elemnti tapan funksiya yazın. (Massivi sort etmək
//		olmaz)

int findmin(int arr[], int size) {
	int temp = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (temp > arr[i]) {
			temp = arr[i];
		}

	}
	return temp;
}



//	7. Massivdəki ən böyük elementi tapan funksiya yazın. (Massivi sort
//		etmək olmaz) (int, double, float, )

int findmax(int arr[], int size) {
	int temp = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (temp < arr[i]) {
			temp = arr[i];
		}

	}
	return temp;
}

float findmax(float arr[], int size) {
	int temp = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (temp < arr[i]) {
			temp = arr[i];
		}

	}
	return temp;
}

double findmax(double arr[], int size) {
	int temp = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (temp < arr[i]) {
			temp = arr[i];
		}

	}
	return temp;
}


//	8. Massivin funksiyaya ötürülən rəqəm qədər sağa dövrü sürüşməsini
//	yerinə yetirən funksiya yazın. (Funksiyaya massiv, ölçüsü, və
//		sürüşmə indeksi göndərilir) Məsələn massiv : 1, 2, 3, 4, 5 rəqəmləri ilə
//	dolurudur, sürüşmə indexi 2dirsə, cavab : 4, 5, 1, 2, 3


void arrreversing(int arr[], int size, int loop) {

	for (int j = 0; j < size; j++)
	{
		cout << arr[j] << " ";
	}
	cout << endl << endl;
	while (loop > 0) {
		int temp = arr[0];
		for (int i = 0; i < size; i++)
		{
			arr[i] = arr[i + 1];
		}
		arr[size - 1] = temp;
		loop -= 1;
	}

	for (int k = 0; k < size; k++)
	{
		cout << arr[k] << " ";
	}
}


////////////////////////////////////////////////////////////////////
//TEMPLATE

//1. Massivdəki maximum elementi qaytaran funksiya yazın.

template<typename T>
T findmax(T arr[], int size) {
	int temp = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (temp < arr[i]) {
			temp = arr[i];
		}

	}
	return temp;
}

//2. Massivdəki minimum elementi qaytaran funksiya yazın.

template<typename T>
T findmin(T arr[], int size) {
	int temp = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (temp > arr[i]) {
			temp = arr[i];
		}

	}
	return temp;
}

//3. İki ədəd arasındakı böyük rəqəmi qaytaran funksiya yazın.

template<typename A, typename B>
float bignum(A i, B j) {
	if (i > j) {
		return i;
	}
	else if (j > i) {
		return j;
	}
}
//cout << bignum(11, 8.6)

//4. İki ədəd arasındakı kiçik ədədi qaytaran funksiya yazın.

template<typename G, typename L>

float smallernum(G i, L j) {
	if (i > j) {
		return j;
	}
	else if (j > i) {
		return i;
	}
}

//5. Calculator yazın.

template<typename X, typename Y>
void calculator(X num1, Y num2) {

	int choice;
	cout << "1)+\n2)-\n3)*\n4)/\n";
	cin >> choice;

	switch (choice)
	{
	case 1:
		cout << num1 + num2;
		break;
	case 2:
		cout << num1 - num2;
		break;
	case 3:
		cout << num1 * num2;
		break;
	case 4:
		cout << num1 / num2;
		break;
	default:
		break;
	}
}

//1. Dinamik yaddaş ayıran funskiya yazın.

template<typename T>
T* mainarr(int size) {
	return new T[size]{};
}
//2. Dinamik massivi random ədədlərlə dolduran funksiya yazın.

void randomfill(int* ptr, int size) {
	for (int i = 0; i < size; i++)
	{
		*(ptr + i) = rand() % 10;
	}
}
//3. Dinamik massivi ekrana çıxaran funksiya yazın.
void coutarr(int* ptr, int size) {
	for (int i = 0; i < size; i++)
	{
		cout << *(ptr + i) << " ";
	}
	cout << endl;
}
//4. Dinamik massivi silən funksiya yazın.
void deletearr(int* ptr, int size) {
	delete ptr;
}
//5. Dinamik massivin sonuna element əlavə edən funksiya yazın.

int* appendnumber(int* dest, int size, int num) {
	int* temp = new int[size + 1]{};
	for (int i = 0; i < size; i++)
	{
		*(temp + i) = *(dest + i);
	}
	*(temp + size) = num;
	return temp;
}
//6. Dinmaik massivin göstərilən indexinə element əlavə edən funksiya
//yazın.
int* addnumtoindex(int* arr, int size, int number, int index) {
	for (int i = 0; i < size; i++)
	{
		if (i + 1 == index)
		{
			*(arr + i) = number;
		}
	}
	return arr;
}
//7. Dinamik massivdən göstərilən indexdəki elementin silinməsi.
int* deletenumfromindex(int* arr, int size, int index) {
	for (int i = 0; i < size; i++)
	{
		if (i == index)
		{
			for (i = index; i <= size; i++)
			{
				arr[i] = arr[i + 1];
			}
		}
	}
	return arr;
}
//8. Dinamik massivin sonuna bir blok element əlavə edən funksiya yazın.

int* linkarrays(int* arr, int firstsize) {
	const int secondsize = 3;
	int arr2[secondsize] = { 11,22,33 };
	int totalsize = firstsize + secondsize;
	int* temp = new int[firstsize + secondsize]{};

	for (int i = 0; i < firstsize; i++)
	{
		*(temp + i) = *(arr + i);
	}
	int k = 0;
	for (int j = firstsize; j < totalsize; j++)
	{
		*(temp + j) = arr2[k++];
	}
	cout << endl;
	for (int w = 0; w < totalsize; w++)
	{
		cout << temp[w] << " ";

	}
	return temp;

}

//9. Dinamik massivin göstərilən indexindən sonra bir blok element əlavə
//edən funksiya yazın.

int* linkindexarrays(int* arr, int firstsize, int index) {
	const int secondsize = 3;
	int arr2[secondsize] = { 11,22,33 };
	int totalsize = index + secondsize;
	int* temp = new int[firstsize + secondsize]{};

	for (int i = 0; i < firstsize; i++)
	{
		*(temp + i) = *(arr + i);
	}
	int k = 0;
	for (int j = index; j < totalsize; j++)
	{
		*(temp + j) = arr2[k++];
	}
	cout << endl;
	for (int w = 0; w < totalsize; w++)
	{
		cout << temp[w] << " ";

	}
	return temp;

}
//10. Dinamik massivdən bir blok elementi silən funksiya yazın.

int* deleteblokfromarray(int* arr, int size, int startindex, int endindex) {

	for (int w = 0; w < size; w++)
	{
		cout << arr[w] << " ";

	}
	cout << endl;
	cout << endl;
	
	for (int i = 0; i < size; i++)
	{
		if (i == startindex)
		{
			for (; i <= endindex; i++)
			{
				arr[i] = arr[i + 1];
			}
		}
	}

	/*for (int w = 0; w < size-(endindex-startindex+1); w++)
	{
		cout << arr[w] << " ";

	}
	return arr;*/
	for (int w = 0; w < size; w++)
	{
		cout << arr[w] << " ";

	}
	return arr;


}



int main()
{
	int arr2[10] = { 1,2,3,4,5,6,7,8,9,0 };


	deletenumfromindex(arr2, 10, 5);
	cout << endl;
	deleteblokfromarray(arr2,10,2,5);










	/////HEAP STACK
	int* ptr = mainarr<int>(6);
	//6
	/*randomfill(ptr, 6);
	coutarr(ptr, 6);
	addnumtoindex(ptr, 6, 99, 3);
	coutarr(ptr, 6);*/
	//7
	/*randomfill(ptr, 6);
	coutarr(ptr, 6);
	deletenumfromindex(ptr, 6,3);
	coutarr(ptr, 5);*/
	//8
	//randomfill(ptr, 6);
	//coutarr(ptr, 6);
	//linkarrays(ptr, 6);
	//9
	//randomfill(ptr, 6);
	//coutarr(ptr, 6);
	//linkindexarrays(ptr, 6,4);

	//10
	//int a8[8] = { 1,2,3,4,5,6,7,8 };
	//deleteblokfromarray(a8, 8);
	//coutarr(ptr, 6);


	//deletearr(ptr, 6);
	//ptr = appendnumber(ptr, 6, 211);




	//calculator(5, 6.5);
	//int arrA[10] = {1,2,3,4,5,67,8,9,12,3};
	//cout << bignum(11, 8.6);

	//cout << findmax(arrA, 10);
	//cout << findmin(arrA, 10);





	//fillingarrbetween(arrA, 10, 20, 11);


	//arrreversing(arrA, 10, 2);

	////////////////////////////////////////////////////////////////////////////
	//POINTERS
	//1. Pointerdən istifadə edərək, İki ədədnin böyük olanını tapan program
	//yazın.
	/*int num1 = 3, num2 = 8;
	int* ptr1 = &num1, * ptr2 = &num2;
	if (*ptr1>*ptr2)
	{
		cout << *ptr1 << endl;
	}
	else {
		cout << *ptr2 << endl;
	}*/

	//2. Pointerdən istifadə edərək, İstiadəçinin daxil etdiyi rəqəmin işarəsini
	//tapan program yazın.

	/*int userinput = 0;
	int* ptr = &userinput;
	cout << "Insert number: ";
	cin >> *ptr;
	*ptr > 0 ? cout << "+ " : cout << "- ";*/

	//3. Pointerdən istifadə edərək, iki dəyişənin yerini dəyişən program
	//yazın.

	/*int num1 = 9, num2 = 1,execute=0;
	int* ptr1 = &num1, * ptr2 = &num2;

	execute=*ptr1;
	*ptr1 = *ptr2;
	*ptr2 = execute;
	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl;
	*/

	//4. Ancaq pointerdən istifadə edərək, primitiv kalkulyator yazın.

	//int num1, num2,choice;
	//int* ptr1 = &num1;
	//int* ptr2 = &num2;

	//cout << "Insert num1: ";
	//cin >> *ptr1;
	//cout << endl;

	//cout << "1)+\n2)-\n3)*\n4)/\n";
	//cin >> choice;

	//cout << "Insert num2: ";
	//cin >> *ptr2;
	//cout << endl;

	//switch (choice)
	//{
	//case 1:
	//	cout << *ptr1 + *ptr2;
	//	break;
	//case 2:
	//	cout << *ptr1 - *ptr2;
	//	break;
	//case 3:
	//	cout << *ptr1 * *ptr2;
	//	break;
	//case 4:
	//	cout << *ptr1 / *ptr2;
	//	break;
	//default:
	//	break;
	//}

	//5. Tam ədədlərdən ibarət massivin elementlərini toplayan program
	//yazın.


	//int arr[5] = { 1,2,3,4,5 }, sum = 0;;
	//int* ptr = arr;

	//for (int i = 0; i < 5; i++)
	//{
	//	sum += *(ptr+i);
	//}
	//cout << sum;

	//6. İki pointerdən istifadə edərək, bir massivdəki elementləri digərinə
	//kopyalayn program yazın.

	//int arr1[6] = { 1,2,3,4,5,6 };
	//int arr2[6] = {};
	//int* ptr1 = arr1;
	//int* ptr2 = arr2;
	//
	//	for (int j = 0; j < 6; j++)
	//	{
	//		arr2[j] = *(ptr1++);
	//	}
	//

	//for (int k = 0; k < 6; k++)
	//{
	//	cout << *(ptr2++) << " ";
	//}

//7. Pointerlərdən istifadə edərək, ölçüsü 10 olan massivdə elementlərin
//sırasını tərsinə çevirən program yazın.


//int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//int arr2[10] = {};
//int* ptr1 = arr1;
//int* ptr2 = arr2;	
//
//for (int i = 0; i < 10; i++)
//{
//	arr2[i] = *(ptr1+9-i);
//}
//
//ptr1 = ptr2;
//
//for (int k = 0; k < 10; k++)
//{
//	cout << *(ptr1 + k)<<" ";
//}
//cout << endl;

//8. İki pointerdən elə istifadə edin ki, birinci massivdən ikinci massivə
//ədədləri tərsinə kopyalayan program yazın

//int arr1[10] = {};
//
//for (int h = 0; h < 10; h++)
//{
//	cin >> arr1[h];
//}
//
//int arr2[10] = {};
//int* ptr1 = arr1;
//int* ptr2 = arr2;
//
//for (int i = 0; i < 10; i++)
//{
//	arr2[i] = *(ptr1 + 9 - i);
//	
//}
//
//for (int k = 0; k < 10; k++)
//{
//	cout << *(ptr1 + k) << " ";
//}
//cout << endl;
//
//for (int k = 0; k < 10; k++)
//{
//	cout << *(ptr2 + k) << " ";
//}
//cout << endl;

//9. Pointerlərdən istifadə edərək, massivin maximal və minimal
//elementlərini tapan program yazın.

	//int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//int max = arr[0], min = arr[0], * ptrmax = &max, * ptrmin = &min;
	//int* ptr = arr;

	//for (int i = 0; i < 10; i++)
	//{
	//	if (*ptrmax < *(ptr + i))
	//	{
	//		*ptrmax = *(ptr + i);
	//	}
	//	if (*ptrmin > *(ptr + i))
	//	{
	//		*ptrmin = *(ptr + i);
	//	}
	//}
	//cout << "max: " << max << endl;
	//cout << "min: " << min << endl;

	//10. Pointerlərdən istifadə edərək massivi dövrü sürüşdürən program
	//yazın. (bu tapışırıq dövrlərdə iki dəfə yazmısınız, alqoritmini ordan
	//götürə bilərsiniz)

	//const int size = 10;
	//int arr[size] = { 1,2,3,4,5,6,7,8,9,10 };
	//int* ptr = arr;
	//
	//int	loop = 3;
	//cout << "Insert number: ";
	//cin >> loop;

	//
	//while (loop > 0)
	//{
	//int execute = arr[0];
	//int * ptrex = &execute;

	//	for (int i = 0; i < size; i++)
	//	{
	//		arr[i] = arr[i+1];
	//	}
	//	arr[size-1] = *ptrex;
	//	loop -= 1;
	//}

	//for (int k = 0; k < size; k++)
	//{
	//	//cout << arr[ k]<<" ";
	//	cout << *(ptr + k)<<" ";
	//}



























}