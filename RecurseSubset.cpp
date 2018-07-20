#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool comparator(vector<int> a,vector<int> b){
	return a.size() > b.size();
}

vector<int> cpyVector(vector<int> A) {
	return A;
}

void SplitArray(vector<vector<int> > &res,vector<int> v, vector<int> helper, int sum, int trgt, int be, int en) {
	if (sum == trgt) {
		res.push_back(helper);
		return;
	}
	if (be >= en || sum > trgt) return;
	for (int i = be; i < en; i++) {
		vector<int> newVect = cpyVector(helper);
		newVect.push_back(i);
		SplitArray(res,v, newVect, sum + v[i], trgt, i + 1, en);
	}
}

void reverse(vector<int> &v, int n) {
	int i = 0, j = n - 1;
	while (i <= j) {
		swap(v[i++], v[j--]);
	}
}

int main() {
	int n, x;
	cin >> n;
	vector<int> v, helper;
	int trgt = 0;
	for (int i = n - 1; i >= 0; i--) {
		cin >> x;
		v.push_back(x);
	}
	vector<vector<int> > res;
	reverse(v, n);
	cin >> trgt;
	SplitArray(res,v, helper, 0, trgt, 0, n);
	vector<vector<int> >::iterator it;
	for(it=res.begin();it!=res.end();it++){
		vector<int> a = *it;
		int sz = a.size();
		for(int i=0;i<sz;i++){
			cout << a[i] << " ";
		}
		cout << endl;
	} 

}