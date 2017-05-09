#include "stdafx.h"
#include "Scan.h"
#include "Language.h"
#include "iostream"
#include <string>
using namespace std;

string* Scan::scantest_lan()
{
	Language lang;
	cout << "Please input language name: ";
	cin.get(lan_name, 20);                  //获取输入的字符
	lan = lang.initlanguage(lan_name);
	return lan;
}
int Scan::scantest_num(string *l)
{
	int num;
	cout << *l;
	cin >> num;
	cout << "***********************************************" << endl;
	return num;
}
int Scan::scantest_answer()
{
	int result;
	cin >> result;
	return result;
}