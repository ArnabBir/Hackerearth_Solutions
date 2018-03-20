s=input()
l=len(s)+1
x=0
for i in range(l):
    for j in range(i,l):
        t=s[i:j]
        if(t==t[::-1]):
            x=max(x,abs(j-i))
print(x)            
