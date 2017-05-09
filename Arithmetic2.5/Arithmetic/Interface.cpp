#include "stdafx.h"
#include "Interface.h"
#include "Message.h"
#include "Language.h"
#include<iostream>
#include<cstring>
#include<fstream>
#include<string>
using namespace std;

void Interface::first()
{
	Message msg;
	cout << "***********************************************" << endl;
	cout << "Please choose the language:" << endl;

	languagelist();
	l=initlanguage();
	cout << *l;
	cin >> msg.equation_num;
	cout << "***********************************************" << endl;
}
void Interface::mid(int result = 0,int k)
{
	if (k == 1)
	{
		cout << *(l + 1);
	}
	if (k == 2)
	{
		cout << *(l + 2)<<result;
	}
	if (k == 3)
	{
		finally();
	}
}
void Interface::finally()
{
	Message msg;
	cout << "***********************************************" << endl;
	cout << *(l+3) << msg.correct << *(l+5) << *(l + 4) << msg.wrong << *(l + 5) << endl;
	cout << "***********************************************" << endl;
}

string *Interface::initlanguage()
{
	Message msg;
	ifstream in;

	char name[100] = { 0 }; //合并后文件路径 
	char lan_name[20] = { 0 };
	string *p;
	int i = 0;
	int k = 0;

	cin.get(lan_name, 20);//获取输入的字符 
	strcat_s(name, "language\\");//拼接 
	strcat_s(name, lan_name);
	strcat_s(name, ".txt");
	//cout<<name<<endl;
	in.open(name, ios::in);            //打开为name的txt 
	while (in.getline(strp, sizeof(strp), '\n'))
	{
		lan[k] = strp;
		k++;
	}
	p = lan;

	while (in.getline(str, sizeof(str), '\n'))
	{
		memcpy(msg.s[i], str, sizeof(str));//一行一行存入 
		i++;
	}
	return p;
}

void Interface::languagelist()
{
	fstream file;
	file.open("language\\languagelist.txt", ios::in);

	int num = 1;
	char language[20];
	while (file.getline(language, 20))
	{
		cout << num << ". " << language << endl;
		num++;
	}
	file.close();
	cout << "Please input language name: ";
}