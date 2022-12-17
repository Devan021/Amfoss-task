listnm = list(map(int, input().split()))
l_1 = list(map(int, input().split()))
l_2 = list(map(int, input().split()))
l_1.sort()
l_2.sort()
min=0
i = 0
n = listnm[0]
for j in range(0, listnm[1]):
    if(l_1[i]<l_2[j]):
        i +=1
        min += l_2[j]
        if i == n :
            break
if (i==listnm[0]):
    print("YES")
    print(min)
else:
    print("NO")