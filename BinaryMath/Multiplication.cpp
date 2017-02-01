#include "stdafx.h"
#include "Multiplication.h"
#include <bitset>
#include <iostream>
#include "UserInput.h"
#include <string>
using namespace std;
//use the variables from UserInput
extern bitset<16> a;
extern bitset<16> b;

Multiplication::Multiplication()
{
	//declarations
	int i;
	bool c = false;
	bitset<16> sum, answer;
	bitset<16> uno, dos, tres, cuatro, cinco, seis, siete, ocho;// easier to keep track for me
	//fist result of multiplicating by b[0] position
    for (i = 0; i < 16; i++) 
	{
		c = a[i] & b[0];
		sum[i] = ((a[i] & b[0]) & c); // c is carry
		uno = sum;
	}
	//second result of multiplicating by b[1] position
	for (i = 0; i < 16; i++)
	{
		c = a[i] & b[1];
		sum[i] = ((a[i] & b[1]) & c); // c is carry
	}
	dos = sum << 1;
	//third result of multiplicating by b[2] position
	for (i = 0; i < 16; i++)
	{
		c = a[i] & b[2];
		sum[i] = ((a[i] & b[2]) & c); // c is carry
	}
	tres = sum << 2;
	//forth result of multiplicating by b[3] position
	for (i = 0; i < 16; i++)
	{
		c = a[i] & b[3];
		sum[i] = ((a[i] & b[3]) & c); // c is carry
	}
	cuatro = sum << 3;
	//fith result of multiplicating by b[4] position
	for (i = 0; i < 16; i++)
	{
		c = a[i] & b[4];
		sum[i] = ((a[i] & b[4]) & c); // c is carry
	}
	cinco = sum << 4;
	//sixth result of multiplicating by b[5] position
	for (i = 0; i < 16; i++)
	{
		c = a[i] & b[5];
		sum[i] = ((a[i] & b[5]) & c); // c is carry
	}
	seis = sum << 5;
	//seventh result of multiplicating by b[6] position
	for (i = 0; i < 16; i++)
	{
		c = a[i] & b[6];
		sum[i] = ((a[i] & b[6]) & c); // c is carry
	}
	siete = sum << 6;
	//eigth result of multiplicating by b[7] position
	for (i = 0; i < 16; i++)
	{
		c = a[i] & b[7];
		sum[i] = ((a[i] & b[7]) & c); // c is carry
	}
	ocho = sum << 7;
	//adding together the rsults
	bitset<16> adding_1, adding_2, adding_3, adding_4, adding_5, adding_6;
	// first addition of 1 & 2
	for (i = 0; i < 16; i++) {
		adding_1[i] = ((uno[i] ^ dos[i]) ^ c); // c is carry
		c = ((uno[i] & dos[i]) | (uno[i] & c)) | (dos[i] & c);
	}
	//adding 3 & 4
	for (i = 0; i < 16; i++) {
		adding_2[i] = ((tres[i] ^ cuatro[i]) ^ c); // c is carry
		c = ((tres[i] & cuatro[i]) | (tres[i] & c)) | (cuatro[i] & c);
	}
	//adding 6 & 6
	for (i = 0; i < 16; i++) {
		adding_3[i] = ((cinco[i] ^ seis[i]) ^ c); // c is carry
		c = ((cinco[i] & seis[i]) | (cinco[i] & c)) | (seis[i] & c);
	}
	//adding 7 & 8
	for (i = 0; i < 16; i++) {
		adding_4[i] = ((siete[i] ^ ocho[i]) ^ c); // c is carry
		c = ((siete[i] & ocho[i]) | (siete[i] & c)) | (ocho[i] & c);
	}
	//adding the rsults of 1 & 2 and 3 & 4
	for (i = 0; i < 16; i++) {
		adding_5[i] = ((adding_1[i] ^ adding_2[i]) ^ c); // c is carry
		c = ((adding_1[i] & adding_2[i]) | (adding_1[i] & c)) | (adding_2[i] & c);
	}
	//adding the results of 5 & 6 and 7 & 8
	for (i = 0; i < 16; i++) {
		adding_6[i] = ((adding_3[i] ^ adding_4[i]) ^ c); // c is carry
		c = ((adding_3[i] & adding_4[i]) | (adding_3[i] & c)) | (adding_4[i] & c);
	}
	//final answer
	for (i = 0; i < 16; i++) {
		answer[i] = ((adding_5[i] ^ adding_6[i]) ^ c); // c is carry
		c = ((adding_5[i] & adding_6[i]) | (adding_5[i] & c)) | (adding_6[i] & c);
	}
	cout << "The product is: " << answer << endl;
	cout << endl;
	cout << endl;
}


Multiplication::~Multiplication()
{
}
