n = int(input())
s = []
row = []
column = []

for i in range(n):
    s_i = input()
    s_i = [i for i in s_i]
    s.append(s_i)
    
for i in range(n):
    cnt = 0
    for j in range(n):
        if s[i][j]=="o":
            cnt+=1
    row.append(cnt)
    
for j in range(n):
    cnt = 0
    for i in range(n):
        if s[i][j]=="o":
            cnt+=1
    column.append(cnt)
    
ans = 0
for i in range(n):
    for j in range(n):
        if s[i][j]=='o': ans += (row[i]-1) * (column[j]-1)
        
print(ans)