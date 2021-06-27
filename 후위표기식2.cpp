#include <iostream>
#include <stack>
#include <iomanip>
using namespace std;
int alpha[26];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	string s;
	stack<double>var;
	cin >> N;
	cin >> s;
	
	for (size_t i = 0; i < N; i++)
		cin >> alpha[i];

	for (auto e : s) {
		if (e == '*') {
			double x = var.top();
			var.pop();
			double y = var.top();
			var.pop();
			var.push(x * y);
		}
		else if (e == '+') {
			double x = var.top();
			var.pop();
			double y = var.top();
			var.pop();
			var.push(x + y);
		}
		else if (e == '-') {
			double y = var.top();
			var.pop();
			double x = var.top();
			var.pop();
			var.push(x - y);
		}
		else if(e=='/'){
			double y = var.top();
			var.pop();
			double x = var.top();
			var.pop();
			var.push(x / y);
		}
		else{
			var.push(alpha[e - 'A']);
		}
	}
	
	cout <<fixed<<setprecision(2)<< var.top();
	

}