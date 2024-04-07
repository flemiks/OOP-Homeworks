/*#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstring>
#include <functional>
#include <iomanip>
#include <stdexcept>

using namespace std;

//---------Task1---------//
class Overcoat {
private: 
	string type;
	int price;
public:
	Overcoat(string type, int price){
		setType(type);
		setPrice(price);
	}

	string getType() {
		return type;
	}
	void setType(string type) {
		if (type.size() == 0) {
			throw invalid_argument("String should contain at least 1 character");
		}
		this->type = type;
	}
	int getPrice() {
		return price;
	}
	void setPrice(int price) {
		if (price < 0) {
			throw invalid_argument("Price could not be less than 0");
		}
		this->price = price;
	}
	void print() {
		cout << "Type:" << type << ", Price: " << price << endl;
	}


	bool operator==(const Overcoat& other) const {
		return type == other.type;
	}

	Overcoat& operator= (const Overcoat& other) {
		if (this == &other) {
			return *this;
		}
		type = other.type;
		price = other.price;
		return *this;
	}

	bool operator>(const Overcoat& other) const {
		return price > other.price;
	}


};

//---------Task2---------//
class Flat {
private:
	int square;
	int price;
public:
	Flat(int square, int price) {
		setSquare(square);
		setPrice(price);
	}

	int getSquare() {
		return square;
	}
	void setSquare(int square) {
		if (square <= 0) {
			throw invalid_argument("Square could not be less or equal 0");
		}
		this->square = square;
	}
	int getPrice(){
		return price;
	}
	void setPrice(int price) {
		if (price < 0) {
			throw invalid_argument("Price could not be less than 0");
		}
		this->price = price;
	}

	void print() {
		cout << "Square:" << square << ", Price: " << price << endl;
	}

	bool operator==(const Flat& other) const {
		return price == other.price;
	}

	Flat& operator=(const Flat& other) {
		if (this == &other) {
			return *this;
		}
		square = other.square;
		price = other.price;
		return *this;
	}

	bool operator>(const Flat& other) const {
		return price > other.price;
	}
};

int main()
{
	//---------Task1---------//
	Overcoat coat1("down jacket", 12);
	Overcoat coat2 = coat1;
	coat2.print();
	Overcoat coat3("sheepskin coat", 15);
	cout << boolalpha << (coat1 > coat3) << endl;
	cout << endl;

	//---------Task2---------//
	
	Flat flat1(45, 70000);
	Flat flat2 = flat1;
	flat2.print();
	Flat flat3(35, 60000);
	cout << boolalpha << (flat1 > flat3) << endl;
	return 0;
}*/