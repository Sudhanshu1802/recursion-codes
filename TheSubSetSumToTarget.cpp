#include <iostream>
#include <map>
using namespace std;
map<pair<int,bool>, int > m;
void TrgtSbst(int a[],int be,int en,int sum,int trgt){
	cout << be << " ";
	if(be>=en){
	 return;
	}
	m[make_pair(be,false)]=sum;
	res = TrgtSbst(a,be+1,en,sum,trgt);
	sum+=a[be];
	m[make_pair(be,true)] = sum;
	
	res = TrgtSbst(a,be+1,en,sum,trgt);
	return res;
}

int main() {
	int n,trgt;
	cin >> n>>trgt;
	int *a = new int[n + 1];
	for (int i = 0; i < n; i++) cin >> a[i];
	TrgtSbst(a, 0, n,0,trgt) ? cout << "Yes" : cout << "No";
	delete [] a;
}