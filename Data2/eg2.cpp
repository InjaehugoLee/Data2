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
            cout << "Stack�� �� á���ϴ�." << endl;
    }
    int Number() {
        return nElements;
    }

    // '}'�� ������ ���ÿ��� �ϳ��� ������ ����.(pop)
    char Pop() {
        if (nElements > 0) {
            nElements--;
            return data[nElements];
        }
        else
            cout << "���� ���ڰ� �����ϴ�." << endl;
    }
    int Empty() {
        return (nElements == 0);
    }
};


int main()
{
    // ������ ����
    Stack intstack;
    FILE* filep;

    filep = fopen("text.txt", "r");


    // �� ���ھ� �ݺ��ؼ� �����鼭 '{'�� ������ ���ÿ� ���� �ִ´�.(push)

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

    // ������ �ݴ´�.
    fclose(filep);


    // ���ÿ� ����ִ� ���Ұ����� 0���� OK
    // �ƴϸ� Fail
    if (intstack.Number() == 0)
        cout << "OK" << endl;
    else
        cout << "fail" << endl;
}