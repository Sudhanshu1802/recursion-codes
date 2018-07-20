#include <iostream>
using namespace std;


void printBoard(char Mat[30][30], int n, int m) {
	cout << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			Mat[i][j] == '1' ? cout << "1 " : cout << "0 ";
		}
		cout << endl;
	}
	cout << endl;
}

bool printRatInMaze(char Mat[30][30], int n, int m, int r, int c) {
	if (r > n || c > m || Mat[r][c] == 'X') return false;
	cout << r << " " << c << endl;
	Mat[r][c] = '1';
	if (r == n && c == m) {
		cout << r << " " << c << endl;
		// cout << "reach" ;
		printBoard(Mat, n, m);
		return true;
	}
	
	bool res;
	if (r + 1 <= n ) {
		res = printRatInMaze(Mat, n, m, r + 1, c);
		if (res == false) {
			if (c + 1 < m) res = printRatInMaze(Mat, n, m, r, c + 1);
			if (res == false) {
				Mat[r][c] = '0';
				return false;
			}
		}
		else return true;
	}
	else if (c + 1 <= m) {
		res = printRatInMaze(Mat, n, m, r, c + 1);
		if (res == false) {
			Mat[r][c] = '0';
			return false;
		}
		else return true;
	}
	else {
		Mat[r][c] = '0';
		return false;
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	char Mat[30][30];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> Mat[i][j];
		}
	}
	printRatInMaze(Mat, n , m , 1, 1);
}