#pragma once
class equation                //算式及结果显示
{
public:
	void initequation();         //初始算式
	double result();             //运算答案 
	
private:
	void clean();
	void printf();            //输出算式
	double mid();
	double high();
	double low();

	int digit_num,
		bracket_num,
		k1 = 1,         //目前位于数字数组位置
		k2 = 0,         //目前位于符号数组位置
		flag = 0,      //是否已出括号
		bracket_a,     //括号a位置
	    bracket_b,     //括号b位置
	    m[30];         //算式数字

	double result_0;      //结果
	char sign,
	     n[30];        //算式符号

};

