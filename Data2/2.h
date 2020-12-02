
//10장-1 Stack.h
//generic 객체들로 구성된 class Stack에 대한 객체는 전처리기에 의해
//TYPE이 macro 선언 시 작성된 내용으로 치환된 후 생성된다.
#define TYPE int

class Stack {
	TYPE* data;
	int nElements;
	int stacksize;

public:
	Stack(int i = 5) : nElements(0) {
		stacksize = i;
		data = new TYPE[stacksize];
	}
	~Stack() {
		delete[] data;
	}
	//한 요소를 Stack에 추가
	void Push(TYPE item);
	//Stack으로부터 한 요소를 얻음
	TYPE Pop();
	//Stack에 있는 실제 요소의 수
	int Number();
	//Stack이 비었나?
	int Empty();
	//Stack이 찼나?
	int Full();
};