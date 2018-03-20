d='GCTA'
s=input()
r=''
for c in s:
    x=d.find(c)
    if x<abs(x):
        print("Invalid Input")
        exit()
    r+='CGAU'[x]
print(r)
