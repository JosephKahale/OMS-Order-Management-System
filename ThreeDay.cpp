#include "ThreeDay.h"

ThreeDayPackage::ThreeDayPackage(const string& senderName, const string& senderAddy, const string& senderCity, const string& senderState, int senderZip, const string& receiverName, const string& receiverAddy, const string& receiverCity, const string& receiverState, int receiverZip, double weight, double cost, double flat)
	: Package(senderName,senderAddy, senderCity, senderState, senderZip, receiverName, receiverAddy, receiverCity, receiverState, receiverZip, weight, cost) {
	setFlatFee(flat);
}

ThreeDayPackage& ThreeDayPackage::setFlatFee(double flat) {
	if (flat > 0) {
		flatFlee = flat;

	}
	else {
		flatFlee = 0;
	}
	return *this;
}

double ThreeDayPackage::calculateCost() const {
	return Package::calculateCost() + getFlatFee() + 5;
}

double ThreeDayPackage::getFlatFee() const {
	return flatFlee;
}