#include "stdafx.h"
#include "Language.h"
#include "Message.h"

//#include<AFX.h>
//#include<WinUser.h>
#include<iostream>
#include<cstring>
#include<fstream>
#include<string>


//using namespace System;
//using namespace System::Resources;
//using namespace System::Collections;
//using namespace System::Globalization;
//using namespace System::Reflection;
using namespace std;

Language::Language()
{}
//�ļ�����
void Language::initlanguage()
{
	Message msg;
	ifstream in;
	char name[100] = { 0 }; //�ļ�·�� 
	char lan[20] = { 0 };
	int i = 0;
	cin.get(lan, 20);//��ȡ������ַ� 
	strcat_s(name, "language\\");//ƴ�� 
	strcat_s(name, lan);
	strcat_s(name, ".txt");
	//cout<<name<<endl;
	in.open(name, ios::in);            //��Ϊname��txt 
	while (in.getline(str, sizeof(str), '\n'))
	{
		memcpy(msg.s[i], str, sizeof(str));//һ��һ�д��� 
		i++;
	}
	/*for (i = 0;i < 5;i++)
	{
	cout << msg.s[i] << endl;
	}*/
}
void Language::languagelist()
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


/*
//δ���
void Language::langua()
{
String^ str;
Assembly^ CurrentAssem = Assembly::GetExecutingAssembly();
ResourceManager RcLang("LangList", CurrentAssem);
CultureInfo^ DefaultLoca = gcnew CultureInfo("", false);
ResourceSet^ RcLangInfo = RcLang.GetResourceSet(DefaultLoca, true, true);

IDictionaryEnumerator^ idlanginfo = RcLangInfo->GetEnumerator();

cout << "Please input the language name:" << endl;
cin.getline(str, 10);
ResourceManager rc("Resource", CurrentAssem);
CultureInfo^ loca = gcnew CultureInfo(RcLang.GetString(str), false);

Console::Write("{0}", rc.GetString("InputNumberOfProblems", loca));
}
*/