// Arithmetic.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "equation.h"
#include "Fraction.h"
#include "Interface.h"
#include <time.h>
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main()
{
    Interface inter;

	double result;

	int n = inter.first();                  //������
	srand((unsigned(time(NULL))));
	for (int j = 0;j < n;j++)
	{
		int judge = rand() % 5;       //���ַ�������ļ��ʣ�Ŀǰ1/5
		if (judge != -1)
		{
			string st;
			equation equ;
			st=equ.initequation();       //��ʼ��������ʽ
			cout << st;
			result=equ.getresult();      //���㲢���ش�
		}
		else
		{
			Fraction fra;
			fra.initFraction();       //��ʼ��������ʽ
			result=fra.result();      //���㲢���ش�
		}
		int answer;
		cin >>answer;
		inter.mid(answer,result);     //��ǰ�𰸽�����
		cout << endl;
	}

	inter.finally();
	return 0;

}