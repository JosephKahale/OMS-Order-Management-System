#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Customer.h"
#include "CustomerList.h"
#include "Orders.h"
#include "OrderHistory.h"
#include "Package.h"
#include "ThreeDay.h"
#include "OneDay.h"
#include "OneTimeOrder.h"
#include "RecurringOrders.h"

using namespace std;

int main() {
	int choiceMenuOne, choiceCustomer, choiceEdit, choiceOrder, zip, exisitingBalance, shipSpeed, selection;
	string fullName, address, city, state, phone;
	string itemName;
	double itemPrice, itemWeight, shipCost, subTotal;
	long custNumb, orderNumb;
	CustomerList custList;
	OrderHistory ordHist;
	cout << setw(30) << "-----------------------------------------------" << endl
		 << setw(30) << "--     ---   ---- -  --        --------   -----" << endl
		 << setw(30) << "-- --- --- -- -- --- --  ----- ------  -- -----" << endl
		 << setw(30) << "-- --- --- ---  ---- -----  ------------- -----" << endl
		 << setw(30) << "-- --- --- ---  ---- -- ----   ---------- -----" << endl
		 << setw(30) << "--     --- --------- --        --  ---       --" << endl
		 << setw(30) << "-----------------------------------------------" << endl;

	cout << setw(30) << "Welcome to Order Management System | Version 1 |" << endl;
	do {
		cout << "-----------------------------------------------" << endl;
		cout << "1) Manage Customers" << endl
			<< "2) Manage Orders" << endl
			<< "3) Exit" << endl;
		cin >> choiceMenuOne;
		cin.ignore();
		while (choiceMenuOne > 3 || choiceMenuOne < 1) {
			cout << "You entered an invalid input, please enter a valid input: " << endl;
			cin >> choiceMenuOne;
			cin.ignore();
		}

		if (choiceMenuOne == 1) {
			cout << "----------|Customer Management Menu|-----------" << endl
				<< "-----------------------------------------------" << endl
				<< "1) Register a New Customer" << endl
				<< "2) Delete an Existing Customer" << endl
				<< "3) View All Existing Customers" << endl
				<< "4) Edit an Exisiting Customers Information" << endl
				<< "5) Exit Back To Original Menu" << endl
				<< "-----------------------------------------------" << endl;
			cin >> choiceCustomer;
			cin.ignore();
			while (choiceCustomer > 5 || choiceCustomer < 1) {
				cout << "You entered an invalid input, please enter a valid input: " << endl;
				cin >> choiceCustomer;
				cin.ignore();
			}

			switch (choiceCustomer) {
			case 1:
			{
				Customer* customer = new Customer();

				cout << "Please enter the customers Full Name: " << endl;
				getline(cin, fullName);
				customer->setFullName(fullName);

				cout << "Please enter the customers address: " << endl;
				getline(cin, address);
				customer->setAddress(address);

				cout << "Please enter the customers city: " << endl;
				getline(cin, city);
				customer->setCity(city);

				cout << "Please enter the customers state: " << endl;
				getline(cin, state);
				customer->setState(state);

				cout << "Please enter the customers phone number: " << endl;
				cout << "EX: 18183456789 " << endl;
				getline(cin, phone);
				customer->setPhoneNumber(phone);

				cout << "Please enter the customers zipcode: " << endl;
				cin.ignore();
				cin >> zip;
				customer->setZipCode(zip);

				cout << "If the user has an existing balance, please enter it: " << endl;
				cin >> exisitingBalance;
				customer->setBalance(exisitingBalance);

				cin.ignore();
				custList.registerCustomer(customer);

				cout << "Congratulations your account has successfuly been created!" << endl
					<< "You can find your customer number below!" << endl
					<< "Keep this number at all times because it is required to place an order." << endl;
				cout << *customer;
				break;
			}
			case 2:
				cout << "To Delete An Existing Customer: " << endl
					<< "\t Please enter an existing customer number: " << endl;
				cin >> custNumb;
				custList.deleteCustomer(custNumb);
				break;

			case 3:
				cout << "Viewing All Existing Customers: " << endl;
				cout << custList;
				break;

			case 4:
			{
				cout << "To Edit An Existing Customer: " << endl
					<< "\t Please enter an existing customer number: " << endl;
				cin >> custNumb;
				Customer* edit = custList.getCustomerByID(custNumb);
				if (edit != nullptr) {

					cout << "----------|Edit Existing Customer Information|-----------" << endl
						<< "---------------------------------------------------------" << endl
						<< "1) Edit Full Name" << endl
						<< "2) Edit Address" << endl
						<< "3) Edit City" << endl
						<< "4) Edit State" << endl
						<< "5) Edit ZipCode" << endl
						<< "6) Edit Phone Number" << endl
						<< "6) Exit Out of Editor" << endl
						<< "-----------------------------------------------" << endl
						<< "Please enter a selection: " << endl;
					cin >> choiceEdit;
					if (choiceEdit == 1) {
						cout << "Please enter the customers Full Name: " << endl;
						getline(cin, fullName);
						edit->setFullName(fullName);
					}
					else if (choiceEdit == 2) {
						cout << "Please enter the customers address: " << endl;
						getline(cin, address);
						edit->setAddress(address);
					}
					else if (choiceEdit == 3) {
						cout << "Please enter the customers city: " << endl;
						cout << "Note: Orders only ship to select cities: La Canada, La Crescenta, Montrose, Burbank, Pasadena, Glendale, Los Angeles, Anaheim, Thousand Oaks" << endl;
						getline(cin, city);
						edit->setCity(city);
					}
					else if (choiceEdit == 4) {
						cout << "Please enter the customers state: " << endl;
						getline(cin, state);
						edit->setState(state);
					}
					else if (choiceEdit == 5) {
						cout << "Please enter the customers zipcode: " << endl;
						cin.ignore();
						cin >> zip;
						edit->setZipCode(zip);
					}
					if (choiceEdit == 6) {
						cout << "Please enter the customers phone number: " << endl;
						cout << "EX: 1(818) 345 - 6789 " << endl;
						getline(cin, phone);
						edit->setPhoneNumber(phone);
					}
					else {
						cout << "You are exiting out of the editor." << endl;
					}
				} else {
					cout << "I couldn't find that customer!" << endl;
				}
				break;
			}
			case 5: 
				cout << "You are exiting out of the Customer Management Menu. " << endl;
				break;
			default: cout << "Invalid input" << endl;
				break;
			}
		}

		if (choiceMenuOne == 2) {
			cout << "----------|Order Management Menu|-----------" << endl
				<< "-----------------------------------------------" << endl
				<< "1) Create a New Order" << endl
				<< "2) Cancel an Existing Order" << endl
				<< "3) View All Existing Orders" << endl
				<< "4) Edit an Exisiting Orders Information" << endl
				<< "5) Exit Back To Original Menu" << endl
				<< "-----------------------------------------------" << endl
				<< "Please have an existing customer number ready." << endl
				<< "-----------------------------------------------" << endl;
				cin >> choiceOrder;
				cin.ignore();
				while (choiceOrder > 5 || choiceOrder < 1) {
					cout << "You entered an invalid input, please enter a valid input: " << endl;
					cin >> choiceOrder;
					cin.ignore();
				}
				cout << "Please enter a customer number to continue: " << endl;
				cout << "If you dont have one, press -1 to go back to the menu: " << endl;
				cin >> custNumb;
				cin.ignore();
				Customer* customer = custList.getCustomerByID(custNumb);
				if (customer != nullptr) {
					switch (choiceOrder) {
					case 1:
					{
						cout << "1) One Time Order" << endl
							<< "2) Reccuring Order" << endl;

						cin >> selection;
						cin.ignore();

						if (selection == 1) {
							OneTimeOrder* order = new OneTimeOrder();
							cout << "Please enter the item name: " << endl;
							getline(cin, itemName);
							order->setItemName(itemName);


							cout << "Please enter the item price: " << endl;
							cin >> itemPrice;
							order->setItemPrice(itemPrice);

							cout << "Please enter the order item weight: " << endl;
							cin >> itemWeight;
							order->setItemWeight(itemWeight);


							order->setTax(customer->getCity());

							cout << "1) Fast Shipping" << endl
								<< "2) Slow Shipping" << endl;
							cin >> shipSpeed;
							if (shipSpeed == 1) {
								OneDayPackage* ship = new OneDayPackage();
								ship->setReceiverAddress(customer->getAddress());
								ship->setReceiverCity(customer->getCity());
								ship->setReceiverName(customer->getFullName());
								ship->setReceiverState(customer->getState());
								ship->setReceiverZip(customer->getZipCode());
								ship->setWeight(order->getItemWeight());
								order->setShippingCosts(ship->calculateCost());

							}
							else {
								ThreeDayPackage* ship = new ThreeDayPackage();
								ship->setReceiverAddress(customer->getAddress());
								ship->setReceiverCity(customer->getCity());
								ship->setReceiverName(customer->getFullName());
								ship->setReceiverState(customer->getState());
								ship->setReceiverZip(customer->getZipCode());
								ship->setWeight(order->getItemWeight());
								order->setShippingCosts(ship->calculateCost());
							}
							ordHist.createOrder(order);

							cout << "Great, You Can Find Your Order Total Below!";
							cout << *order;
						}
						else if (selection == 2) {
							RecurringOrder* order = new RecurringOrder();
							cout << "Please enter the item name: " << endl;
							getline(cin, itemName);
							order->setItemName(itemName);


							cout << "Please enter the item price: " << endl;
							cin >> itemPrice;
							order->setItemPrice(itemPrice);

							cout << "Please enter the order item weight: " << endl;
							cin >> itemWeight;
							order->setItemWeight(itemWeight);


							order->setTax(customer->getCity());

							cout << "1) Fast Shipping" << endl
								<< "2) Slow Shipping" << endl;
							cin >> shipSpeed;
							if (shipSpeed == 1) {
								OneDayPackage* ship = new OneDayPackage();
								ship->setReceiverAddress(customer->getAddress());
								ship->setReceiverCity(customer->getCity());
								ship->setReceiverName(customer->getFullName());
								ship->setReceiverState(customer->getState());
								ship->setReceiverZip(customer->getZipCode());
								ship->setWeight(order->getItemWeight());
								order->setShippingCosts(ship->calculateCost());

							}
							else {
								ThreeDayPackage* ship = new ThreeDayPackage();
								ship->setReceiverAddress(customer->getAddress());
								ship->setReceiverCity(customer->getCity());
								ship->setReceiverName(customer->getFullName());
								ship->setReceiverState(customer->getState());
								ship->setReceiverZip(customer->getZipCode());
								ship->setWeight(order->getItemWeight());
								order->setShippingCosts(ship->calculateCost());
							}
							ordHist.createOrder(order);

							cout << "Great, You Can Find Your Order Total Below!";
							cout << *order;

						}

						break;
					}
					case 2:
					{
						cout << "To Cancel An Existing Order: " << endl
							<< "\t Please enter an existing order number: " << endl;
						cin >> orderNumb;
						ordHist.archiveOrder(orderNumb);
						break;
					}
					case 3:
					{
						cout << "Viewing All Existing Orders: " << endl;
						cout << ordHist;
						break;
					}
					case 4:
					{
						cout << "To Edit An Existing Order: " << endl
							<< "\t Please enter an existing order number: " << endl;
						cin >> orderNumb;
						Order* edit = ordHist.getOrderByID(orderNumb);
						if (edit != nullptr) {

							cout << "----------|Edit Existing Customer Information|-----------" << endl
								<< "---------------------------------------------------------" << endl
								<< "1) Edit Item Name" << endl
								<< "2) Edit Item Weight" << endl
								<< "3) Edit Item Price" << endl
								<< "4) Edit Shipping Cost" << endl
								<< "5) Exit Out of Editor" << endl
								<< "-----------------------------------------------" << endl
								<< "Please enter a selection: " << endl;
							cin >> choiceEdit;
							cin.ignore();
							if (choiceEdit == 1) {
								cout << "Please enter the item name: " << endl;
								getline(cin, itemName);
								edit->setItemName(itemName);
								cin.ignore();
							}
							else if (choiceEdit == 2) {
								cout << "Please enter the item price: " << endl;
								cin >> itemPrice;
								edit->setItemPrice(itemPrice);
								cin.ignore();
							}
							else if (choiceEdit == 3) {
								cout << "Please enter the order item weight: " << endl;
								cin >> itemWeight;
								edit->setItemWeight(itemWeight);
								cin.ignore();
							}
							else if (choiceEdit == 4) {
								cout << "Please enter the order shipping costs: " << endl;
								cin >> shipCost;
								edit->setShippingCosts(shipCost);
								cin.ignore();
							}
							else {
								cout << "You are exiting out of the editor." << endl;
							}
						}
						else {
							cout << "I couldn't find that customer!" << endl;
						}
						break;

					}
					default:
						cout << "Invalid input. Please Try again" << endl;
					}
				}
		}
	} while (choiceMenuOne != 3);
}