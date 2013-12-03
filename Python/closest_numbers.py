a = input()
b = input()
b = b.split()
c = []

for i in b:
	c.append(float(i))

c.sort()

b = len(c)
i = 0
diffmin = 10000000000000000
min1 = []
min2 = []

while i<b-1:
    diff = c[i+1] - c[i]
    if diff==diffmin:
    	min1.append(i)
    	min2.append(i+1)
	
    elif diff<diffmin:
        min1 = []
        min2 = []
        diffmin = diff
        min1.append(i)
        min2.append(i+1)

    i = i+1

b = len(min1)
i = 0

while i<b:
    print ("%d %d" % (c[min1[i]],c[min2[i]]),end="")
    if i<b-1:
        print (" ",end="")
    i = i+1