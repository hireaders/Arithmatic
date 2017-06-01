#include "stdafx.h"
#include "Interface.h"

#include<iostream>
#include<cstring>
#include<fstream>
#include<string>
using namespace std;

int Interface::first()
{
	cout << "***********************************************" << endl;
	cout << "Please choose the language:" << endl;

	languagelist();
	l=initlanguage();
	cout << *l;
	cin >> equation_num;
	cout << "***********************************************" << endl;
	return equation_num;
}
void Interface::mid(int answer,double result)
{
	char ch = getchar();
	if (answer == result)
	{
		correct += 1;
		cout << *(l + 1);
	}
	else if ((answer != result) && (ch != 'e'))
	{
		wrong += 1;
		cout << *(l + 2) << result;
	}
	if (ch == 'e')
	{
		finally();
	}
}
void Interface::finally()
{
	cout << "***********************************************" << endl;
	cout << *(l+3) << correct << *(l+5) << *(l + 4) << wrong << *(l + 5) << endl;
	cout << "***********************************************" << endl;
}

string *Interface::initlanguage()
{
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