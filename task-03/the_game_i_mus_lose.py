n,m=map(int,input().split())
l=[]
count=0
if (n%2==0 and m%2==0) or (n%2==0 and m%2!=0):
    for i in range(1,m+1):
        if i%2!=0:
            count+=1
            l.append(i) 
    print(count)
elif (n%2!=0 and m%2==0)or(n%2!=0 and m%2!=0):
    print(count)
for j in l:
    print(j,end=' ')