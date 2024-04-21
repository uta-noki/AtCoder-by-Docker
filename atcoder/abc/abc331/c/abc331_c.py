n = int(input())
a = list(map(int,input().split()))

a_i = [0]*1000002

for i in a:
    a_i[i]+=1

for i in range(2,1000001):
    a_i[i] = a_i[i-1] + a_i[i]*i

for i in range(0,n):
    print(a_i[1000000]-a_i[a[i]],end=" ")