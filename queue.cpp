#include <iostream>
using namespace std;
//circular queue
class arrQ {
private:
	int* Q;
	int rear;
	int front;
	int capacity;
public:
	arrQ(int capacity) {
		this->capacity = capacity + 1; //원형큐이므로, 셀이 하나 더 필요
		Q = new int[this->capacity];
		front = rear = 0;// 처음에는 둘다 0번째 인덱스에서 시작
		for (int i = 0; i < capacity; i++)
		{
			Q[i] = 0;
		}
	}
	void enqueue(int value) {
		if (isFull()) { cout << "Full" << endl; }
		else {
			rear = (rear + 1) % capacity;
			Q[rear] = value;
		}
	}
	void dequeue() {
		if (isEmpty()) { cout << "Empty" << endl; }
		else {
			front = (front + 1) % capacity;
			Q[front] = 0;
		}
	}
	void _front() {
		if (isEmpty()) { cout << "Empty" << endl; }
		else cout << Q[(front + 1) % capacity] << endl;
	}
	void _rear() {
		if (isEmpty()) cout << "Empty" << endl;
		else cout << Q[rear] << endl;
	}
	int size() {
		return (rear - front + capacity) % capacity;
	}
	bool isFull() {
		return front == (rear + 1) % capacity;
	}
	bool isEmpty() {
		return front == rear;
	}
};