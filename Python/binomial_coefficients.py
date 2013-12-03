a = input()
for i in range(0,a): 
	s = raw_input()
	d = s.split(' ')
	b = int(d[0])
        c = int(d[1])
        n = b
        count = 1
	while b > 0:
		count = count * ((b%c) +1)
		b = b/c
	print(n + 1 - count)