
#include <iostream>
#include <string>
using namespace std;

class User {
	string username;
	string pasword;
public:

	////////////////////////////////////////////
	//GET
	string GetUsername() { return username; }

	string GetPassword() { return pasword; }

	//SET
	void SetUsername(string u) { username = u; }

	void SetPassword(string p) {
		if (pasword.size() >= 8)
		{
			pasword = p;
		}
	}
	////////////////////////////////////////////

	User() {}

	User(string u, string p) {
		username = u;
		pasword = p;
	}
	////////////////////////////////////////////
	friend class Databsae;
};

class Database {
	User* users;
	int size;
public:

	friend class User;

	bool SignIn(string u, string p) {

		for (int i = 0; i < size; i++)
		{
			if (users[i].GetUsername() == u && users[i].GetPassword() == p)
			{
				return 1;
			}
			else { return 0; }
		}
	}

	bool SignUp(string u, string p) {
		User* temp = new User[size + 1];

		for (int i = 0; i < size; i++)
		{
			if (users[i].GetUsername() != u)
			{
				for (int i = 0; i < size; i++)
				{
					temp[i].SetUsername(users[i].GetUsername());
					temp[i].SetPassword(users[i].GetPassword());
				}
				temp[size].SetUsername(users[size].GetUsername());
				temp[size].SetPassword(users[size].GetPassword());

				delete[] users;
				users = temp;
				temp = nullptr;

				return 1;
			}
			else {
				return 0;
			}
		}
	}

	User GetUserByUsrename(string u) {
		for (int i = 0; i < size; i++)
		{
			if (users[i].GetUsername() == u)
			{
				return users[i];
			}
		}
	}
};

int main()
{


}