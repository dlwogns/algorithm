#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
	int data;
	Node* par;
	vector<Node*> chi_v;
	Node(int data) {
		this->data = data;
		this->par = NULL;
	}
};

class Tree {
public:
	Node* root;
	vector<Node*> node_v;
	Tree(int);
	void insertNode(int, int);
	void delNode(int);
	void printChi(int);
	void printPar(int);
	void printDepth(int);
	void printLevel(int);
	void preorder(Node*);
	void postorder(Node*);
};

Tree::Tree(int data) {
	Node* node = new Node(data);
	this->root = node;
	this->node_v.push_back(node);
}
void Tree::insertNode(int par_data, int data) {
	Node* node = new Node(data);
	for (size_t i = 0; i < node_v.size(); i++)
	{
		if (node_v[i]->data == par_data) {
			node_v[i]->chi_v.push_back(node);
			node_v.push_back(node);
			node->par = node_v[i];
			return;
		}
	}
	cout << -1 << endl;
}

void Tree::delNode(int data) {
	Node* curNode;
	Node* parNode;
	for (size_t i = 0; i < node_v.size(); i++)
	{
		if (node_v[i]->data == data) {
			if (node_v[i] == root) {
				cout << -1 << endl;
				return;
			}
			curNode = node_v[i];
			parNode = curNode->par;
			for (Node* child : curNode->chi_v) {
				parNode->chi_v.push_back(child);
				child->par = parNode;
			}
			for (int j = 0; j < parNode->chi_v.size(); j++) {
				if (parNode->chi_v[j]->data == data) {
					parNode->chi_v.erase(parNode->chi_v.begin() + j);
				}
			}
			node_v.erase(node_v.begin() + i);
			delete curNode;
			return;
		}
	}

}
