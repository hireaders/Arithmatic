#pragma once
#include<string>
using namespace std;
class Language           //������Դ�ļ���ȡ
{
public:
	Language();
	string *initlanguage();
	string *l;
	string lan[10];
	void languagelist();

	char name[10],
		str[100];//���� 
};

