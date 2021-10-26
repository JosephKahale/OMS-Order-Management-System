#include "Orders.h"
#include "Customer.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <map>
using namespace std;

Order::Order(const string& name, double price, double weight, double sub, double tot, double tax, int quantity, const Date& orderDt) {
	setItemName(name).setItemPrice(price).setItemWeight(weight).setSubtotal(sub).setTotal(tot).setTax(tax).setItemQuantity(quantity);
	setOrderDate(orderDt).setOrderNumber();
}

Order::Order(const string& name, double price, double weight, double sub, double tot, const string& tax, int quantity, const Date& orderDt) {
	setItemName(name).setItemPrice(price).setItemWeight(weight).setSubtotal(sub).setTotal(tot).setTax(tax).setItemQuantity(quantity);
	setOrderDate(orderDt).setOrderNumber();
}

Order& Order::setItemName(const string& name) {
	if (name.length() > 0) {
		itemName = name;
	}
	else {
		itemName = " ";
	}
	return *this;
}

Order& Order::setItemPrice(double price) {
	if (price >= 0) {
		itemPrice = price;
	}
	else {
		itemPrice = 0;
	}
	return *this;
}

Order& Order::setItemWeight(double weight) {
	if (weight >= 0) {
		itemWeight = weight;
	}
	else {
		itemWeight = 0;
	}
	return *this;
}

Order& Order::setSubtotal(double priceship) {
	if (priceship >= 0) {
		subtotal = priceship;
	}
	else {
		subtotal = 0;
	}
	return *this;
}

Order& Order::setTotal(double sub) {
	if (sub >= 0) {
		total = sub ;
	}
	else {
		total = 0;
	}
	return *this;
}

// THROWS an out_of_range exception
Order& Order::setTax(const string& city) {
	map<string, double> taxes = {
		{"La Canada", .095},
		{"La Crescenta", .1025},
		{"Montrose", .1025},
		{"Burbank", .1025},
		{"Pasadena", .1025},
		{"Glendale", .1025},
		{"Los Angeles", .0950},
		{"Anaheim", .0775},
		{"Thousand Oaks", .0725}
	};

	try {
		tax = taxes.at(city);
	}
	catch (const out_of_range& error) {
		tax = 9.5;
	}
	return *this;
}

Order& Order::setTax(double taxo) {
	if (taxo >= 0) {
		tax = taxo;
	}
	else {
		tax = 0;
	}
	return *this;
}

Order& Order::setItemQuantity(int quantity) {
	if (quantity >= 0) {
		itemQuantity = quantity;
	}
	else {
		itemQuantity = 0;
	}
	return *this;
}

Order& Order::setOrderNumber() {
	srand((unsigned int)time(NULL));
	orderNumber = rand() % 10000;
	while (binary_search(orderNumbs.begin(), orderNumbs.end(), orderNumber)) {
		orderNumber = rand() % 10000;
	}
	orderNumbs.push_back(orderNumber);
	return *this;
}

Order& Order::setOrderNumber(long num) {
	orderNumber = num;
	return *this;
}

Order& Order::setShippingCosts(double num) {

	if (num >= 0) {
		shippingCosts = num;
	}
	else {
		num = 0;
	}
	return *this;
}

const string& Order::getItemName() const {
	return itemName;
}

double Order::getItemPrice() const {
	return itemPrice;
}

double Order::getItemWeight() const {
	return itemWeight;
}

double Order::getShippingCosts() const {
	return shippingCosts;
}

double Order::calcSubtotal() const {
	return getItemPrice();
}

double Order::getSubtotal() const {
	return subtotal;
}

double Order::getTotal() const {
	return total;
}

double Order::getTax() const {
	return tax;
}

int Order::getItemQuantity() const {
	return itemQuantity;
}

double Order::calcTotal() const {
	return getItemPrice() + (getItemPrice() * getTax()) + getShippingCosts();
}

Date Order::getOrderDate() const {
	return orderDate;
}

Order& Order::setOrderDate(const Date& r) {
	orderDate = r;
	return *this;
}

long Order::getOrderNumber()  const {
	return orderNumber;
}



ostream& operator<<(ostream& out, const Order& order) {
	out << "Order Information: \n" << order.getItemName() << " ----- Order Number: " << order.getOrderNumber() << " ----- Order Date: " << order.getOrderDate() << endl;
	out << "Item Price: \t" << "$" << order.getItemPrice() << endl;
	out << "Item Weight \t" << order.getItemWeight() << "LB ----- Shipping Costs: $" << order.getShippingCosts() << endl;
	out << "Tax: \t" << "$" << order.getTax() << endl;
	out << "Total: \t" << "$" << fixed << setprecision(2) << order.calcTotal() << endl;
	return out;
}

bool Order::operator==(const Order& order) const {
	if (orderNumber == order.getOrderNumber()) {
		return true;
	}
	return false;
}