
S2=[]
i=0
target=int(input("what should be the sum"))
k=int(input("size of the list "))
while i<k:
    l=int(input("what is the number"))
    S2.append(l)
    i=i+1

t=0
c=0
summ=0
found=False
while t<k:
    c=0
    while c<k:
        if c==t:
            c=c+1
            continue
        summ=S2[c]+S2[t]
        if summ==target:
            print(f"target achived at {t},{c}")
            found=True
            break
        c=c+1
    if found==True:
        break
    t=t+1

