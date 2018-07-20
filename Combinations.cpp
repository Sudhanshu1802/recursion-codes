#include <iostream>
#include <vector>
using namespace std;


vector<int> CopyVector(vector<int> dci){
    return dci;
}

void FindCombination(vector<vector<int> > &res,vector<int> deci,int st,int en,int k){
    if(en-st+1<k || k<0) return;
    if(k==0) {
        for(int i=0;i<deci.size();i++) cout << deci[i] << " ";
            cout << endl;
        res.push_back(deci);
        return;
    }
    // cout <<"\n\n" <<st << " " << en << " " << k << endl;
    //FindCombination(res,deci,st+1,en,k-1);
    for(int i=st;i<=en;i++){
        vector<int> newDeci=CopyVector(deci);
        newDeci.push_back(i);
        FindCombination(res,newDeci,i+1,en,k-1);
        
    }
    
}



vector<vector<int> > combine(int A, int B) {
    vector<vector<int> > res;
    vector<int> helper;
    FindCombination(res,helper,1,A,B );
    
    return res;
}

int main(){
    int n,b;
    cin >> n >> b;
    combine(n,b);
}