#include "OneDay.h"

OneDayPackage::OneDayPackage(const string& senderName, const string& senderAddy, const string& senderCity, const string& senderState, int senderZip, const string& receiverName, const string& receiverAddy, const string& receiverCity, const string& receiverState, int receiverZip, double weight, double cost, double flat)
	: Package(senderName, senderAddy, senderCity, senderState, senderZip, receiverName, receiverAddy, receiverCity, receiverState, receiverZip, weight, cost) {
	setFlatFee(flat);
}

OneDayPackage& OneDayPackage::setFlatFee(double flat) {
	if (flat > 0) {
		flatFlee = flat;

	}
	else {
		flatFlee = 0;
	}
	return *this;
}

double OneDayPackage::calculateCost() const {
	return Package::calculateCost() + getFlatFee() + 10;
}

double OneDayPackage::getFlatFee() const {
	return flatFlee;
}