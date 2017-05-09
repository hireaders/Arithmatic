#include<string>
using namespace std;

class equation                //算式及结果显示
{
public:

	void initequation();
	void bracket();           //添加括号
	void checkprintf();          //检查并输出

	int bracket_num,
	    s1[20],
		bracket_a,//括号a位置
		bracket_b;//括号a位置
	char s2[20];
};

