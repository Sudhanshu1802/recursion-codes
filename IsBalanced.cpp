#include <iostream>
using namespace std;
bool CheckIsBalance(string s, int st, int en, bool res1, bool res2, bool res3) {
	if (st > en) return (res1 && res2 && res3);
	if (s[st] == '{') res1 = false;
	else if (s[st] == '}' && res1 == false) res1 = true;
	else if (s[st] == '[') res2 = false;
	else if (s[st] == ']' && res2 == false) res2 = true;
	else if (s[st] == '(') res3 = false;
	else if (s[st] == ')' && res3 == false) res3 = true;
	return CheckIsBalance(s, st + 1, en, res1, res2, res3);

}
int main() {
	string s;
	getline(cin, s);
	CheckIsBalance(s, 0, s.size() - 1, true, true, true) ? cout << "true" : cout << "false";
}