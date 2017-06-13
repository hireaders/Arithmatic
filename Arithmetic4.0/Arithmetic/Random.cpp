#include "stdafx.h"
#include "Random.h"
#include<string>
#include<assert.h>
using namespace std;

Random::Random(){}
char* Random::getc() { char* c='\0';return c; }
int* Random::geti() { int* i=0;return i; }
Random::~Random(){}

RandomOperation::RandomOperation(int n) {
	const char c[] = "+-*/";
	int k = 0;
	memset(ope, '\0', 50);
	bracket_num = rand() % 2;
	if (bracket_num == 1)
	{
		bracket_a = rand() % ((n - 1) / 2) + 1;
		bracket_b = bracket_a + rand() % ((n - 3) / 2) + 1;
	}
	for (int i = 0;i < n-1;i++)
	{
		if (bracket_num == 1)
		{
			if (i == bracket_a) ope[k++] = '(';
			if (i == bracket_b) ope[k++] = ')';
		}
		ope[k++] = c[rand() % 4];
	}

	if (bracket_num == 1) ope[k++] = '=';
	else ope[k++] = '=';

	ope[k] = '\0';
}
char* RandomOperation::getc() 
{
	return ope;
}
RandomOperation::~RandomOperation() {}


RandomNumber::RandomNumber(int n) {
	memset(num, 0, 30);
	for (int i = 0;i < n;i++){
		num[i] = rand() % 8 + 1;
	}
}
int* RandomNumber::geti()
{
	//cout << num[0] << num[1] << num[2] << endl;
	int* n=&num[0];
	return n;
}
RandomNumber::~RandomNumber() {}


RandomFactory::RandomFactory(){}
RandomFactory::~RandomFactory() {}
Random* RandomFactory::Create(std::string& model,int& n)
{
	if (model == "Number")
	{
		return new RandomNumber(n);
	}
	else if (model == "Operation")
	{
		return new RandomOperation(n);
	}
	else
	{
		assert(false);
	}
	return NULL;
}
	
