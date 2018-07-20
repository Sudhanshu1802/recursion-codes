#include <iostream>
using namespace std;



void fiboPrint(int st, int n, int SuperPrev, int prev) {
	if (st > n) return;
	// cout << st << " ";
	int cur = prev + SuperPrev;
	if (st == 0 || st == 1)	{
		cout << st << " ";
		fiboPrint(st + 1, n, SuperPrev, prev);
	}
	else {
		cout << cur << " ";
		fiboPrint(st + 1, n, prev, cur);
	}

}

int main() {
	int n;
	cin >> n;
	fiboPrint(0, n, 0, 1);
}