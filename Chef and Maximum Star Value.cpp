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
		int n;
		cin >> n;
        
        int a[n+5];
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		int ans = 0;
		int m[1000001];
		memset(m, 0, sizeof(m));
        
		for(int i = 0; i < n; i++)
		{
			int x = a[i];

			if(x < 2)
			{
				ans = i;
				continue;
			}
			
			ans = max(ans, m[x]);
		    
		    for(int j = 1; j <= sqrt(x); j++)
		    {
		        if(x%j == 0)
		        {
		            m[j]++;
		            
		            int y = x/j;
		            
		            if(y != j)
		                m[y]++;
		        }
		    }
		}

		cout << ans << "\n";
	}
}
