//Joseph Kahale, Emil H.
//CSIS 137
//Homework #4
#include "Package.h"

Package::Package(const string& senderName, const string& senderAddy, const string& senderCity, const string& senderState, int senderZip, const string& receiverName, const string& receiverAddy, const string& receiverCity, const string& receiverState, int receiverZip, double weight, double cost) {
	setSenderName(senderName);
	setSenderAddress(senderAddy);
	setSenderCity(senderCity);
	setSenderState(senderState);
	setSenderZip(senderZip);

	setReceiverName(receiverName);
	setReceiverAddress(receiverAddy);
	setReceiverCity(receiverCity);
	setReceiverState(receiverState);
	setReceiverZip(receiverZip);

	setWeight(weight);
	setCostPerOunce(cost);
}

Package& Package::setSenderName(const string& senderName) {
	if (senderName.length() > 0) {
		sName = senderName;
	}
	else {
		sName = "N/A";
	}
	return *this;
}

Package& Package::setSenderAddress(const string& senderAddy) {
	if (senderAddy.length() > 0) {
		sAddress = senderAddy;
	}
	else {
		sAddress = "N/A";
	}
	return *this;
}

Package& Package::setSenderCity(const string& senderCity) {
	if (senderCity.length() > 0) {
		sCity = senderCity;
	}
	else {
		sCity = "N/A";
	}
	return *this;
}

Package& Package::setSenderState(const string& senderState) {
	if (senderState.length() > 0) {
		sState = senderState;
	}
	else {
		sState = "N/A";
	}
	return *this;
}

Package& Package::setSenderZip(int senderZip) {
	if (senderZip > 0) {
		sZip = senderZip;
	}
	else {
		sZip = 0;
	}
	return *this;
}

Package& Package::setReceiverName(const string& receiverName) {
	if (receiverName.length() > 0) {
		rName = receiverName;
	}
	else {
		rName = "N/A";
	}
	return *this;
}

Package& Package::setReceiverAddress(const string& receiverAddy) {
	if (receiverAddy.length() > 0) {
		rAddress = receiverAddy;
	}
	else {
		rAddress = "N/A";
	}
	return *this;
}

Package& Package::setReceiverCity(const string& receiverCity) {
	if (receiverCity.length() > 0) {
		rCity = receiverCity;
	}
	else {
		rCity = "N/A";
	}
	return *this;
}

Package& Package::setReceiverState(const string& receiverState) {
	if (receiverState.length() > 0) {
		rState = receiverState;
	}
	else {
		rState = "N/A";
	}
	return *this;
}

Package& Package::setReceiverZip(int receiverZip) {
	if (receiverZip > 0) {
		rZip = receiverZip;
	}
	else {
		rZip = 0;
	}
	return *this;
}


Package& Package::setWeight(double weight) {
	if (weight > 0) {
		this->weight = weight;
	}
	else {
		this->weight = 0;
	}
	return *this;
}

Package& Package::setCostPerOunce(double cost) {
	if (cost > 0) {
		costPerOunce = cost;
	}
	else {
		costPerOunce = 0;
	}
	return *this;
}

const string& Package::getSenderName() const {
	return sName;
}

const string& Package::getSenderAddress() const {
	return sAddress;
}

const string& Package::getSenderCity() const {
	return sCity;
}

const string& Package::getSenderState() const {
	return sState;
}

int Package::getSenderZip() const {
	return sZip;
}

const string& Package::getReceiverName() const {
	return rName;
}

const string& Package::getReceiverAddress() const {
	return rAddress;
}

const string& Package::getReceiverCity() const {
	return rCity;
}

const string& Package::getReceiverState() const {
	return rState;
}

int Package::getReceiverZip() const {
	return rZip;
}

double Package::calculateCost() const {
	return weight * getCostPerOunce();
}

double Package::getWeight() const {
	return weight;
}

double Package::getCostPerOunce() const {
	return costPerOunce;
}

double Package::calcWeightCost() {
	if (weight <= 5) {
		weightCost = 1.25;
	}
	else if (weight > 5 && weight <= 10) {
		weightCost = 1.75;
	}
	else {
		weightCost = 2.25;
	}
	return weightCost;
}