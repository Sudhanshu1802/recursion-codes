#include<iostream>
using namespace std;
int len(string a) {
	int j = 0;
	while (a[j] != '\0') {
		j++;
	}
	return j;
}
void moveX(int be,int en,string& a){
   // cout<<a;
	if(be>=en){
		return;
	}
	if(a[be]=='x'){
		int j=a[be];
		int i=be;
		while(a[i+1]!='\0'||((a[i+1]=='x')&&(a[i]=='x'))){
			swap(a[i],a[i+1]);
			i++;
		}
		a[en]=j;// can be en or en-1
		moveX(be,en-1,a);
	//	en--;
	}
	//	moveX(be,en-1,a);
	else{
	moveX(be+1,en,a);
//	be++;
	}
//	cout<<a;
}

int main() {
	string a;
	cin >> a;
	int n = len(a);
	int be = 0;
	int en = n - 1;
	//cout<<a;
	//cout<<n;
	moveX(be,en,a);
	cout<<a;
}