#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second
int board[300][300];
int vis[300][300];
int dx[8] = { 2,1,-1,-2,-2,-1,1,2 };
int dy[8] = { 1,2,2,1,-1,-2,-2,-1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int fnum;
	cin >> fnum;
	while (fnum--)
	{
		int n;
		cin >> n;
		int cx, cy, px,py;
		cin >> cx >> cy;
		cin >> px >> py;
		queue<pair<int, int>>Q;
		Q.push({ cx,cy });
		while (!Q.empty())
		{
			pair<int, int>cur = Q.front();
			Q.pop();
			for (size_t i = 0; i < 8; i++)
			{
				int nx = cur.X + dx[i];
				int ny = cur.Y + dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
				if (nx == cx && ny == cy)continue;
				if (vis[nx][ny] != 0)continue;
				vis[nx][ny] = vis[cur.X][cur.Y] + 1;
				Q.push({ nx,ny });

			}
		}
		cout << vis[px][py] << "\n";
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				vis[i][j] = 0;
			}
		}

	}

}
