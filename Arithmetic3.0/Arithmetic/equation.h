#pragma once
class equation                //��ʽ�������ʾ
{
public:
	void initequation();         //��ʼ��ʽ
	double result();             //����� 
	
private:
	void clean();
	void printf();            //�����ʽ
	double mid();
	double high();
	double low();

	int digit_num,
		bracket_num,
		k1 = 1,         //Ŀǰλ����������λ��
		k2 = 0,         //Ŀǰλ�ڷ�������λ��
		flag = 0,      //�Ƿ��ѳ�����
		bracket_a,     //����aλ��
	    bracket_b,     //����bλ��
	    m[30];         //��ʽ����

	double result_0;      //���
	char sign,
	     n[30];        //��ʽ����

};

