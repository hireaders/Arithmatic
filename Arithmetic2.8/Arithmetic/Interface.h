#pragma once
#include<string>
using namespace std;

class Interface       //界面
{
public:
	int first();           //开始界面（包括语言）
	void mid(int, double );      //每一道题的结果
	void finally();         //统计错题数

private:
	string *initlanguage();
	void languagelist();

	int equation_num,
		correct,    //一共对了
		wrong;      //一共错了
	string *l,      //init后语言指针
	       lan[10];
	char name[10],
		 str[100],//内容 
	     strp[100];

};

