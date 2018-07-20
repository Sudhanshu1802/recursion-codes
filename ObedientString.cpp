#include <iostream>
using namespace std;

bool checkString(string s,int be,int en) {
	if(be>=en){
		return true;
	}
	if(s[be-1]=='a'){
		if(s[be]=='a') return checkString(s,be+1,en);
		else if(be+1<en){
			if(s[be]=='b'&&s[be+1]=='b') return checkString(s,be+2,en);
			else return false;
		}
		else return false;
	}
	else if(s[be-1]=='b'){
		if(s[be]=='a') return checkString(s,be+1,en);
		else return false;
	}
	else return false;

}

int main() {
	string s;
	cin >> s;
	if (s[0] == 'a') {
		cout << boolalpha <<checkString(s, 1, s.size());
	}
	else cout << "false";
}