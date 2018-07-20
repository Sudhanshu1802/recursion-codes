#include <iostream>
using namespace std;
string keypads[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wx","yz"};


void intTostr(int n,string &decision){
	if(n<=0) return;
	int rem = n%10;
	char c = char('0'+rem);
	decision=c+decision;
	intTostr(n/10,decision);

}
int countKey(int n){
	if(n<=0) return 1;
	// cout << keypads[(n%10)-1].size() << " ";
	return (keypads[(n%10)-1].size())*countKey(n/10);
}
void KeyPad(string s,string decision,int st,int en){
	if(st>=en){
		cout << decision << " ";
		return;
	}
	string newDeci;
	int rem = (int)(s[st]-'0');
	int size = keypads[rem].size();
	for(int i=0;i<size;i++){
		newDeci = decision + keypads[rem-1][i];
		KeyPad(s,newDeci,st+1,en);
	}
}

int main(){
	int n;
	cin >> n;
	string deci;
	intTostr(n,deci);
	cout <<countKey(n) << "\n";
	KeyPad(deci,"",0,deci.size());
}