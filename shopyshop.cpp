//#include <conio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <string>
#include <iomanip>
using namespace std;

		vector <double> price = { 5.23, 0.50, 3.00, 5.07, 4.87, 2.65, 3.44, 4.45, 3.33, 1.25};
		vector <string> names = { "Grapes", "Apples", "Potatoes", "Carrots", "Kiwi", "Banana", "Pear", "Mango", "Pepper", "Onion" };
		vector <string> cart_item;
		vector <double> item_price;
		double wallet = 0;
		double total;

int newAccount()
{
		// Generate  an account number between 840000000 and 847000000
		srand(time(0));
		int limit = rand() % 7000001;
		int accountNum = 839999999 + limit;
		
		return accountNum;
}

float makePayment()
{
		int bAccountNum;
		cout << "Enter your account number: ";
		cin>> bAccountNum;
		
		if ( bAccountNum <= 847000000 && bAccountNum >839999999) // Acceptable values
		{
				srand(time(0));
				wallet = 5 + rand()%20; // Generate a Random amount of money between 1 and 20 in your account
				//return wallet;
		}
		else
		{
				cout << "Invalid account number.\n";
		}
		return 0;
}

void inventory()
{

		// Printing out the list of available items
		cout << "0-----------------------------0"<<endl;
		cout << "|           INVENTORY         |"<<endl;
		cout << "0-----------------------------0"<<endl;
		for(int i = 0; i<10; i++)
		{
			cout << "| " << setw(12)<< names[i] << " | " << setw(12)<< fixed << setprecision(2) << price[i] << " |" << endl;
		}
		cout << "0-----------------------------0"<<endl;
}

double cart()
{
		while(true)
		{
			string searchString;
			string choice;
			cout << "Add items to your cart (P.S respect capitalization) : ";
			cin >> choice;
		
			// Get the Index of the entered item
			int index;

			auto iter = find(names.begin(), names.end(), choice);
			if (iter != names.end()) 
			{
				index = distance(names.begin(), iter);
			
			} 
			
			// Get the corresponding price in the price vector and sum up the total price
			total = total + price[index];
			
			// Append the items  and prices to the cart
			cart_item.push_back(choice);
			item_price.push_back(price[index]);
			
			// Decide whether the user continue shopping
			char decision;
			cout << "Continue shopping(y/n): ";
			cin>> decision;
			if ( decision != 'y')
			{
					break;
			}
		}
		return 0;
}

int main()
{
		// Display the iventory
		inventory();

		// Select items
		cart();
		
		// basic invoice
		int lim = cart_item.size();
		cout << "0--------------------------------------------------------0" << endl;
		cout << "|                        INVOICE                         "<<"|" << endl;
		cout << "0--------------------------------------------------------0" << endl;
		cout << "| "<<setw(16)<<"Description"<<" | "<<setw(16)<<"Prices"<<" | "<<setw(16)<<"Subtotal"<<" |" << endl;
		cout << "0--------------------------------------------------------0" << endl;
		
		for (int i=0; i<lim; i++)
		{
			cout << "| " << setw(16) << left << cart_item[i] << " | ";
			cout << setw(16) << item_price[i] << " | ";
			cout << setw(12) << right << "R"<< fixed << setprecision(2) << item_price[i] << " |\n";
		}
		
		cout << "0--------------------------------------------------------0" << endl;
		cout << "| " << setw(49) <<"Total: "<< fixed << setprecision(2) << total<<" |" << endl;
		cout << "0--------------------------------------------------------0" << endl;
			
			// Run the payment function
			makePayment();
			
			// Determine if the user has enough money to buy the goods
			if (total > wallet)
			{
					cout << "Payment decline."<<endl;
			}
			else{
				cout<<"Thanks for shopping at RERD."<<endl;
			}
			
			//getch();
			return 0;
}
