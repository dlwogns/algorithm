#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long N, M;
long long arr[1000001];
int main() {
	cin >> N >> M;
	for (size_t i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	long long low = 0;
	long long high = arr[N - 1];
	long long mid;
	long long ans = 0;
	while (low <= high) {
		mid = (low + high) / 2;
		long long sum = 0;
		for (int i = 0; i < N; i++) {
			if (arr[i] < mid)
				continue;
			else
				sum += arr[i] - mid;
		}
		if (sum >= M) {
			if (ans < mid)
				ans = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	cout << ans;
}