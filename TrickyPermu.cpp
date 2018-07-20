#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void trickyPermu(string s,vector<string> &v,int be,int en){
	if(be>=en){
		// cout << s << " ";
		v.push_back(s);
		return;
	}
	for(int i=be;i<en;i++){
		swap(s[be],s[i]);
		trickyPermu(s,v,be+1,en);
	}

}


int main(){
	string s;
	cin >> s;
	// sort(s.begin(),s.end());
	// cout << s;
	vector<string> v;
	trickyPermu(s,v,0,s.size());
	sort(v.begin(),v.begin()+v.size());
	for(int i=0;i<v.size();i++){
		while(i+1<v.size() && v[i]==v[i+1]){
			++i;
		}

		 cout << v[i] << endl;
	}

}