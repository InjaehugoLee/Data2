#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "2.h"

// �ʿ��� ���� ��Ŭ���
using namespace std;

int main()
{	
	Stack intstack;
	FILE* fp;
	// ������ ����
	errno_t err = fopen_s(&fp, "12.txt", "r");

	if (fp == NULL)
	{
		//���ȳ�? ������ �����մϴ�.
		cout << "Fail to open\n" << endl;
		return 0;
	}
	char ch;
	while ((ch = fgetc(fp)) != EOF)    //�ܾ����� ����������.
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