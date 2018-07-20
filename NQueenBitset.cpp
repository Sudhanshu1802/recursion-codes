#include<bits/stdc++.h>
using namespace std;
bitset<35> col,dia1,dia2;
void rec(int n,int i,int &counts)
{
    if(i==n)
    {
        counts++;
        return;
    }
    for(int j=0;j<n;j++)
    {
        if(!col[j]&&!dia1[i-j+n]&&!dia2[i+j])
        {
            col[j]=dia1[i-j+n]=dia2[i+j]=1;
            rec(n,i+1,counts);
            col[j]=dia1[i-j+n]=dia2[i+j]=0;
        }
    }
    return;
}
int main() {
    int n;
    cin>>n;
    int counts=0;
    rec(n,0,counts);
    cout<<counts<<endl;
	return 0;
}