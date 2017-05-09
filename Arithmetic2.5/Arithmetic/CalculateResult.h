#pragma once
class CalculateResult   //算式运算
{
public:
	int check();  //开始计算
	void match(char);
	int checkanswer(int,int); //检验答案
	double mid();
	double high();
	double low();
private:
	int answer,
		k = 0,      //目前位于算式位置
		temp = 0,   
		flag = 0;   //见下方解释
	char sign,
		nowsign;
};
/*
比如1*（2+3）
当k=3的时候 需要匹配括号或者2
先输出括号然后把flag标记一下为1说明括号已输出
然后下一次k=3的时候就匹配2了
*/
