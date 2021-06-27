#include <iostream>
using namespace std;
class Node {
private:

public:
	int data;
	Node* next;
	Node(int e) {
		this->data = e;
		this->next = NULL;

	}
};

class LinkedList {
public:
	Node* head;
	Node* tail;

	LinkedList() {
		head = NULL;
		tail = NULL;
		

	}
	int empty() {
		if (head == NULL && tail==NULL) 
			return 1;
		else 
			return 0;
	}
	int front() {
		if (head == NULL)
			return -1;
		else {
			return head->data;
		}

	}
	void addfront(int x) {
		Node* newNode = new Node(x);
		if (head == NULL) {
			//list empty
			head = tail = newNode;
		}
		else {
			//list not empty
			newNode->next = head;
			head = newNode;
		}
	}
	int removeFront() {
		if (head == NULL)
			return -1;
		else {
			//list not empty
			Node* old = head;
			int result = old->data;
			head = old->next; // 1st die, second-> first
			delete old;
			return result;
		} //return value of remove node
	}
	void addBack(int x) {
		Node* newNode = new Node(x);
		if (head == NULL)
			head = tail = newNode;
		else {
			tail->next = newNode;
			tail = newNode;
		}
	}
};

