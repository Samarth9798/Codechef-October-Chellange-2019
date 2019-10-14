T = int(input())

while T:
    T -= 1
    N = int(input())
    
    price = list(map(int, input().split()))
    
    ans = 0
    for i in range(0, N):
        min_cost = price[i]
        cnt = 0
        for j in range(i-1, -1, -1):
            min_cost = min(min_cost, price[j])
            cnt += 1
            if price[j] == price[i]:
                min_cost = price[i] + 1
                break
            if cnt == 5:
                break
        if min_cost == price[i]:
            ans += 1
            
    print(ans)
