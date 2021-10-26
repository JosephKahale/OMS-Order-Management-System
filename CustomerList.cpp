#include "CustomerList.h"
#include "Customer.h"
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

CustomerList::CustomerList() 
{
	readFromFile();
}

CustomerList::~CustomerList() {
	writeToFile();
	for (int i = 0; i < customers.size(); i++) 
	{
		delete customers[i];
	}
}

bool CustomerList::registerCustomer(Customer* customer) 
{
	for (int i = 0; i < customers.size(); i++) {
		if (*customers[i] == *customer) {	
			return false;
		}
	}
	customers.push_back(customer);
	return true;
}

bool CustomerList::deleteCustomer(long custN) 
{
	for (int i = 0; i < customers.size(); i++) {
		if (customers[i]->getCustomerNumber() == custN) {
			customers.erase(customers.begin() + i);
			return true;
		}
	}
	return false;
}

int CustomerList::getNumCustomers() const 
{
	return (int) customers.size();
}

const vector<Customer*>& CustomerList::getCustomers() const
{
	return customers;
}

void CustomerList::writeToFile() 
{
	ofstream out("CustomerList.txt", ios::out);
	for (int i = 0; i < customers.size(); i++) {
		out << customers[i]->getFullName() << endl;
		out << customers[i]->getAddress() << endl;
		out << customers[i]->getCity() << endl;
		out << customers[i]->getState() << endl;
		out << customers[i]->getPhoneNumber() << endl;
		out << customers[i]->getZipCode() << endl;
		out << customers[i]->getRegDate() << endl;
		out << customers[i]->getCustomerNumber() << endl;
		out << customers[i]->getBalance() << endl;
		out << "END" << endl;
	}
	out.close();
}

void CustomerList::readFromFile() 
{
	string line;
	int size = 0;
	int pos = 1;
	ifstream in("CustomerList.txt", ios::in);
	if (!in.fail()) {
		Customer* person = new Customer();
		getline(in, line); 
		while (!in.fail()) {
			if (line == "END") {
				customers.push_back(person);
				pos = 1;
				person = new Customer();
			} else if (pos == 2) {
				person->setAddress(line);
				pos = 3;
			}
			else if (pos == 3) {
				person->setCity(line);
				pos = 4;
			}
			else if (pos == 4) {
				person->setState(line);
				pos = 5;
			}
			else if (pos == 5) {
				person->setPhoneNumber(line);
				pos = 6;
			}
			else if (pos == 6) {
				person->setZipCode(stoi(line));
				pos = 7;
			}
			else if (pos == 7) {
				person->setRegDate(Date());
				pos = 8;
			}
			else if (pos == 8) {
				person->setCustomerNumber(stol(line));
				pos = 9;
			}
			else if (pos == 9) {
				person->setBalance(stod(line));
				pos = 10;
			}
			else {
				person->setFullName(line);
				pos = 2;
			}

			getline(in, line);
		}
	}
	in.close();
	
}

Customer* CustomerList::getCustomerByID(long num) {
	for (int i = 0; i < customers.size(); i++) {
		if (customers[i]->getCustomerNumber() == num) {
			return customers[i];
		}
	}
	return nullptr;
}

ostream& operator<<(ostream& out, const CustomerList& list) {
	out << "Customer List\n" << endl;
	out << "________________________________" << endl;
	for(int i = 0; i < list.getCustomers().size(); i++) {
		out << *list.getCustomers()[i] << endl;
	}
	return out;
}