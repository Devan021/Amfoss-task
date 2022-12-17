n=int(input())
row=0
n_1=(n**(0.5))+1
for i in range(1,int(n_1)):
  if n%i==0:
    if n/i==i:
        row+=1
    else:
      row+=2
print(row)