#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
#define X first
#define Y second
string board[500];
int vis[500][500];
int n;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main() {
	int num = 0; //단지
	 //건물수
	vector<int>ans;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> board[i];
	}
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			int num2 = 0;
			queue<pair<int, int>>Q;
			if (board[i][j] == '0' || vis[i][j])continue;
			Q.push({ i,j });
			vis[i][j] = 1;
			num++;
			while (!Q.empty())
			{
				num2++;
				pair<int, int>cur = Q.front();
				Q.pop();
				for (size_t i = 0; i < 4; i++)
				{
					int nx = cur.X + dx[i];
					int ny = cur.Y + dy[i];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
					if (board[nx][ny] == '0' || vis[nx][ny])continue;
					vis[nx][ny] = 1;
					Q.push({ nx,ny });
				}
			}
			ans.push_back(num2);

		}
	}
	sort(ans.begin(), ans.end());
	cout << num << "\n";
	for (auto e : ans)
		cout << e << '\n';
	
}