#ifndef ORDERHISTORY_H
#define ORDERHISTORY_H
#include "Orders.h"
#include "Customer.h"
#include <vector>
#include <iostream>

class OrderHistory {
	friend ostream& operator<<(ostream&, const OrderHistory&);
private:
	vector<Order*> orders;

public:
	OrderHistory();
	~OrderHistory();

	const vector<Order*>& getOrders() const;
	Order* getOrderByID(long);
	void readFromFile();
	void writeToFile();

	bool createOrder(Order*);
	bool archiveOrder(long);
	int getNumOrders() const;
};

#endif // !ORDERHISTORY_H
