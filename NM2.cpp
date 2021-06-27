#include <iostream>
using namespace std;
int n, m;
int arr[10];
bool isused[10];

void func(int n1, int k) {

	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (size_t i = n1; i <= n; i++)
	{
		if (!isused[i]) {
			isused[i] = 1;
			arr[k] = i;
			func(i + 1, k + 1);
			isused[i] = 0;
		}
	}
}
int main() {

	cin >> n >> m;
	func(1,0);
}