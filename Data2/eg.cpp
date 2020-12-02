#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "2.h"

using namespace std;

int main(void)
{
    //read mode �� ������ �����.
    Stack* a = new Stack;   //a�� {}Ȯ��
    Stack* b = new Stack;   //b�� []Ȯ��
    Stack* d = new Stack;   //d�� ()Ȯ��

    FILE* pFile = fopen("2.h", "r");
    if (pFile == NULL)
        return 0;

    while (true)
    {
        char c = fgetc(pFile);
        if (c == EOF)
        {
            //������ ���� �˸��� EOF
            break;
        }
        if (c == '{')
            a->Push(3);
        else if (c == '}')
            a->Pop();
        else if (c == '[')
            b->Push(2);
        else if (c == ']')
            b->Pop();
        else if (c == '(')
            d->Push(5);
        else if (c == ')')
            d->Pop();
    }

    fclose(pFile);

    if (a->Empty() && b->Empty() && d->Empty())
        cout << "���� \n";
    else if (a->Empty() != 0)
        cout << "�߰�ȣ {} Error\n";
    else if (b->Empty() != 0)
        cout << "���ȣ [] Error\n";
    else if (d->Empty() != 0)
        cout << "�Ұ�ȣ () Error\n";
    else
        cout << "�̻��� Error\n";

    delete a, b, d;

    return 0;
}