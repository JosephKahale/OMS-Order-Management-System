#include "Customer.h"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <algorithm>
using namespace std;

Customer::Customer(const string& n, const string& a, const string& c, const string& s, const string& p, int z, const Date& r, double b) {
	setFullName(n).setAddress(a).setCity(c).setState(s).setPhoneNumber(p).setZipCode(z).setRegDate(r).setCustomerNumber().setBalance(b);
}

Customer& Customer::setFullName(const string& f) {
	
	if (f.length() > 0) { 
		fullName = f;
	}
	else { 
		fullName = "N/A";
	}
	return *this;
}

Customer& Customer::setAddress(const string& a) {

	if (a.length() > 0) {
		address = a;
	}
	else {
		address = "N/A";
	}
	return *this;
}

Customer& Customer::setCity(const string& c) {

	if (c.length() > 0) {
		city = c;
	}
	else {
		city = "N/A";
	}
	return *this;
}

Customer& Customer::setState(const string& s) {

	if (s.length() > 0 && s.length() < 3) {
		state = s;
	}
	else {
		state = "N/A";
	}
	return *this;
}

Customer& Customer::setPhoneNumber(const string& p) {

	if (p.length() > 0 && p.length() < 13) {
		phoneNumber = p;
	}
	else {
		phoneNumber = "N/A";
	}
	return *this;
}

Customer& Customer::setZipCode(int z) {

	if (z >= 0) {
		zip = z;
	}
	else {
		zip = 00000;
	}
	return *this;
}

Customer& Customer::setRegDate(const Date& r) {
	registerDate = r;
	return *this;
}

Customer& Customer::setCustomerNumber() {
	srand((unsigned int)time(NULL));
	customerNumber = rand() % 1500;
	while (binary_search(custNumbs.begin(), custNumbs.end(), customerNumber)) {
		customerNumber = rand() % 1500;
	}
	custNumbs.push_back(customerNumber);
	return *this;
}

Customer& Customer::setCustomerNumber(long id)
{
	customerNumber = id;
	return *this;
}

Customer& Customer::setBalance(double b) {
	balance = b;
	return *this;
}

long Customer::getCustomerNumber() const {
	return customerNumber;
}

const string& Customer::getFullName() const {
	return fullName;
}

const string& Customer::getAddress() const {
	return address;
}

const string& Customer::getCity() const {
	return city;
}

const string& Customer::getState() const {
	return state;
}

const string& Customer::getPhoneNumber() const {
	return phoneNumber;
}

int Customer::getZipCode() const {
	return zip;
}

Date Customer::getRegDate() const {
	return registerDate;
}

double Customer::getBalance() const {
	return balance;
}

ostream& operator<<(ostream& out, const Customer& customer) {
	out << "Customer Information: \n" << customer.getFullName() << " ----- Account Number: " << customer.getCustomerNumber() << endl;
	out << "Address: \t" << customer.getAddress() << endl;
	out << customer.getCity() << ", " << customer.getState() <<  customer.getZipCode() << endl;
	out << "Phone Number: \t" << customer.getPhoneNumber() << endl;
	out << "Registeration Date: \t" << customer.getRegDate() << endl;
	out << "Current Balance Due: \t" << customer.getBalance() << endl;
	return out;
}

bool Customer::operator==(const Customer& customer) const {
	if (customerNumber == customer.getCustomerNumber()) {
		return true;
	}
	return false;
}

