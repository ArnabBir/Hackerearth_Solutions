x=0
def f(n):
    if(n==0):
        global x
        x+=1
    if(n>0):
        f(n-2)
        f(n-3)
        f(n-5)
f(int(input()))
print(x)
