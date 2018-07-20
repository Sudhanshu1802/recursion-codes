#include <iostream>
using namespace std;

void printBoard(char Mat[25][25], int n, int m) {
	// cout << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			Mat[i][j] == '1' ? cout << "1 " : cout << "0 ";
		}
		cout << endl;
	}
	// cout << endl;
}


bool printPath(char Mat[25][25], int n, int m, int r, int c) {
	if (r > n || c > m || Mat[r][c] == 'X') return false;

	// cout << r << " " << c << "\n";
	Mat[r][c] = '1';
	if (r == n && c == m) {
		printBoard(Mat, n, m);
		return true;
	}
	bool res;
	if (c + 1 <= m) {
		res = printPath(Mat, n, m, r, c + 1);
		if (res) return true;
		else {
			if (r + 1 <= n) {
				res = printPath(Mat, n, m, r + 1, c);
				if (res) return true;
				else {
					Mat[r][c] = '0';
					return false;
				}
			}
		}
	}
	else if (r + 1 <= n) {
		res = printPath(Mat, n, m, r + 1, c);
		if (res) return true;
		else {
			Mat[r][c] = '0';
			return false;
		}
	}
	else {
		Mat[r][c] = '0';
		return false;
	}
}




int main() {
	int n, m;
	cin >> n >> m;

	char Mat[25][25];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> Mat[i][j];
		}
	}


	printPath(Mat, n, m, 1, 1);
}