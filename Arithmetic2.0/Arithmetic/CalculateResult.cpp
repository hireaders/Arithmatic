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

void CalculateResult::check()  //����� 
{
	Message msg;
	sign = msg.s1[0]; //�����һ������
	msg.result = low(); //���м���
}

void CalculateResult::match(char nowsign) //ƥ����� 
{
	Message msg;
	if (msg.bracket_num == 0)
	{
		if (sign == nowsign) //ƥ��ɹ�����ȡ��һ����־
		{
			k++;
			if ((k % 2) == 0) //��һλ������ 
				sign = msg.s1[k / 2];
			else    //��һλ�Ƿ��� 
				sign = msg.s2[(k - 1) / 2];
		}
	}
	else if (msg.bracket_num == 1)
	{
		if (sign == nowsign) //ƥ��ɹ�����ȡ��һ����־
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
			else if (((k % 2) == 0) && (k != 2 * msg.bracket_a)) //��һλ������ 
				sign = msg.s1[k / 2];
			else if (((k % 2) != 0) && (k != msg.bracket_b * 2 - 1))    //��һλ�Ƿ��� 
				sign = msg.s2[(k - 1) / 2];
		}
	}

}

double CalculateResult::low() //�Ӽ����� 
{
	Message msg;
	double result1 = mid(); //����ȼӼ��������ȼ���ߵĲ���
	while ((sign == '+') || (sign == '-'))
		if (sign == '+')
		{
			match('+');     //���мӷ�����
			result1 += mid();
			if (k == 2 * msg.digit_num - 1)
				break;
		}
		else if (sign == '-')
		{
			match('-');    //���м�������
			result1 -= mid();
			if (k == 2 * msg.digit_num - 1)
				break;
		}
	return result1;
}

double CalculateResult::mid() //�˳����� 
{
	Message msg;
	double result2 = high();
	while ((sign == '*') || (sign == '/'))
		if (sign == '*')
		{
			match('*');     //���г˷�����
			result2 *= high();
			if (k == 2 * msg.digit_num - 1)
				break;
		}
		else if (sign == '/')
		{
			match('/');    //���г�������
			result2 /= high();
			if (k == 2 * msg.digit_num - 1)
				break;
		}
	return result2;
}


double CalculateResult::high() //�������㼰���� 
{
	Message msg;
	double result3 = 0;
	if (sign == '(') //�������ŵ�����
	{
		match('(');
		result3 = low(); //�ݹ������ʽ
		match(')');
	}
	else if (sign >= 0 && sign <= 9) //ʵ�ʵ�����
	{
		result3 = sign;
		k++;
		if (msg.bracket_num == 0)
		{
			sign = msg.s2[(k - 1) / 2];//��һλ�Ƿ��� 
		}
		else if (msg.bracket_num == 1)
		{
			if ((k == msg.bracket_b * 2 - 1) && (temp == 0))
			{
				sign = ')';
				temp = 1;
				k--;
			}
			else if (((k % 2) != 0) && (k != msg.bracket_b * 2 - 1))    //��һλ�Ƿ��� 
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

