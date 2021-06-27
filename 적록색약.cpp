#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

string board[100];
bool vis[100][100];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> board[i];
	}
	
	int ans1 = 0;
	int ans2 = 0;
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			if (vis[i][j]) continue;
			queue<pair<int, int>>Q;
			Q.push({ i,j });
			vis[i][j] = 1;
			ans1++;
			while (!Q.empty())
			{
				pair<int, int> cur = Q.front();
				Q.pop();
				for (size_t dir = 0; dir < 4; dir++)
				{
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
					if (vis[nx][ny])continue;
					if (board[nx][ny] != board[cur.first][cur.second])continue;
					vis[nx][ny] = 1;
					Q.push({ nx,ny });
				}
			}
		}
	}
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			vis[i][j] = 0;
			if (board[i][j] == 'G')
				board[i][j] = 'R';
		}
	}

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			if (vis[i][j]) continue;
			queue<pair<int, int>>Q;
			Q.push({ i,j });
			vis[i][j] = 1;
			ans2++;
			while (!Q.empty())
			{
				pair<int, int> cur = Q.front();
				Q.pop();
				for (size_t dir = 0; dir < 4; dir++)
				{
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
					if (vis[nx][ny])continue;
					if (board[nx][ny] != board[cur.first][cur.second])continue;
					vis[nx][ny] = 1;
					Q.push({ nx,ny });
				}
			}
		}
	}
	cout << ans1<<' '<<ans2;


}