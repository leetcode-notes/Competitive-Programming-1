#include<bits/stdc++.h>

#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
using namespace std;
const int mod = 1e9+7;
const int maxn = 400005;
vector<int>g[maxn]; 
vector<int>rev[maxn]; 
stack<int>st;  
int n,m,scc,idx;  
int low[maxn],dfn[maxn],instack[maxn],fa[maxn];  
int ans[maxn];
int in[maxn];
int opp[maxn],c[maxn];
int nd[maxn];
void tarjan(int now){
    dfn[now] = low[now] = ++idx;
    instack[now] = 1;
    st.push(now);
    for(auto i:g[now]){
        if(!dfn[i]){
            tarjan(i);
            low[now] = min(low[now],low[i]);
        }
        else if(instack[i]){
            low[now] = min(low[now],dfn[i]);
        }
    }
    if(dfn[now] == low[now]){
        scc++;
        while(1){
            int cur = st.top();
            st.pop();
            instack[cur] = 0;
            fa[cur] = scc;
            if(cur == now)break;
        }
    }
}
bool check(){
    for(int i=0;i<2*n;i++){
        if(!dfn[i]){
            tarjan(i);
        }
    }
    for(int i=0;i<2*n;i+=2){
        //cout<<fa[i]<<' '<<fa[i+1]<<endl;
        if(fa[i]==fa[i+1])return 0;
        opp[fa[i]] = fa[i+1];
        opp[fa[i+1]] = fa[i];
    }
    return 1;
}
void build(){
    for(int i=0;i<2*n;i++){
        int x = fa[i];
        for(int j=0;j<(int)g[i].size();j++){
            int y = fa[g[i][j]];
            if(x!=y){
                rev[y].push_back(x);
                in[x]++;
            }
        }
    }
}
void topo(){
    memset(c,0,sizeof(c));
    queue<int>q;
    f1(scc){
        if(!in[i])q.push(i);
    }
    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(!c[now]){
            c[now] = 1;
            c[opp[now]] = 2;
        }
        for(int i = 0 ; i <(int)rev[now].size() ; i++){
            int nxt = rev[now][i];
            in[nxt]--;
            if(!in[nxt]){
                q.push(nxt);
            }
        }
    }
    vector<int>ans;
    f(n){
        if(c[fa[i*2]]==1){
            ans.pb(i+1);
        }
    }
    cout<<ans.size()<<endl;
    for(auto i:ans){
        cout<<i<<' ';
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> n >> m){
        vector<int>last;
        vector<int>cur;
        int k;
        cin >> k;
        f(k){
            int add;
            cin >> add;
            last.pb(add);
        }
        f(n-1){
            cin >> k;
            while(k--){
                int add;
                cin >> add;
                cur.pb(add);
            }
            int sz1 = last.size();
            int sz2 = cur.size();
            int f = 0;
            fr(j,0,min(sz1,sz2)){
                if(last[j]!=cur[j]){
                    if(last[j]>cur[j]){
                        int num1 = last[j];
                        int num2 = cur[j];
                        num1--,num2--;
                        g[num2*2].pb(num2*2+1);
                        g[num1*2+1].pb(num1*2);
                    }
                    else{
                        int num1 = last[j];
                        int num2 = cur[j];
                        num1--,num2--;
                        g[num2*2].pb(num1*2);
                        g[num1*2+1].pb(num2*2+1);
                    }
                    f = 1;
                    break;
                }
            }
            if(!f&&sz2<sz1){
                cout<<"No"<<endl;
                exit(0);
            }
            last = cur;
            cur.clear();
        }
        n = m;
        if(check()){
            cout<<"Yes"<<endl;
            build();
            topo();
        }
        else{
            cout<<"No"<<endl;
        }
    }
}