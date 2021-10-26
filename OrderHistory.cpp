#include "OrderHistory.h"
#include "Orders.h"
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

OrderHistory::OrderHistory() 
{
	readFromFile();
}

OrderHistory::~OrderHistory() 
{
	writeToFile();
	for (int i = 0; i < orders.size(); i++) {
		delete orders[i];
	}
}

bool OrderHistory::createOrder(Order* order) {
	for (int i = 0; i < orders.size(); i++) {
		if (*orders[i] == *order) {
			return false;
		}
	}
	orders.push_back(order);
	return true;
}

bool OrderHistory::archiveOrder(long ord) {
	for (int i = 0; i < orders.size(); i++) {
		if (orders[i]->getOrderNumber() == ord) {
			orders.erase(orders.begin() + i);
			return true;
		}
	}
	return false;
}

int OrderHistory::getNumOrders() const {
	return (int)orders.size();
}

Order* OrderHistory::getOrderByID(long num) {
	for (int i = 0; i < orders.size(); i++) {
		if (orders[i]->getOrderNumber() == num) {
			return orders[i];
		}
	}
	return nullptr;
}

const vector<Order*>& OrderHistory::getOrders() const {
	return orders;
}

void OrderHistory::writeToFile() 
{
	ofstream out("OrderHistory.txt", ios::out);
	for (int i = 0; i < orders.size(); i++) {
		out << orders[i]->getItemName() << endl;
		out << orders[i]->getItemPrice() << endl;
		out << orders[i]->getItemWeight() << endl;
		out << orders[i]->getShippingCosts() << endl;
		out << orders[i]->getSubtotal() << endl;
		out << orders[i]->getTotal() << endl;
		out << orders[i]->getTax() << endl;
		out << orders[i]->getItemQuantity() << endl;
		out << orders[i]->getOrderDate() << endl;
		out << orders[i]->getOrderNumber() << endl;
		out << "END" << endl;
	}
	out.close();
}


void OrderHistory::readFromFile() 
{
	string line;
	int size = 0;
	int pos = 1;
	ifstream in("OrderHistory.txt", ios::in);
	if (!in.fail()) {
		Order* order = new Order("N/A", 0.0, 0.0, 0.0, 0.0, 0.0);
		getline(in, line);
		while (!in.fail()) {
			if (line == "END") {
				orders.push_back(order);
				pos = 1;
				order = new Order("N/A", 0.0, 0.0, 0.0, 0.0, 0.0);
			}
			else if (pos == 2) {
				order->setItemPrice(stod(line));
				pos = 3;
			}
			else if (pos == 3) {
				order->setItemWeight(stod(line));
				pos = 4;
			}
			else if (pos == 4) {
				order->setShippingCosts(stod(line));
				pos = 5;
			}
			else if (pos == 5) {
				order->setSubtotal(stod(line));
				pos = 6;
			}
			else if (pos == 6) {
				order->setTotal(stod(line));
				pos = 7;
			}
			else if (pos == 7) {
				order->setTax(stod(line));
				pos = 8;
			}
			else if (pos == 8) {
				order->setItemQuantity(stoi(line));
				pos = 9;
			}
			else if (pos == 9) {
				order->setOrderDate(Date());
				pos = 10;
			}
			else if (pos == 10) {
				order->setOrderNumber(stol(line));
				pos = 11;
			}
			else {
				order->setItemName(line);
				pos = 2;
			}

			getline(in, line);
		}
	}
	in.close();
}

ostream& operator<<(ostream& out, const OrderHistory& list) {
	out << "Order List\n" << endl;
	out << "________________________________" << endl;
	for (int i = 0; i < list.getOrders().size(); i++) {
		out << *list.getOrders()[i] << endl;
	}
	return out;
}