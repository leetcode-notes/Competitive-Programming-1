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
const ll mod = 1e9+7;

int main(){
	int n,m;
	while(cin >> n >> m){
		ll pre[n+5] = {};
		ll now = 1;
		pre[0] = 1;
		for(int i=1;i<=n;i++){
			now *= max(m-1-i,0);
			now %= mod;
			pre[i] = now;
		}
		int deg[n+5] = {};
		f1(n){
			deg[i] = -1;
		}
		deg[1] = 0;
		f(n-1){
			int add1,add2;
			cin >> add1 >> add2;
			deg[add1]++;
			deg[add2]++;
		}
		ll ans = m;
		for(int i=1;i<=deg[1];i++){
			ans *= m-i;
			ans %= mod;
		}
		fr(i,2,n+1){
			ans *= pre[deg[i]];
			ans %= mod;
		}
		cout << ans << endl;
	}

}