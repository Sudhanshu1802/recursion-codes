#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int cntt = 0;
vector<int> cpyVector(vector<int> A) {
	return A;
}

int CountSplitArray(vector<int> v, vector<int> helper, int sum, int trgt, int be, int en) {
	if (sum == trgt) return 1;
	if (be >= en || sum > trgt) return 0;
	int count = 0;
	for (int i = be; i < en; i++) {
		vector<int> newVect = cpyVector(helper);
		newVect.push_back(i);
		count += CountSplitArray(v, newVect, sum + v[i], trgt, i + 1, en);
	}
	return count;

}
void SplitArray(vector<int> v, vector<int> helper, int sum, int trgt, int be, int en) {
	if (sum == trgt) {
		++cntt;
		int sz = helper.size();
		for (int i = 0; i < sz; i++) cout << v[helper[i]] << " ";
		cout << "and ";
		for (int i = 0; i < en; i++) {
			bool flag = true;
			for (int j = 0; j < sz; j++) {
				if (i == helper[j]) flag = false;
			}
			if (flag) cout << v[i] << " ";
		}
		cout << endl;
		return;
	}
	if (be >= en || sum > trgt) return;
	for (int i = be; i < en; i++) {
		vector<int> newVect = cpyVector(helper);
		newVect.push_back(i);
		SplitArray(v, newVect, sum + v[i], trgt, i + 1, en);
	}
}


int main() {
	int n, x;
	cin >> n;
	vector<int> v, helper;
	int trgt = 0;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
		trgt += x;
	}
	if (trgt % 2 == 0) {
		cout << CountSplitArray(v, helper, 0, trgt / 2, 0, n) << " \n";
		SplitArray(v, helper, 0, trgt / 2, 0, n);
	}
	else cout << "0";
}