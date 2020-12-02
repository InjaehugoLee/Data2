#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "2.h"

// 필요한 파일 인클루드
using namespace std;

int main()
{	
	Stack intstack;
	FILE* fp;
	// 파일을 연다
	errno_t err = fopen_s(&fp, "12.txt", "r");

	if (fp == NULL)
	{
		//열렸네? 파일이 존재합니다.
		cout << "Fail to open\n" << endl;
		return 0;
	}
	char ch;
	while ((ch = fgetc(fp)) != EOF)    //단어장이 끝날때까지.
	{
		if (ch == '{')
		{
			intstack.Push(ch);
		}
		else if (ch == '}')
		{
			if (intstack.Pop() == -1)
			{
				fclose(fp);
				return 1;
			}
		}
	}
	fclose(fp);    

	if (intstack.Number() == 0)
		cout << "OK" << endl;
	else
		cout << "fail" << endl;

	return 0;
}