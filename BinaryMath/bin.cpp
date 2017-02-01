#include "stdafx.h"
#include "bin.h"
#include <iostream>
#include <string>
using namespace std;

bin::bin()
{
	class bin
	{
		char a[32], b[32], c[32];
		int s1, s2, m;
		char cary;
	public:
		bin()
		{
			cary = '0';
			s1 = 0; s2 = 0; m = 0;
			for (int i = 0; i<32; i++)
			{
				a[i] = '0';
				b[i] = '0';
				c[i] = '0';
			}
		}
		void getdata()
		{
			char m[32], n[32];
			cout << "Enter first binary number \n";
			gets(m);
			cout << "Enter second binary number \n";
			gets(n);
			s1 = strlen(m);
			s2 = strlen(n);
			for (int i = 31, j = s1 - 1; j >= 0;)
			{
				if (m[j] != '0'&&m[j] != '1')
				{
					system("cls");
					cout << "\nNot a binary number";
					exit(1);
				}
				a[i] = m[j];
				i--; j--;
			}
			for (int i = 31, j = s2 - 1; j >= 0;)
			{
				if (n[j] != '0'&&n[j] != '1')
				{
					system("cls");
					cout << "\nNot a binary number";
					exit(1);
				}
				b[i] = n[j];
				i--; j--;
			}
			system("cls");//edit as per compiler
		}
		void add();
		void sub();
		void com();
		void display();
	};
	void bin::sub()
	{
		m = 1;
		com();
		add();
	}
	void bin::com()
	{
		int count = 0;
		for (int i = 31; i >= 0; i--)
		{
			if (count>0)
			{
				if (b[i] == '1')
				{
					b[i] = '0';
				}
				else
				{
					b[i] = '1';
				}
			}
			if (b[i] == '1')
			{
				count++;
			}
		}
	}
	void bin::add()
	{
		cout << "\a";
		for (int i = 31; i >= 0; i--)
		{
			if (cary == '0'&&a[i] == '0'&&b[i] == '0')
			{
				cary = '0';
				c[i] = '0';
			}
			else if (cary == '0'&&a[i] == '0'&&b[i] == '1')
			{
				cary = '0';
				c[i] = '1';
			}
			else if (cary == '0'&&a[i] == '1'&&b[i] == '0')
			{
				cary = '0';
				c[i] = '1';
			}
			else if (cary == '0'&&a[i] == '1'&&b[i] == '1')
			{
				cary = '1';
				c[i] = '0';
			}
			else if (cary == '1'&&a[i] == '1'&&b[i] == '1')
			{
				cary = '1';
				c[i] = '1';
			}
			else if (cary == '1'&&a[i] == '0'&&b[i] == '0')
			{
				cary = '0';
				c[i] = '1';
			}
			else if (cary == '1'&&a[i] == '0'&&b[i] == '1')
			{
				cary = '1';
				c[i] = '0';
			}
			else if (cary == '1'&&a[i] == '1'&&b[i] == '0')
			{
				cary = '1';
				c[i] = '0';
			}
			else if (cary == '1'&&a[i] == '1'&&b[i] == '1')
			{
				cary = '1';
				c[i] = '1';
			}
		}
	}

	void bin::display()
	{
		int n;
		cout << "\nUpto how many bits do you want to display\n->";
		cin >> n;
		cout << "\nFirst Binary Number is:\n";
		for (int i = 32 - n; i<32; i++)
		{
			cout << a[i];
		}
		cout << endl;
		if (m == 1)
			cout << "\n2's complement of second number is:\n";
		else
		{
			cout << "\nSecond Binary Number is:\n";
		}
		for (int i = (32 - n); i<32; i++)
		{
			cout << b[i];
		}
		cout << endl;
		cout << "Result is: \n";
		for (int i = 32 - n; i<32; i++)
		{
			cout << c[i];
		}
		cout << endl;
	}
}


bin::~bin()
{
}
