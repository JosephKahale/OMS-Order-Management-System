#include "OneTimeOrder.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

OneTimeOrder::OneTimeOrder(const string& name, double price, double weight, double sub, double tot, const string& subtax, int quantity, const Date& orderDt, double fee) 
: Order(name, price, weight, sub, tot, subtax, quantity, orderDt)
{
	setFee(fee);
}

OneTimeOrder& OneTimeOrder::setFee(double f) {
	if (f > 0) {
		fee = f;
	}
	else {
		fee = 0;
	}
	return *this;
}

double OneTimeOrder::getFee() {
	return fee;
}

double OneTimeOrder::calcTotal() {
	return Order::calcTotal() + getFee();
}