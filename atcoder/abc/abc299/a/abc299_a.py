N = int(input())
S = list(input())

idx = S.index("*")

if ("|" in S[0:idx]) and ("|" in S[idx+1:N]):
    print("in")
else:
    print("ut")