// Arithmetic.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "equation.h"
#include "Fraction.h"
#include "CalculateResult.h"
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
	CalculateResult cal;
	int result;
	
	inter.first();
	srand((unsigned(time(NULL))));
	for (int j = 0;j < msg.equation_num;j++)
	{
		msg.clean();
		int judge = rand() % 5;      //���ַ�������ļ��ʣ�Ŀǰ1/5
		if (judge != 0)
		{
			equ.initequation();      //��ʼ��������ʽ
			result=cal.check();      //���㲢���ش�
		}
		else
		{
			fra.initFraction();     //��ʼ��������ʽ
			result=fra.fraction();  //���㲢���ش�
		}

		int answer;
		cin >>answer;

		int n=cal.checkanswer(result,answer);   //����
		inter.mid(result,n);                 //�������
		cout << endl;
	}

	inter.finally();
	return 0;

}
