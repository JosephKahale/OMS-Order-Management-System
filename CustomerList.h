#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H
#include <iostream>
#include <string>
#include "Customer.h"
#include <vector>

using namespace std;

class CustomerList {

	friend ostream& operator<<(ostream&, const CustomerList&);

private:
	vector<Customer*> customers;

	//bool checkCustomer(const Customer&)const;
public:
	CustomerList();
	~CustomerList();

	const vector<Customer*>& getCustomers() const;

	void readFromFile();
	void writeToFile();

	bool registerCustomer(Customer*);
	bool deleteCustomer(long);
	int getNumCustomers() const;
	Customer* getCustomerByID(long);
};
#endif // !CUSTOMERLIST_H

