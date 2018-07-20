#include<iostream>
using namespace std;

void boardPath(int a[], int i, int be, int en, int m) {
	if (be == en) {
		for (int j = 0; j < i; j++) cout << a[j] << " ";
		cout << endl;
		return;
	}
	if (be > en) return;
	for (int l = 1; l <= m; l++) {
		a[i] = l;
		boardPath(a, i + 1, be + l, en, m);

	}

}
int main() {
	int n;
	cin >> n;
	int m;
	cin >> m;
	int a[100];
	int be = 0;
	int en = n;
	boardPath(a, 0, be, en, m);
}

