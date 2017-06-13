#pragma once
#include<stack>
using namespace std;
class equation                //算式及结果显示
{
public:
	string initequation();         //初始算式
	double result();             //运算答案 
	double getresult();
private:
	void clean();
	void toget();     //汇集算式，数字用|代替
	void readdata();
	bool readop();
	void calremain();
	double cal(double lh, char op, double rh);
	bool prior(char o1, char o2);
	void print();    //输出算式
//	double mid();
//  double high();
//	double low();

	stack<char> ops;
	stack<double> ds;
	double v, lh, rh;       // 计算结果和临时操作数变量
	char op;                //运算符

	int digit_num,
		len = 0,           //汇集后算式长度
		k1 = 1,         //目前位于数字数组位置
		k2 = 0,         //目前位于符号数组位置
		flag = 0,      //是否已出括号
	    m[30],         //算式数字
	    cnt1,           //计算符号位置
	    cnt2;           //计算数字位置

	double result_0;      //结果
	char n[30],       //算式符号
		eq[50];
	   
};

