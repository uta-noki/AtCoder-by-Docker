n = int(input())
nm = [1,11,111,1111,11111,111111,1111111,11111111,111111111,1111111111,11111111111,111111111111]
ans = [3]

for i in range(len(nm)):
    for j in range(len(nm)):
        for k in range(len(nm)):
            if nm[i]+nm[j]+nm[k] not in ans:
                ans.append(nm[i]+nm[j]+nm[k])
                
ans.sort()
print(ans[n-1])
            