#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
typedef long long int ll;
#define MAX 500005

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

ordered_set s;
int n;
vector<int> adj[MAX];
int level[MAX];
vector<pair<ll, int>> update[MAX];
vector<int> query[MAX];
bool leaves[MAX];
ll a[MAX];
map<int, ll> m;
ll BIT[MAX], cost;

struct item
{
    ll val;
    int sec;
};
vector<item> ans;
bool comp(item a, item b)
{
    return a.sec < b.sec;
}

void dfs(int x, int p, int d)
{
    level[x] = d;
    
    if(adj[x].size() == 1 and x > 1)
        leaves[x] = true;
        
    for(int i = 0; i < adj[x].size(); i++)
    {
        int y = adj[x][i];
        if(y != p)
            dfs(y, x, d+1);
    }
}

//fenwick tree code start
void fenwick_update(int x, ll val)
{
    for(; x < MAX; x += (x & -x))
        BIT[x] += val;
}
ll fenwick_query(int x)
{
    ll res = 0;
    for(; x > 0; x -= (x & -x))
        res += BIT[x];
    return res;
}
//end

void queryForLeaves(int x)
{
    int dx = level[x];
    item curr;
    for(int i : query[x])
    {
        int sec = i - dx;
        curr.val = 0;
        curr.sec = i;
    
        auto it = s.upper_bound(sec);
        if(it != s.end())
        {
            sec = *it;
            int id = s.order_of_key(sec);
            curr.val += fenwick_query(id);
        }
        else
        {
            curr.val += cost;
        }
        
        curr.val += a[x];
        ans.push_back(curr);
    }
}

void queryForNonLeaves(int x)
{
    int dx = level[x];
    item curr;
    for(int i : query[x])
    {
        int sec = i - dx;
        curr.val = m[sec];
        curr.sec = i;
        ans.push_back(curr);
    }
}

void solve(int x, int p)
{
    int dx = level[x];
    for(pair<ll, int> it : update[x])
    {
        int sec = it.second - dx;
        ll val = it.first;
        m[sec] += val;
        
        cost += val;

        int id = s.order_of_key(sec) + 1;
        fenwick_update(id, val);
    }
    
    if(leaves[x])
    {
        queryForLeaves(x);
    }
    else
    {
        queryForNonLeaves(x);
    }
    
    for(int i = 0; i < adj[x].size(); i++)
    {
        int y = adj[x][i];
        if(y != p)
            solve(y, x);
    }
    
    for(pair<ll, int> it : update[x])
    {
        int sec = it.second - dx;
        ll val = it.first;
        m[sec] -= val;
        
        cost -= val;
        
        int id = s.order_of_key(sec) + 1;
        fenwick_update(id, -val);
    }
}

void findAllSeconds(int x, int p)
{
    int dx = level[x];
    for(pair<ll, int> it : update[x])
    {
        int sec = it.second - dx;
        s.insert(sec);
    }
    for(int i = 0; i < adj[x].size(); i++)
    {
        int y = adj[x][i];
        if(y != p)
            findAllSeconds(y, x);
    }
}

int main()
{
    fast
    
    int q;
    cin >> n >> q;
    
    for(int i = 0; i < n-1; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    memset(leaves, false, sizeof(leaves));
    dfs(1, 0, 0);
    
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(!leaves[i])
        	update[i].push_back({a[i], 0});
    }
    
    int sec = 1;
    while(q--)
    {
        char ty;
        cin >> ty;
        if(ty == '+')
        {
            int x;
            ll y;
            cin >> x >> y;
            update[x].push_back({y, sec});
        }
        else
        {
            int x;
            cin >> x;
            query[x].push_back(sec);
        }
        sec++;
    }
    
    findAllSeconds(1, 0);
    memset(BIT, 0, sizeof(BIT));
    cost = 0;
    solve(1, 0);
    
    sort(ans.begin(), ans.end(), comp);
    
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i].val << "\n";
}
