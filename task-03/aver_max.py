t=int(input())
for i in range(0,t):
    n,k=map(int,input().split())
    arr=list(map(float,input().split()))
    if(k>=1):
        for j in range(0,n):
            if(arr[j]<0):
                arr[j]=arr[j]*(-1)
    print(max(arr))