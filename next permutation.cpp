//순열이나 조합을 구할때, 백트래킹으로 안들어가고 next permutation으로 들어가는게 낫다.
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a[3] = { 1,2,3 };
	do {
		for (int i = 0; i < 3; i++)
			cout << a[i];
		cout << '\n';
	} while (next_permutation(a, a + 3)); //순열

	//4C2를 구하고 싶을때(조합)
	int a[4] = { 0,0,1,1 };
	do {
		for (int i = 0; i < 4; i++) {
			if (a[i] == 0)
				cout << i + 1;
		}
		cout << '\n';
	} while (next_permutation(a, a + 4));
}