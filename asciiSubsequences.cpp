#include <iostream>
using namespace std;
int count=0;
string strRes(int n){
	string deci="";
	while(n>0){
		int rem = n%10;
		n/=10;
		char charToAdd = '0'+rem;
		deci=charToAdd+deci;
	}
	return deci;
}
int countAsciiSequence(string s,string decision,int st,int en){
	if(st>=en) return 1;
	int count1 = countAsciiSequence(s,decision,st+1,en);
	string Newdeci1 = decision+s[st];
	string Newdeci2 = decision+strRes((int)s[st]);
	int count2 = countAsciiSequence(s,Newdeci1,st+1,en); 
	int count3 = countAsciiSequence(s,Newdeci2,st+1,en);
	return count1+count2+count3;
}
void printAsciiSubSq(string s,string decision, int st,int en){
	if(st>=en){
		cout << decision << " ";
		++count;
	 return;
	}
	printAsciiSubSq(s,decision,st+1,en);
	string Newdeci1 = decision+s[st];
	string Newdeci2 = decision+strRes((int)s[st]);
	printAsciiSubSq(s,Newdeci1,st+1,en); 
	printAsciiSubSq(s,Newdeci2,st+1,en);
}
int main(){
	string s;
	cin >> s;
	cout << countAsciiSequence(s,"",0,s.size()) << "\n";
	printAsciiSubSq(s,"",0,s.size());
	// cout << count;
}