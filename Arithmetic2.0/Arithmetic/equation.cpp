#include "stdafx.h"
#include "equation.h"
#include "CalculateResult.h"
#include "Message.h"

#include <iostream>
#include <stdlib.h>
using namespace std;

const char c[] = "+-*/";


void equation::initequation()
{
	Message msg;
	msg.digit_num = rand() % 3 + 4;

	for (int i = 0;i < msg.digit_num;i++)
	{
		s1[i] = rand() % 8 + 1; //Êý×Ö
		s2[i] = c[rand() % 4];  //·ûºÅ
	}
	s2[msg.digit_num - 1] = '=';
	bracket();
}

void equation::bracket() {
	CalculateResult cal();
	Message msg;

	bracket_num = rand() % 2;
	if (bracket_num == 1)
	{
		bracket_a = rand() % ((msg.digit_num - 1) / 2) + 1;
		bracket_b = bracket_a + rand() % ((msg.digit_num - 1) / 2) + 2;
	}


	
	checkprintf();
}

void  equation::checkprintf() { 
	Message msg;
	if (msg.result != (int)msg.result)
	{
		initequation();
	}
	else
	{
		if (bracket_num == 0)
		{
			for (int i = 0;i < msg.digit_num;i++)
			{
				if (s2[i] == '/')
					cout << s1[i] << "¡Â";
				else
					cout << s1[i] << s2[i];
			}
			//cout<<result;
		}
		else if (bracket_num == 1)
		{
			for (int i = 0;i < msg.digit_num; i++)
			{
				if (i == bracket_a) cout << "(";
				cout << s1[i];
				if (i == bracket_b - 1) cout << ")";
				if (s2[i] == '/')
					cout << "¡Â";
				else
					cout << s2[i];
			}
			//		cout<<msg.result; 
		}
	}

	
}


