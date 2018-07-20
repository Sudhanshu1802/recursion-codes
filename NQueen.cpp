#include <iostream>
using namespace std;
int count=0;
bool check(char a[10][10], int r, int c, int n) {
	int i = r - 1, j = c;
	while (i >= 0) {
		if (a[i--][j] == 'Q') return false;
	}
	i = r - 1, j = c - 1;
	while (i >= 0 && j >= 0) {
		if (a[i--][j--] == 'Q') return false;
	}
	i = r - 1, j = c + 1;
	while (i >= 0 && j < n) {
		if (a[i--][j++] == 'Q') return false;
	}
	return true;
}


void printBoard(char a[10][10], int en) {
	for (int i = 0; i < en; i++) {
		for (int j = 0; j < en; j++) {
			cout << a[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void printNQueen(char a[10][10], int be, int en) {
	if(be>=en){
		++count;
		// printBoard(a,en);
		return;
	}
	for (int i = 0; i < en; i++) {
		// cout << check(a, be, i, en) << " ";
		if (check(a, be, i, en)) {
			a[be][i] = 'Q';
			printNQueen(a,be+1,en);
			a[be][i] = '.';
		}
	}
}


int main() {
	int n;
	cin >> n;
	char a[10][10];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = '.';
		}
	}
	printNQueen(a, 0, n);
	cout << count << " ";
}