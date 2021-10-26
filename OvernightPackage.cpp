//Joseph Kahale, Emil H.
//CSIS 137
//Homework #4
#include "OvernightPackage.h"

OvernightPackage::OvernightPackage(const string& senderName, const string& senderAddy, const string& senderCity, const string& senderState, int senderZip, const string& receiverName, const string& receiverAddy, const string& receiverCity, const string& receiverState, int receiverZip, double weight, double cost, double addFee) : Package(senderName, senderAddy, senderCity, senderState, senderZip, receiverName, receiverAddy, receiverCity, receiverState, receiverZip, weight, cost) {
	setAddFeePerOunce(addFee);
}

OvernightPackage& OvernightPackage::setAddFeePerOunce(double addFee) {
	if (addFee > 0) {
		addFeePerOunce = addFee;

	}
	else {
		addFeePerOunce = 0;
	}
	return *this;
}

double OvernightPackage::getAddFeePerOunce() const {
	return addFeePerOunce;
}

double OvernightPackage::calculateCost() const {
	return (getAddFeePerOunce() + getCostPerOunce()) * getWeight();
}