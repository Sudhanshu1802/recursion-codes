#include <iostream>
#include <vector>
using namespace std;
void printBoard(vector<vector<int> > sol, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << sol[i][j] << " ";
		}
		cout << "\n";
	}
}

vector<vector<int> > copyBoard(vector<vector<int> > sol) {
	return sol;
}

bool canPlace(vector<vector<int> > ToCheck, int r, int c, int size, int val) {
	for (int i = 0; i < size; i++) {
		if (ToCheck[r][i] == val || ToCheck[i][c] == val) return false;
	}
	int i = (r / 3) * 3;
	int iEnd = i + 3;
	int j = (c / 3) * 3;
	int jEnd = j + 3;
	for (; i < iEnd; i++) {
		j = (c / 3) * 3;
		jEnd = j + 3;
		for (; j < jEnd; j++) {
			if (ToCheck[i][j] == val) return false;
		}
		// i = (r / 3) * 3;
	}
	return true;

}

void solver(vector<vector<int> > ques,vector<vector<int> > &sol, int r, int c, int n) {
	if (r >= n) {
		// printBoard()
		sol = copyBoard(ques);
		return;
	}
	if (c >= n) {
		solver(ques,sol, r + 1, 0, n);
		return;
	}
	if (ques[r][c] != 0) solver(ques,sol, r, c + 1, n);
	else {
		for (int i = 1; i <= 9; i++) {
			bool isTrue = canPlace(ques, r, c, n, i);
			// cout << isTrue << " ";
			if (isTrue) {
				ques[r][c] = i;
				solver(ques,sol, r, c + 1, n);
				ques[r][c] = 0;
			}
		}
	}


}

vector<vector<int> > SolveSudoku(vector<vector<int> > ques, int size) {
	vector<vector<int> > ans;
	solver(ques,ans, 0, 0, size);
	return ans;
}



int main() {
	int n, x;
	cin >> n;
	vector<vector<int> > ques;
	for (int i = 0; i < n; i++) {
		vector<int> v;
		for (int j = 0; j < n; j++) {
			cin >> x;
			v.push_back(x);
		}
		ques.push_back(v);
	}
	// printBoard(ques, n);
	vector<vector<int> >res = SolveSudoku(ques, n);
	// cout << res.size() << " ";
	printBoard(res, n);
}