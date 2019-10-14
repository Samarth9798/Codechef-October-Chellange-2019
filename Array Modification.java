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
	        long n = in.nextLong();
	        long k = in.nextLong();
	        long a[] = new long[(int)n+5];
	        
	        for(int i = 0; i < (int)n; i++)
	        {
	            a[i] = in.nextLong();
	        }
	        
	        long K = ((k/n)%3 * n) + (k%n);
	        
	        for(int i = 0; i < (int)K; i++)
	        {
	            int j = (int)(i%n);
	            long x = a[j];
	            long y = a[(int)(n-1-j)];
	            a[j] = (x ^ y);
	        }
	        
	        if(k >= n && n%2 == 1)
	            a[(int)n/2] = 0;
	           
	        for(int i = 0; i < (int)n; i++)
	            System.out.print(a[i] + " ");
	        System.out.println();
	    }
	}
}
