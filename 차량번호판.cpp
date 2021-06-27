#include <iostream>
#include <string>
using namespace std;
int num = 10;
int alpha=26;
int sum = 1;
string s;
void func(int k) {
	if (k == s.size())
		return;
	if (k == 0) {
		if (s[k] == 'd') {
			sum *= num;
			func(k + 1);
		}
		else {
			sum *= alpha;
			func(k + 1);
		}
	}
	if (k != 0 && s[k - 1] == 'd') {
		if (s[k] == 'c') {
			alpha = 26;
			sum *= alpha;
			func(k + 1);
		}
		else {
			sum *= num - 1;
			func(k + 1);
		}
	}
	else if(k !=0 && s[k-1]=='c' ){
		if (s[k] == 'd') {
			num = 10;
			sum *= num;
			func(k + 1);
		}
		else {
			sum *= alpha - 1;
			func(k + 1);
		}
	}
	
}
int main() {

	cin >> s;
	func(0);
	cout << sum;

}