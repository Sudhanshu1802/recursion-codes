#include <iostream>
using namespace std;

void Subseq(string s,string deci,int be,int en){
	if(be>=en){
		cout << deci << endl;
		return;
	}
	Subseq(s,deci,be+1,en);
	string NewDeci = deci+s[be];
	Subseq(s,NewDeci,be+1,en);
}

int main(){
	string s;
	cin >> s;
	Subseq(s,"",0,s.size());
}