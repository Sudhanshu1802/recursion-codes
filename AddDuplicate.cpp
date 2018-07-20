#include <iostream>
using namespace std;

string addStar(string s,string decision,int st,int en){
    if(st>=en){
        if(st==en) decision+=s[st];
        return decision;
        
    }
    decision+=s[st];
    if(s[st]==s[st+1]) decision+="*";
    return addStar(s,decision,st+1,en);
}

int main() {
  string s;
  cin >> s;
  int len = s.size();
  cout << addStar(s," ",0,len-1);
}
