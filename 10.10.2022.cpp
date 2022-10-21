#include <iostream>
using namespace std;
// Kechilenlerin her biri istifade olunsun
// Initializer list, Delegate, getter setter
//class : Product
//  fields : id, name, description, price, discount
//  methods : ShowProduct(), GetPriceWithDiscount()
//
//
//  class Stock {
//  char* name
//      Product*    // array
//      Print() // show all product in Stock
//      Product& GetProduct(int id);
//}
class Product
{
	int id;
	char* name = nullptr;
	char* description = nullptr;
	double price;
	short discount;
public:
#pragma region get&set
	//get
	int GetId() { return id; }
	const char* GetName() { return name; }
	const char* GetDescription() { return description; }
	int GetPrice() { return price; }
	short GetDiscount() { return discount; }
	//set
	void SetId(int id) {
		this->id = id;
	}
	void SetName(const char* name) {
		delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}
	void SetDescription(const char* description) {
		delete[] this->description;
		this->description = new char[strlen(description) + 1];
		strcpy_s(this->description, strlen(description) + 1, description);
	}
	void SetPrice(int price) {
		this->price = price;
	}
	void SetDiscount(short discount) {
		this->discount = discount;
	}
#pragma endregion

	Product() :int id, name(nullptr), description(nullptr), price(0), discount(0) {
	}
	Product(int id) :Product() {
		SetId(id);
	}
	Product(int id, char* name) :Product(id) {
		SetName(name);
	}
	Product(int id, char* name, char* description) : Product(id, name) {
		SetDescription(description);
	}
	Product(int id, char* name, char* description, double price) : Product(id, name, description) {
		SetPrice(price);
	}
	Product(int id, char* name, char* description, double price, int discount) : Product(id, name, description, price) {
		SetPrice(discount);
	}
	void ShowProduct() {
		cout << "<<PRODUCT>>\n";
		cout << id << "\n" <<name<< "\n" << description << "\n" << price << "\n" << discount<< "\n";
	}
	int GetPriceWithDiscount() {
		return GetPrice() - GetPrice() * GetDiscount() / 100;
	}
	~Product() {
		delete[] name;
		delete[] description;
	}
};


class Stock {
public:
	char* name;
	int ProductCount;
	Product* products = new Product[ProductCount];
	Stock();
	Stock(Product* prods, int size) {
		ProductCount = size;
		products = new Product[size];
		for (int i = 0; i < size; i++)
		{
			products[i].SetName(prods[i].GetName());
			products[i].SetDescription(prods[i].GetDescription());
			products[i].SetPrice(prods[i].GetPrice());
			products[i].SetDiscount(prods[i].GetDiscount());
		}
	}
	void Print() {
		for (int i = 0; i < ProductCount; i++)
		{
			products[i].ShowProduct();
		}
	}
	Product& GetProduct(int id) {
		for (int i = 0; i < ProductCount; i++)
		{
			if (products[i].GetId() == id)
			{
				return products[i];
			}
		}
	}
};

int main() {
	Product o("ad", "des", 5);
	o.ShowProduct();

}