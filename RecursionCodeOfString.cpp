#include <iostream>
#include <vector>
using namespace std;

void findCodeOfStr(vector<string> &res, string s, string deci, int be, int en) {
	if (be >= en) {

		// cout << deci << " ";
		res.push_back(deci);
		return;
	}
	char c = (char)(s[be] - '1' + 'a');
	string newDeci = deci + c;
	findCodeOfStr(res, s, newDeci, be + 1, en);
	int ans = 0;
	if (be + 1 < en) {
		ans = ((int)(s[be] - '0')*10 + (int)(s[be+1]-'0'));
		// cout << ans << " ";
		if(ans<=26){
		 c = (char)('a'+ans-1);
		 newDeci = deci+c;
		 findCodeOfStr(res,s,newDeci,be+2,en);
		}
	}
}


int main() {
	string s;
	cin >> s;
	vector<string> res;
	findCodeOfStr(res, s, "", 0, s.size());
	int sz = res.size();
	cout << "[";
	for(int i=0;i<sz;i++){
		cout << res[i];
		if(i!=sz-1) cout << ", ";
	}
	cout << "]";
}