// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// a small C++ program
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>

using namespace std;

const int ARRAYSIZE = 7;
int list[ARRAYSIZE];

void fill();

int index(int a);

void find();

void highLow();

void swap();

void sort();

void shuffle();


int main()
{
	char choice = 0;
	while (choice != 'x')
	{
		//system("clear");
		cout << "*************************************\n";
		cout << "0) Display array\n"
			<< "1) Find a value\n"
			<< "2) Find the highest and lowest value\n"
			<< "3) swap values\n"
			<< "4) Sort an array\n"
			<< "5) Shuffle an array\n"
			<< "x) Exit\n" << endl;

		cout << "Enter a choice: ";
		cin >> choice;
		if (choice == '0')
		{
			fill();
		}
		else if (choice == '1')
		{
			find();
		}
		else if (choice == '2')
		{
			highLow();
		}
		else if (choice == '3')
		{
			swap();
		}
		else if (choice == '4')
		{
			sort();
		}
		else if (choice == '5')
		{
			shuffle();
		}
		else
		{
			continue;
		}
	}

	system("pause");
	return 0;
}


// Function definitions

void fill()
{
	system("clear");
	srand(time(0));
	for (int i = 0; i<ARRAYSIZE; i++)
	{

		int randNum = rand() % 20;
		list[i] = randNum;
	}
	for (int i = 0; i<ARRAYSIZE; i++)
	{
		cout << list[i] << endl;
	}
	cout << "*************************************\n";
	return;
}

int index(int a)
{
	int num(a);


	for (int i = 0; i<ARRAYSIZE; i++)
	{
		if (num == list[i])
		{

			num = i;
			break;
		}
		else if (list[i] == list[ARRAYSIZE - 1])
		{
			cout << "The number you entered does not exist\n";
		}
	}
	return num;
}

void find()
{
	system("clear");

	cout << "Enter a number: ";
	int num;
	cin >> num;

	cout << "\n";

	for (int i = 0; i<ARRAYSIZE; i++)
	{
		if (num == list[i])
		{
			cout << "The index of " << num << " is " << i << endl;
			cout << "*************************************\n";
			break;
		}
		else if (list[i] == list[ARRAYSIZE - 1])
		{
			cout << "The number you entered does not exist\n";
			cout << "*************************************\n";
		}
	}
	return;
}

void highLow()
{
	system("clear");
	cout << "*************************************\n";

	int highest(list[0]), lowest(list[0]);
	//int indHigh(0), indLow(0);
	for (int i = 0; i<ARRAYSIZE; i++)
	{
		if (highest < list[i])
		{
			highest = list[i];
			//indHigh = i;
		}
		//=====================================
		if (lowest > list[i])
		{
			lowest = list[i];
			//indLow = i;
		}

	}

	cout << "*************************************\n";

	cout << "The highest value is " << highest << endl
		<< "The lowest value is " << lowest << endl;
	return;
}

void swap()
{
	system("clear");
	for (int i = 0; i<ARRAYSIZE; i++)
	{
		cout << list[i] << endl;
	}

	cout << "*************************************\n";

	int a, b, temp, idxa, idxb;
	cout << "Enter the first number: ";
	cin >> a;
	cout << "Enter the 2nd number: ";
	cin >> b;

	idxa = index(a);
	idxb = index(b);

	list[idxa] = b;
	list[idxb] = a;

	cout << "*************************************\n";

	for (int i = 0; i<ARRAYSIZE; i++)
	{
		cout << list[i] << endl;
	}
}

void sort()
{
	system("clear");
	cout << "*************************************\n";
	for (int i = 0; i<ARRAYSIZE; i++)
	{
		for (int j = i + 1; j<ARRAYSIZE; j++)
		{
			if (list[i]>list[j])
			{
				int temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
		}
	}
	for (int i = 0; i<ARRAYSIZE; i++)
	{
		cout << list[i] << endl;
	}
	cout << "*************************************\n";
}

void shuffle()
{
	system("clear");
	srand(time(NULL));
	cout << "*************************************\n";
	for (int i = 0; i<ARRAYSIZE; i++)
	{
		int rand1 = rand() % (ARRAYSIZE - 1);
		int rand2 = rand() % (ARRAYSIZE - 1);

		int temp = list[rand1];
		list[rand1] = list[rand2];
		list[rand2] = temp;
	}

	for (int i = 0; i<ARRAYSIZE; i++)
	{
		cout << list[i] << endl;
	}
	cout << "*************************************\n";

}