#pragma once
class equation                //��ʽ�������ʾ
{
public:
	equation();
	void initequation();
	void bracket();           //�������
	void checkanswer(int result);
private:
	int answer,   //����Ĵ�
		m[20];    //��ʽ����  
	char n[20];   //��ʽ����

};

