#pragma once
	class Operate   //��ʽ����
{
public:
	Operate();
	void check();
	void match(char nowsign);
	double mid();
	double high();
	double low();
private:
	int k = 0,      //Ŀǰλ����ʽλ��
		temp = 0,   //����ʲô��
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
