#include "stdafx.h"
#include "Addition.h"
#include <bitset>
#include <iostream>
#include "UserInput.h"
#include <string>
using namespace std;
//use the variables from UserInput
extern bitset<16> a;
extern bitset<16> b;
//start
Addition::Addition()
{
	//declarations
	int i;
	bool c = false;
	bitset<16> sum;
	// for loop up to 16 
	for (i = 0; i < 16; i++) {
		sum[i] = ((a[i] ^ b[i]) ^ c); // c is carry
		c= ((a[i] & b[i]) | (a[i] & c)) | (b[i] & c);
	}
	cout << "Additon result: " << sum << endl;
	cout << endl;
}


Addition::~Addition()
{
}
