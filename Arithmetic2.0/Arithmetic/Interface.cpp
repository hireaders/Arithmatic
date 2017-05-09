#include "stdafx.h"
#include "Interface.h"
#include "Message.h"
#include "Language.h"
#include<iostream>
#include<string>
using namespace std;

void Interface::first()
{
	Language langu;
	cout << "***********************************************" << endl;
	cout << "Please choose the language:" << endl;
	langu.languagelist();
}
void Interface::finally(string *l,int c,int w)
{
	cout << endl;
	cout << "***********************************************" << endl;
	cout << *(l+3) << c << *(l+5) << *(l+4) << w << *(l+5) << endl;
	cout << "***********************************************" << endl;
}