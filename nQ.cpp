#include <iostream>
#include <vector>
using namespace std;

bool check(vector<string> v,int r,int c,int n){
    int i=r-1,j=c;
    while(i>=0){
        if(v[i--][j]=='Q') return false;
    }
    i=r-1,j=c-1;
    while(i>=0&&j>=0){
        if(v[i--][j--]=='Q') return false;
    }
    i=r-1,j=c+1;
    while(i>=0&&j<n){
        if(v[i--][j++]=='Q') return false;
    }
    return true;
}


void NQueen(vector<vector<string> > &res,vector<string> v,int be,int en){
    if(be>=en){
        res.push_back(v);
        return;
    }
    for(int i=0;i<en;i++){
        if(check(v,be,i,en)){
            v[be][i]='Q';
            NQueen(res,v,be+1,en);
            v[be][i]='.';
        }
    }
}

vector<vector<string> > solveNQueens(int A) {
    vector<string> v;
    string s;
    for(int j=0;j<A;j++){
        s+='.';
    }
    for(int i=0;i<A;i++){
        v.push_back(s);
    }
    
    vector<vector<string> > res;
    
    NQueen(res,v,0,A);
    return res;
    
}

int main(){
    int n;
    cin >> n;

}