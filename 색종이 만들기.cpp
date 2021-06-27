#include <iostream>
using namespace std;
int board[128][128];
int n;
int wnum = 0, bnum = 0;
void func(int n, int x, int y) {
	
	for (x; x < n; x++)
	{
		for (y;  y< n; y++)
		{
			if (board[x][y] == 0)
				bnum++;
		}
	}
	if (bnum == 0) { 
		wnum++;
		
	}
	else if (bnum == n * n) {
		bnum++;
		
	}
	else {
		func(n / 2, x, y);
		func(n, x,y + n / 2);
		func(n, x + n / 2, y);
		func(n, x + n / 2, y + n / 2);


	}

}
int main() {
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}
	cout << wnum << "\n" << bnum;
}