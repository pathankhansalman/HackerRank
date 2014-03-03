gcdlist = []
gcdval = []

def GCD(a,b):
    if a<b:
        a,b=b,a
    if b==0:
        return a
    a = a%b
    return GCD(b,a)

def GCDL(l):
    if len(l) == 2:
        return GCD(l[0],l[1])
    head,*tail = l
    return GCD(head,GCDL(tail))

def main():
    t = int(input())
    for i in range(0,t):
        k = int(input())
        print (k)
        nlist = input()
        nlist = nlist.split()
        for j in range(0,k):
            nlist[j] = int(nlist[j])
        if nlist in gcdlist:
            print (gcdval[gcdlist.index(nlist)])
        else:
            gcdlist.append(nlist)
            gcdval.append(GCDL(nlist))
            print (gcdval[gcdlist.index(nlist)])