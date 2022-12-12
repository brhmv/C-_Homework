#include <iostream>
#include <windows.h>
#include <vector>
using namespace std;

// text, line, source, time. //cari vaxti alinmasini internetden arashdirin

class CustomException : public exception {
public:
	string text, source, time;
	int line;

	CustomException(string text, int line, string source, string time) {
		this->text = text;
		this->line = line;
		this->source = source;
		this->time = time;
	}
};

class DatabaseException :public CustomException {
public:
	DatabaseException(string text, int line, string source, string time) :CustomException(text, line, source, time) {}
};



class InvalidArgumentException :public CustomException {
public:
	InvalidArgumentException(string text, int line, string source, string time) :CustomException(text, line, source, time) {}
};


class User {
	string username;
	string password;
	string name;
	string surname;
	static int id;
	int userId;
public:
	User() { userId = id++; }

	User(string username, string password, string name, string surname) {
		userId = id++;
		SetUsername(username);
		SetName(name);
		SetPassword(password);
		SetSurname(surname);
	}

#pragma region GETSET
	//GET
	string GetUsername() { return username; }
	string GetName() { return name; }
	string GetPassword() { return password; }
	string GetSurname() { return surname; }
	int GetUserId() { return userId; }
	//SET
	void SetUsername(string n) { username = n; }
	void SetName(string n) { name = n; }
	void SetPassword(string n) { password = n; }
	void SetSurname(string n) { surname = n; }
#pragma endregion

	void show() const {
		cout << "************USER**************\n" << "Name: " << name << endl << "Surname: " << surname << endl << endl << "Username: " << username << "Password: " << password;
	};
};

int User::id = 1;

class Database {
public:
	vector<User>users;



	// Database elave olunsun
	void deleteUserById(const int& id) //eger bele bir id istifadechi yoxdursa exception atilsin
	{
		for (int i = 0; i < users.size(); i++) {
			if (id == users[i].GetUserId()) {
				users.erase(users.begin() + i);
				return;
			}
		}
		throw new InvalidArgumentException("Id is not valid.", __LINE__, "DeleteUserById()", __TIME__);
	}

	void AddUser(const User& user) {
		users.push_back(user);
	}

	User& getUserByUsername(string username) {
		if (!users.empty()) {
			for (User i : users) {
				if (i.GetUsername() == username) {
					return i;
				}
				else
					cout << "This username not found!\n";
			}
		}
		else
			cout << "Database is empty!\n";
	}

	void updateUser(User& olduser, const User& newuser) {
		for (User i : users) {
			if (i.GetUserId() == olduser.GetUserId() && i.GetName() == olduser.GetName() && i.GetPassword() == olduser.GetPassword() && i.GetSurname() == olduser.GetSurname() && i.GetUsername() == olduser.GetUsername())
				i = newuser;
		}
	}
	bool CheckUsername(string username) {
		for (int i = 0; i < users.size(); i++) {
			if (users[i].GetUsername() == username) {
				return true;
			}
		}
		return false;
	}



	bool CheckPassword(string password) {
		for (int i = 0; i < users.size(); i++) {
			if (users[i].GetPassword() == password) {
				return true;
			}
		}
		return false;
	}

	void Show() {
		for (User i : users) {
			i.show();
		}
	}
};



class Registration {
public:
	Database database;
	Registration(const Database& database) {
		this->database = database;
	}
	//eger bu username istifadechi yoxdursa error atsin
	//eger username varsa amma password yanlishdirsa error atsin
	void SignIn(string username, string password) {

		if (database.CheckUsername(username) == false) 
			throw new DatabaseException("This username is not in the database", __LINE__, "SignIn()", __TIME__);
		
		if (database.CheckPassword(password) == false) 
			throw new DatabaseException("This password is not in the database", __LINE__, "SignIn()", __TIME__);
	}

	//Eger istifadechi varsa hemen username de throw DatabaseException
	//Eger username xarakter sayi 6 dan kichikdirse InvalidArgumentException
	//Eger username ilk herf kichikdirse InvalidArgumentException
	//Eger password xarakter sayi 6 dan kichikdirse InvalidArgumentException
	//Eger name xarakter sayi 4 dan kichikdirse InvalidArgumentException
	//Eger surname xarakter sayi 4 dan kichikdirse InvalidArgumentException
	
	void SignUp(string username, string password, string name, string surname) {
		if (database.CheckUsername(username) == true) 
			throw new DatabaseException("This username exists in the database.", __LINE__, "SignUp()", __TIME__);
		if (username.size() < 6)
			throw new InvalidArgumentException("This username is not valid.", __LINE__, "SignUp()", __TIME__);
		
		if (username.at(0) > char(97) && username.at(0) < char(122)) 
			throw new InvalidArgumentException("The first character of the username must be capitalized.", __LINE__, "SignUp()", __TIME__);
		
		if (password.size() < 6) 
			throw new InvalidArgumentException("This password is not valid.", __LINE__, "SignUp()", __TIME__);
		
		if (name.size() < 4)
			throw new InvalidArgumentException("This name is not valid.", __LINE__, "SignUp()", __TIME__);
		
		if (surname.size() < 4)
			throw new InvalidArgumentException("This surname is not valid.", __LINE__, "SignUp()", __TIME__);
	}
	
};

class System {
public:

	static void Control() {
		User user1("Allahverdi", "1234", "A", "Ibrahimov");
		Database db;
		Registration twitter(db);
		twitter.database.AddUser(user1);
		try
		{
			twitter.SignIn("Hakunamatata", "HakunaMatata");
			twitter.SignUp("Toghrulaziz", "Togrul123", "Toghrul", "Azizli");
		}
		catch (CustomException* ex)
		{
			cout << "Text: " << ex->text << "\nLine: " << ex->line << "\nSource: " << ex->source << "\nTime: " << ex->time << endl;
		}
	}

};
void main() {
	System::Control();
	
}