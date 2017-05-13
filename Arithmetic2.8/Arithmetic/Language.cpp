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
//文件方法
string *Language::initlanguage()
{
	Message msg;
	ifstream in;

	char name[100] = { 0 }; //文件路径 
	char lan_name[20] = { 0 };

	int i = 0;
	int k = 0;

	cin.get(lan_name, 20);//获取输入的字符 
	strcat_s(name, "language\\");//拼接 
	strcat_s(name, lan_name);
	strcat_s(name, ".txt");
	//cout<<name<<endl;
	in.open(name, ios::in);            //打开为name的txt 
	while (in.getline(str, sizeof(str), '\n'))
	{
		lan[k] = str;
		k++;
	}
	l = lan;

	while (in.getline(str, sizeof(str), '\n'))
	{
		memcpy(msg.s[i], str, sizeof(str));//一行一行存入 
		i++;
	}

	return l;
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
//未完成
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