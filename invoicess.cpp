#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main()
{
	double price[10] = { 5.23, 0.50, 3.00, 5.07, 4.87, 2.65, 3.44, 4.45, 3.33, 1.25};
	int quantity[10] = { 12, 48, 10, 12, 12, 13, 14, 12, 14, 16 };
	string names[10] = { "Grapes", "Apples", "Potatoes", "Carrots", "Kiwi", "Banana", "Pear", "Mango", "Pepper", "Onion" };
	int i = 0;
	double subtotal;
	double total = 0;
	cout << "0---------------------------------------------------------------------------0" << endl;
	cout << "|                                 AN INVOICE                                |" << endl;
	cout << "0---------------------------------------------------------------------------0" << endl;
	cout << "| "<<setw(16)<<"Description"<<" | "<<setw(16)<<"Prices"<<" | "<<setw(16)<<"Quantity"<<" | "<<setw(16)<<"Subtotal"<<" |" << endl;
	cout << "0---------------------------------------------------------------------------0" << endl;
	for (i; i<10; i++)
	{
		subtotal = price[i] * quantity[i];
		total = total + subtotal;
		cout << "| " << setw(16) << left << names[i] << " | ";
		cout << setw(16) << price[i] << " | ";
		cout << setw(16) << quantity[i] << " | ";
		cout << setw(11) << right << "R"<< fixed << setprecision(2) << subtotal << " |\n";
	}
	cout << "0---------------------------------------------------------------------------0" << endl;
	cout << "| " << setw(67) <<"Total: "<< fixed << setprecision(2) << total<<" |" << endl;
	cout << "0---------------------------------------------------------------------------0" << endl;
	//_getch();
	return 0;
}