n, l, r= map(int,input().split())
a = list(map(int,input().split()))

for i in a:
    if i<l: print(l,end=" ")
    elif i>r: print(r,end=" ")
    else: print(i,end=" ")