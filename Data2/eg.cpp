#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "2.h"

using namespace std;

int main(void)
{
    //read mode 로 파일을 열어요.
    Stack* a = new Stack;   //a는 {}확인
    Stack* b = new Stack;   //b는 []확인
    Stack* d = new Stack;   //d는 ()확인

    FILE* pFile = fopen("2.h", "r");
    if (pFile == NULL)
        return 0;

    while (true)
    {
        char c = fgetc(pFile);
        if (c == EOF)
        {
            //파일의 끝을 알리는 EOF
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
        cout << "성공 \n";
    else if (a->Empty() != 0)
        cout << "중괄호 {} Error\n";
    else if (b->Empty() != 0)
        cout << "대괄호 [] Error\n";
    else if (d->Empty() != 0)
        cout << "소괄호 () Error\n";
    else
        cout << "이상한 Error\n";

    delete a, b, d;

    return 0;
}