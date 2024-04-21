import math

d = int(input())
ans = d

for i in range(int(math.sqrt(d))+1):
    c = i*i - d
    if c>=0: ans = min(ans,c)
    else:
        y1 = int(math.sqrt(-c))
        y2 = int(math.sqrt(-c)+1)
        ans = min(ans,abs(y1*y1+c),abs(y2*y2+c))
        
print(ans)