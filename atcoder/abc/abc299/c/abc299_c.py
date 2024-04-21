n = int(input())
s = input()
s = [char for char in s]

left_max = 0
right_max = 0
length = 0

for i in s:
    if i=="-":
        left_max = max(left_max,length)
        length = 0
    else:
        length+=1

s.reverse()
length = 0


for i in s:
    if i=="-":
        right_max = max(right_max,length)
        length = 0
    else:
        length+=1
  
if max(left_max,right_max)==0: print(-1)
else: print(max(left_max,right_max))
    
    