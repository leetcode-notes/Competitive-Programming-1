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
#define bg begin()
#define ed end()
#define pii pair<int,int>
const ll mod = 1e9+7;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int cnt[3]={};
		f(n){
			int add;
			cin >> add;
			cnt[add%3]++;
		}
		int ans =cnt[0];
		int c=min(cnt[1],cnt[2]);
		ans += c;
		cnt[1] -= c;
		cnt[2] -= c;
		ans += cnt[1]/3 + cnt[2]/3;
		cout << ans <<'\n';
	}
}