#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>
#include <vector>
#include "Date.h"
using namespace std;

class Customer {
	friend ostream& operator<<(ostream&, const Customer&);

private:
	vector<long> custNumbs;

	string fullName;
	string address;
	string city;
	string state;
	string phoneNumber;
	int zip;
	Date registerDate;
	long customerNumber;
	double balance;

public:
	Customer(const string & = "N/A", const string & = "N/A", const string & = "N/A", const string & = "N/A", const string & = "N/A", int = 0 , const Date& = Date(), double = 0.0);
	Customer& setFullName(const string&);
	Customer& setAddress(const string&);
	Customer& setCity(const string&);
	Customer& setState(const string&);
	Customer& setPhoneNumber(const string&);
	Customer& setZipCode(int);
	Customer& setRegDate(const Date&);
	Customer& setCustomerNumber();
	Customer& setCustomerNumber(long);
	Customer& setBalance(double);

	const string& getFullName() const;
	const string& getAddress() const;
	const string& getCity() const;
	const string& getState() const;
	const string& getPhoneNumber() const;
	long getCustomerNumber() const;
	int getZipCode() const;
	double getBalance() const;
	//bool checkID(long) const;

	Date getRegDate() const;
	bool operator==(const Customer&) const;
};



#endif // !CUSTOMER_H
