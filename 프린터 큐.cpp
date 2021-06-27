#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace	std;
int main() {
	int T;
	cin >> T;
	while (T--)
	{
		int N, M, cnum;
		int ans = 0;
		queue<int>q;

		cin >> N >> M;

		for (size_t i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			q.push(a);	
			if (i == M)
				cnum = a;
		}
		int idx = M;
		while (!q.empty())
		{

		}



	}

}