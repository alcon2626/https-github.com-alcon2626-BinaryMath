// BinaryMath.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <bitset>
#include "UserInput.h"
#include "Addition.h"
#include "Substraction.h"
#include"Multiplication.h"
using namespace std;

int main()
{
	//welcome message and instructions
	cout << "welcome to binary math!" << endl;
	string finish = "no";
	//loop to keep the program runing
	while (finish == "no")
	{
		UserInput();//calls user input obj
		Addition(); // addition call
		Substraction(); // calls substraction
		Multiplication(); // calls multiplication

		cout << "End the program?" << endl;
		cin >> finish;
		//input validation
		while (finish != "yes" && finish != "no")
		{
			cout << "Enter yes or no" << endl;
			cin >> finish;
		}
		//end loop
		if (finish == "yes")
		{
			break;
		}
	}
	return 0;
}