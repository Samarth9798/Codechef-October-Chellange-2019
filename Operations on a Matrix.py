t = int(input())

while t:
    t-=1
    
    n,m,q = map(int, input().split())
    
    r = [0]*(n+1)
    c = [0]*(m+1)
    
    R = 0
    C = 0
    while q:
        q-=1
        x,y = map(int,input().split())
        
        r[x] ^= 1
        c[y] ^= 1
        
        R += -1 if r[x] == 0 else 1
        C += -1 if c[y] == 0 else 1
    
    odd = C
    even = m - C
    ans = R*even + (n-R)*odd
    print(ans)
