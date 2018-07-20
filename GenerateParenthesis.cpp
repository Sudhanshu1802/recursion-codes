#include <iostream>
#include <vector>
using namespace std;

vector<string> cpyVect(vector<string> v){
	return v;
}

void grntePnths(vector<string> &v,string deci,int n,int count1,int count2){
	if(count1>n && count2>n){
		// cout << deci << " ";
		v.push_back(deci);
		return ;
	}
	if(count1<=n){
		string newDeci = deci+'(';
		grntePnths(v,newDeci,n,count1+1,count2);
	}
	if(count2<count1){
		string newDeci = deci+')';
		grntePnths(v,newDeci,n,count1,count2+1);
	}
}


vector<string> generateParenthesis(int n){
	vector<string> res;
	grntePnths(res,"",n,1,1);
	return res;
}

int main(){
	int n;
	cin >> n;
	vector<string> res = generateParenthesis(n);
}