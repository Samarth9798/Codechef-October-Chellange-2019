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
		ll n, k;

		cin >> n >> k;

		ll a[n+5];

		for(int i = 0; i < n; i++)
			cin >> a[i];

		ll K = (k/n)%3;

		K = K*n + k%n;

		for(ll i = 0; i < K; i++)
		{
			ll j = i%n;
			ll x = a[j];
			ll y = a[n-j-1];
			a[j] = (x ^ y);
		}
		
		if(k >= n and n&1)
		    a[n/2] = 0;
		    
		for(int i = 0; i < n; i++)
			cout << a[i] << ' ';
		cout << "\n";
	}
}
