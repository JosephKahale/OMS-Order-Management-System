#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include <string>
#include "Customer.h"
#include "Time.h"  
#include "Date.h"
#include "Package.h"
#include <vector>
using namespace std;

class Order {
	friend ostream& operator<<(ostream&, const Order&);
private:
	vector<long> orderNumbs;
	long orderNumber;
	string itemName;
	double itemPrice;
	double itemWeight;
	double shippingCosts;
	double subtotal;
	double total;
	double tax;
	int itemQuantity;
	Date orderDate;
public:
	Order(const string & = "N/A", double = 0.0, double = 0.0, double = 0.0, double = 0.0, const string& = "Glendale", int = 0, const Date & = Date());
	Order(const string& = "N/A", double = 0.0, double = 0.0, double = 0.0, double = 0.0, double = 0.0, int = 0, const Date& = Date());
	const string& getItemName() const;
	double getItemPrice() const;
	double getItemWeight() const;
	double getShippingCosts() const;
	double getSubtotal() const;
	double getTotal() const;
	double getTax() const;
	int getItemQuantity() const;
	Date getOrderDate() const;
	long getOrderNumber() const;
	double calcSubtotal() const;

	Order& setItemName(const string&);
	Order& setItemPrice(double);
	Order& setItemWeight(double);
	Order& setSubtotal(double);
	Order& setTotal(double);
	Order& setTax(const string&);
	Order& setTax(double);
	Order& setItemQuantity(int);
	Order& setOrderNumber();
	Order& setOrderNumber(long);
	Order& setOrderDate(const Date&);
	Order& setShippingCosts(double); //

	virtual double calcTotal() const;

	bool operator==(const Order&) const;


};

#endif // !ORDER_H
