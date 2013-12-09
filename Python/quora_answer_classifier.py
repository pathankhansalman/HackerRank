#If only ones and zeroes - boolean

attr = []
used = []
globalids = [0]
dtrees = []

class Dtree:
	val = ""
	ids = 0
	parent_id = 0
	is_leaf = 0
	parent_val = ""
	lower = ""
	upper = ""
	children = []

	def _init_(self,arg1,arg2,arg3,arg4,arg5,arg6): #arg1->is_leaf;arg2->parent_id;arg3->val;arg4->parent_val;arg5->lower;arg6->upper
		val = arg3
		is_leaf = arg1
		parent_id = arg2
		ids = max(globalids) + 1
		if not is_leaf == 0:
			parent_val = arg4
			lower = arg5
			upper = arg6
		dtrees.append(self)

	def buildChildren(self):
		mini = 100000000000000000000
		minind = 0
		arr = values(attr[val])
		is_int = 0 if arr[0] == "0" else 1
		arr = arr[1:]
		for value in arr:
			if is_int == 0:
				all_positive = 1
				all_negative = 1
				for i in range(0,len(attr) - 1):
					arg = []
					if used[i] == 0:
						for j in range(0,len(attr[i]) - 1):
							if attr[int(parent_val)][j] == value:
								arg.append(attr[i][j])
								if correct[j] == "+1":
									all_negative = 0
								elif correct[j] == "-1":
									all_positive = 0 
						ginis = gini(arg)
						if ginis < mini:
							mini = ginis
							minind = i
				is_leaf_child = "0"
				if all_positive == 1 or all_negative == 1:
					is_leaf_child = "1"
				child = Dtree(is_leaf_child,ids,minind,val,value,value)
				if is_leaf_child == "0":
					child.buildChildren()
				children.append(child.ids)

def values(a):
	retval = []
	if is_disc(a) == 1:
		retval.append("1")
		for i in range(0,len(a) - 1):
			if a[i] not in retval:
				retval.append(a[i])
		return retval
	else:
		retval.append("0")
		maxi = -10000000000000000
		mini = 10000000000000000
		for i in range(0,len(a) - 1):
			if a[i] < mini:
				mini = a[i]
			if a[i] > maxi:
				maxi = a[i]
		ranges = maxi - mini
		curr = mini
		while curr<=maxi:
			retval.append(curr)
			curr+=(ranges/5.)

def is_disc(a):
	is_bool = 1
	is_string = 1
	is_number = 1
	size = len(a) if len(a) - 200 >=0 else 200
	for i in range(0,size-1):
		if not (isinstance(a[i],float)):
			is_bool = 0
			is_number = 0
		elif float(a[i]) > 1 or float(a[i]) < 0:
			is_bool = 0
			is_string = 0
		else:
			is_number = 0
			is_string = 0

	if is_string == 1 or is_bool == 1:
		return 1
	else:
		return 0

def gini_contin(a):
	return 1

def gini_disc(a):
	total = len(a)
	p = []
	mem = []
	count = []
	sums = 0.0

	for i in range(0,len(a)):
		if a[i] not in mem:
			mem.append(a[i])
			count.append(1)
		else:
			count[mem.index(a[i])]+=1

	for i in range(0,len(count)):
		p.append(count[i]/(total*1.))
		sums+=(p[i]**2)

	sums = 1 - sums

	return sums
	
def gini(a):
	if is_disc(a) == 1:
		return gini_disc(a)
	else:
		return gini_contin(a)

def build_dtree():
	mini = 10000000000000000
	minind = 0
	
	for i in range(0,len(attr)-1):
		ginis = gini(attr[i])
		if ginis < mini:
			mini = ginis
			minind = i

	is_leaf_child = 0
	all_positive = 1
	all_negative = 1
	for i in correct:
		if i == "+1":
			all_negative = 0
		elif i == "-1":
			all_positive = 0
	if all_positive == 1 or all_negative == 1:
		is_leaf_child = 1

	root = Dtree(is_leaf_child,0,minind,"-1","-1","-1")

def classify_dtree():


NandM = input()
NandM = NandM.split()
N = int(NandM[0])
M = int(NandM[1])
i = 0
main_ids = []
correct = []

for i in range(1,N):
	Training = input()
	Training = Training.split()
	main_ids.append(Training[0])
	correct.append(Training[1])
	k = 2
	j = 0
	attr.append([])
	for j in range(0,M-1):
		attr[j].append(Training[k])
		k = k+1

mini = 100000000000000
minind = 0

build_dtree()
attr = []
Q = input()
Q = int(Q)
main_ids = []
for i in range(1,Q):
	Testing = input()
	Testing = Testing.split()
	main_ids.append(Testing[0])
	k = 1
	j = 0
	attr.append([])
	for j in range(0,M-1):
		attr[j].append(Testing[k])
		k = k+1

classify_dtree(root)

for i,j in zip(main_ids,classes):
	print ("%s %s\n"%(i,j))