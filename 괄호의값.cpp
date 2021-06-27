#include<iostream>
#include<stack>
#include <string>
using namespace std;
int main() {
	string s;
	stack<char>para;
	cin >> s;
	int mul = 1;
	bool emp = false;
	for (auto e : s) {
		
		if (e == '[' || e == '(') {
			para.push(e);
			if (e == '[')
				mul *= 3;
			else
				mul *= 2;
		}
		else if (e == ')') {
			if (para.empty()||para.top()=='[') {
				emp = true;
				break;
			}
			else
			{

			}
		}

	}

}