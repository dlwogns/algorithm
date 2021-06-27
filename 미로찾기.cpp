#include <iostream>
#include<algorithm>
#include <queue>
#include <string>
using namespace std;

#define X first
#define Y second

string board[502];
int vis[502][502];
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {

	cin >> n >> m;
	for (size_t i = 0; i < n; i++)
	{
		cin >> board[i];
	}
	vis[0][0] = 1;
	queue<pair<int, int>>Q;
	Q.push({ 0,0 });
	while (!Q.empty())
	{
		pair<int, int>cur = Q.front();
		Q.pop();
		for (size_t i = 0; i < 4; i++)
		{
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == '0' || vis[nx][ny]>0) continue;
			vis[nx][ny] = vis[cur.X][cur.Y]+1;
			Q.push({ nx,ny });
		}
	}


	cout << vis[n - 1][m - 1];
}
