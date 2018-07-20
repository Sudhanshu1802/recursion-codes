#include <iostream>
using namespace std;

bool checkRes(int a[],int be,int en,int trk,int trgt){
	int sum=0;

	while(trk<en){
		sum+=a[trk++];
		if(sum==trgt) return true;
		while(sum>trgt && be<en){
			sum-=a[be++];
		}
		if(sum==trgt) return true;
	}
	return false;
}



int main(){
	int tcse;
	cin >> tcse;
	while(tcse--){
		int n,trgt;
		cin >> n >> trgt;
		int *a = new int[n+1];
		for(int i=0;i<n;i++){
			cin >> a[i];
		}
		cout << boolalpha << checkRes(a,0,n,0,trgt) << endl;
		delete [] a;
	}
}