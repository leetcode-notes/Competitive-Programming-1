#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second

int main(){
    int n,w;
    cin >> w >> n;
    ll s = 0;
    f(n){
        int a,b;
        cin >> a >> b;
        s += a*b;
    }
    cout << s/w<< endl;
}
