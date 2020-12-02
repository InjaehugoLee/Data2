//10장-2. Stack1.cpp
//generic class Stack의 member 함수 정의
#include <iostream>
#include "2.h"
using namespace std;

void Stack::Push(TYPE item) {
	if (Full())
	{
		cout << "더 이상 입력이 불가합니다." << endl;
	}
	else
	{
		data[nElements] = item;
		nElements++;
	}
}
TYPE Stack::Pop() {
	if (Empty())
	{
		cout << "비어있습니다." << endl;
		return -1;
	}
	nElements--;
	return data[nElements];
}
int Stack::Number() {
	return nElements;
}
int Stack::Empty() {
	return (nElements == 0);
}
int Stack::Full() {
	return (nElements == stacksize);
}

