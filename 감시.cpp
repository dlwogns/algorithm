#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>


using namespace std;
int board[10][10];
int checkboard[10][10];
int main() {

	int N, M, count=0;
	cin >> N >> M;
	vector<pair<int, int>>v;

	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 6) {
				v.push_back({ i,j });
				checkboard[i][j]++;
				count++;
			}
			else if (board[i][j] != 0) {
				checkboard[i][j]++;
			}

		}
	}
	int maxnum = 0;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			if (board[i][j] == 1) {
				int ans[4] = { 0 };
				int che[4] = { 0 };
				//0->위에서 아래 1-> 아래에서 위 2-> 왼쪽에서 3-> 오른쪽에서
				for (auto e : v) {
					if (e.first == i && e.second > j) {
						if (ans[0] > e.second - j - 1)
							ans[0] = e.second - j - 1;
						che[0]++;
					}
					else if (e.first == i && e.second < j) {
						if (ans[1] > j - e.second - 1)
							ans[1] = j - e.second - 1;
						che[1]++;
					}
					else if (e.second == j && e.first > i) {
						if (ans[2] > e.first - i - 1)
							ans[2] = e.first - i - 1;
						che[2]++;
					}
					else if (e.second == j && e.first < i) {
						if (ans[3] > i - e.first - 1)
							ans[3] = i - e.first - 1;
						che[3]++;
					}
				}
				for (size_t u = 0; u < 4; u++)
				{
					if (che[u] == 0) {
						if (u == 0)
							ans[u] = M - j - 1;
						if (u == 1)
							ans[u] = j;
						if (u == 2)
							ans[u] = N - i - 1;
						if (u == 3)
							ans[u] = i;
					}
				}
				int idx = 0;
				int ans2 = ans[0];
				for (size_t k = 1; k < 4; k++)
				{
					if (ans[k] > ans2)
					{
						idx = k;
						ans2 = ans[k];
					}
				}

				if (idx == 0) {
					for (size_t x = 0; x <= ans[0]; x++)
					{
						checkboard[i][j + x]++;
					}
				}
				else if (idx == 1) {
					for (int x = 0; x <= ans[1]; x++) {
						checkboard[i][j - x]++;
					}

				}
				else if (idx == 2) {
					for (size_t x = 0; x <= ans[2]; x++)
					{
						checkboard[i + x][j]++;
					}
				}
				else if (idx == 3) {
					for (size_t x = 0; x <= ans[3]; x++)
					{
						checkboard[i - x][j]++;
					}

				}

			}
			else if (board[i][j] == 2) {
				int ans[4] = { 0 };
				int che[4] = { 0 };
				//0->위에서 아래 1-> 아래에서 위 2-> 왼쪽에서 3-> 오른쪽에서
				for (auto e : v) {
					if (e.first == i && e.second > j) {
						if (ans[0] > e.second - j - 1)
							ans[0] = e.second - j - 1;
						che[0]++;
					}
					else if (e.first == i && e.second < j) {
						if (ans[1] > j - e.second - 1)
							ans[1] = j - e.second - 1;
						che[1]++;
					}
					else if (e.second == j && e.first > i) {
						if (ans[2] > e.first - i - 1)
							ans[2] = e.first - i - 1;
						che[2]++;
					}
					else if (e.second == j && e.first < i) {
						if (ans[3] > i - e.first - 1)
							ans[3] = i - e.first - 1;
						che[3]++;
					}
				}
				for (size_t u = 0; u < 4; u++)
				{
					if (che[u] == 0) {
						if (u == 0)
							ans[u] = M - j - 1;
						if (u == 1)
							ans[u] = j;
						if (u == 2)
							ans[u] = N - i - 1;
						if (u == 3)
							ans[u] = i;
					}
				}
				if ((ans[0] + ans[1]) > (ans[2] + ans[3])) {
					for (size_t x = 0; x <= ans[0]; x++)
					{
						checkboard[i][j + x]++;
					}
					for (int x = 0; x <= ans[1]; x++) {
						checkboard[i][j - x]++;
					}

				}
				else {
					for (size_t x = 0; x <= ans[2]; x++)
					{
						checkboard[i + x][j]++;
					}
					for (size_t x = 0; x <= ans[3]; x++)
					{
						checkboard[i - x][j]++;
					}

				}

			}
			else if (board[i][j] == 3) {
			int ans[4] = { 0 };
			int che[4] = { 0 };
			//0->위에서 아래 1-> 아래에서 위 2-> 왼쪽에서 3-> 오른쪽에서
			for (auto e : v) {
				if (e.first == i && e.second > j) {
					if (ans[0] > e.second - j - 1)
						ans[0] = e.second - j - 1;
					che[0]++;
				}
				else if (e.first == i && e.second < j) {
					if (ans[1] > j - e.second - 1)
						ans[1] = j - e.second - 1;
					che[1]++;
				}
				else if (e.second == j && e.first > i) {
					if (ans[2] > e.first - i - 1)
						ans[2] = e.first - i - 1;
					che[2]++;
				}
				else if (e.second == j && e.first < i) {
					if (ans[3] > i - e.first - 1)
						ans[3] = i - e.first - 1;
					che[3]++;
				}
			}
			for (size_t u = 0; u < 4; u++)
			{
				if (che[u] == 0) {
					if (u == 0)
						ans[u] = M - j - 1;
					if (u == 1)
						ans[u] = j;
					if (u == 2)
						ans[u] = N - i - 1;
					if (u == 3)
						ans[u] = i;
				}
			}
			int arr3[4] = { ans[0] + ans[2], ans[0] + ans[3], ans[1] + ans[3], ans[1] + ans[2] };
			int idx = 0;
			int ans2 = arr3[0];
			for (size_t k = 1; k < 4; k++)
			{
				if (arr3[k] > ans2)
				{
					idx = k;
					ans2 = arr3[k];
				}

			}
			if (idx == 0) {

				for (size_t x = 0; x <= ans[0]; x++)
				{
					checkboard[i][j + x]++;
				}
			
				for (size_t x = 0; x <= ans[2]; x++)
				{
					checkboard[i + x][j]++;
				}
			}
			else if (idx == 1) {
				for (size_t x = 0; x <= ans[0]; x++)
				{
					checkboard[i][j + x]++;
				}
				
				for (size_t x = 0; x <= ans[3]; x++)
				{
					checkboard[i - x][j]++;
				}
			}
			else if (idx == 2) {
				
				for (int x = 0; x <= ans[1]; x++) {
					checkboard[i][j - x]++;
				}
				for (size_t x = 0; x <= ans[3]; x++)
				{
					checkboard[i - x][j]++;
				}
			}
			else if (idx == 3) {
				for (int x = 0; x <= ans[1]; x++) {
					checkboard[i][j - x]++;
				}
				for (size_t x = 0; x <= ans[2]; x++)
				{
					checkboard[i + x][j]++;
				}
			}

			}
			else if (board[i][j] == 4) {
				int ans[4] = { 0 };
				int che[4] = { 0 };
				//0->위에서 아래 1-> 아래에서 위 2-> 왼쪽에서 3-> 오른쪽에서
				for (auto e : v) {
					if (e.first == i && e.second > j) {
						if (ans[0] > e.second - j - 1)
							ans[0] = e.second - j - 1;
						che[0]++;
					}
					else if (e.first == i && e.second < j) {
						if (ans[1] > j - e.second - 1)
							ans[1] = j - e.second - 1;
						che[1]++;
					}
					else if (e.second == j && e.first > i) {
						if (ans[2] > e.first - i - 1)
							ans[2] = e.first - i - 1;
						che[2]++;
					}
					else if (e.second == j && e.first < i) {
						if (ans[3] > i - e.first - 1)
							ans[3] = i - e.first - 1;
						che[3]++;
					}
				}
				for (size_t u = 0; u < 4; u++)
				{
					if (che[u] == 0) {
						if (u == 0)
							ans[u] = M - j - 1;
						if (u == 1)
							ans[u] = j;
						if (u == 2)
							ans[u] = N - i - 1;
						if (u == 3)
							ans[u] = i;
					}
				}
				int arr3[4] = { ans[0] + ans[2] + ans[1], ans[0] + ans[2] + ans[3], ans[1] + ans[3] + ans[0], ans[1] + ans[2] + ans[3] };
				int idx = 0;
				int ans2 = arr3[0];
				for (size_t k = 1; k < 4; k++)
				{
					if (arr3[k] > ans2)
					{
						idx = k;
						ans2 = arr3[k];
					}

				}
				if (idx == 0) {

					for (size_t x = 0; x <= ans[0]; x++)
					{
						checkboard[i][j + x]++;
					}
					for (int x = 0; x <= ans[1]; x++) {
						checkboard[i][j - x]++;
					}
					for (size_t x = 0; x <= ans[2]; x++)
					{
						checkboard[i + x][j]++;
					}
				}
				else if (idx == 1) {
					for (size_t x = 0; x <= ans[0]; x++)
					{
						checkboard[i][j + x]++;
					}
					for (size_t x = 0; x <= ans[2]; x++)
					{
						checkboard[i + x][j]++;
					}
					for (size_t x = 0; x <= ans[3]; x++)
					{
						checkboard[i - x][j]++;
					}
				}
				else if (idx == 2) {
					for (size_t x = 0; x <= ans[0]; x++)
					{
						checkboard[i][j + x]++;
					}
					for (int x = 0; x <= ans[1]; x++) {
						checkboard[i][j - x]++;
					}
					for (size_t x = 0; x <= ans[3]; x++)
					{
						checkboard[i - x][j]++;
					}
				}
				else if (idx == 3) {
					for (int x = 0; x <= ans[1]; x++) {
						checkboard[i][j - x]++;
					}
					for (size_t x = 0; x <= ans[2]; x++)
					{
						checkboard[i + x][j]++;
					}
					for (size_t x = 0; x <= ans[3]; x++)
					{
						checkboard[i - x][j]++;
					}
				}
				
			}
			else if (board[i][j] == 5) {
				int ans[4] = { 0 };
				int che[4] = { 0 };
				//0->위에서 아래 1-> 아래에서 위 2-> 왼쪽에서 3-> 오른쪽에서
				for (auto e : v) {
					if (e.first == i && e.second > j) {
						if (ans[0] > e.second - j - 1)
							ans[0] = e.second - j - 1;
						che[0]++;
					}
					else if (e.first == i && e.second < j) {
						if (ans[1] > j - e.second - 1)
							ans[1] = j - e.second - 1;
						che[1]++;
					}
					else if (e.second == j && e.first > i) {
						if (ans[2] > e.first - i - 1)
							ans[2] = e.first - i - 1;
						che[2]++;
					}
					else if (e.second == j && e.first < i) {
						if (ans[3] > i - e.first - 1)
							ans[3] = i - e.first - 1;
						che[3]++;
					}
				}
				for (size_t u = 0; u < 4; u++)
				{
					if (che[u] == 0) {
						if (u == 0)
							ans[u] = M - j - 1;
						if (u == 1)
							ans[u] = j;
						if (u == 2)
							ans[u] = N - i - 1;
						if (u == 3)
							ans[u] = i;
					}
				}
				int idx = 0;
				int ans2 = ans[0];
				for (size_t k = 1; k < 4; k++)
				{
					if (ans[k] > ans2)
					{
						idx = k;
						ans2 = ans[k];
					}
				}


				for (size_t x = 0; x <= ans[0]; x++)
				{
					checkboard[i][j + x]++;
				}


				for (int x = 0; x <= ans[1]; x++) {
					checkboard[i][j - x]++;
				}


				for (size_t x = 0; x <= ans[2]; x++)
				{
					checkboard[i + x][j]++;
				}

				for (size_t x = 0; x <= ans[3]; x++)
				{
					checkboard[i - x][j]++;
				}
			}
		}
	}
		int rans = 0;
		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < M; j++)
			{
				/*if (checkboard[i][j] == 0)
					rans++;*/
				cout << checkboard[i][j];
			}
			cout << "\n";
		}
		/*cout << rans;*/
	

}