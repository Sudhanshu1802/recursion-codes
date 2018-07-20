#include <iostream>
#include <vector>
using namespace std;


void findSubset(vector<int> A,vector<vector<int> > &res,vector<int> deci,int be,int en){
    cout << be << " " << en << " \n";
    if(be>en) {
        int ss = deci.size();
        cout << ss << " ";
        for(int i=0;i<ss;i++) cout << deci[i] << " ";
        res.push_back(deci);
        return;
    }
    findSubset(A,res,deci,be+1,en);
    vector<int> newDeci;
    int sz = deci.size();
    for(int i=0;i<sz;i++) newDeci.push_back(deci[i]);
    newDeci.push_back(deci[be]);
    findSubset(A,res,newDeci,be+1,en);
}

vector<vector<int> > subsets(vector<int> &A) {
    vector<vector<int> > res;
    vector<int> deci;
    int size = A.size();
    cout << size << " ";
    findSubset(A,res,deci,0,size-1);
    
    int ResSize = res.size();
   // sort(res.begin(),res.begin()+ResSize);
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<int> ans;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        ans.push_back(x);
    }
    vector<vector<int> > res;
    res = subsets(ans);

}