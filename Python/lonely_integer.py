a = input()
a = input()
a = a.split()
i = ""
list1 = [];

for i in a:
	if i in list1:
		list1.remove(i)
	else:
		list1.append(i)

print (list1[0])