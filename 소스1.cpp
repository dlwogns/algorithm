#include <iostream>
#include <vector>
using namespace std;
int arr[41];
int vip[41];
int N, M;
int main() {
	cin >> N >> M;
	for (size_t i = 1; i <= M; i++) {
		int a;
		cin >> a;
		for (int j = 1; j <= 40; j++) {
			if (a == j)
				vip[j]++;
		}
	}

	/*arr[1] = 1;
	arr[2] = 2;*/
	arr[0] = 1;
	int checknum = 1;
	int maxnum = 1;
	for (size_t i = 1; i <= N; i++)
	{
		if (vip[i] > 0)
		{
			checknum = 1;
			arr[i] = arr[i - 1];
			
			maxnum = arr[i - 1];
			continue;
		}
		else {
			if (checknum == 1) {
				arr[i] = 1 * maxnum;
				checknum++;
			}
			else if (checknum == 2){
				arr[i] = 2 * maxnum;
				checknum++;
			}
			else {
				arr[i] = 
					arr[i - 1] + arr[i - 2];
				checknum++;
			}

		}


	}
	if (arr[N] == 0)
		arr[N]++;
	cout << arr[N];

}