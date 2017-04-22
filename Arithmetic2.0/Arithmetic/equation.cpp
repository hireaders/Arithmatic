#include "stdafx.h"
#include "equation.h"
#include "CalculateResult.h"
#include "Message.h"

#include <iostream>
#include <stdlib.h>
using namespace std;

const char c[] = "+-*/";

equation::equation()
{}

void equation::initequation()
{
	Message msg;
	msg.digit_num = rand() % 3 + 4;

	for (int i = 0;i < msg.digit_num;i++)
	{
		m[i] = rand() % 8 + 1;
		n[i] = c[rand() % 4];
	}
	n[msg.digit_num - 1] = '=';
	bracket();
}

void equation::bracket() {
	CalculateResult cal;
	Message msg;

	msg.bracket_num = rand() % 2;


	if (msg.bracket_num == 1)
	{
		msg.bracket_a = rand() % ((msg.digit_num - 1) / 2) + 1;
		msg.bracket_b = msg.bracket_a + rand() % ((msg.digit_num - 1) / 2) + 2;

		for (int i = 0; i < msg.digit_num; i++)
		{
			msg.s1[i] = m[i];  //Êý×Ö 
			msg.s2[i] = n[i];  //·ûºÅ 
		}	
	}
	else if (msg.bracket_num == 0)
	{
		for (int i = 0; i < msg.digit_num; i++)
		{
			msg.s1[i] = m[i];  //Êý×Ö 
			msg.s2[i] = n[i];  //·ûºÅ 
		}
	}
	checkint();
	
}

void  equation::checkint() {  //
	Message msg;
	if (msg.result != (int)msg.result)
	{
		initequation();
	}
	else 
        GenerateEquation();
}

void equation::GenerateEquation() {
	Message msg;
	if (msg.bracket_num == 0)
	{
		for (int i = 0;i < msg.digit_num;i++)
		{
			if (msg.s2[i] == '/')
				cout << msg.s1[i] << "¡Â";
			else
				cout << msg.s1[i] << msg.s2[i];
		}
		//cout<<msg.result;
	}
	else if (msg.bracket_num == 1)
	{
		for (int i = 0;i < msg.digit_num; i++) //²âÊÔËãÊ½
		{
			if (i == msg.bracket_a) cout << "(";
			cout << msg.s1[i];
			if (i == msg.bracket_b - 1) cout << ")";
			if (msg.s2[i] == '/')
				cout << "¡Â";
			else
				cout << msg.s2[i];
		}
		//		cout<<msg.result; 
	}
}


