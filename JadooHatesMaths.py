n=int(input())
while(1):
    n+=1
    if(n%3 and '3' not in str(n)):
        break
print(n)
