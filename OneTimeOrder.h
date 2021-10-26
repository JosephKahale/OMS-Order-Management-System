#ifndef ONETIMEORDER_H
#define ONETIMEORDER_H
#include "Orders.h"
using namespace std;

class OneTimeOrder : public Order {

private:
	double balance;
	double fee;
public:
	OneTimeOrder(const string& = "N/A", double = 0, double = 0, double = 0, double = 0, const string& = "N/A", int = 0, const Date& = Date(), double = 0.0);
	OneTimeOrder& setFee(double);
	double getFee();
	virtual double calcTotal();
};
#endif // !ONETIMEORDER_H
