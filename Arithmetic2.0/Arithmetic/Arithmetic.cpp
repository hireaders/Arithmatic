// Arithmetic.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "equation.h"
#include "Fraction.h"
#include "CalculateResult.h"
#include "Message.h"
#include "Scan.h"
#include "Interface.h"

#include <time.h>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
	Fraction fra;//������ʽ����
	equation equ;//������ʽ����
	Message msg;
	Interface inter;//����
	CalculateResult cal();//����
	Scan sc;

	int n,              //��Ŀ����
		result,         //������
	    y,              //����ȷ��ͳ��
	    correct=0,        //ͳ�ƶ�����
	    wrong=0;          //ͳ�ƴ�����
	string *l;            //��������ָ��
	
	inter.first();
	l=sc.scantest_lan();
	n=sc.scantest_num(l);

	srand((unsigned(time(NULL))));

	for (int j = 0;j < n;j++)
	{
		msg.clean();
		int judge = rand() % 5;//���ַ�������ļ��ʣ�Ŀǰ1/5
		if (judge != 0)
		{
			equ.initequation();//��ʼ��������ʽ
			cal().check();    //�����
		}
		else
		{
			fra.initFraction();//��ʼ��������ʽ
		}
		result = sc.scantest_answer();
		y = cal().checkanswer(result, l);//���𰸲������ǰ���
		if (y == 1) correct += 1;
		if (y == 2) wrong += 1;
		if (y == 3) break;
		cout << endl;
	}
	
	inter.finally(l,correct,wrong);
	return 0;

}
