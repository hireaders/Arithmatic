#pragma once
class equation                //��ʽ�������ʾ
{
public:
	equation();
	void initequation();
	void bracket();           //�������
	void checkint();          //�����Ƿ�Ϊ����
	void GenerateEquation();  //���
private:
	int m[20];    //��ʽ����  
	char n[20];   //��ʽ����

};

