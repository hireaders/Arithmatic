#pragma once
	class CalculateResult   //��ʽ����
{
public:
	CalculateResult();
	void check();
	void match(char nowsign);
	void checkanswer(int result); //�����
	double mid();
	double high();
	double low();
private:
	int answer,
		k = 0,      //Ŀǰλ����ʽλ��
		temp = 0,   
		flag = 0;   //���·�����
	char sign,
		nowsign;
};
/*
����1*��2+3��
��k=3��ʱ�� ��Ҫƥ�����Ż���2
���������Ȼ���flag���һ��Ϊ1˵�����������
Ȼ����һ��k=3��ʱ���ƥ��2��
*/
