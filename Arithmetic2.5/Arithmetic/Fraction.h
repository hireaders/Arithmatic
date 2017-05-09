#pragma once
class Fraction
{
public:
	void initFraction();//随机生成
	int  fraction();    //显示算式
private:
	int    n[4],     //算式数字 
		   demo,     //分子
		   result;   //答案

	double nume;     //分母 
	char s[2];     //算式符号 

};

