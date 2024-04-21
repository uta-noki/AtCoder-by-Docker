n, t = map(int,input().split())
c = list(map(int,input().split()))
r = list(map(int,input().split()))

is_t = False
c_index = -1
r_max = -1

for i in range(len(c)):
    if c[i]==t:
        is_t = True
        if r_max<r[i]:
            c_index = i
            r_max = r[i]
        
if is_t:
    print(c_index+1)
    exit()

r_max = r[0]
c_index = 0
for i in range(len(c)):
    if c[i]==c[0] and r_max<r[i]:
        c_index = i
        r_max = r[i]

print(c_index+1)