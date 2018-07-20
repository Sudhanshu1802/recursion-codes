#include <iostream>
using namespace std;
int StringToInt(string s, int mul, int be, int en) {
	if(be>en) return 0;
	int ans = mul*((int)(s[en]-'0')) + StringToInt(s,mul*10,be,en-1);
	return ans;

}
int main() {
	string str;
	cin >> str;
	cout << StringToInt(str, 1, 0, str.size() - 1);
}