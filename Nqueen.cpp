#include <iostream>
#include <algorithm>
using namespace std;
int n;
bool isused[40]; //열
bool isused2[40]; //오른쪽 위로가는 대각선
bool isused3[40]; // 왼쪽 아래로가는 대각선
int cnt = 0;
void func(int cur) {
	if (cur == n) { //n*n의 배열에 N개의 퀸을 놓으므로 cur이 N이되면 +1해준다.
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (isused[i] || isused2[i + cur] || isused3[cur - i + n - 1])
			continue;
		isused[i] = 1;
		isused2[i + cur] = 1;
		isused3[cur - i + n - 1] = 1;
		func(cur + 1);
		isused[i] = 0;
		isused2[i + cur] = 0;
		isused3[cur - i + n - 1] = 0;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	func(0);
	cout << cnt;

}
