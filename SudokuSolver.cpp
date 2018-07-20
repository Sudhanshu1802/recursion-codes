#include <iostream>
using namespace std;

bool canPlace(int N[10][10], int r, int c, int size, int val) {
	for (int i = 0; i < size; i++) {
		if (N[i][c] == val || N[r][i] == val) return false;
	}
	int i = (r / 3) * 3, enI = i + 3;
	int j = (c / 3) * 3, enJ = j + 3;
	for (; i < enI; i++) {
		j = (c / 3) * 3;
		enJ = j + 3;
		for (; j < enJ; j++) {
			if (N[i][j] == val) return false;
		}
	}
	return true;

}

void printBoard(int N[10][10], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << N[i][j] << " ";
		}
		cout << endl;
	}
}

void sudokuSolver(int N[10][10], int r, int c, int en) {
	if (r >= en) {
		printBoard(N, en);
		return;
	}
	if (c >= en) {
		sudokuSolver(N, r + 1, 0, en);
		return;
	}
	if (N[r][c] != 0) sudokuSolver(N, r, c + 1, en);
	else {
		for (int j = 1; j <= en; j++) {
			if (canPlace(N, r, c, en, j)) {
				N[r][c] = j;
				sudokuSolver(N, r, c + 1, en);
				N[r][c] = 0;
			}
		}
	}


}


int main() {
	int N;
	cin >> N;
	int a[10][10];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
		}
	}
	sudokuSolver(a, 0, 0, N);
}