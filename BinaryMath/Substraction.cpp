#include "stdafx.h"
#include "Substraction.h"
#include <bitset>
#include <iostream>
#include "UserInput.h"
#include <string>
using namespace std;
//use the variables from UserInput
extern bitset<16> a;
extern bitset<16> b;

Substraction::Substraction()
{
	//invert b
	int inverter = 0;
	bitset<16> second_b;
	second_b = b;
	for (inverter; inverter < 16; inverter++)
	{
		if (second_b[inverter] == 0)
		{
			second_b[inverter] = 1;
		}
		else
		{
			second_b[inverter] = 0;
		}
	}
	//b is inverted
	//get the two's compliment of b
	int d;
	bitset<16> compliment, sum_comp;
	bool k = false;
	compliment[0] = 1;//add 1
	//loop to add 1
	for (d = 0; d < 16; d++) {
		sum_comp[d] = ((compliment[d] ^ second_b[d]) ^ k); // k is carry
		k = ((compliment[d] & second_b[d]) | (compliment[d] & k)) | (second_b[d] & k);
	}
	//add the 2's compliment and a
	int i;
	bool c = false;
	bitset<16> sum;
	// for loop up to 16 
	for (i = 0; i < 16; i++) {
		sum[i] = ((a[i] ^ sum_comp[i]) ^ c); // c is carry
		c = ((a[i] & sum_comp[i]) | (a[i] & c)) | (sum_comp[i] & c);
	}
	//if the result is positive
	if (sum[8] == 0)
	{
		cout << "difference result: " << sum << endl;
	}
	//if negative
	if (sum[8] == 1)
	{
		bitset<16> negative_compliment;
		// invert first sum
		inverter = 0;
		for (inverter; inverter < 16; inverter++)
		{
			if (sum[inverter] == 0)
			{
				sum[inverter] = 1;
			}
			else
			{
				sum[inverter] = 0;
			}
		}
		//declarations
		k = false;
		compliment[0] = 1;
		// get the 2's compliment of sum
		for (d = 0; d < 16; d++) {
			negative_compliment[d] = ((compliment[d] ^ sum[d]) ^ k); // k is carry
			k = ((compliment[d] & sum[d]) | (compliment[d] & k)) | (sum[d] & k);
		}
		//this is the answer
		cout << "the difference is -" << negative_compliment << endl;
	}
	cout << endl;
}


Substraction::~Substraction()
{
}
