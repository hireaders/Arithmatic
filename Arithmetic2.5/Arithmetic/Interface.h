#pragma once
#include<string>
using namespace std;

class Interface       //����
{
public:
    string *initlanguage();
    void languagelist();

	void first();           //��ʼ���棨�������ԣ�
	void mid(int,int);      //ÿһ����Ľ��
	void finally();         //ͳ�ƴ�����

private:
	string *l,      //init������ָ��
	       lan[10];
	char name[10],
		 str[100],//���� 
	     strp[100];
};

