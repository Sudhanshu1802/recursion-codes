#include <iostream>
#include <set>
using namespace std;

bool stringCompare(string s1,string s2){
    int sz1 = s1.size();
    int sz2 = s2.size();
    int i=0,j=0;
    while(i!=sz1 && j!=sz2){
        if(s1[i]<s2[j]) return true;
        if(s1[i]>s2[j]) return false;
        ++i;++j;
    }
    return false;
}
// set<string> st;
void printPermutations(string s,string deci,int be,int en,string ref){
	if(s.size()==0){
// 		st.insert(deci);
		if(stringCompare(deci,ref)) cout << deci << "\n";
		return;
	}
	int sz=s.size();
	for(int i=0;i<sz;i++){
		string newDeci = deci+s[i];
		string helper2="";
		for(int j=0;j<s.size();j++){
			if(j!=i) helper2+=s[j];
		}
		printPermutations(helper2,newDeci,be,en,ref);
	}

}



int main(){
	string s;
	cin >> s;
	printPermutations(s,"",0,s.size(),s);
// 	for(auto it=st.begin();it!=st.end();it++){
// 		if(*it==s) break;
// 		cout << *it << "\n";
// 	}

}