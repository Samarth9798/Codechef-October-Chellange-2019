#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
typedef long long int ll;

int n,k;

int LIS(vector<int>& a)
{
    int len = 0;
    vector<int> v;

    for(int i = 1; i <= n; i++)
    {
        if(len == 0)
        {
            v.push_back(a[i]);
            len++;
        }
        else 
        {
            if(v[len-1] < a[i])
            {
                v.push_back(a[i]);
                len++;
            }
            else
            {
                int id = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
                v[id] = a[i];
            }
        }
    }
    
    return len;
}

int main()
{
    fast
    
    cin >> n >> k;
    
    int cnt = (k-1)/2;
    
    vector<int> a(n+5);
    vector<int> b(n+5);
    for(int i = 1; i <= n; i++) 
    {
        cin >> a[i];
        b[i] = a[i];
    }
    
    vector<int> v;
    for(int i = 1; i <= n; i++)
        if(cnt < a[i])
            v.push_back(a[i]);
            
    for(int i = 1; i <= cnt; i++)   
        a[i] = i;
    
    int j = 0;
    for(int i = cnt+1; i <= n; i++)
        a[i] = v[j++];
    
    v.clear();
    
    int initial = LIS(a);
    
    vector<vector<int>> curr;
    int i = 1;
    int prev = 0;
    for(i = 1; i <= n; i++)
    {
        if(prev > b[i])
        {
            if(curr.size() == k-1)
            {
                for(int j = i; j <= n; j++)
                    v.push_back(b[j]);
            }
            curr.push_back(v);
            v.clear();
        }
        if(curr.size() == k)
            break;
        v.push_back(b[i]);
        prev = b[i];
    }
    
    sort(curr.begin(), curr.end());
    
    vector<int> c; 
    c = b;
    
    for(i = 1; i <= n; i++)
        b[i] = a[i];
    
    j = 1;
    for(i = 0; i < curr.size(); i++)
    {
        for(int k = 0; k < curr[i].size(); k++)
        {
            a[j++] = curr[i][k];
        }
    }
    
    int current = LIS(a);
    if(current > initial)
    {
        initial = current;
        b = a;
    }
    
    curr.clear();
    v.clear();
    for(i = 1; i <= n; i++)
    {
        v.push_back(c[i]);
        if(i%1 == 0)
        {
            if(curr.size() == k-1)
            {
                for(j = i+1; j <= n; j++)
                    v.push_back(c[j]);
            }
            curr.push_back(v);
            v.clear();
        }
        if(curr.size() == k)
            break;
    }
    if(curr.size() < k)
        curr.push_back(v);
    
    sort(curr.begin(), curr.end());
    
    current = initial;
    vector<int> per;
    c.clear();
    for(int i = 0; i < curr.size(); i++)
        per.push_back(i);
    
    for(int t = 0; t < 20; t++)
    {
        j = 1;
        for(i = 0; i < per.size(); i++)
        {
            int id = per[i];
            for(int k = 0; k < curr[id].size(); k++)
            {
                a[j++] = curr[id][k];
            }
        }
        
        int temp = LIS(a);
        if(temp > current)
        {
            current = temp;
            c = a;
        }
        
        next_permutation(per.begin(), per.end());
    }
    
    if(current > initial)
    {
        for(int i = 1; i <= n; i++)
            cout << c[i] << ' ';
        return 0;
    }
    
    for(i = 1; i <= n; i++)
        cout << b[i] << ' ';
}
