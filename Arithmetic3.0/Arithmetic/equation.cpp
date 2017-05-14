#include "stdafx.h"
#include "equation.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

const char c[] = "+-*/";
void equation::clean()
{
	k1 = 1;
	k2 = 0;
	flag = 0;
}

void equation::initequation()
{
	result_0 = 9.9;
	while (result_0 != (int)result_0)
	{
		int k = 0;
		memset(m, 0, 30);
		memset(n, '\0', 30);
		digit_num = rand() % 3 + 5;              //5-7位运算
		bracket_num = rand() % 2;
		if (bracket_num == 1)
		{
			bracket_a = rand() % ((digit_num - 1) / 2) + 1;
			bracket_b = bracket_a + rand() % ((digit_num - 3) / 2) + 1;
		}
		for (int i = 0;i < digit_num;i++)
		{
			if (bracket_num == 1)
			{
				if (i == bracket_a)
				{
					n[k] = '(';
					k++;
				}
				if (i == bracket_b)
				{
					n[k] = ')';
					k++;
				}
			}
			
			m[i] = rand() % 8 + 1;
			n[k] = c[rand() % 4];
			k++;
		}
		if (bracket_num == 1)
		{
            n[digit_num + 1] = '=';
		}
		else
		{
			n[digit_num - 1] = '=';
		}
        result_0 = result();
	}
	printf();
}

void equation::printf() {
	int k = 0;
	for (int i = 0;i < digit_num;i++)
	{
		if (n[k] == '/')
			cout << m[i] << "÷";
		else if (n[k] == '(')
		{
			if (n[k + 1] == '/')
				cout << n[k] << m[i] << "÷";
			else
				cout << n[k] << m[i] << n[k + 1];
			k++;
		}
		else if (n[k] == ')')
		{
			if (n[k + 1] == '/')
				cout << m[i] << n[k] << "÷";
			else
				cout << m[i] << n[k] << n[k + 1];
			k++;
		}
		else
			cout << m[i] << n[k];
		k++;
	}
}

double equation::result()  //运算答案 
{
	clean();
	sign = m[0]; //载入第一个符号
	result_0 = low(); //进行计算
	return result_0;
}

double equation::low() //加减运算 
{
	double result1 = mid(); //计算比加减运算优先级别高的部分
	if (flag == 2) return result1;
	while ((sign == '+') || (sign == '-'))
	{
		if (sign == '+')
		{
			sign = m[k1];
			k1++;
			result1 += mid();
		}
		else
		{
			sign = m[k1];
			k1++;   
			result1 -= mid();
		}
		if (k1 == digit_num || (sign == ')'&&flag == 0))
		{
			sign = n[k2];
			flag = 1;
			break;
		}
	}
	return result1;
}

double equation::mid() //乘除运算 
{
	double result2 = high();
	while ((sign == '*') || (sign == '/'))
	{
		if (sign == '*')
		{
			sign = m[k1];
			k1++;    
			result2 *= high();
		}
		else
		{
			sign = m[k1];               //sign为数字
			k1++;   
			result2 /= high();
		}
		if (k1 == digit_num || (sign == ')'&&flag == 0))
		{
			sign = n[k2];
			flag = 2;
			break;
		}
	}
	return result2;
}


double equation::high() //括号运算及数字 
{

	double result3 = 0;
	if (n[k2] == '(')          //进入带有括号
	{
		k2++;
		result3 = low();        //递归计算表达式
		k2++;
	}
	if (sign >= 0 && sign <= 9) //实际的数字
	{
		result3 = sign;
		sign = n[k2];
		k2++;
	}
	return result3;
}