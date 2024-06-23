n, l = map(int,input().split())
a = list(map(int,input().split()))
ans = 0

for i in a:
    if i>=l: ans+=1

print(ans)
