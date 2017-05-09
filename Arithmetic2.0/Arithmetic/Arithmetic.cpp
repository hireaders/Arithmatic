// Arithmetic.cpp : 定义控制台应用程序的入口点。
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
	Fraction fra;//分数算式生生
	equation equ;//整数算式生成
	Message msg;
	Interface inter;//界面
	CalculateResult cal();//计算
	Scan sc;

	int n,              //题目数量
		result,         //输入结果
	    y,              //答案正确数统计
	    correct=0,        //统计对题数
	    wrong=0;          //统计错题数
	string *l;            //语言数组指针
	
	inter.first();
	l=sc.scantest_lan();
	n=sc.scantest_num(l);

	srand((unsigned(time(NULL))));

	for (int j = 0;j < n;j++)
	{
		msg.clean();
		int judge = rand() % 5;//出现分数运算的几率，目前1/5
		if (judge != 0)
		{
			equ.initequation();//初始化整数算式
			cal().check();    //计算答案
		}
		else
		{
			fra.initFraction();//初始化分数算式
		}
		result = sc.scantest_answer();
		y = cal().checkanswer(result, l);//检查答案并输出当前结果
		if (y == 1) correct += 1;
		if (y == 2) wrong += 1;
		if (y == 3) break;
		cout << endl;
	}
	
	inter.finally(l,correct,wrong);
	return 0;

}
