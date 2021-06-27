#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[100000];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (size_t i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	cin >> M;
	for (size_t i = 0; i < M; i++)
	{
		int a;
		cin >> a;
		int low = 0;
		int high = N - 1;
		int mid;
		bool check = 0;
		while (low<=high)
		{
			mid = (low + high) / 2;
			if (arr[mid] == a) {
				cout << 1<<'\n';
				check = 1;
				break;
			}
			else if (arr[mid] > a)
				high = mid - 1;
			else
				low = mid + 1;
		}
		if (!check)
			cout << 0 << '\n';
	}

}