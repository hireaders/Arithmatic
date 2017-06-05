#pragma once
#include <string>
#include <iostream>
using namespace std;
class Random
{
public:
	Random();
	virtual int* geti();
	virtual char* getc();
	~Random();
};
class RandomOperation:public Random
{
private:
	int bracket_num,
		bracket_a,
		bracket_b;
	char ope[50];
public:
	RandomOperation(int);
	virtual char* getc();
	~RandomOperation();
	
};

class RandomNumber :public Random
{
private:
	int num[30];
public:
	RandomNumber(int);
	virtual int* geti();
	~RandomNumber();
};

class RandomFactory
{
public:
	RandomFactory();
	~RandomFactory();
	static Random* Create(string&,int&);
};