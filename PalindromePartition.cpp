#include <iostream>
#include <vector>
using namespace std;

vector<string> cpyVect(vector<string> s){
	return s;
}

bool checkPalin(string s,int be,int en){
	int sz = s.size();
	int i=be,j=en;
	while(i<j){
		if(s[i++]!=s[j--]) return false;
	}
	return true;
}

string createString(string s,int be,int en){
	string deci="";
	for(int i=be;i<=en;i++)deci+=s[i];
	return deci; 
}

void findSol(vector<vector<string> > &res,string s, vector<string> help , int be, int en) {
	if (be >= en) {
		// for (int i = 0; i < help.size(); i++) cout << help[i] << " ";
		// cout << endl;
		res.push_back(help);
		return;
	}
	for(int i=0;i<en-be;i++){
		if(checkPalin(s,be,be+i)){
			string sNew = createString(s,be,be+i);
			vector<string> newVec = cpyVect(help);
			newVec.push_back(sNew);
			findSol(res,s,newVec,be+i+1,en);
		}
	}


}



vector<vector<string> > partition(string A) {
	vector<vector<string> > res;
	vector<string> help;
	findSol(res,A ,help, 0, A.size());
	return res;
}

int main() {
	string s;
	cin >> s;
	vector<vector<string> > res = partition(s);

}