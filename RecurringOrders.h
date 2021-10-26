#ifndef RECURRINGORDER_H
#define RECURRINGORDER_H
#include "Orders.h"
using namespace std;

class RecurringOrder : public Order {

private:
	double balance;
	Date subEndDate;
public:
	RecurringOrder(const string& = "N/A", double = 0, double = 0, double = 0, double = 0, const string& = "N/A", int = 0, const Date& = Date(), const Date& = Date());
	RecurringOrder& setSubDate(const Date&);
	virtual double calcTotal();
	double getSubMonthTotal();
};
#endif // !RECURRINGORDER_H