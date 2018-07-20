#include <iostream>
#include <stack>
using namespace std;

stack<int> reverseStack(stack<int> s,stack<int> helper){
	if(s.empty()) return helper;
	helper.push(s.top());
	s.pop();
	return reverseStack(s,helper);
}

int main(){
	int n,x;
	cin >> n;
	stack<int> s,helper;
	for(int i=0;i<n;i++){
		int x;
		s.push(x);
	}
	s = reverseStack(s,helper);
	while(s.empty()==false){
		cout << s.top() << endl;
		s.pop();
	}
}