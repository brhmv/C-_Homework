#include <iostream>
#include <vector>
using namespace std;

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



class HDD {
public:
	double currentSize = 0;

	class File {
	private:
		double fileSize;
		string fileName;
		string content;
	public:

#pragma region GETSET
		double GetFileSize() { return fileSize; }
		void SetFileSize(double size) { fileSize = size; }
		void SetFileName(string name) { fileName = name; }
		void SetContent(string cntnt) { fileName = cntnt; }
		string GetFileName() { return fileName; }
		string GetContent() { return content; }
#pragma endregion

		File() {}
		File(string filename, string content = "") {
			this->fileName = filename;
			this->content = content;
		}
	};

	vector <File> files;

	const static double maxSize;

	File& getFile(string filename) {
		if (files.empty()) 
			throw new DatabaseException("File is empty!", __LINE__, "GetFile()", __TIME__);

		for (int i = 0; i < files.size(); i++) {
			if (files[i].GetFileName() == filename) {
				return files[i];
			}
		}
		throw new InvalidArgumentException("File isnt Exist!", __LINE__, "GetFile()", __TIME__);
	}

	bool isFileExist(string filename) {
		if (files.empty())
			throw new DatabaseException("File is empty!", __LINE__, "IsExistsFile()", __TIME__);
		bool q = 0;
		for (int i = 0; i < files.size(); i++) {
			if (files[i].GetFileName() == filename) {
				q = 1;
				break;
			}
		}
		return q;
	}

	void createFile(string filename, string content = "") {
		if (currentSize + content.size() < maxSize)
		{
			File obj;
			obj.SetFileName(filename);
			obj.SetContent(filename);
			files.push_back(obj);
			currentSize += content.size();
			cout << "File created succesfully"<<endl;
		}
		else {
			throw new InvalidArgumentException("Storage is full", __LINE__, "GetFile()", __TIME__);
		}
	}

	void setFileContent(string filename, string content = "") {
		bool w = 0;
		for (int i = 0; i < files.size(); i++) {
			if (files[i].GetFileName() == filename) {
				if (content.size() + currentSize < maxSize)
				{
					files[i].SetContent(content);
					cout << "file content set succesfully " << endl;
					break;
				}
				throw new InvalidArgumentException("This Filename is not found!", __LINE__, "GetFile()", __TIME__);
			}
			throw new InvalidArgumentException("This Filename is not found!", __LINE__, "GetFile()", __TIME__);
		}
	}

	void deleteFileContent(string filename) {
		for (int i = 0; i < files.size(); i++) {
			if (files[i].GetFileName() != filename) {
				throw new InvalidArgumentException("This Filename is not found!", __LINE__, "DeleteFileContent()", __TIME__);
			}
			if (files[i].GetFileName() == filename) {
				files[i].SetContent(" ");
			}
		}
	}




	void Show() {
		for (File i : files) {
			cout << "File Name: " << i.GetFileName() << "\nContent: " << i.GetContent() << endl;
		}
	}
};

const double HDD::maxSize = 1024;

class OperationSystem {
	OperationSystem() {}
public:

	static void controlPC();
};


void OperationSystem::controlPC() {
	HDD hd;

	try
	{
		hd.createFile("newtext.txt", "hello world");

		cout<<"Is file exist: "<<hd.isFileExist("newtext.txt")<<endl;

		hd.deleteFileContent("newtext.txt");
		
		hd.setFileContent("newtext.txt", "Hello World");
	}
	catch (const char* ex)
	{
		cout << "Error : " << ex << endl;
	}


	try
	{
		hd.getFile("newtext.txt");
	}

	catch (const char * a)
	{
		cout << "Error : " << a << endl;

	}


}


void main() {
	OperationSystem::controlPC();
}