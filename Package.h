//Joseph Kahale, Emil H.
//CSIS 137
//Homework #4
#ifndef PACKAGE_H
#define PACKAGE_H
#include <string>
using namespace std;

class Package{

private:
	string sName;
	string sAddress;
	string sCity;
	string sState;
	int sZip;

	string rName;
	string rAddress;
	string rCity;
	string rState;
	int rZip;

	double weight;
	double costPerOunce;
	double weightCost;


	Package& setSenderName(const string&);
	Package& setSenderAddress(const string&);
	Package& setSenderCity(const string&);
	Package& setSenderState(const string&);
	Package& setSenderZip(int);


public:
	Package(const string& = "N/A", const string& = "N/A", const string& = "N/A", const string& = "N/A", int = 0, const string& = "N/A", const string& = "N/A", const string& = "N/A", const string& = "N/A", int = 0, double = 0.0, double = 0.0);
	const string& getSenderName() const;
	const string& getSenderAddress() const;
	const string& getSenderCity() const;
	const string& getSenderState() const;
	int getSenderZip() const;

	const string& getReceiverName() const;
	const string& getReceiverAddress() const;
	const string& getReceiverCity() const;
	const string& getReceiverState() const;
	int getReceiverZip() const;
	double calcWeightCost();


	double getWeight() const;
	double getCostPerOunce() const;

	Package& setReceiverName(const string&);
	Package& setReceiverAddress(const string&);
	Package& setReceiverCity(const string&);
	Package& setReceiverState(const string&);
	Package& setReceiverZip(int);

	Package& setWeight(double);
	Package& setCostPerOunce(double);

	virtual double calculateCost() const;
};

#endif // !PACKAGE_H
