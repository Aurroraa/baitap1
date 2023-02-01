#include <bits/stdc++.h>

using namespace std;
#define ll long long
int t,n,a,b,c;
pair<ll,int> p[100000];
map<int,int> m;
void solve(){
    vector<ll> sum;
    int cnt=0;
    for(int i=0;i<(1<<n);i++){
        if(p[i].second==1){
            cout<<p[i].first<<" ";
            cnt++;
            int si=sum.size();
            for(int j=0;j<si;j++){
                ll s=p[i].first+sum[j];
                sum.push_back(s);
                int size=1<<n;
                auto it=lower_bound(p,p+size,make_pair(s,1));
                it->second=0;
            }
            sum.push_back(p[i].first);
        }
        if(cnt==n) break;
    }
    cout<<endl;
}
int main()
{
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<(1<<n);i++){
            cin>>a;
            p[i]={a,1};
        }
        int size=1<<n;
        sort(p,p+size);
        p[0].second=0;
        solve();
    }
}
