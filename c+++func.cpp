

#include <iostream>
#include<time.h>
using namespace std;
 


///1
//void eslreqem(int i) {
//	int sum = 0;
//	for (int j = 1; j < i; j++) {
//		if (i % j == 0) {
//			sum += j;
//		}
//		
//	}
//	if (sum == i) {
//		cout << "Esl reqem :)";
//	}
//	else
//		cout << "Esl reqem deyil :)";
//}

///4
//void xosbextreqem(int i) {
//	int num1 = i % 10;
//	int num2 = (i / 10) % 10;
//	int num3 = (i /  100) % 10;
//	int num4 = (i / 1000) % 10;
//	int num5 = (i / 10000) % 10;
//	int num6 = (i / 100000) % 10;
//	//cout << num1<<endl;
//	//cout << num2<<endl;
//	//cout << num3<<endl;
//	//cout << num4<<endl;
//	//cout << num5<<endl;
//	//cout << num6<<endl;
//	if (num1 + num2 + num3 == num4 + num5 + num6) {
//		cout << "Xosbext eded :)";
//	}
//	else {
//		cout << " Xosbext eded deyil :)";
//	}
//}

///6
//int ortamass(int m[],int size) {
//	int sum = 0;
//	for (int i = 0; i <size ; i++)
//	{
//		sum +=m[i];
//	}
//	return sum / size - 1;
//}


/////////////////////////////////////////////////////////////  1
//void massivfill(int a[],int size) {
//	for (int i = 0; i <size ; i++)
//	{
//		a[i] = rand() % 10;
//	}
//	
//}
//void massivfill(float a[],int size) {
//	for (int i = 0; i <size ; i++)
//	{
//		a[i] = (rand() % 10) /10.0 ;
//	}
//	
//}void massivfill(double a[],int size) {
//	for (int i = 0; i <size ; i++)
//	{	
//		a[i] = (rand() % 10) /10.0 ;
//	}
//	
//}
//void massivfill(char a[],int size) {
//	for (int i = 0; i <size ; i++)
//	{
//		a[i] =char( rand() % 256);
//	}
//	
//}

////////////////////////////////////////////////////////////////  3

//
//void printarray(int a[], int size) {
//	for (int i = 0; i < size; i++)
//	{
//		cout << a[i] << " ";
//	}
//}
//
//
//void printarray(float a[], int size) {
//	for (int i = 0; i < size; i++)
//	{
//		cout << a[i] << " ";
//	}
//}
//
//void printarray(char a[], int size) {
//	for (int i = 0; i < size; i++)
//	{
//		cout << a[i] << " ";
//	}
//}
//void printarray(double a[], int size) {
//	for (int i = 0; i < size; i++)
//	{
//		cout << a[i] << " ";
//	}
//}


/////////////////////////////////////////////////// 6

//
//int findmin(int arr[],int size) {
//	int temp = arr[0];
//	for (int i = 0; i < size; i++)
//	{
//		if (temp > arr[i]) {
//			temp = arr[i];
//		}
//		
//	}
//	return temp;
//}


/////////////////////////////////////////////////// 7

//int findmax(int arr[],int size) {
//	int temp = arr[0];
//	for (int i = 0; i < size; i++)
//	{
//		if (temp < arr[i]) {
//			temp = arr[i];
//		}
//		
//	}
//	return temp;
//}
//
//float findmax(float arr[],int size) {
//	int temp = arr[0];
//	for (int i = 0; i < size; i++)
//	{
//		if (temp < arr[i]) {
//			temp = arr[i];
//		}
//		
//	}
//	return temp;
//}
//
//double findmax(double arr[],int size) {
//	int temp = arr[0];
//	for (int i = 0; i < size; i++)
//	{
//		if (temp < arr[i]) {
//			temp = arr[i];
//		}
//		
//	}
//	return temp;
//}



/////////////////////////////////////////////////// 5


//int findnum(int arr[],int size,int number) {
//	
//	for (int i = 0; i < size; i++)
//	{
//		if (number == arr[i]) {
//			return i;
//		}
//	}
//}
//float findnum(float arr[],int size,float number) {
//	
//	for (int i = 0; i < size; i++)
//	{
//		if (number == arr[i]) {
//			return i;
//		}
//	}
//}
//double findnum(double arr[],int size,double number) {
//	
//	for (int i = 0; i < size; i++)
//	{
//		if (number == arr[i]) {
//			return i;
//		}
//	}
//}
//char findnum(char arr[],int size,char number) {
//	
//	for (int i = 0; i < size; i++)
//	{
//		if (number == arr[i]) {
//			return i;
//		}
//	}
//}
		
//void reversing(int arr[],int size,int loop) {
//
//
//	int temp = arr[0];
//	while (loop > 0) {
//		for (int i = 0; i < size; i++)
//		{
//			arr[i] = arr[i - 1];
//		}
//		arr[size - 1] = temp;
//		loop -= 1;
//	}
//}



///////////////// 1
#include<conio.h>


//void funv() {
//	char user;
//	while (true)
//	{
//		if (_getch() >= 48 && _getch() <= 57) {
//			_putch(32);
//		}
//	}
//}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////function 1 
//////1.Ədədin kubunu qaytaran funksiya yazın.
int kub(int i) {
	return i * i * i;
}

////////2. İki ədəddən böyüyünü tapan funksiya yazın.
double bignum(int i,int j) {
	if (i > j) {
		return i;
	}
	else if(j>i) {
		return j;
	}
}
	
////////// 
//3. Ədəd müsbətdirsə doğru, mənfidirsə yanlış qaytaran funksiya yazın.

bool number0(int i) {
	if (i > 0) {
		return true;
		}
	else  {
		return false;
			}
}

////////// 
//4. İstifadəçinin seçimindən asılı olaraq Toplama, Çıxma, Vurma, Bölmə
//funksiyalarından birini çağıran, funksiya yazın.
//
//int action() {
//	int choice = 0;
//	cout << " 1)+ \n2)-\n3)/\n4)*\n ";
//	cin >> choice;
//
//	switch (choice)
//	{
//	case 1:
//		toplama();
//		break;
//	case 2:
//		cixma();
//		break;
//	case 3:
//		vurma();
//		break;
//	case 4:
//		bolma();
//		break;
//	default:
//		cout << "Choose one of them :) ";
//		break;
//	}
//}


////////// 
//5. Parametr kimi tərfinin uzunluğunu qəbul edən, və ekrana həmin
//ölçüdə kvadrat çıxaran funksiya yazın.

void cube(int size) {
	for (int  i = 0; i <size ; i++)
	{
		for (int i = 0; i < size; i++)
		{
			cout << "* ";
		}
		cout << endl;
	}
}

//////////
//6. Göndərilən rəqəmin sadə olub olmadığını yoxlayan funksiya yazın.

void ededsm(int eded) {
	
	int saygac = 0;
	for (int i = 1; i <=eded; i++)
	{
		if (eded % 2 == 0) {
			saygac +=1;
		}
	}
	if (saygac > 2) {
		cout<<"Eded murekkebdir )";
	}
	else if (saygac == 1) {
		cout << "Ne sade ne de murekkeb :)";
	}
	else {
		cout << "Eded sadedir )";
	}
}


///////////
//7. Ədədin faktorialını qaytaran funksiya yazın.

int factorial(int number) {
	
	int fac = 1;
	for (int  i = 1; i <= number; ++i)
	{
		fac *= i;	
	}
	return fac;
}

///////////
//8.İki parametr qəbul edən : Üst və Qüvvət, və ədədin qüvvətini
//qaytaran funksiya yazın.
int pow(int number, int power) {
	int result = 1;
	for (int i = 0; i < power; i++)
	{
		result *= number;
	}
	return result;
}
///////////
//9.Funksiya 2 ədəd qəbul edir və bunlar arasındakı bütün ədədləri
//toplayıb qaytarır.

int sumofnums(int num1, int num2) {
	int sum = 0;
	for (int i = num1+1; i <num2 ; i++)
	{
		sum += i;
	}
	return sum;
}

////////////
//10. Massivdəki ən böyük ədədi qaytaran funksiya yazın.

int bignuminmassiv(int mas[],int length) {
	int bignum = mas[0];
	for (int i = 0; i < length; i++)
	{
		if (bignum < mas[i]) {
			bignum = mas[i];
		}
	}
	return bignum;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Function 2

//1. Əsl ​rəqəmlər o rəqəmlərdir ki bölənlərinin cəmi(rəqəmin özünü bölən
//kimi hesablamırıq) özünə bərabər olsun.Əsl rəqəmləri tapan funksiya
//yazın.Ola bilər ki sizə funksiya lazım olsun.

//void eslreqem(int i) {
//	int sum = 0;
//	for (int j = 1; j < i; j++) {
//		if (i % j == 0) {
//			sum += j;
//		}
//		
//	}
//	if (sum == i) {
//		cout << "Esl reqem :)";
//	}
//	else
//		cout << "Esl reqem deyil :)";
//}








///4
//void xosbextreqem(int i) {
//	int num1 = i % 10;
//	int num2 = (i / 10) % 10;
//	int num3 = (i /  100) % 10;
//	int num4 = (i / 1000) % 10;
//	int num5 = (i / 10000) % 10;
//	int num6 = (i / 100000) % 10;
//	//cout << num1<<endl;
//	//cout << num2<<endl;
//	//cout << num3<<endl;
//	//cout << num4<<endl;
//	//cout << num5<<endl;
//	//cout << num6<<endl;
//	if (num1 + num2 + num3 == num4 + num5 + num6) {
//		cout << "Xosbext eded :)";
//	}
//	else {
//		cout << " Xosbext eded deyil :)";
//	}
//}

///6
//int ortamass(int m[],int size) {
//	int sum = 0;
//	for (int i = 0; i <size ; i++)
//	{
//		sum +=m[i];
//	}
//	return sum / size - 1;
//}

////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////


///1
//void eslreqem(int i) {
//	int sum = 0;
//	for (int j = 1; j < i; j++) {
//		if (i % j == 0) {
//			sum += j;
//		}
//		
//	}
//	if (sum == i) {
//		cout << "Esl reqem :)";
//	}
//	else
//		cout << "Esl reqem deyil :)";
//}


//3. Verilən rəqəmi müəyyən dəqiqliyə qədər yuvarlaqlaşdıran funksiya yazın. (Funksiya iki parametr qəbul edir, birinci kəsr rəqəm, ikinci parametr isə vergüldən sonra neçə rəqəm qalmalıdır)

//double yuvar(double num, int count) {
//	
//
//	int a = pow(10, count + 1); 
//	double result = int(a * num); 
//	int end = int(result) % 10; 	
//	result = int(result / 10); 
//	if (5 <= end)
//		result += 1; 
//	a /= 10; 
//
//	return result / a; 
//}


///4. Rəqəmin xoşbəxt olub olmadığını tapan funksiya yazın. (Xoşbəxt rəqəm ilk 3 rəqəmin cəmi son 3 rəqəmin cəminə bərabər olmalıdır)

//void xosbextreqem(int i) {
//	int num1 = i % 10;
//	int num2 = (i / 10) % 10;
//	int num3 = (i /  100) % 10;
//	int num4 = (i / 1000) % 10;
//	int num5 = (i / 10000) % 10;
//	int num6 = (i / 100000) % 10;
//	//cout << num1<<endl;
//	//cout << num2<<endl;
//	//cout << num3<<endl;
//	//cout << num4<<endl;
//	//cout << num5<<endl;
//	//cout << num6<<endl;
//	if (num1 + num2 + num3 == num4 + num5 + num6) {
//		cout << "Xosbext eded :)";
//	}
//	else {
//		cout << " Xosbext eded deyil :)";
//	}
//}

//5. İki tarix qəbul edən və bu tarixlər arasındakı fərqi tapan funksiya
//yazın.Bu funksiyanı yazarkən ilin uzun və ya qısa olduğunu tapan
//funksiyanı da yazmalısınız.

//void timegap() {
//	int year1, year2, month1, month2;
//	cin >> year1;
//	cin >> year2;
//	cin >> month1;
//	cin >> month2;
//	cout<< (year2 - year1 * 365) - (month1 - month2 * 30);
//
//}

///6. Göndərilən massivin ədədi ortasını tapan funksiya yazın:

//int ortamass(int m[],int size) {
//	int sum = 0;
//	for (int i = 0; i <size ; i++)
//	{
//		sum +=m[i];
//	}
//	return sum / size - 1;
//}

//7. Massivdəki sıfırların, mənfilərin, müsbətlərin sayını tapan funksiya
//(funksiyalar)yazın..

void masscount(int mas[], int size) {
	
	int plus = 0, minus = 0, zero = 0;
	for (int i = 0; i < size; i++)
	{
		if (mas[i] > 0) {
			plus += 1;
		}
		else if (mas[i] < 0)
		{
			minus += 1;
		}
		else {
			zero += 1;
		}
	}
	for (int i = 0; i < size; i++)
	{
		cout << mas[i] << " ";
	}
	cout << endl << endl;
	cout << "+ :" << plus << endl;
	cout << "- :" << minus << endl;
	cout << "0 :" << zero << endl;
}

//8. Massivdəki maxmimum və minimum rəqəmi tapan funksiya
//(funksiyalar) yazın.

//void arrmaxmin(int arr[], int size) {
//	int max = arr[0], min = arr[0];
//	for (int i = 0; i < size; i++)
//	{
//		if (max < arr[i]) {
//			max = arr[i];
//		}
//		else if (min > arr[i]) {
//			min = arr[i];
//		}
//	}
//	cout << max << endl;
//	cout << min << endl;
//
//
//}

//9. Göndərilən massivi əksinə çevirən funksiya yazın.

//void arrreverse(int arr[],int size){
//	for (int i = size-1; i >= 0; i--)
//	{
//		cout << arr[i] << " ";
//	}
//}

//10. Massivdəki sadə rəqəmlərin sayını qaytaran fuksiya yazın.

int arrsimple(int arr[],int size){
	int maincount = 0;
	for (int i = 0; i < size; i++)
	{
		int count = 0;
		for (int  j = 0; j < arr[i]; j++)
		{
			if (arr[i] % i == 0) {
				count += 1;
			}
			
		}
		if (count < 2) {
			maincount += 1;
		}
	}
	return maincount;
}
///////// 10
void simplenumbers(int arr[], int size) {
	for (int i = 0; i < size; i++)
	{
		int counter = 0;
		for (int j = 1; j < size; j++)
		{
			if (arr[i] % j == 0)
				counter++;
		}
		if (counter == 2) {
			cout << arr[i] << endl;
		}
	}
	
}

int main()
{

	//int A[10] = { 0,0,-2,-3,-8,1,2,3,4,7};
	//arrmaxmin(A, 10);
	//masscount(A,10);

	//arrreverse(A, 10);

	//cout<<arrsimple(B, 10);

	int B[10] = { 24,11,2,3,43,1,2,3,4,7};

	simplenumbers(B,10);








	//int number=0;
	//cout << "insert number : ";
	//cin >> number;
	//eslreqem(number);
	//xosbextreqem(number);
	//ortamass(a,5);


	
	//cout<<findmin(a,5);
	
	//cout<<findmax(a,5);

	//funv();


	////////// 2
	/*srand(time(0));
	
	int bot = 0,botscore=0;
	int user = 0,userscore=0,saygac=5;
	while (saygac!=0)
	{
		if (_getch() == 32) {

			int num = 1 + rand() % 5;
			cout << "bot num : ";
			cout << num<<" ";
			botscore += num;
			 num = 1 + rand() % 5;
			 cout << num<<endl;
			botscore += num;


			 num = 1 + rand() % 5;
			cout << "user num : ";
			cout << num << " ";
			userscore += num;
			 num = 1 + rand() % 5;
			 cout << num<<endl;
			userscore += num;
			
		}
		saygac-=1;

	}

	cout <<"userscore: " << userscore << endl;
	cout <<"botscore: "<< botscore << endl;

	if (userscore > botscore) {
		cout << "user win :)";
	}
	else if (userscore < botscore) {
		cout << "bot win :)";
	}
	else {
		cout << " draw :)";
	}*/


	//////////////////////////////// 1
	//int number = 0;
	//cout << "Insert number: ";
	//cin >> number;
	//cout<<kub(number);

	//////////////////////////////// 2
	//cout << bignum(5, 7);


	 ////////////////////////////5
	//cube(number);
	
   ////////////////////////////7
	//cout<< factorial(5);
	// 
	/////////////////////////8 
	//cout<< pow(5,3);

	/////////////////////////9
	//cout << sumofnums(5, 8);

	/////////////////////////10
		//int b[5] = { 1,2,3,4,5 };
		//cout << bignuminmassiv(b, 5);

}