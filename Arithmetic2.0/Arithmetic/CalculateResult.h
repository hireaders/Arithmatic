#include <string>
using namespace std;

class CalculateResult   //��ʽ����
{
public:
	void check();
	void match(char nowsign);
	int checkanswer(int result, string *l); //�����
	double mid();
	double high();
	double low();
private:
	int answer,
		k = 0,      //Ŀǰλ����ʽλ��
		temp = 0,
		flag = 0,   //���·�����
		bracket_num,
		bracket_a,
		bracket_b,
		s1[20];
	char sign,
		nowsign,
		s2[20];
};
/*
����1*��2+3��
��k=3��ʱ�� ��Ҫƥ�����Ż���2
���������Ȼ���flag���һ��Ϊ1˵�����������
Ȼ����һ��k=3��ʱ���ƥ��2��
*/
