#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define X first
#define Y second
int board[502][502];
bool vis[502][502];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main() {
	int fnum;
	cin >> fnum;
	while (fnum--)
	{
		int n, m, cab;
		cin >> n >> m >> cab;
		for (size_t i = 0; i < cab; i++)
		{
			int x, y;
			cin >> x >> y;
			board[x][y] = 1;
		}
		queue<pair<int, int>>Q;
		int bug = 0;
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < m; j++)
			{
				if (board[i][j] == 0 || vis[i][j]) continue;
				Q.push({ i,j });
				vis[i][j] = 1;
				bug++;
				while (!Q.empty())
				{
					pair<int, int>cur = Q.front();
					Q.pop();
					for (size_t i = 0; i < 4; i++)
					{
						int nx = cur.X + dx[i];
						int ny = cur.Y + dy[i];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
						if (board[nx][ny] == 0 || vis[nx][ny])continue;
						Q.push({ nx,ny });
						vis[nx][ny] = 1;
					}

				}

			}
		}
		cout << bug << "\n";
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < m; j++)
			{
				vis[i][j] = 0;
				board[i][j] = 0;
			}
		}
	}


}