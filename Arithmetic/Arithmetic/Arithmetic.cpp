// Arithmetic.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "equation.h"
#include "Fraction.h"
#include "Operate.h"
#include "Message.h"
#include "Interface.h"
#include <time.h>
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main()
{
	Fraction fra;
	equation equ;
	Message msg;
	Interface inter;

	inter.first();

	srand((unsigned(time(NULL))));
	for (int j = 0;j < msg.equation_num;j++)
	{
		msg.clean();
		int judge = rand() % 5;//���ַ�������ļ��ʣ�Ŀǰ1/5
		if (judge != 0)
		{
			equ.initequation();
		}
		else
		{
			fra.initFraction();
		}
		cout << endl;
	}

	inter.finally();
	return 0;

}
