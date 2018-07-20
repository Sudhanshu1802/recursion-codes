#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> cpyVect(vector<int> v){
	return v;
}

void permuteSol(vector<vector<int> > &s,vector<int> A,vector<int> helper){
	if(A.size()==0){
		// for(int i=0;i<helper.size();i++) cout << helper[i] << " ";
		// cout << endl;
		s.push_back(helper);
		return;
	}
	int size = A.size();
	for(int i=0;i<size;i++){
		vector<int> newVect = cpyVect(helper);
		newVect.push_back(A[i]);
		vector<int> newA;
		for(int j=0;j<size;j++){
			if(i!=j) newA.push_back(A[j]);
		}
		permuteSol(s,newA,newVect);
	}

}



vector<vector<int> > permute(vector<int> &A){
	sort(A.begin(),A.begin()+A.size());
	vector<vector<int> > s;
	vector<int> helper;
	permuteSol(s,A,helper);
	return s;
}

int main(){
	int n,x;
	cin >> n;
	vector<int> v;
	for(int i=0;i<n;i++){
		cin >> x;
		v.push_back(x);
	}
	vector<vector<int> > sol = permute(v);
}