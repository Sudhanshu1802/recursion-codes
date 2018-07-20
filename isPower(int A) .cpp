#include <iostream>
#include <map>
#include <vector>
using namespace std;

bool isPower(int A) {
    vector<int> prime;
    map<int,int> m;
    prime.push_back(2);
    prime.push_back(3);
    bool bb[66000];
    for(int i=4;i<=65536;i=i+2){
        bb[i]=1;
    }
    bb[2]=0;
    bb[3]=0;
    for(int i=3;i<=65536;i=i+2){
        if(bb[i]==0){
            for(int j=2*i;j<=65636;j=j+i){
              bb[j]=1;
            }
        }
    }
    for(int i=5;i<=65536;i++){
        if(bb[i]==0) prime.push_back(i);
    }
    // for(int i=0;i<prime.size();i++){
    //     cout << prime[i] << " ";
    // }
    int i=0;
    while(A!=1){
        cout << prime[i] << " ";
        while(A && A%prime[i]==0){
            A/=prime[i];
            ++m[prime[i]];
        }
        ++i;
        if(i==prime.size()) break;
    }
    if(m.size()==1) {
        if(m.begin()->second==1) return false;
        return true;
    }
    map<int,int>::iterator it1,it2,it;
    it=m.begin();
    it1=it;
    ++it;
    it2=it;
    for(;it!=m.end();it++){
        if(it1->second!=it2->second) return false;
        ++it1;
        ++it2;
    }
    return true;
    
}

int main(){
    int n;
    cin >> n;
    cout << boolalpha <<isPower(n);
}
