#include "stdafx.h"
#include "UserInput.h"
#include <string>
#include <bitset>
#include <iostream>

using namespace std;
// global because i want to use them elsewhere.
bitset<16> a;
bitset<16> b;
//start
UserInput::UserInput()
{
	//ask the user to input and input
	cout << "Enter a binary Number up to 8 bits: ";
	cin >> a;
	cout << "Enter a binary Number up to 8 bits: ";
	cin >> b;
}


UserInput::~UserInput()
{
}
