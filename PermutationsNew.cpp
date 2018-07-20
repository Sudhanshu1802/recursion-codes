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
	if(be>=en){
// 		st.insert(deci);
		// if(stringCompare(deci,ref))
		 cout << deci << "\n";
		return;
	}
	// int sz=s.size();
	for(int i=be;i<en;i++){
		string newDeci = deci+s[i];
		swap(s[be],s[i]);
		printPermutations(s,newDeci,be+1,en,ref);
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