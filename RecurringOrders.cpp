#include "RecurringOrders.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

RecurringOrder::RecurringOrder(const string& name, double price, double weight, double sub, double tot, const string& subtax, int quantity, const Date& orderDt, const Date& subEnd)
	: Order(name, price, weight, sub, tot, subtax, quantity, orderDt)
{
	setSubDate(subEnd);
}

RecurringOrder& RecurringOrder::setSubDate(const Date& subEnd) {
	subEndDate.setMonth(subEnd.getMonth()).setDay(subEnd.getDay()).setYear(subEnd.getYear());
	return *this;
}

double RecurringOrder::getSubMonthTotal() {
	
	return subEndDate.getMonth();
}

double RecurringOrder::calcTotal() {
	return Order::calcTotal() *  getSubMonthTotal();
}