#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main()
{
	while(true)
	{
		string userchoice;
		cout << "Enter your choice (rock, paper, scissors): ";
		cin >> userchoice;

		srand(time(0));
		int i = rand()%3;

		string option[3] = {"rock", "paper", "scissors"};
		string cpu = option[i];

		if(cpu == userchoice)
		{
			cout << "Draw! I'll smash you next time!!" << endl;
		}
		else if(cpu == "rock")
		{
			if(userchoice == "paper")
			{
				cout << "You are a legend!" << endl;
			}
			else if(userchoice == "scissors")
			{
				cout << "You are such a loser ahahah!!" << endl;
			}
		}
		else if(cpu == "paper")
		{
			if(userchoice == "scissors")
			{
				cout << "You are a legend!" << endl;
			}
			else if(userchoice == "rock")
			{
				cout << "You are such a loser ahahah!!" << endl;
			}
		}
		else if(cpu == "scissors")
		{
			if(userchoice == "rock")
			{
				cout << "You are a legend!" << endl;
			}
			else if(userchoice == "paper")
			{
				cout << "You are such a loser ahahah!!" << endl;
			}
		}
		/*else
		{
			cout << "Bro you had ONE JOB!!!" << endl;
		}*/

		string decision;
		cout << "Do you want to continue (y/n)? ";
		cin >> decision;
		if(decision != "y")
		{
			cout << "Bye Bye!" << endl;
			break;
		}
	}
}