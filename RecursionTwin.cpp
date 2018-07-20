#include <iostream>
using namespace std;
int FindTwin(string s,int be,int en){
	if(be+2>=en) return 0;
	int ans;
	if(s[be]==s[be+2]) ans = 1+ FindTwin(s,be+1,en);
	else ans = FindTwin(s,be+1,en);
	return ans;
}
int main(){
	string s;
	cin >> s;
	cout << FindTwin(s,0,s.size());
}