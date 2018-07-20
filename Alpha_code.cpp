#include <iostream>
#include <map>
using namespace std;
typedef long long int ll;

map< pair<ll, ll> , ll > ans;

void alph_code(string s, string decision, int st, int en) {
	if (st > en) {
		cout << decision << " ";
		return;
	}
	int res = s[st] - '0';
	// cout << res  << "    ";
	string newDeci = decision + (char)('a' + res - 1);
	alph_code(s, newDeci, st + 1, en);
	if (st + 1 <= en) {
		res = ((int)(s[st] - '0')) * 10 + (int)(s[st + 1] - '0');
		// cout << res << "    ";
		if (res <= 26) {
			newDeci = decision + (char)('a' + res - 1);
			alph_code(s, newDeci, st + 2, en);
		}
	}
}

ll alpha_code(string s, string decision, ll st, ll en) {
	ll ans1 = 0, ans2 = 0;
	int res1=0;
	int res2=50;
	if (ans.find(make_pair(st, en)) != ans.end()) return ans[make_pair(st, en)];
	if (st > en) {
		// cout << decision << " ";
		return 1;
	}
	res1 = s[st] - '0';
	int res2 = ((int)(s[st] - '0')) * 10 + (int)(s[st + 1] - '0');
	// cout << res  << "    ";
	string newDeci;
	if (res != 0) {
		newDeci = decision + (char)('a' + res - 1);
		ans1 = alpha_code(s, newDeci, st + 1, en);
	}
	if (st + 1 <= en) {
		res = ((int)(s[st] - '0')) * 10 + (int)(s[st + 1] - '0');
		// cout << res << "    ";
		if (res <= 26) {
			newDeci = decision + (char)('a' + res - 1);
			ans2 = alpha_code(s, newDeci, st + 2, en);
		}
	}
	return ans[make_pair(st, en)] = (ans1 + ans2);
}


int main() {
	string s;
	cin >> s;
	int len = s.size();
	// alph_code(s, "", 0, len-1);
	cout << alpha_code(s, "", 0, len - 1);

}