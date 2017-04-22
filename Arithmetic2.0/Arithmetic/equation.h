#pragma once
class equation                //算式及结果显示
{
public:
	equation();
	void initequation();
	void bracket();           //添加括号
	void checkint();          //检验是否为整数
	void GenerateEquation();  //输出
private:
	int m[20];    //算式数字  
	char n[20];   //算式符号

};

