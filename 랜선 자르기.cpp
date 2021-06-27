#include <iostream>
#include <algorithm>
using namespace std;
long long K, N;
long long arr[10001];
long long ans;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + K);
	long long low = 1;
	long long high = arr[K - 1];
	while (low <= high) {

		long long mid = (low + high) / 2;
		long long len = 0;
		for (int i = 0; i < K; i++) {
			if (arr[i] >= mid) {
				len += arr[i] / mid;
			}
		}
		if (len >= N) {
			ans = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	cout << ans;
}