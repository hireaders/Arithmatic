#pragma once
#include<string>
using namespace std;
class Language           //语言资源文件读取
{
public:
	Language();
	string *initlanguage();
	string *l;
	string lan[10];
	void languagelist();

	char name[10],
		str[100];//内容 
};

