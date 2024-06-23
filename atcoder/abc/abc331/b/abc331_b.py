n,s,m,l = map(int,input().split())
ans = 1000000000000000000000000

for i in range(0,n+1):
    for j in range(0,n+1):
        for k in range(0,n+1):
            if 6*i+8*j+12*k>=n:
                if ans>=s*i+m*j+k*l:
                    ans = s*i+m*j+k*l
                    
                    
print(ans)