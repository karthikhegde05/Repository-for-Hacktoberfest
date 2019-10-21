l = map(int,raw_input().split())
ls= map(int,raw_input().split())
n = l[0]
lst = []
p =1
f = 0
for i in range(l[1]):
	lst.append([])
for i in range(l[0]):
	lst[ls[i]-1].append(i)
for i in range(1,n):
	for j in range(ls[n-1-i]-1):
		for k in lst[j]:
			if k>n-1-i:
				f = k-(n-i-1)+1
				p = p*f
print p
