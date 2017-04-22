#include "stdafx.h"
#include "CalculateResult.h"
#include "equation.h"
#include "Message.h"
#include "Interface.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

CalculateResult::CalculateResult()
{}

void CalculateResult::check()  //运算答案 
{
	Message msg;
	sign = msg.s1[0]; //载入第一个符号
	msg.result = low(); //进行计算
}

void CalculateResult::match(char nowsign) //匹配符号 
{
	Message msg;
	if (msg.bracket_num == 0)
	{
		if (sign == nowsign) //匹配成功，获取下一个标志
		{
			k++;
			if ((k % 2) == 0) //下一位是数字 
				sign = msg.s1[k / 2];
			else    //下一位是符号 
				sign = msg.s2[(k - 1) / 2];
		}
	}
	else if (msg.bracket_num == 1)
	{
		if (sign == nowsign) //匹配成功，获取下一个标志
		{
			k++;
			if ((k == 2 * msg.bracket_a) && (flag == 0))
			{
				sign = '(';
				flag = 1;
				k--;
			}
			else if ((k == msg.bracket_b * 2 - 1) && (temp == 0))
			{
				sign = ')';
				temp = 1;
				k--;
			}
			else if ((k == 2 * msg.bracket_a) && (flag == 1))
				sign = msg.s1[k / 2];
			else if ((k == msg.bracket_b * 2 - 1) && (temp == 1))
				sign = msg.s2[(k - 1) / 2];
			else if (((k % 2) == 0) && (k != 2 * msg.bracket_a)) //下一位是数字 
				sign = msg.s1[k / 2];
			else if (((k % 2) != 0) && (k != msg.bracket_b * 2 - 1))    //下一位是符号 
				sign = msg.s2[(k - 1) / 2];
		}
	}

}

double CalculateResult::low() //加减运算 
{
	Message msg;
	double result1 = mid(); //计算比加减运算优先级别高的部分
	while ((sign == '+') || (sign == '-'))
		if (sign == '+')
		{
			match('+');     //进行加法运算
			result1 += mid();
			if (k == 2 * msg.digit_num - 1)
				break;
		}
		else if (sign == '-')
		{
			match('-');    //进行减法运算
			result1 -= mid();
			if (k == 2 * msg.digit_num - 1)
				break;
		}
	return result1;
}

double CalculateResult::mid() //乘除运算 
{
	Message msg;
	double result2 = high();
	while ((sign == '*') || (sign == '/'))
		if (sign == '*')
		{
			match('*');     //进行乘法运算
			result2 *= high();
			if (k == 2 * msg.digit_num - 1)
				break;
		}
		else if (sign == '/')
		{
			match('/');    //进行除法运算
			result2 /= high();
			if (k == 2 * msg.digit_num - 1)
				break;
		}
	return result2;
}


double CalculateResult::high() //括号运算及数字 
{
	Message msg;
	double result3 = 0;
	if (sign == '(') //带有括号的运算
	{
		match('(');
		result3 = low(); //递归计算表达式
		match(')');
	}
	else if (sign >= 0 && sign <= 9) //实际的数字
	{
		result3 = sign;
		k++;
		if (msg.bracket_num == 0)
		{
			sign = msg.s2[(k - 1) / 2];//下一位是符号 
		}
		else if (msg.bracket_num == 1)
		{
			if ((k == msg.bracket_b * 2 - 1) && (temp == 0))
			{
				sign = ')';
				temp = 1;
				k--;
			}
			else if (((k % 2) != 0) && (k != msg.bracket_b * 2 - 1))    //下一位是符号 
				sign = msg.s2[(k - 1) / 2];
		}

	}
	return result3;
}


void CalculateResult::checkanswer(int result)
{
	Message msg;
	Interface inter;

	cin >> answer;
	char ch = getchar();

	if (answer == result)
	{
		cout << msg.s[1];
		msg.correct += 1;
	}
	else if ((answer != result) && (ch != 'e'))
	{
		cout << msg.s[2] << result;
		msg.wrong += 1;
	}
	if (ch == 'e')
	{
		inter.finally();
	}
}

