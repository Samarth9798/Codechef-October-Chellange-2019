import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
	    Scanner in = new Scanner(System.in);
	    
	    int t = in.nextInt();
	    
	    while(t-- > 0)
	    {
	        int n = in.nextInt();
	        int a[] = new int[n+5];
	        
	        for(int i = 0; i < n; i++)
	            a[i] = in.nextInt();
	           
	        int cnt[] = new int[1000005];
	        int ans = 0;
	        for(int i = 0; i < n; i++)
	        {
	            int x = a[i];
	            if(x == 1)
	            {
	                ans = a[i];
	                continue;
	            }
	            
	            ans = Math.max(ans, cnt[x]);
	            
	            for(int j = 1; j <= (int)Math.sqrt(x); j++)
	            {
	                if(x%j == 0)
	                {
	                    cnt[j]++;
	                    int y = x/j;
	                    if(y != j)
	                        cnt[y]++;
	                }
	            }
	        }
	        
	        System.out.println(ans);
	    }
	}
}
