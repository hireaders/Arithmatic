#include<string>
using namespace std;

class equation                //��ʽ�������ʾ
{
public:

	void initequation();
	void bracket();           //�������
	void checkprintf();          //��鲢���

	int bracket_num,
	    s1[20],
		bracket_a,//����aλ��
		bracket_b;//����aλ��
	char s2[20];
};

