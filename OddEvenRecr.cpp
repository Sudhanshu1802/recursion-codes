#include <iostream>
using namespace std;
void printOddEven(int n, int x, bool res) {
	if (n > x + 1) return;
	if (n == 1) {
		cout << n << "\n";
		res=false;
		printOddEven(2, x, res);
		return;
	}
	cout << n << endl;
	if (res)printOddEven(n - 2, x, res);
	else printOddEven(n + 2, x, res);
}
int main() {
	int n;
	cin >> n;
	if (n & 1) printOddEven(n, n - 1, true);
	else printOddEven(n - 1, n, true);
}