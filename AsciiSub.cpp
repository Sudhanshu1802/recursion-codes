#include <iostream>
using namespace std;

string intTostr(int n) {
	string decision;
	while (n > 0) {
		int rem = n % 10;
		char charToAdd = (char)('0' + rem);
		decision = charToAdd + decision;
		n /= 10;
	}
	return decision;
}

int countAsciiSeq(string s, string decision, int be, int en) {
	// cout << be << " ";
	if (be > en) {
		// cout << decision << " ";
		return 1;
	}
	int ans1=0,ans2=0,ans3=0;
	ans1=countAsciiSeq(s, decision, be + 1, en);
	string newDeci1 = decision + s[be];
	string newDeci2 = decision + intTostr((int)(s[be]));
	ans2=countAsciiSeq(s, newDeci1, be + 1, en);
	ans3=countAsciiSeq(s, newDeci2, be + 1, en);
	return (ans1+ans2+ans3);
}


void printAsciiSeq(string s, string decision, int be, int en) {
	// cout << be << " ";
	if (be > en) {
		cout << decision << " ";
		return;
	}
	printAsciiSeq(s, decision, be + 1, en);
	string newDeci1 = decision + s[be];
	string newDeci2 = decision + intTostr((int)(s[be]));
	printAsciiSeq(s, newDeci1, be + 1, en);
	printAsciiSeq(s, newDeci2, be + 1, en);
}


int main() {
	string s;
	cin >> s;
	int len = s.size();
	cout << countAsciiSeq(s,"",0,len-1) << endl;
	printAsciiSeq(s, "", 0, len - 1);
}