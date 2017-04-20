#include "stdafx.h"
#include "Operate.h"
#include "equation.h"
#include "Message.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

Operate::Operate()
{}

void Operate::match(char nowsign) //ƥ����� 
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

double Operate::low() //�Ӽ����� 
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

double Operate::mid() //�˳����� 
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


double Operate::high() //�������㼰���� 
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

void Operate::check()  //����� 
{
	Message msg;
	equation equ;
	sign = msg.s1[0]; //�����һ������
	msg.result = low(); //���м���

	if (msg.result == (int)msg.result)
	{
		if (msg.bracket_num == 0)
		{
			for (int i = 0;i < msg.digit_num;i++)
			{
				if (msg.s2[i] == '/')
					cout << msg.s1[i] << "��";
				else
					cout << msg.s1[i] << msg.s2[i];
			}
			//cout<<msg.result;
		}
		else if (msg.bracket_num == 1)
		{
			for (int i = 0;i < msg.digit_num; i++) //������ʽ
			{
				if (i == msg.bracket_a) cout << "(";
				cout << msg.s1[i];
				if (i == msg.bracket_b - 1) cout << ")";
				if (msg.s2[i] == '/')
					cout << "��";
				else
					cout << msg.s2[i];
			}
			//		cout<<msg.result; 
		}
		equ.checkanswer(msg.result);
	}
	else if (msg.result != (int)msg.result)
	{
		k = 0;
		equ.initequation();
	}
}



