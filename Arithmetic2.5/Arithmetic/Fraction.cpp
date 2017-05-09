#include "stdafx.h"
#include "Fraction.h"
#include "Message.h"

#include <stdlib.h>
#include <iostream>
using namespace std;
const char c[] = "+-*/";

void Fraction::initFraction()
{
	for (int i = 0;i<4;)
	{
		int x = rand() % 9 + 1;    //分子分母的两个数 
		int y = rand() % 9 + 1;
		if (x != y)
		{

			if (x>y)
			{
				n[i] = y;n[i + 1] = x;
			}
			else
			{
				n[i] = x;n[i + 1] = y;
			}
			i += 2;
		}
	}
	s[0] = c[rand() % 4];
	s[1] = '=';
}

int Fraction::fraction()
{
	Message msg;

	demo = n[1] * n[3];
	n[0] *= n[3];
	n[2] *= n[1];
	switch (s[0])
	{
	case '+':nume = n[0] + n[2];break;
	case '-':nume = n[0] - n[2];break;
	case '*':nume = n[0] * n[2] / n[3] / n[1];break;
	case '/':nume = (double)n[0] / (double)n[2];break;
	}

	result = nume / (double)demo;
	if (result != (int)result)
	{
		initFraction();
	}
	else
	{
		n[0] /= n[3];
		n[2] /= n[1];
		for (int j = 0, i = 0;i<4;i++) //测试算式
		{
			if (i / 2.0 == i / 2)
			{
				cout << "(";
			}
			cout << n[i];
			if (i / 2.0 != i / 2)
			{
				cout << ")";
			}
			if (i / 2.0 == i / 2)
			{
				cout << "/";
			}
			else
			{
				if (s[j] == '/')
					cout << "÷";
				else
					cout << s[j];
				j++;
			}
		}
	}
	return result;
}
