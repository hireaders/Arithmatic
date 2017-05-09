#include "stdafx.h"
#include "CalculateResult.h"
#include "equation.h"
#include "Message.h"
#include "Interface.h"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

void CalculateResult::check()  //����� 
{
	Message msg;
	sign = s1[0]; //�����һ������
	msg.result = low(); //���м���
}

void CalculateResult::match(char nowsign) //ƥ����� 
{

	if (bracket_num == 0)
	{
		if (sign == nowsign) //ƥ��ɹ�����ȡ��һ����־
		{
			k++;
			if ((k % 2) == 0) //��һλ������ 
				sign = s1[k / 2];
			else    //��һλ�Ƿ��� 
				sign = s2[(k - 1) / 2];
		}
	}
	else if (bracket_num == 1)
	{
		if (sign == nowsign) //ƥ��ɹ�����ȡ��һ����־
		{
			k++;
			if ((k == 2 * bracket_a) && (flag == 0))
			{
				sign = '(';
				flag = 1;
				k--;
			}
			else if ((k == bracket_b * 2 - 1) && (temp == 0))
			{
				sign = ')';
				temp = 1;
				k--;
			}
			else if ((k == 2 * bracket_a) && (flag == 1))
				sign = s1[k / 2];
			else if ((k == bracket_b * 2 - 1) && (temp == 1))
				sign = s2[(k - 1) / 2];
			else if (((k % 2) == 0) && (k != 2 * bracket_a)) //��һλ������ 
				sign = s1[k / 2];
			else if (((k % 2) != 0) && (k != bracket_b * 2 - 1))    //��һλ�Ƿ��� 
				sign = s2[(k - 1) / 2];
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
		if (bracket_num == 0)
		{
			sign = s2[(k - 1) / 2];//��һλ�Ƿ��� 
		}
		else if (bracket_num == 1)
		{
			if ((k == bracket_b * 2 - 1) && (temp == 0))
			{
				sign = ')';
				temp = 1;
				k--;
			}
			else if (((k % 2) != 0) && (k != bracket_b * 2 - 1))    //��һλ�Ƿ��� 
				sign =s2[(k - 1) / 2];
		}

	}
	return result3;
}

int CalculateResult::checkanswer(int result, string *l)
{
	char ch = getchar();

	if (ch == 'e')//����
	{
		return 3;
	}
	if (answer == result)//����ȷ
	{
		cout << *(l + 1);
		return 1;
	}
	if (answer != result)//�𰸴���
	{
		cout << *(l + 2) << result << endl;
		return 2;
	}
}

