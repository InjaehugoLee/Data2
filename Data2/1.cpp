//10장-3 Stack_use.cpp
//class Stack의 instance 예제
#include <iostream>
#include "2.h"
//정수 stack 정의
using namespace std;
void main() {

	Stack* a = new Stack(2);
	a->Push(100);
	a->Push(200);
	a->Push(300);
	a->Push(400);
	a->Push(500);

	a->Pop();
	a->Pop();
	a->Pop();
	a->Push(10);
	a->Push(5);
	//값을 stack에 넣는다


	//stack을 비우면서 요소를 출력
	while (!a->Empty())
		cout << a->Pop() << endl;
	delete a;
	system("pause");
}
//
//void main() {
//
//	Stack* a = new Stack(2);
//	a->Push(10);
//	cout << a->Pop() << endl;
//	cout << a->Pop() << endl;
//	cout << a->Pop() << endl;
//	cout << a->Pop() << endl;
//	cout << a->Pop() << endl;
//	cout << a->Pop() << endl;
//	delete a;
//	system("pause");
//}