#include <iostream>
using namespace std;

string DupliStr(string s, string &deci, int be, int en) {
	if (be >= en) {
		deci += s[be - 1];
		return deci;
	}
	deci += s[be - 1];
	if (s[be] == s[be - 1]) {
		deci += '*';
	}
	DupliStr(s, deci, be + 1, en);
}

int main() {
	string s,deci;
	cin >> s;

	 DupliStr(s, deci, 1, s.size());
	 cout << deci;
}