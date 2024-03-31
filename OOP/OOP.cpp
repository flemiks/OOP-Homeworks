
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
using namespace std;

class Man {
private:
	string name;
	string age;
	string gender;

public:
	void setName(const string& name) { this->name = name; }
	void setAge(const string& age) { this->age = age; }
	void setGender(const string& gender) { this->gender = gender; }

	Man(string name, string age, string gender) {
		setName(name);
		setAge(age);
		setGender(gender);
	}

	string getName() const { return name; }
	string getAge() const { return age; }
	string getGender() const { return gender; }

	void printMan() {
		cout << "Name: " << name << ", Age: " << age << ", Gender: " << gender << endl;
	}
};

class Appartment {
private:
	vector<Man> tenants;
	int rooms;
	int number;

public:
	void setTenants(const Man& man) {
		tenants.push_back(man);
	}
	void setRooms(const int& rooms) {
		if (rooms < 1 || rooms > 4) {
			throw invalid_argument("Invalid rooms qty");
		}
		this->rooms = rooms;
	}
	void setNumber(const int& number) {
		if (number < 1) {
			throw invalid_argument("Invalid number");
		}
		this->number = number;
	}

	Appartment(const Man& man, int rooms, int number) {
		setTenants(man);
		setRooms(rooms);
		setNumber(number);
	}

	int getRooms() { return rooms; }
	int getNumber() { return number; }
	vector<Man> getListByManField(function<string(const Man&)> method, const string& field) const {
		vector<Man> filteredList;
		for (auto tenant : tenants) {
			if (method(tenant) == field) {
				filteredList.push_back(tenant);
			}
		}
		return filteredList;
	}

	void printAppartment() {
		cout << "App Number: " << number << endl;
		for (auto tenant : tenants) {
			tenant.printMan();
		}
		cout << "Rooms: " << rooms << endl;
		cout << endl;
	}
};

class Building {
private:
	vector<Appartment> appartments;
	int floors;

public:
	void setFloors(const int& floors) {
		this->floors = floors;
	}
	void setAppartments(const Appartment& appartment) {
		appartments.push_back(appartment);
	}

	Building(const Appartment& appartment, int floors) {
		setAppartments(appartment);
		setFloors(floors);
	}

	int getFloors() { return floors; }
	vector<Appartment> getListByRooms(const vector<Appartment>& appartments, const int& rooms) const {
		vector<Appartment> filteredList;
		for (auto appartment : appartments) {
			if (appartment.getRooms() == rooms) {
				filteredList.push_back(appartment);
			}
		}
		return filteredList;
	}
	vector<Man> getListByManFieldInBuilding(function<string(const Man&)> method, const string& field) const {
		vector<Man> filteredList;
		for (auto appartment : appartments) {
			auto tenants = appartment.getListByManField(method, field);
			for (const auto& tenant : tenants) {
				filteredList.push_back(tenant);
			}
		}
		return filteredList;
	}

	void printBuilding() {
		for (auto appartment : appartments) {
			appartment.printAppartment();
		}
		cout << "Floors: " << floors << endl;
		cout << endl;
	}
};

void printVectorMan(const vector<Man>& tenants) {
	for (auto tenant : tenants) {
		tenant.printMan();
	}
}

int main()
{
	Man man1 { "Alex", "39", "male" };
	Man man2 { "Elena", "31", "female" };
	Man man3 { "Nick", "10", "male" };
	Man man4 { "Olga", "5", "female" };
	Man man5{ "Ivan", "42", "male" };
	Man man6{ "Maria", "35", "female" };
	Man man7{ "Sergey", "28", "male" };
	Man man8{ "Anna", "24", "female" };
	Man man9{ "Dmitry", "50", "male" };
	Man man10{ "Natalia", "45", "female" };
	man2.printMan();
	cout << "------------" << endl;
	Appartment appartment1{ man1 , 3, 1 };
	appartment1.setTenants(man2);
	appartment1.setTenants(man3);
	appartment1.setTenants(man4);
	Appartment appartment2{ man5 , 4, 2 };
	appartment2.setTenants(man6);
	appartment2.setTenants(man7);
	appartment2.setTenants(man8);
	Appartment appartment3{ man9 , 2, 3 };
	appartment3.setTenants(man10);
	appartment1.printAppartment();
	cout << "------------" << endl;
	Building building{ appartment1 , 2 };
	building.setAppartments(appartment2);
	building.setAppartments(appartment3);
	building.printBuilding();
	cout << "------------" << endl;
	auto maleTenantsInBuilding = building.getListByManFieldInBuilding([](const Man& m) -> string { return m.getGender(); }, "male");
	printVectorMan(maleTenantsInBuilding);
	cout << "------------" << endl;
	auto femaleTenants = appartment1.getListByManField([](const Man& m) -> string { return m.getGender(); }, "female");
	printVectorMan(femaleTenants);

}