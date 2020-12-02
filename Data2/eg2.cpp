#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


class Stack {
    int data[50];
    int nElements;

public:
    Stack() :nElements(0) {}

    void Push(int item) {
        if (nElements < 49)
        {
            data[nElements] = item;
            nElements++;
        }
        else
            cout << "Stack이 다 찼습니다." << endl;
    }
    int Number() {
        return nElements;
    }

    // '}'가 나오면 스택에서 하나를 꺼집어 낸다.(pop)
    char Pop() {
        if (nElements > 0) {
            nElements--;
            return data[nElements];
        }
        else
            cout << "꺼낼 인자가 없습니다." << endl;
    }
    int Empty() {
        return (nElements == 0);
    }
};


int main()
{
    // 파일을 연다
    Stack intstack;
    FILE* filep;

    filep = fopen("text.txt", "r");


    // 한 글자씩 반복해서 읽으면서 '{'가 나오면 스택에 집어 넣는다.(push)

    char ch;
    while ((ch = fgetc(filep)) != EOF)
    {
        if (ch == '{')
        {
            intstack.Push(ch);
        }
        else if (ch == '}')
        {
            intstack.Pop();
        }
    }

    // 파일을 닫는다.
    fclose(filep);


    // 스택에 들어있는 원소개수가 0개면 OK
    // 아니면 Fail
    if (intstack.Number() == 0)
        cout << "OK" << endl;
    else
        cout << "fail" << endl;
}