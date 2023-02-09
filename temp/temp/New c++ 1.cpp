#include <iostream>
using namespace std;


///////////////////////////////////////////////////////
// STACK VƏ HEAP

//1. Dinamik yaddaş ayıran funskiya yazın
template<typename T>
T* mainarr(int size) {
	return new T[size]{};
}
//2. Dinamik massivi random ədədlərlə dolduran funksiya yazın
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

int* addelementtoindex(int* des, int size, int index, int elem) {
	int* temp = new int[size] {};
	for (int i = 0; i < size; i++)
	{
		if (i == index)
		{
			*(temp + i) = elem;
		}
	}
	return temp;
}

//7. Dinamik massivdən göstərilən indexdəki elementin silinməsi.

int* deletenumfromindex(int* arr, int size, int index) {
	for (int i = 0; i < size; i++)
	{
		if (i + 1 == index)
		{
			for (i = index; i <= 9; i++)
			{
				arr[i] = arr[i + 1];
			}
		}
	}
	return arr;
}

//8. Dinamik massivin sonuna bir blok element əlavə edən funksiya yazın.

int* linkarrays(int* arr, int firstsize, int arr2, int secondsize) {

	int totalsize = firstsize + secondsize;
	int* temp = new int[firstsize + secondsize]{};

	for (int i = 0; i < firstsize; i++)
	{
		*(temp + i) = *(arr + i);
	}
	int k = 0;
	for (int j = firstsize - 1; j < totalsize; j++)
	{
		*(temp + j) = arr[k++];
	}
	cout << endl;
	for (int w = 0; w < totalsize; w++)
	{
		cout << temp[w] << " ";

	}
	return arr;

}

//9. Dinamik massivin göstərilən indexindən sonra bir blok element əlavə
//edən funksiya yazın.

//int* linkindexarrays(int* arr, int firstsize, int index, int arr2, int secondsize) {
//
//	int totalsize = index + secondsize;
//	int* temp = new int[firstsize + secondsize]{};
//
//	for (int i = 0; i < firstsize; i++)
//	{
//		*(temp + i) = *(arr + i);
//	}
//	int k = 0;
//	for (int j = index; j < totalsize; j++)
//	{
//		*(temp + j) = arr2[k++];
//	}
//	cout << endl;
//	for (int w = 0; w < totalsize; w++)
//	{
//		cout << temp[w] << " ";
//
//	}
//	return temp;
//
//}

//10. Dinamik massivdən bir blok elementi silən funksiya yazın


int* deleteblokfromarr(int* dest, int size, int count) {
	int totalsize = size - count;
	int* temp = new int[totalsize] {};

	for (int i = 0; i < totalsize; i++)
	{
		*(temp + i) = *(dest + i);
	}

	return temp;
}

///////////////////////////////////////////////////////
//////////Rekursiya

//1. Ədədin faktorialını tapan rekursiv funksiya yazın.

int factorial(int number) {

	if (number > 0)
	{
		number - 1;
		return number * factorial(number - 1);
	}
}

//2. 0 - dan verilən rəqəmə kimi ədədlərin cəmini toplayan
//rekursiv funksiya yazın.

int sumrecursion(int number) {
	if (number > 1)
	{
		number - 1;
		return number + sumrecursion(number - 1);
	}
}

//3. Massivin hər bir elementini ekrana çıxaran rekursiv
//funksiya yazın.

void coutarrrecurs(int arr[], int size = 0) {


	if (size == 1)
		cout << arr[0];
	else
	{
		coutarrrecurs(arr, size - 1);
		cout << arr[size - 1] << " ";
	}

}
//4. Massivin hər bir elementinin cəmini tapan rekursiv
//funksiya yazın.

void sumarrrecurs(int arr[], int size) {
	int sum = 0;
	if (size == 1)
		cout << arr[0];
	else
	{
		sum += arr[size];
		coutarrrecurs(arr, size - 1);
		cout << "size:" << size << " ";
		cout << arr[size - 1] << " ";
		cout << "size:" << size << " ";
	}
	cout << "last:" << sum;
}

//5. Ədədin üstünü tapan rekursiv funksiya yazın.

int numberpow(int number, int pow) {

	//5  //3
	if (pow > 1)
	{
		//pow - 1;
		return number * sumrecursion(number - 1);
	}

}

///////////////////////////////////////////////////////
//////////Reference

//1. Funksiya, parametr olaraq, massiv və onun ölçüsünü qəbul
//edir.Massivin içərsindəki bütün mənfi ədədləri silin.

//void deleteNegativeNumbersFromArray(int*& arr, int& size) {
//	int c = 0;
//	for (int i = 0; i < size; i++) {
//		if (arr[i] >= 0)
//			c++;
//	}
//
//	int* temp = new int[c];
//	for (int i = 0, j = 0; i < size; i++) {
//		if (arr[i] >= 0) {
//			temp[j] = arr[i];
//			j++;
//		}
//	}
//
//	delete[] arr;
//	arr = temp;
//	temp = nullptr;
//	

//2. İki massiv verilib : А[M] və B[N] (M və N klaviaturadan daxil
//edilir).Minimal ölçüdə üçüncü massiv yaradıb bu iki
//massivi A massivinə yazın.

//void linkingarrays(int*& arra, int& sizea, int* arrb, int sizeb) {
//	int totalsize = sizea + sizeb;
//	int* temp = new int[totalsize] {};
//	for (int i = 0; i < sizea; i++)
//	{
//		*(temp + i) = *(arra + i);
//	}
//	int k = 0;
//	for (int j = sizea; j <= totalsize; j++)
//	{
//		*(temp + j) = arrb[k++];
//	}
//
//	delete[]arra;
//	arra = temp;
//	temp = nullptr;
//	sizea = totalsize;
//
//	for (int w = 0; w < totalsize; w++)
//	{
//		cout << arra[w] << " ";
//
//	}
//}

//3. İki massiv verilib: А[M] və B[N] (M və N klaviaturadan daxil edilir).Minimal ölçüdə üçüncü massiv yaradıb bu iki
//massivin ortaq elementlərini A massivinə yazın.

//void sameelementstoarr(int*& arr1, int& size1, int* arr2, int size2) {

	//int count = 0;

	//for (int i = 0; i < size1; i++)
	//{
	//	for (int j = 0; j < size2; j++)
	//	{
	//		if (arr1[i] = arr2[j]) {
	//			count += 1;
	//		}

	//	}
	//}
	//int* temp = new int[count] {};

	//for (int i = 0; i < size1; i++)
	//{
	//	for (int j = 0, z = 0; j < size2; j++)
	//	{
	//		if (arr1[i] = arr2[j]) {
	//			temp[z] = arr1[i];
	//			z++;
	//		}
	//	}
	//}

	//delete[]arr1;
	//arr1 = temp;
	//temp = nullptr;

	//for (int w = 0; w < count; w++)
	//{
	//	cout << arr1[w] << " ";

	//}
	//cout << endl;
	

}

//4. İki massiv verilib : А[M] və B[N](M və N klaviaturadan daxil edilir).Minimal ölçüdə üçüncü massiv yaradıb, A - da olub
// B - də olmayan elementləri A massivinə yazın.Təkrarlanmasın.

//
//void notsameelementsinarray(int*& arr1, int size1, int* arr2, int size2) {
//
//	int count = 0;
//	for (int i = 0; i < size1; i++)
//	{
//		for (int y = 0; y < size2; y++)
//		{
//			if (arr1[i] != arr2[y]) {
//				count += 1;
//			}
//		}
//	}
//	int* temp = new int[count]{};
//
//	for (int i = 0; i < size1; i++)
//	{
//		for (int y = 0; y < size2; y++)
//		{
//			if (arr1[i] != arr2[y]) {
//				temp[i]=;
//			}
//		}
//	}
//}

//5. İki massiv verilib : А[M] və B[N](M və N klaviaturadan daxil
//edilir).Minimal ölçüdə üçüncü massiv yaradıb, A və B - nin
//ortaq olmayan elemntlərini A massivinə yazın.
//Təkrarlanmasın.

//void NewArr(int*& arr1, int*& arr2, int*& arr3, int size1, int size2) {
//  int index = 0;
//  for (int i = 0; i < size1; i++)
//  {
//      bool check = true;
//      for (int j = 0; j < size1; j++)
//      {
//          if (arr1[i] == arr2[j]) {
//              check = false;
//              break;
//          }
//
//      }
//      if (check) {
//          for (int k = 0; k < index; k++)
//          {
//              if (arr1[i] == arr3[k]) {
//                  check = false;
//                  break;
//              }
//          }
//          if (check)
//              arr3[index++] = arr1[i];
//      }
//  }
//  int index2 = index;
//  for (int i = 0; i < size2; i++)
//  {
//      bool check2 = true;
//      for (int j = 0; j < size2; j++)
//      {
//          if (arr2[i] == arr1[j]) {
//              check2 = false;
//              break;
//          }
//
//      }
//      if (check2) {
//          for (int k = 0; k < index2; k++)
//          {
//              if (arr2[i] == arr3[k]) {
//                  check2 = false;
//                  break;
//              }
//          }
//          if (check2)
//              arr3[index2++] = arr2[i];
//      }
//  }
//


int main()
{
	//int* ptr = mainarr<int>(6);
	//randomfill(ptr, 6);
	//coutarr(ptr, 6);
	//deletearr(ptr, 6);
	//ptr = appendnumber(ptr, 6, 211);
	//coutarr(ptr, 7);

	int sizea = 6;
	int* a = new int[sizea] { 9, 2, 3, 4, 5, 6 };

	int const sizeb = 7;
	int* b = new int[sizeb] { 1, 2, 33, 4, 4, 6 };
	//cout << *(deleteblokfromarr(a, 6, 2));

	//cout << factorial(1);
	//cout << sumrecursion(3);

	//int c[sizeb] = { 1,2,3,4,5,6,7 };
	//coutarrrecurs(b, 6);
	//sumarrrecurs(b, 6);


	//cout << numberpow(5, 3);


	//linkingarrays(a, sizea, b, sizeb);
	//coutarr(a, sizea + sizeb);

	sameelementstoarr(a, sizea, b, sizeb);

}