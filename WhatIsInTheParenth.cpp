#include <iostream>
using namespace std;

string WhatInPare(string s,string decision,int st,int en,bool flag){
	if(st>en||s[st]==')') return decision;
	if(s[st-1]=='(') flag=false;
	string newDecision;
	if(flag==false) newDecision = decision+s[st];
	newDecision = WhatInPare(s,newDecision,st+1,en,flag);
	return newDecision;
}


int main(){
	string s;
	cin >> s;
	string decision;
	decision = WhatInPare(s,"",1,s.size(),true);
	cout << decision ;
}