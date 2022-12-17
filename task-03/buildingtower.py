num= int(input())
numbers = list(map(int,input().split()))
b =  len(set(numbers))
o = max(numbers,key=numbers.count)
count = 0
for i in range(num):
    if o == numbers[i]:
        count+=1
print (count,end=' ')
print(b)