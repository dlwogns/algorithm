#include<iostream>
#include <algorithm>
using namespace std;
int arr[10];
int arr2[10];
int isused[10];
int n,m;

void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr2[arr[i]-1] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!isused[i]) {
			isused[i] = 1;
			arr[k] = i;
			func(k + 1);
			isused[i] = 0;
		}

	}

}
int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr2[i];
	}
	sort(arr2, arr2 + n);
	func(0);

}

