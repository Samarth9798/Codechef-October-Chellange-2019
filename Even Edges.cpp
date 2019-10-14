#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
typedef long long int ll;

int main()
{
	fast 	

	int t;	
	cin >> t;

	while(t--)
	{
		int n,m;
		cin >> n >> m;

		vector<int> adj[n+5];

		for(int i = 0; i < m; i++)
		{
			int u,v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		if(m%2 == 0)
		{
			cout << "1\n";
			for(int i = 0; i < n; i++)
				cout << 1 << ' ';
			cout << "\n";
			continue;
		}
		
		int ans[n+5], K;
		for(int i = 0; i <= n; i++)
			ans[i] = 1;

		int f = 0;
		K = 2;
		for(int i = 1; i <= n; i++)
		{
			if(adj[i].size()%2 == 1)
			{
				f = 1;
				ans[i] = 2;
				break;
			}
		}

		if(f == 0)
		{
			for(int i = 1; i <= n; i++)
			{
				if(adj[i].size() > 0)
				{
					ans[i] = 2;
					ans[ adj[i][0] ] = 3;
					break;
				}
			}
			K += 1;
		}

		cout << K << "\n";
		for(int i = 1; i <= n; i++)
			cout << ans[i] << ' ';
		cout << "\n";
	}
}
