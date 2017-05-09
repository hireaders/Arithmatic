#include<string>
using namespace std;

class Scan
{
public:
	string* scantest_lan();
	int scantest_num(string *l);
	int scantest_answer();

	string *lan;      //记录语言数组的指针
	char lan_name[20]; //获取输入的语言
};

