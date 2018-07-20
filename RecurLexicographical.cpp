#include <iostream>
using namespace std;

void printLexico(int n,int x,int y,int mul){
	// cout << x << " " << mul << endl;
	if(x>9){
		return;
	}
	if(y>n){
		printLexico(n,x+1,x+1,1);
		return;
	}
	y=mul*x;
	for(int i=0;i<mul;i++){
		if(y<=n) cout << y++ << " ";
	}
	printLexico(n,x,y,mul*10);
	
}

int main(){
	int n;
	cin >>  n;
	cout << "0 ";
	printLexico(n,1,0,1);
}