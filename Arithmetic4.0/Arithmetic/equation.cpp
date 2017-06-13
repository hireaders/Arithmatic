#include "stdafx.h"
#include "equation.h"
#include "Random.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

void equation::clean()
{
	k1 = 1;
	k2 = 0;
	flag = 0;
	cnt1 = 0;
	cnt2 = 0;
}

string equation::initequation()
{
	result_0 = 9.9;
	while (result_0 != (int)result_0)
	{
		int* in;
		char * ch;
		string modeName;
		Random * random = NULL;
		digit_num = rand() % 3 + 5;              //5-7λ����

		memset(m, 0, 30);
		memset(n, '\0', 50);
		
		modeName = "Number";
		random = RandomFactory::Create(modeName, digit_num);
		in = random->geti();
		for (int i = 0;i < 30;i++) m[i] = in[i];

		modeName = "Operation";
		random = RandomFactory::Create(modeName, digit_num);
		ch = random->getc();
		for (int i = 0;i < 50;i++) n[i] = ch[i];

		delete random;
		random = NULL;

		try
		{
			clean();
			toget();
			result_0 = result(); //���м���
		}
		catch (const string &e)
		{
		}
	}
	print();
	cout << endl;
	int u = 0;
	int g = 0;
	string  str;
	for (int i = 0;i<len;i++)
	{
		if (eq[i] == '|')
		{
			str.push_back(m[u]+48);
			cout << str[g++]<<endl;
			u++;
		}
		else
		{
			str.push_back(eq[i]);
			cout << str[g++] << endl;
		}
			
		if (eq[i] == '=') break;
	}
	return str;
}
/*
void equation::initequation()
{
	result_0 = 9.9;
	while (result_0 != (int)result_0)
	{
		int k = 0;
		memset(m, 0, 30);
		memset(n, '\0', 50);
		digit_num = rand() % 3 + 5;              //5-7λ����
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
			n[digit_num + 2] = '\0';
		}
		else
		{
			n[digit_num - 1] = '=';
			n[digit_num] = '\0';
		}
		try
		{
			clean();
			toget();
			result_0 = result(); //���м���
		}
		catch (const string &e)
		{
		}
	}
	print();
}
*/
void equation::toget() {
	strcpy_s(eq, n);
	int y = 0;
	while (m[y] != 0) y++;
	len = strlen(eq) + y;

	for (int i = 0;i<len;i++)
	{
		if (i == 0 && eq[i] != '(')
		{
			for (int j = len - 1;j >= 0;j--)
			{
				eq[j + 1] = eq[j];
			}
			eq[i] = '|';
			len++;
		}
		if ((eq[i] == '(' || eq[i] == '+') || eq[i] == '-' || eq[i] == '*' || eq[i] == '/')
		{
			if (eq[i + 1] != '(')
			{
				for (int j = len - 1;j>i;j--)
				{
					eq[j + 1] = eq[j];
				}
				eq[i + 1] = '|';
				len++;
			}
		}
	}
}
void equation::print()
{
	int u = 0;
	for (int i = 0;i<len;i++)
	{
		if (eq[i] == '|')
		{
			cout << m[u];
			u++;
		}
		else
			cout << eq[i];
		if (eq[i] == '=') break;
	}
	
}
/*
double equation::result()  //����� 
{
	clean();
	//sign = m[0]; //�����һ������
	try
	{
		//print();
		result_0 = calinput(); //���м���
		cout << result_0 << endl;
	}
		catch (const string &e )
	{
	}
	return result_0;
}
*/
double equation::getresult()
{
	return result_0;
}
double equation::result()//��ȡ��������ʽֱ������Ϊֹ
{
	do
	{
		readdata();
	} while (readop());
	calremain(); //����ջ��ʣ��������
	return v;
}

void equation::readdata() //�ڸó������ݵ�ʱ����ܳ���'(' 
{
	// ��1+((2*3)) �����ſ����Ƕ�� 
	while (1)  //��ȡ����ʧ�ܣ���ʱ��ȡӦ����'('����vΪdouble���� 
	{
		op = eq[cnt1];
		if ( op == '|')
		{
			cnt1++;
			v = m[cnt2++];
			break;
		}	
		ops.push(op); //��������ջ 
		cnt1++;
	}
	ds.push(v);
}

bool equation::readop() //��ȡ����������ܳ��������Ż��߻��з�(���ʽ������ 
{
	//��(2*(3+4/(4-5)))�������ſ����Ƕ�� 
	while (1)
	{
		op = eq[cnt1++];
		if (op != ')') break;
		while (ops.top() != '(')
		{
			rh = ds.top(); //ȡ������� 
			ds.pop();
			lh = ds.top();//ȡ�Ҳ����� 
			ds.pop();
			ds.push(cal(lh, ops.top(), rh)); //���㲢��ջ
			ops.pop(); //ȡ������� 
		}
		ops.pop(); //����'(' 
	}
	if (op == '=')
	{
		return false;
	}

	if (strchr("+-*/", op) == NULL) //��Ч����� 
	{
		throw string("��Ч�����") + op;
	}
	while (!ops.empty() && ops.top() != '(' && !prior(op, ops.top()))
	{
		rh = ds.top(); ds.pop();
		lh = ds.top(); ds.pop();
		ds.push(cal(lh, ops.top(), rh)); //���㲢��ջ
		ops.pop(); //ȡ�������  
	}

	ops.push(op);
	return true;
}

void equation::calremain()
{
	while (!ops.empty())
	{
		rh = ds.top(); ds.pop();
		lh = ds.top(); ds.pop();
		ds.push(cal(lh, ops.top(), rh)); //���㲢��ջ
		ops.pop(); //ȡ������� 
	}
	if (ds.size() != 1)
	{
		throw string("��Ч�ı��ʽ");
	}
	v = ds.top();
	ds.pop();
	return;
}
double equation::cal(double lh, char op, double rh)
{
	return op == '+' ? lh + rh : op == '-' ? lh - rh : op == '*' ? lh*rh : lh / rh;
}

bool equation::prior(char o1, char o2)//��o1��o2���ȼ��߷���true,���򷵻�false 
{
	return o1 != '+' && o1 != '-' && o2 != '*' && o2 != '/';
}










/*
double equation::low() //�Ӽ����� 
{
	double result1 = mid(); //����ȼӼ��������ȼ���ߵĲ���
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

double equation::mid() //�˳����� 
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
			sign = m[k1];               //signΪ����
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


double equation::high() //�������㼰���� 
{

	double result3 = 0;
	if (n[k2] == '(')          //�����������
	{
		k2++;
		result3 = low();        //�ݹ������ʽ
		k2++;
	}
	if (sign >= 0 && sign <= 9) //ʵ�ʵ�����
	{
		result3 = sign;
		sign = n[k2];
		k2++;
	}
	return result3;
}
*/