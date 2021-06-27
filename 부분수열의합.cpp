#include <iostream>

using namespace std;
int n, s;
int isused[21];
int arr[21];
int cnt = 0;
void func(int cur, int tot) {
	if (cur == n) {
		if (tot == s) cnt++;
		return;
	}
	func(cur + 1, tot);
	func(cur + 1, tot + arr[cur]);
}

int main() {
	cin >> n >> s;
	for (size_t i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	func(0, 0);
	if (s == 0) cnt--; //공집합 하나만 있을떄
	cout << cnt;

}