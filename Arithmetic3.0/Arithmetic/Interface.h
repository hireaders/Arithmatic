#pragma once
#include<string>
using namespace std;

class Interface       //����
{
public:
	int first();           //��ʼ���棨�������ԣ�
	void mid(int, double );      //ÿһ����Ľ��
	void finally();         //ͳ�ƴ�����

private:
	string *initlanguage();
	void languagelist();

	int equation_num,
		correct,    //һ������
		wrong;      //һ������
	string *l,      //init������ָ��
	       lan[10];
	char name[10],
		 str[100],//���� 
	     strp[100];

};

