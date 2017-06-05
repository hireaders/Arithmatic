// Arithmetic.cpp : 定义控制台应用程序的入口点。
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

	int n = inter.first();                  //多少题
	srand((unsigned(time(NULL))));
	for (int j = 0;j < n;j++)
	{
		int judge = rand() % 5;       //出现分数运算的几率，目前1/5
		if (judge != 0)
		{
			equation equ;
			equ.initequation();       //初始化整数算式
			result=equ.getresult();      //计算并返回答案
		}
		else
		{
			Fraction fra;
			fra.initFraction();       //初始化分数算式
			result=fra.result();      //计算并返回答案
		}
		int answer;
		cin >>answer;
		inter.mid(answer,result);     //当前答案结果输出
		cout << endl;
	}

	inter.finally();
	return 0;

}
