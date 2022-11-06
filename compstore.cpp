#include <iostream>
#include <string>
using namespace std;

class Computer {

	static int Id()
	{
		static int Id = 0;
		return Id++;
	}

	int objectId;
	int cpuHz, core, ram, diskSize;
	string model, vendor, videocard, monitor;
	bool isSSD;

public:

#pragma region	GETSET

	//GET
	int GetObjectId() { return objectId; }

	int GetCpuHz() { return cpuHz; }

	int GetCore() { return core; }

	int GetRam() { return ram; }

	int GetDiskSize() { return diskSize; }

	bool GetIsSSD() { return isSSD; }

	string GetModel() { return model; }

	string GetVendor() { return model; }

	string GetVideocard() { return  videocard; }

	string GetMonitor() { return monitor; }

	//SET
	void SetObjectId(static int id) { objectId = id; }

	void SetModel(string m) { model = m; }

	void SetVendor(string V) { vendor = V; }

	void SetVideocard(string v) { videocard = v; }

	void SetMonitor(string M) { monitor = M; }

	void SetCpuHz(int hz) { cpuHz = hz; }

	void SetCore(int c) { core = c; }

	void SetRam(int r) { ram = r; }

	void SetDiskSize(int ds) { diskSize = ds; }

	void SetIsSSD(bool o) { isSSD = o; }

#pragma endregion


	Computer() { cpuHz = 0, core = 0, ram = 0, diskSize = 0, isSSD = 0; }


	Computer(string modell, string vendorr, string videocardd, string monitorr, int cpuHzz, int coree, int ramm, int diskSizee, bool isSSDD) {
		SetObjectId(Id());
		SetModel(modell);
		SetVendor(vendorr);
		SetVideocard(videocardd);
		SetMonitor(monitorr);
		SetCpuHz(cpuHzz);
		SetCore(coree);
		SetRam(ramm);
		SetDiskSize(diskSizee);
		SetIsSSD(isSSDD);
	}

	friend ostream& operator<<(ostream& out, const Computer& cmptr) {
		out << "=============== Computer's Information ===============\n"
			<< "\nId: " << cmptr.objectId
			<< "\nModel: " << cmptr.model
			<< "\nVendor: " << cmptr.vendor
			<< "\nMonitor: " << cmptr.monitor
			<< "\nVideocard: " << cmptr.videocard
			<< "\nCpuHz: " << cmptr.cpuHz
			<< "\nRam: " << cmptr.ram
			<< "\nDisk Size: " << cmptr.diskSize
			<< "\nHas SSD: " << cmptr.isSSD << endl;
		return out;
	}


	friend istream& operator>>(istream& in, Computer& cmptr) {
		string a;

		cout << "Vendor: ";
		cin >> a;
		cmptr.SetVendor(a);

		cout << "Model: ";
		cin >> a;
		cmptr.SetModel(a);

		cout << "Monitor: ";
		cin >> a;
		cmptr.SetMonitor(a);

		cout << "Videocard: ";
		cin >> a;
		cmptr.SetVideocard(a);

		int b;
		cout << "CpuHzz: ";
		cin >> b;
		cmptr.SetCpuHz(b);

		cout << "Ram: ";
		cin >> b;
		cmptr.SetRam(b);

		cout << "Disk size: ";
		cin >> b;
		cmptr.SetDiskSize(b);

		bool c;
		cout << "Has SSD: ";
		cin >> c;
		cmptr.SetIsSSD(c);

		return in;
	}
};

class ComputerStore {
	string storeName;
	string storeAdress;
	Computer* computers;
	int size = 20;

	ComputerStore(string sn, string sa) {
		computers = new Computer[size];
		storeName = sn;
		storeAdress = sa;
	}

	void addComputer(Computer cmptr) {
		static int i = 0;
		computers[i] = cmptr;
	}

	void deleteComputer(int id) {
		int i = 0;
		for (i; i < size; i++)
		{
			if (computers[i].GetObjectId() == id) {
				for (i; i < size; i++)
				{
					computers[i] = computers[i + 1];
				}
			}
		}
		size -= 1;
	}
};

int main() {
	Computer q("a", "b", "c", "d", 2, 3, 4, 5, 1);
	cout << q;
	Computer c("a", "b", "c", "d", 2, 3, 4, 5, 1);
	cout << c;


}